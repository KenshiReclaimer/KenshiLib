#pragma once

#include <kenshi/util/lektor.h>

// TODO move?
class GameDataHeader
{
public:
    GameDataHeader(const GameDataHeader&);// RVA = 0x6CA8C0
    GameDataHeader(const std::string&, const std::string&);// RVA = 0x55F340
    GameDataHeader();// RVA = 0x55D600
    std::string name; // 0x0 Member
    std::string author; // 0x28 Member
    int version; // 0x50 Member
    std::string description; // 0x58 Member
    lektor<std::string > dependencies; // 0x80 Member
    lektor<std::string > references; // 0x98 Member
    ~GameDataHeader();// RVA = 0xE3630
    GameDataHeader& operator=(const GameDataHeader&);// RVA = 0xE74A0
    // no_addr public void * __vecDelDtor(unsigned int);
};

class ModInfo : Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    ModInfo(const ModInfo&);// RVA = 0x6CAF60
    ModInfo();// RVA = 0x6B8010
    std::string name; // 0x0 Member
    std::string file; // 0x28 Member
    std::string path; // 0x50 Member
    bool isWorkshop; // 0x78 Member
    bool isBaseMod; // 0x79 Member
    std::string leveldataFolder; // 0x80 Member
    GameDataHeader header; // 0xA8 Member
    bool getLocale(std::string&, std::string&);// RVA = 0x6BE700
    ~ModInfo();// RVA = 0x6C93F0
    ModInfo& operator=(const ModInfo&);// RVA = 0x6CA990
    // no_addr public void * __vecDelDtor(unsigned int);
};
