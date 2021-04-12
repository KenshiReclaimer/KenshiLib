#pragma once

#include <stdafx.h>

#include <ogre/OgreCamera.h>
#include <ogre/OgreSceneNode.h>


namespace Kenshi
{
  struct  __declspec(align(1)) ViewData
  {
    _BYTE byte0;
    _BYTE gap1[15];
    _QWORD qword10;
    _QWORD qword18;
    _WORD word20;
    _BYTE gap22[6];
    _QWORD qword28;
    _DWORD dword30;
    _DWORD dword34;
    _QWORD qword38;
    _DWORD dword40;
    _BYTE gap44[4];
    _DWORD dword48;
    _DWORD dword4C;
    _DWORD dword50;
    _BYTE gap54[4];
    Ogre::Node *camera_center;
    _DWORD dword60;
    _BYTE gap64[4];
    Ogre::Camera *camera;
    Ogre::SceneNode *pogre__scenenode70;
    _DWORD dword78;
    _BYTE gap7C[4];
    _QWORD qword80;
    _QWORD qword88;
    _BYTE gap90[4];
    _DWORD dword94;
    _BYTE gap98[8];
    _QWORD qwordA0;
    _DWORD dwordA8;
    _BYTE gapAC[4];
    _QWORD qwordB0;
    _DWORD dwordB8;
    _WORD wordBC;
    _BYTE byteBE;
  };

}

