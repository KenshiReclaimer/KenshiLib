#pragma once
#include "mygui/MyGUI_Gui.h"


namespace Kenshi 
{


    class GameWorld;
    class PlayerInterface;
    class Character;
    class Building;
    class Renderer;
    class PhysicsActual;
    class ModInfo;
    class Character;
    class Building;
    class ZoneManager;
    class AudioSystemGlobal;
    class Alarm;
    class PlayerInterface;
    class ResearchManager;
    class ResearchItem;
    class InputHandler;
    class SaveManager;
    class SaveFileSystem;
    typedef bool SaveGameFunc(SaveManager* thisptr, std::string savesDirectory, std::string saveName);

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

        std::string GetBinaryName()
        {
            if (platform == KenshiPlatform::STEAM)
                return "Kenshi_x64.exe";
            if (platform == KenshiPlatform::GOG)
                return "Kenshi_GOG_x64.exe";
            return "Unknown";
        }

        std::string ToString()
        {
            return version + " " + GetPlatformStr();
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

        bool operator== (const BinaryVersion& b) const
        {
            return this->version == b.version && this->platform == b.platform;
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
    // This function creates the "Kenshi has crashed" window
    void* GetCrashReporterFunction();

    // On 1.0.55 + 1.0.59 Kenshi doesn't initailize MyGUI with this properly
    // TODO remove after dropping support for old versions
    float& GetCurrentFontSize();
    // this is an OptionsWindow member function - probably a MyGUI OnClick delegate or something
    // it takes arguments, but doesn't read them, so we can just pretend it's a void(void) function
    void* GetUpdateFonts();

    // Static var separate to GameWorld
    int& GetNumAttackSlots();
    int& GetMaxFactionSize();
    int& GetMaxSquadSize();
    int& GetMaxSquads();

    SaveManager* GetSaveManager();
    SaveGameFunc* GetSaveManagerSaveGameFunction();
    SaveFileSystem* GetSaveFileSystem();
}