#pragma once
#include "mygui/MyGUI_Gui.h"


namespace Kenshi 
{


    struct GameWorld;
    struct PlayerInterface;
    struct Character;
    struct Building;
    struct Renderer;
    struct PhysicsActual;
    struct ModInfo;
    struct Character;
    struct Building;
    struct ZoneManager;
    struct AudioSystemGlobal;
    struct Alarm;
    struct PlayerInterface;
    struct ResearchManager;
    struct ResearchItem;

    MyGUI::WidgetPtr FindWidget(MyGUI::EnumeratorWidgetPtr enumerator, std::string name);

    class BinaryVersion
    {
    public:
        enum KenshiPlatform
        {
            GOG,
            STEAM,
            UNKNOWN
        };

        BinaryVersion(KenshiPlatform platform, std::string version)
            : platform(platform), version(version)
        {

        }

        KenshiPlatform GetPlatform()
        {
            return platform;
        }

        std::string GetPlatformStr()
        {
            if (platform == KenshiPlatform::STEAM)
                return "Steam";
            if (platform == KenshiPlatform::GOG)
                return "GOG";
            return "Unknown";
        }

        std::string GetVersion()
        {
            return version;
        }

        // used for sorting/map
        // TODO should use unordered map?
        bool operator< (const BinaryVersion& b) const
        {
            if (this->version != b.version)
                return this->version < b.version;
            return this->platform < b.platform;
        }

    private:
        KenshiPlatform platform;
        // TODO should this be ints?
        std::string version;
    };

    BinaryVersion GetKenshiVersion();

    // GameWorld looks to be an object of all game state, whether its loaded or not.
    // Has things like a list of loaded mods and all the GameData loaded in, probably saves too.
    GameWorld& GetGameWorld();

    // Static var separate to GameWorld
    int& GetNumAttackSlots();

}