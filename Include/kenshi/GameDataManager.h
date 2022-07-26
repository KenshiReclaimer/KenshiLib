#pragma once

#include <boost/unordered_map.hpp>

namespace Kenshi
{
    class GameData;

    struct GameDataContainer
    {
        virtual ~GameDataContainer();
    };

    struct GameDataManager : public GameDataContainer // 0x180 bytes total
    {
        // has a bunch of unordered_maps and other data containers for lists of gamedata
        char unk_0008[0x58]; // 0x8
        // 0x20 - STLAllocator< ?? :: ?? > (probably boost::unordered_map of some kind)
        boost::unordered_map<int, GameData*> intGameDataMap;// 0x60
        char unk_0090[0x50];// 0x90
        // 0xA0 - STLAllocator< ?? :: ?? > (probably boost::unordered_map of some kind)
        boost::unordered_map<std::string, GameData*> stringGameDataMap;// 0xE0
        char unk_0110[0x70];// 0x110
        // 0x118 - might be a boost::unordered_set<GameData*>?
    };
}
