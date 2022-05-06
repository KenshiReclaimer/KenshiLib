#pragma once

#include <string>
#include <boost/unordered_map.hpp>

namespace Kenshi
{
    struct GameDataManager;
    // extends Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0>>
    // vtable only contains destructor?
    class GameData // probably 0x300 long
    /*
        Basic entity of the game, all serialized data/assets are built from this class.
        Equivalent to a TESForm in bethesda games it looks like.
        Contains a bunch of boost hashtables by the look
    */
    {
        virtual ~GameData();
    public:
        char pad_0008[0x8]; // 0x08
        GameDataManager* gameDataManager; // 0x10
        char pad_0018[0x10]; // 0x18
        std::string name; // 0x28
        char unk_0050[0x78];// 0x50
        // sizeof(boost::unordered_map) = 48 = 0x30
        // Pretty sure my template is wrong - could be an allocator or something? these look like 0x40 bytes...
        boost::unordered_map<std::string, bool> booleans;// 0xc8
        char unk_00F8[0x10];// 0xF8
        boost::unordered_map<std::string, bool> booleans2;// 0x108
        char unk_0138[0x10];// 0x138
        boost::unordered_map<std::string, std::string> strings;// 0x148
        char unk_0178[0x10];// 0x178
        boost::unordered_map<std::string, int> ints;// 0x188
        char unk_01B8[0x10];// 0x1B8
        boost::unordered_map<std::string, float> floats;// 0x1C8
        char unk_01F8[0x10];// 0x1F8
        boost::unordered_map<std::string, std::string> strings2;// 0x208
        char unk_0238[0x10];// 0x238
        boost::unordered_map<std::string, Ogre::Vector3> vec3s;// 0x248
        char unk_0278[0x10];// 0x278
        boost::unordered_map<std::string, Ogre::Quaternion> quaternions;// 0x288
        // 2C8 = boost::unordered_map<std::string, std::vector<GameDataReference>> 
    };
}
