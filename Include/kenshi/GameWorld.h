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
        class Renderer *renderEngine; //0x0010
        class PhysicsActual *physicsEngine; //0x0018
        class GameDataManager dataMgr1; //0x0020
        class GameDataManager dataMgr2; //0x01A0
        class GameDataManager dataMgr3; //0x0320
        class N00000FA0 *uiStuff; //0x04A0
        class FactionData *factionData; //0x04A8
        class NavMesh *navMesh; //0x04B0
        class N00001239 *locationData; //0x04B8
        class hand N00000310; //0x04C0
        class MessageRoller *messageRoller; //0x04E0
        char pad_04E8[16]; //0x04E8
        class lektor<ModInfo> coreMods; //0x04F8 ModInfo
        class lektor<std::string> coreModNames; //0x0510 std::string
        class lektor<ModInfo*> loadedMods; //0x0528 ModInfo*
        char pad_0540[40]; //0x0540
        class lektor<ModInfo*> availableMods; //0x0568
        class PlayerInterface *playerInterface; //0x0580
        char pad_0588[160]; //0x0588
        class lektor<hand> unkHand; //0x0628 hand
        char pad_0640[584]; //0x0640
        class lektor<Character*> unkCharArray; //0x0888 Character*
        char pad_08A0[16]; //0x08A0
        class ZoneManager *zoneManager; //0x08B0
        char pad_08B8[8]; //0x08B8
        class AudioSystemGlobal *audioSystem; //0x08C0
        char pad_08C8[80]; //0x08C8
        class lektor<StringPair> someBuffs; //0x0918 StringPair
        char pad_0930[720]; //0x0930
        class lektor<Building*> usedBuildings; //0x0C00 Building* ?
        char pad_0C18[864]; //0x0C18
        class lektor<Alarm*> currentAlarms; //0x0F78 AlarmManager::Alarm*
        char pad_0F90[1368]; //0x0F90

    };
}
