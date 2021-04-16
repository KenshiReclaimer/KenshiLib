#pragma once

#include <stdafx.h>

#include <kenshi/util/lektor.h>
#include <kenshi/util/hand.h>

#include <kenshi/GameDataManager.h>

namespace Kenshi
{
    struct Renderer;
    struct PhysicsActual;
    struct ModInfo;
    struct Character;
    struct Building;
    struct ZoneManager;
    struct AudioSystemGlobal;
    struct Alarm;
    struct PlayerInterface;

    struct StringPair
    {
        std::string first;
        std::string second;
    };

    struct GameWorld
    {
        virtual ~GameWorld();

        float N00000050; //0x0008
        float N0000009B; //0x000C
        struct Renderer *renderEngine; //0x0010
        struct PhysicsActual *physicsEngine; //0x0018
        struct GameDataManager dataMgr1; //0x0020
        struct GameDataManager dataMgr2; //0x01A0
        struct GameDataManager dataMgr3; //0x0320
        struct N00000FA0 *uiStuff; //0x04A0
        struct FactionData *factionData; //0x04A8
        struct NavMesh *navMesh; //0x04B0
        struct N00001239 *locationData; //0x04B8
        struct hand N00000310; //0x04C0
        struct MessageRoller *messageRoller; //0x04E0
        char pad_04E8[16]; //0x04E8
        struct lektor<ModInfo> coreMods; //0x04F8 ModInfo
        struct lektor<std::string> coreModNames; //0x0510 std::string
        struct lektor<ModInfo*> loadedMods; //0x0528 ModInfo*
        char pad_0540[40]; //0x0540
        struct lektor<ModInfo*> availableMods; //0x0568
        struct PlayerInterface *playerInterface; //0x0580
        char pad_0588[160]; //0x0588
        struct lektor<hand> unkHand; //0x0628 hand
        char pad_0640[0xC0]; //0x0640
        float gameSpeed; //0x0700
        char pad_0704[0x184]; //0x0704
        struct lektor<Character*> unkCharArray; //0x0888 Character*
        char pad_08A0[16]; //0x08A0
        struct ZoneManager *zoneManager; //0x08B0
        char pad_08B8[8]; //0x08B8
        struct AudioSystemGlobal *audioSystem; //0x08C0
        char pad_08C8[80]; //0x08C8
        struct lektor<StringPair> someBuffs; //0x0918 StringPair
        char pad_0930[720]; //0x0930
        struct lektor<Building*> usedBuildings; //0x0C00 Building* ?
        char pad_0C18[864]; //0x0C18
        struct lektor<Alarm*> currentAlarms; //0x0F78 AlarmManager::Alarm*
        char pad_0F90[1368]; //0x0F90

    };
}
