#define LEAN_AND_MEAN
#include <windows.h>
#include <string>
#include "util/lektor.h"

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
};