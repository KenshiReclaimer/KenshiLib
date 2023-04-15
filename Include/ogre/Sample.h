/*
 -----------------------------------------------------------------------------
 This source file is part of OGRE
 (Object-oriented Graphics Rendering Engine)
 For the latest info, see http://www.ogre3d.org/
 
 Copyright (c) 2000-2014 Torus Knot Software Ltd
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 -----------------------------------------------------------------------------
 */
#ifndef __Sample_H__
#define __Sample_H__

#include "OgreRoot.h"
#include "OgreOverlaySystem.h"
#include "OgreResourceManager.h"

#include "InputContext.h"
#include "OgreFileSystemLayer.h"
#include "OgreSceneManager.h"
#include "Compositor/OgreCompositorManager2.h"

#ifdef INCLUDE_RTSHADER_SYSTEM
#   include "OgreRTShaderSystem.h"
#endif //INCLUDE_RTSHADER_SYSTEM

#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE_IOS
#   include "macUtils.h"
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_NACL && !defined(INCLUDE_RTSHADER_SYSTEM)
#   define INCLUDE_RTSHADER_SYSTEM
#include "OgreShaderGenerator.h"
#endif


namespace OgreBites
{
    /*=============================================================================
    | Base class responsible for everything specific to one sample.
    | Designed to be subclassed for each sample.
    =============================================================================*/
    class Sample : public Ogre::GeneralAllocatedObject
    {
    public:
        /*=============================================================================
        | Utility comparison structure for sorting samples using SampleSet.
        =============================================================================*/
        struct Comparer
        {
            bool operator() (Sample* a, Sample* b)
            {
                Ogre::NameValuePairList::iterator aTitle = a->getInfo().find("Title");
                Ogre::NameValuePairList::iterator bTitle = b->getInfo().find("Title");
                
                if (aTitle != a->getInfo().end() && bTitle != b->getInfo().end())
                    return aTitle->second.compare(bTitle->second) < 0;
                else return false;
            }
        };

#ifdef INCLUDE_RTSHADER_SYSTEM
        Sample() : mShaderGenerator(0)
#else
        Sample()
#endif
        {
            mRoot = Ogre::Root::getSingletonPtr();
            mWindow = 0;
            mSceneMgr = 0;
            mDone = true;
            mResourcesLoaded = false;
            mContentSetup = false;
            mWorkspace = 0;

            mFSLayer = 0;
            mOverlaySystem = 0;
        }

        virtual ~Sample() {}

        /*-----------------------------------------------------------------------------
        | Retrieves custom sample info.
        -----------------------------------------------------------------------------*/
        Ogre::NameValuePairList& getInfo()
        {
            return mInfo;
        }

        /*-----------------------------------------------------------------------------
        | Tests to see if target machine meets any special requirements of
        | this sample. Signal a failure by throwing an exception.
        -----------------------------------------------------------------------------*/
        virtual void testCapabilities(const Ogre::RenderSystemCapabilities* caps) {}

        /*-----------------------------------------------------------------------------
        | If this sample requires a specific render system to run, this method
        | will be used to return its name.
        -----------------------------------------------------------------------------*/
        virtual Ogre::String getRequiredRenderSystem()
        {
            return "";
        }

        /*-----------------------------------------------------------------------------
        | If this sample requires specific plugins to run, this method will be
        | used to return their names.
        -----------------------------------------------------------------------------*/
        virtual Ogre::StringVector getRequiredPlugins()
        {
            return Ogre::StringVector();
        }

        Ogre::SceneManager* getSceneManager()
        {
            return mSceneMgr;
        }

        bool isDone()
        {
            return mDone;
        }

