#pragma once

#include <kenshi/Logger.h>
#include <kenshi/ThreadClass.h>
#include <kenshi/util/lektor.h>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <kenshi/util/OgreUnordered.h>
#include <string>
#include <boost/thread/shared_mutex.hpp>

namespace MyGUI
{
    class ImageBox;
}

class SaveFileSystem : public ThreadClass
{
public:
    // ThreadClass offset = 0x0, length = 0x88
    static SaveFileSystem * getSingleton();// public RVA = 0x37D9A0
    // no_addr void SaveFileSystem(const class SaveFileSystem & _a1);// public missing arg names
    SaveFileSystem();// public RVA = 0x471660
    void _CONSTRUCTOR();// public RVA = 0x471660
    virtual ~SaveFileSystem();// public RVA = 0x471B20 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x471B20 vtable offset = 0x0
    void log(const std::string & message, Logger::Severity level);// public RVA = 0x470550
    void setTemporaryPath(const std::string & path);// public RVA = 0x470710
    bool fileExists(const std::string & name) const;// public RVA = 0x470690
    std::string readFile(const std::string & name) const;// public RVA = 0x470840
    std::string writeFile(const std::string & name);// public RVA = 0x471590
    void deleteFile(const std::string & name);// public RVA = 0x471080
    void newGame();// public RVA = 0x470920
    void loadGame(const std::string & savePath);// public RVA = 0x473F60
    bool saveGame(const std::string & savePath);// public RVA = 0x472FA0
    void sync();// public RVA = 0x473B30
    void analyse();// public RVA = 0x4734B0
    void cleanup(bool full);// public RVA = 0x472F00
    void scanForResidualTempFolders();// public RVA = 0x471260
    bool isTempFolder(const std::string & f) const;// public RVA = 0x470F60
    const std::string & getActiveSave() const;// public RVA = 0x47A200
    bool busy() const;// public RVA = 0x3D2440
    void createCurrent();// protected RVA = 0x470A60
    virtual unsigned long threadProc();// protected RVA = 0x472340 vtable offset = 0x0
    unsigned long _NV_threadProc();// protected RVA = 0x472340 vtable offset = 0x0
    std::map<std::string,int,std::less<std::string >,Ogre::STLAllocator<std::pair<std::string const ,int>,Ogre::GeneralAllocPolicy > > fileSystem; // 0x88 Member
    boost::unordered::unordered_set<std::string,boost::hash<std::string >,std::equal_to<std::string >,Ogre::STLAllocator<std::string,Ogre::GeneralAllocPolicy > > deletedFiles; // 0xB0 Member
    lektor<std::string > paths; // 0xF0 Member
    lektor<std::string > oldCurrentFolders; // 0x108 Member
    std::string currentSave; // 0x120 Member
    std::string currentFolder; // 0x148 Member
    std::string tempFolder; // 0x170 Member
    int currentPathIndex; // 0x198 Member
    boost::shared_mutex currentMutex; // 0x1A0 Member
    MyGUI::ImageBox * savingIcon; // 0x1C0 Member
    enum MessageType
    {
        MSG_COPY,
        MSG_COPY_REPLACE,
        MSG_DELETE    
    };

    struct FileMessage
    {
        SaveFileSystem::MessageType mode; // 0x0 Member
        std::string source; // 0x8 Member
        std::string dest; // 0x30 Member
        // no_addr void FileMessage(const struct SaveFileSystem::FileMessage & _a1);// public missing arg names
        FileMessage();// public RVA = 0x476400
        void _CONSTRUCTOR();// public RVA = 0x476400
        ~FileMessage();// public RVA = 0x476430
        void _DESTRUCTOR();// public RVA = 0x476430
        SaveFileSystem::FileMessage & operator=(const SaveFileSystem::FileMessage & __that);// public RVA = 0x477700
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    lektor<SaveFileSystem::FileMessage> messages; // 0x1C8 Member
    void addMessage(SaveFileSystem::MessageType type, const std::string & src, const std::string & dst);// protected RVA = 0x470780
    enum State
    {
        NORMAL,
        SAVING,
        COMPLETE    
    };

    SaveFileSystem::State state; // 0x1E0 Member
    std::string failedToCopyError; // 0x1E8 Member
    std::basic_ofstream<char,std::char_traits<char> > saveLog; // 0x210 Member
    // no_addr class SaveFileSystem & operator=(const class SaveFileSystem & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};
