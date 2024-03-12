#pragma once

#include <string>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <kenshi/util/lektor.h>

struct SaveInfo;
class LoadGameMenu;
class SaveGameMenu;
class ImportGameMenu;

class SaveManager : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    enum Flags
    {
        RESET_POSITION = 0x1,
        IMPORT_SQUAD = 0x2,
        IMPORT_BUILDINGS = 0x4,
        IMPORT_RESEARCH = 0x8,
        IMPORT_NPC_STATES = 0x10,
        IMPORT_RELATIONS = 0x20    
    };

    static SaveManager * getSingleton();// public RVA = 0x37D7E0
    int isVisible();// public RVA = 0x47A230
    void showSave();// public RVA = 0x481CE0
    void showLoad();// public RVA = 0x481D40
    void showImport();// public RVA = 0x481DA0
    void hide();// public RVA = 0x47A270
    void newGame(const std::string & startId);// public RVA = 0x47AA20
    void save(const std::string & s, bool autosave);// public RVA = 0x47B1A0
    void load(const SaveInfo & s, bool resetPos);// public RVA = 0x47AA90
    void load(const std::string & name);// public RVA = 0x47AD00
    void import(const SaveInfo & s, int _flags);// public RVA = 0x47AB70
    bool savesExist();// public RVA = 0x36B160
    bool saveExists(const std::string & location, const std::string & name);// public RVA = 0x36C0D0
    int scanGames(lektor<SaveInfo> & list, bool loadDetails);// public RVA = 0x47F520
    int scanGames(const std::string & location, lektor<SaveInfo> & list, bool loadDetails);// public RVA = 0x47ED20
    bool loadInfo(SaveInfo & info);// public RVA = 0x47DC10
    bool checkVersion(const SaveInfo & info);// public RVA = 0x47CA90
    void execute();// public RVA = 0x47BB90
    const std::string & getCurrentGame();// public RVA = 0x47A7D0
    unsigned int versionCode(const std::string & version);// public RVA = 0x47A570
    void updateAutoSave();// public RVA = 0x47B6F0
    const std::string & getSavePath() const;// public RVA = 0x47A210
    void initialisePaths();// public RVA = 0x47AEC0
    enum Signal
    {
        SAVEGAME = 0x1,
        LOADGAME = 0x2,
        IMPORTGAME = 0x3,
        NEWGAME = 0x4    
    };

    // no_addr void SaveManager(const class SaveManager & _a1);// public missing arg names
    SaveManager();// private RVA = 0x47A5E0
    void _CONSTRUCTOR();// private RVA = 0x47A5E0
    ~SaveManager();// private RVA = 0x47A6A0
    void _DESTRUCTOR();// private RVA = 0x47A6A0
    int saveGame(const std::string & location, const std::string & name);// private RVA = 0x374E40
    int loadGame(const std::string & location, const std::string & name);// private RVA = 0x3739E0
    int importGame(const std::string & location, const std::string & name, int flags);// private RVA = 0x378510
    int importPlayerBuildings(const std::string & path, const std::string & file);// private RVA = 0x3771F0
    int importOldPlayerBuildings(const std::string & path, const std::string & name);// private RVA = 0x3777F0
    // no_addr bool verifyZoneFiles();// private
    std::string currentGame; // 0x0 Member
    std::string saveVersion; // 0x28 Member
    std::string localSavePath; // 0x50 Member
    std::string userSavePath; // 0x78 Member
    int signal; // 0xA0 Member
    int flags; // 0xA4 Member
    int delay; // 0xA8 Member
    std::string name; // 0xB0 Member
    std::string location; // 0xD8 Member
    LoadGameMenu * loadMenu; // 0x100 Member
    SaveGameMenu * saveMenu; // 0x108 Member
    ImportGameMenu * importMenu; // 0x110 Member
    float autoSaveTimer; // 0x118 Member
    bool pauseAutoSaveTimer; // 0x11C Member
    // no_addr class SaveManager & operator=(const class SaveManager & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// private missing arg names
};
