#pragma once

namespace Kenshi
{
    struct GameDataContainer
    {
        virtual ~GameDataContainer();
    };

    struct GameDataManager : public GameDataContainer // 0x180 bytes total
    {
        // will re this structure later,
        // has a bunch of unordered_maps and other data containers for lists of gamedata
        char pad[0x178];
    };
}
