#pragma once

#include "util/lektor.h"
#include "Logger.h"

//#define LEAN_AND_MEAN
//#define NOMINMAX
//#include <windows.h>
#include <boost/thread/shared_mutex.hpp>
#include <boost/unordered_set.hpp>

#include <string>

/*
Top-level: SaveManager::saveGame() kenshi_GOG_x64.exe+2B5830
bool save1(SaveManager* thisptr, std::string savesDirectory, std::string save_name2)
kenshi_GOG_x64.exe + 0x3815f0
save2(SaveFileSystem * thisptr, std::string path)
Note: SaveFileSystem extends ThreadClass
ThreadClass.virtual_8 = thread function

Plan : call save1, then call WaitForSingleObject(saveFileSystem.threadHandle, INFINITE) to sync

*/

namespace MyGUI
{
	class ImageBox;
}

namespace Kenshi
{
	/*
	// Class name confirmed by RTTI
	class SaveFileSystem
	{
	public:
		virtual ~SaveFileSystem();
		// TODO return value?
		virtual void Run();

		HANDLE threadHandle; // 0x8
		char unk_0010[8]; // 0x10
		std::string unk_18; // 0x18 "Saving"
		// Note: it looks like there might be a boost::unordered<std::string, ???> around 0xA0
		char unk_0040[0xB0];// 0x40
		// TODO is this the right name? contains target save + save/current_1
		Kenshi::lektor<std::string> directoriesToSave;// 0xF0
		Kenshi::lektor<std::string> unk0108;// 0x108
		std::string targetSaveDirectory; // 0x120 appears to mirror directoriesToSave[0] - path to named save
		std::string currentSaveDirectory; // 0x148 appears to mirror directoriesToSave[1] - path to current_1 save
		std::string pathToSaves; // 0x170 path to directory containing saves
		char unk_0198[0x28]; // 0x198
		MyGUI::ImageBox* imageBox; // 0x1C0
		// 0x1C8 lektor<SaveFileSystem::FileMessage>
		// 0x1E0 looks like maybe an ofstream or something comes after here?
		// there's an std::basic_filebuf
	};

	// Class name confirmed by debug prints
	class SaveManager
	{
	public:
		// GOG 1.0.59 bool SaveManager::saveGame(SaveManager* thisptr, std::string savesDirectory, std::string saveName) @ kenshi_GOG_x64.exe+2B5830 - name confirmed by debug prints
		typedef bool SaveGameFunc(SaveManager* thisptr, std::string savesDirectory, std::string saveName);
		std::string saveName1; // 0x0
		std::string gameVersion; // 0x28 - not 100% sure what this is or is used for
		std::string installSaveDir; // 0x50 /save/ dir in Kenshi install dir
		std::string appDataSaveDir; // 0x78 /save/ dir in %appdata%
		char unk_00A0[0x10];// 0xA0
		std::string saveName2;// 0xB0
		std::string saveWriteDir; // 0xD8 /save/ directory new saves are saved to
		// 0x108 MyGUI SaveGameMenu
	};
	*/

    // TODO move?
    class ThreadClass
    {
    public:
        // VTable         : (none)
        void* threadHandle; // 0x8 Member
        unsigned int threadID; // 0x10 Member
        bool _running; // 0x14 Member
        std::string name; // 0x18 Member
        float frameTime; // 0x40 Member
        bool infiniteMode; // 0x44 Member
        bool pretendThread; // 0x45 Member
        boost::shared_mutex runMute; // 0x48 Member
        boost::shared_mutex lockedWhileRunningMute; // 0x68 Member
        void stopRunning();// RVA = 0x1D27B0
        bool canIRun();// RVA = 0x1D2A60
        bool startRunning(float);// RVA = 0x2EFE00
        bool isRunning();// RVA = 0x1CFEE0
        // no_addr public bool waitForRunningStop_SleepWhileWait();
        bool waitForRunningStop_Blocking();// RVA = 0x6043E0
        // no_addr public void ThreadClass(const class ThreadClass &);
        ThreadClass(const std::string&);// RVA = 0x1D24E0
        virtual ~ThreadClass();// RVA = 0x1D2880// vtable offset = 0x0
        void setup(float, bool, bool);// RVA = 0x6C4AE0
        bool beginThread(float, bool, int);// RVA = 0x2EFFC0
        void setThreadName(const char*);// RVA = 0x2E5D40
        void endThread();// RVA = 0x1D2800
        // no_addr public bool endThreadTry();
        void setName(const char*);// RVA = 0x2E5D90
        // no_addr public virtual unsigned long threadProc();// vtable offset = 0x8
        // no_addr public class ThreadClass & operator=(const class ThreadClass &);
        // no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };

