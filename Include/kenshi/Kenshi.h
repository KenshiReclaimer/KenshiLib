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
    struct InputHandler;

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

    // default 2000
    float& GetMaxCameraDistance();
    // default 10
    float& GetMinCameraDistance();

    // Not 100% sure what this is called
    InputHandler& GetInputHandler();

    // I haven't reverse-engineered this function, it probably does more than just load mods
    // but we hook it for sync'ing with the mod loader
    // (this function sets up GameWorld::loadedMods)
    void* GetModLoadFunction();

    // Static var separate to GameWorld
    int& GetNumAttackSlots();

    void* GetSoundEngineGetIDFromString();
    void* GetSoundEngineGetIDFromString2();
    void* GetSoundEngineLoadBank();
    void* GetSoundEngineSetState();
    void* GetSoundEngineSetSwitch();
    void* GetSoundEnginePostEvent();
    void* GetSoundEngineRegisterGameObj();

}