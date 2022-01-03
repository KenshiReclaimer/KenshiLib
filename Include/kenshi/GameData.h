#pragma once

#include <string>

namespace Kenshi
{
    struct GameDataManager;
    // extends Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0>>
    // vtable only contains destructor?
    class GameData
    /*
        Basic entity of the game, all serialized data/assets are built from this class.
        Equivalent to a TESForm in bethesda games it looks like.
    */
    {
        virtual ~GameData();
    public:
        char pad_0008[0x8]; // 0x08
        GameDataManager* gameDataManager; // 0x10
        char pad_0018[0x10]; // 0x18
        std::string name; // 0x28
    };
}