    class SaveFileSystem : public ThreadClass
    {
        // ThreadClass offset = 0x0, length = 0x88
        static SaveFileSystem* getSingleton();// RVA = 0x2BACF0
        // no_addr public void SaveFileSystem(const class SaveFileSystem &);
        SaveFileSystem();// RVA = 0x381E60
        virtual ~SaveFileSystem();// RVA = 0x382320// vtable offset = 0x0
        void log(const std::string&, Logger::Severity);// RVA = 0x380D60
        void setTemporaryPath(const std::string&);// RVA = 0x380F20
        bool fileExists(const std::string&);// RVA = 0x380EA0
        std::string readFile(const std::string&);// RVA = 0x381050
        std::string writeFile(const std::string&);// RVA = 0x381D90
        void deleteFile(const std::string&);// RVA = 0x381880
        void newGame();// RVA = 0x381130
        void loadGame(const std::string&);// RVA = 0x384760
        bool saveGame(const std::string&);// RVA = 0x3837A0
        void sync();// RVA = 0x384330
        void analyse();// RVA = 0x383CB0
        void cleanup(bool);// RVA = 0x383700
        void scanForResidualTempFolders();// RVA = 0x381A60
        bool isTempFolder(const std::string&);// RVA = 0x381760
        const std::string& getActiveSave();// RVA = 0x388C00
        bool busy();// RVA = 0x2FFA60
        void createCurrent();// RVA = 0x381260
        virtual unsigned long threadProc();// RVA = 0x382B40// vtable offset = 0x0
        std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > fileSystem; // 0x88 Member
        boost::unordered::unordered_set<std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::string, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > deletedFiles; // 0xB0 Member
        lektor<std::string > paths; // 0xF0 Member
        lektor<std::string > oldCurrentFolders; // 0x108 Member
        std::string currentSave; // 0x120 Member
        std::string currentFolder; // 0x148 Member
        std::string tempFolder; // 0x170 Member
        int currentPathIndex; // 0x198 Member
        boost::shared_mutex currentMutex; // 0x1A0 Member
        MyGUI::ImageBox* savingIcon; // 0x1C0 Member
        enum MessageType
        {
            MSG_COPY = 0x0,
            MSG_COPY_REPLACE = 0x1,
            MSG_DELETE = 0x2
        };

        struct FileMessage
        {
            MessageType mode; // 0x0 Member
            std::string source; // 0x8 Member
            std::string dest; // 0x30 Member
            // no_addr public void FileMessage(const struct SaveFileSystem::FileMessage &);
            FileMessage();// RVA = 0x385A30
            ~FileMessage();// RVA = 0x385A60
            struct SaveFileSystem::FileMessage& operator=(const struct SaveFileSystem::FileMessage&);// RVA = 0x3868F0
            // no_addr public void * __vecDelDtor(unsigned int);
        };
        lektor<SaveFileSystem::FileMessage> messages; // 0x1C8 Member
        void addMessage(SaveFileSystem::MessageType, const std::string&, const std::string&);// RVA = 0x380F90
        enum State
        {
            NORMAL = 0x0,
            SAVING = 0x1,
            COMPLETE = 0x2
        };

        State state; // 0x1E0 Member
        std::string failedToCopyError; // 0x1E8 Member
        std::basic_ofstream<char, std::char_traits<char> > saveLog; // 0x210 Member
        // no_addr public class SaveFileSystem & operator=(const class SaveFileSystem &);
        // no_addr public void __local_vftable_ctor_closure();
        // no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };

    class LoadGameMenu;
    class SaveGameMenu;
    class ImportGameMenu;

    class SaveManager : Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
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

        static SaveManager* getSingleton();// RVA = 0x2BAB70
        int isVisible();// RVA = 0x388C30
        void showSave();// RVA = 0x3906E0
        void showLoad();// RVA = 0x390740
        void showImport();// RVA = 0x3907A0
        void hide();// RVA = 0x388C70
        void newGame(const std::string&);// RVA = 0x389420
        void save(const std::string&, bool);// RVA = 0x389BA0
        void load(const struct SaveInfo&, bool);// RVA = 0x389490
        void load(const std::string&);// RVA = 0x389700
        void import(const struct SaveInfo&, int);// RVA = 0x389570
        bool savesExist();// RVA = 0x2AC0B0
        bool saveExists(const std::string&, const std::string&);// RVA = 0x2AD020
        int scanGames(lektor<SaveInfo>&, bool);// RVA = 0x38DF20
        int scanGames(const std::string&, lektor<SaveInfo>&, bool);// RVA = 0x38D720
        bool loadInfo(struct SaveInfo&);// RVA = 0x38C610
        bool checkVersion(const struct SaveInfo&);// RVA = 0x38B490
        void execute();// RVA = 0x38A590
        const std::string& getCurrentGame();// RVA = 0x3891D0
        unsigned int versionCode(const std::string&);// RVA = 0x388F70
        void updateAutoSave();// RVA = 0x38A0F0
        const std::string& getSavePath();// RVA = 0x388C10
        void initialisePaths();// RVA = 0x3898C0
        enum Signal
        {
            SAVEGAME = 0x1,
            LOADGAME = 0x2,
            IMPORTGAME = 0x3,
            NEWGAME = 0x4
        };

        // no_addr public void SaveManager(const class SaveManager &);
        SaveManager();// RVA = 0x388FE0
        ~SaveManager();// RVA = 0x3890A0
        int saveGame(const std::string&, const std::string&);// RVA = 0x2B5D90
        int loadGame(const std::string&, const std::string&);// RVA = 0x2B4930
        int importGame(const std::string&, const std::string&, int);// RVA = 0x2B9460
        int importPlayerBuildings(const std::string&, const std::string&);// RVA = 0x2B8140
        int importOldPlayerBuildings(const std::string&, const std::string&);// RVA = 0x2B8740
        // no_addr private bool verifyZoneFiles();
        std::string currentGame; // 0x0 Member
        std::string saveVersion; // 0x28 Member
        std::string localSavePath; // 0x50 Member
        std::string userSavePath; // 0x78 Member
        int signal; // 0xA0 Member
        int flags; // 0xA4 Member
        int delay; // 0xA8 Member
        std::string name; // 0xB0 Member
        std::string location; // 0xD8 Member
        LoadGameMenu* loadMenu; // 0x100 Member
        SaveGameMenu* saveMenu; // 0x108 Member
        ImportGameMenu* importMenu; // 0x110 Member
        float autoSaveTimer; // 0x118 Member
        bool pauseAutoSaveTimer; // 0x11C Member
        // no_addr public class SaveManager & operator=(const class SaveManager &);
        // no_addr private void * __vecDelDtor(unsigned int);
    };
};