#pragma once
#include <stdafx.h>

#include <ogre/OgreVector3.h>

#include <kenshi/Root.h>
#include <kenshi/MedicalSystem.h>

namespace Kenshi
{

    struct GameData;
    struct Faction;

    struct Character : public RootObject
    {
        virtual ~Character();

    public:
    	uint64_t id; //0x0008
        Faction *faction; //0x0010
        std::string name; //0x0018
        char pad_0038[8]; //0x0038
        GameData *dataNode; //0x0040
        Ogre::Vector3 position; //0x0048
        char pad_0054[92]; //0x0054
        Ogre::Vector3 rotation; //0x00B0
        char pad_00BC[8]; //0x00BC
        Ogre::Vector3 N00000E8C; //0x00C4
        char pad_00D0[904]; //0x00D0
        MedicalSystem medicalSystem; //0x0458 MedicalSystem
    };


    struct CharacterHuman
    {

    };
}