        /*-----------------------------------------------------------------------------
        | Sets up a sample. Used by the SampleContext class. Do not call directly.
        -----------------------------------------------------------------------------*/
        virtual void _setup(Ogre::RenderWindow* window, InputContext inputContext, Ogre::FileSystemLayer* fsLayer, Ogre::OverlaySystem* overlaySys)
        {
            // assign mRoot here in case Root was initialised after the Sample's constructor ran.
            mRoot = Ogre::Root::getSingletonPtr();
            mOverlaySystem = overlaySys;
            mWindow = window;
            mInputContext = inputContext;
            mFSLayer = fsLayer;

            locateResources();
            createSceneManager();
            setupView();

            loadResources();
            mResourcesLoaded = true;
            mWorkspace = setupCompositor();
            setupContent();
            mContentSetup = true;

            mDone = false;
        }

        /*-----------------------------------------------------------------------------
        | Shuts down a sample. Used by the SampleContext class. Do not call directly.
        -----------------------------------------------------------------------------*/
        virtual void _shutdown()

        {
            if (mContentSetup)
                cleanupContent();
            if (mSceneMgr)
                mSceneMgr->clearScene();
            mContentSetup = false;

            if (mResourcesLoaded)
                unloadResources();
            mResourcesLoaded = false;
            if (mSceneMgr) 
            {
#ifdef INCLUDE_RTSHADER_SYSTEM
                mShaderGenerator->removeSceneManager(mSceneMgr);
#endif
                mWorkspace = 0;
                Ogre::CompositorManager2 *compositorManager = mRoot->getCompositorManager2();
                compositorManager->removeAllWorkspaces();
                mSceneMgr->removeRenderQueueListener(mOverlaySystem);
                mRoot->destroySceneManager(mSceneMgr);
            }
            mSceneMgr = 0;

            mDone = true;
        }

        /*-----------------------------------------------------------------------------
        | Actions to perform when the context stops sending frame listener events
        | and input device events to this sample.
        -----------------------------------------------------------------------------*/
        virtual void paused() {}

        /*-----------------------------------------------------------------------------
        | Actions to perform when the context continues sending frame listener
        | events and input device events to this sample.
        -----------------------------------------------------------------------------*/
        virtual void unpaused() {}

        /*-----------------------------------------------------------------------------
        | Saves the sample state. Optional. Used during reconfiguration.
        -----------------------------------------------------------------------------*/
        virtual void saveState(Ogre::NameValuePairList& state) {}

        /*-----------------------------------------------------------------------------
        | Restores the sample state. Optional. Used during reconfiguration.
        -----------------------------------------------------------------------------*/
        virtual void restoreState(Ogre::NameValuePairList& state) {}

        // callback interface copied from various listeners to be used by SampleContext

        virtual bool frameStarted(const Ogre::FrameEvent& evt) { return true; }
        virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt) { return true; }
        virtual bool frameEnded(const Ogre::FrameEvent& evt) { return true; }
        virtual void windowMoved(Ogre::RenderWindow* rw) {}
        virtual void windowResized(Ogre::RenderWindow* rw) {}
        virtual bool windowClosing(Ogre::RenderWindow* rw) { return true; }
        virtual void windowClosed(Ogre::RenderWindow* rw) {}
        virtual void windowFocusChange(Ogre::RenderWindow* rw) {}
        virtual bool keyPressed(const OIS::KeyEvent& evt) { return true; }
        virtual bool keyReleased(const OIS::KeyEvent& evt) { return true; }
        virtual bool pointerMoved(const OIS::PointerEvent& evt) { return true; }
        virtual bool pointerPressed(const OIS::PointerEvent& evt, OIS::MouseButtonID id) { return true; }
        virtual bool pointerReleased(const OIS::PointerEvent& evt, OIS::MouseButtonID id) { return true; }

    protected:

        /*-----------------------------------------------------------------------------
        | Finds sample-specific resources. No such effort is made for most samples,
        | but this is useful for special samples with large, exclusive resources.
        -----------------------------------------------------------------------------*/
        virtual void locateResources() {}

        /*-----------------------------------------------------------------------------
        | Loads sample-specific resources. No such effort is made for most samples,
        | but this is useful for special samples with large, exclusive resources.
        -----------------------------------------------------------------------------*/
        virtual void loadResources() {}

        /*-----------------------------------------------------------------------------
        | Creates a scene manager for the sample. A generic one is the default,
        | but many samples require a special kind of scene manager.
        -----------------------------------------------------------------------------*/
        virtual void createSceneManager()
        {
#if OGRE_DEBUG_MODE
            //Debugging multithreaded code is a PITA, disable it.
            const size_t numThreads = 1;
            Ogre::InstancingThreadedCullingMethod threadedCullingMethod = Ogre::INSTANCING_CULLING_SINGLETHREAD;
#else
            //getNumLogicalCores() may return 0 if couldn't detect
            const size_t numThreads = std::max<size_t>( 1, Ogre::PlatformInformation::getNumLogicalCores() );

            Ogre::InstancingThreadedCullingMethod threadedCullingMethod = Ogre::INSTANCING_CULLING_SINGLETHREAD;

            //See doxygen documentation regarding culling methods.
            //In some cases you may still want to use single thread.
            if( numThreads > 1 )
                threadedCullingMethod = Ogre::INSTANCING_CULLING_THREADED;
#endif
            mSceneMgr = Ogre::Root::getSingleton().createSceneManager(Ogre::ST_GENERIC, numThreads, threadedCullingMethod);
#ifdef INCLUDE_RTSHADER_SYSTEM
            mShaderGenerator->addSceneManager(mSceneMgr);
#endif
            if(mOverlaySystem)
                mSceneMgr->addRenderQueueListener(mOverlaySystem);
        }

        /// Most likely the user wants to implement one. @See SdkSample::setupCompositor
        virtual Ogre::CompositorWorkspace* setupCompositor() { return 0; }

        /*-----------------------------------------------------------------------------
        | Sets up viewport layout and camera.
        -----------------------------------------------------------------------------*/
        virtual void setupView() {}

        /*-----------------------------------------------------------------------------
        | Sets up the scene (and anything else you want for the sample).
        -----------------------------------------------------------------------------*/
        virtual void setupContent() {}

        /*-----------------------------------------------------------------------------
        | Cleans up the scene (and anything else you used).
        -----------------------------------------------------------------------------*/
        virtual void cleanupContent() {}

        /*-----------------------------------------------------------------------------
        | Unloads sample-specific resources. My method here is simple and good
        | enough for most small samples, but your needs may vary.
        -----------------------------------------------------------------------------*/
        virtual void unloadResources()
        {
            Ogre::ResourceGroupManager::ResourceManagerIterator resMgrs =
            Ogre::ResourceGroupManager::getSingleton().getResourceManagerIterator();

            while (resMgrs.hasMoreElements())
            {
                resMgrs.getNext()->unloadUnreferencedResources();
            }
        }   

        Ogre::Root* mRoot;                // OGRE root object
        Ogre::OverlaySystem* mOverlaySystem; // OverlaySystem
        Ogre::RenderWindow* mWindow;      // context render window
        InputContext mInputContext;
        Ogre::FileSystemLayer* mFSLayer;          // file system abstraction layer
        Ogre::SceneManager* mSceneMgr;    // scene manager for this sample
        Ogre::NameValuePairList mInfo;    // custom sample info
        Ogre::CompositorWorkspace *mWorkspace;
        bool mDone;                       // flag to mark the end of the sample
        bool mResourcesLoaded;    // whether or not resources have been loaded
        bool mContentSetup;       // whether or not scene was created
#ifdef INCLUDE_RTSHADER_SYSTEM
        Ogre::RTShader::ShaderGenerator*            mShaderGenerator;           // The Shader generator instance.
    public:
        void setShaderGenerator(Ogre::RTShader::ShaderGenerator* shaderGenerator) 
        { 
            mShaderGenerator = shaderGenerator;
        };
#endif
    };

    typedef std::set<Sample*, Sample::Comparer> SampleSet;
}

#endif
