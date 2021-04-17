#include <stdafx.h>
#include <MyGUIHooks.h>
#include <vector>
#include <winternl.h>
#include <ogre/OgreString.h>
#include <psapi.h>
#include <mygui/MyGUI_WidgetManager.h>

namespace
{
	struct CallbackData
	{
		std::string name; 
		std::string type;
		KenshiLib::OnWidgetCallback* callback;

		CallbackData(std::string _name,
		std::string _type,
		KenshiLib::OnWidgetCallback* _callback)
			: name(_name), type(_type), callback(_callback)
		{}
	};

	std::vector<CallbackData> callbacks;

	bool initialized = false;

	using createWidget_t = MyGUI::Widget* (MyGUI::WidgetManager* thisptr, MyGUI::WidgetStyle _style, const std::string& _type, const std::string& _skin, const MyGUI::IntCoord& _coord, MyGUI::Widget* _parent, MyGUI::ICroppedRectangle* _cropeedParent, const std::string& _name);
	createWidget_t* createWidget_original;

	MyGUI::Widget* createWidget_hook(MyGUI::WidgetManager* thisptr, MyGUI::WidgetStyle _style, const std::string& _type, const std::string& _skin, const MyGUI::IntCoord& _coord, MyGUI::Widget* _parent, MyGUI::ICroppedRectangle* _croppedParent, const std::string& _name)
	{
		printf("createWidget_hook(name=%s,type=%s)\n", _name.c_str(), _type.c_str());
		MyGUI::Widget* w = createWidget_original(thisptr, _style, _type, _skin, _coord, _parent, _croppedParent, _name);
		for (auto& cb : callbacks) {
			if (cb.name == _name || cb.type == _type) {
				w = cb.callback(w, _name, _type, _skin, _parent);
			}
		}
		return w;
	}


	bool HookIAT(const char* module_name, const char* symbol_name, void* hook, void** original)
	{
		LPVOID imageBase = GetModuleHandleA(module_name);
		PIMAGE_DOS_HEADER dosHeaders = (PIMAGE_DOS_HEADER)imageBase;
		PIMAGE_NT_HEADERS ntHeaders = (PIMAGE_NT_HEADERS)((DWORD_PTR)imageBase + dosHeaders->e_lfanew);
		PIMAGE_IMPORT_DESCRIPTOR importDescriptor = NULL;
		IMAGE_DATA_DIRECTORY importsDirectory = ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
		importDescriptor = (PIMAGE_IMPORT_DESCRIPTOR)(importsDirectory.VirtualAddress + (DWORD_PTR)imageBase);
		LPCSTR libraryName = NULL;
		HMODULE library = NULL;
		PIMAGE_IMPORT_BY_NAME functionName = NULL;

		while (importDescriptor->Name != NULL)
		{
			libraryName = (LPCSTR)importDescriptor->Name + (DWORD_PTR)imageBase;
			library = LoadLibraryA(libraryName);

			if (library)
			{
				PIMAGE_THUNK_DATA originalFirstThunk = NULL, firstThunk = NULL;
				originalFirstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)imageBase + importDescriptor->OriginalFirstThunk);
				firstThunk = (PIMAGE_THUNK_DATA)((DWORD_PTR)imageBase + importDescriptor->FirstThunk);

				while (originalFirstThunk->u1.AddressOfData != NULL)
				{
					functionName = (PIMAGE_IMPORT_BY_NAME)((DWORD_PTR)imageBase + originalFirstThunk->u1.AddressOfData);

					MEMORY_BASIC_INFORMATION mbi;
					if (VirtualQuery(functionName, &mbi, sizeof(mbi))) {

						// find MessageBoxA address
						if (!strcmp(functionName->Name, symbol_name))
						{
							SIZE_T bytesWritten = 0;
							DWORD oldProtect = 0;
							VirtualProtect((LPVOID)(&firstThunk->u1.Function), 8, PAGE_READWRITE, &oldProtect);

							// swap MessageBoxA address with address of hookedMessageBox
							*original = (void*)firstThunk->u1.Function;
							firstThunk->u1.Function = (DWORD_PTR)hook;
							return true;
						}
					}

					++originalFirstThunk;
					++firstThunk;
				}
			}

			importDescriptor++;
		}
		return false;
	}


	struct TestHookManager
	{
		TestHookManager(const char* module_name)
		{
			BYTE *mod = (PBYTE)GetModuleHandleA(module_name), *seek = mod+1;

			while 

			

		}


		BYTE* bufstart;
		BYTE* bufseek;
	};

	template <class T>
	union fuck {
		T fuck;
		uintptr_t lol;
	};

	void Initialize()
	{
		fuck<decltype(&MyGUI::WidgetManager::createWidget)> t;
		t.fuck = &MyGUI::WidgetManager::createWidget;


		printf("lol test = %p\n", t.lol);
		HookIAT(NULL, "?createWidget@WidgetManager@MyGUI@@QEAAPEAVWidget@2@UWidgetStyle@2@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1AEBU?$TCoord@H@types@2@PEAV32@PEAVICroppedRectangle@2@1@Z", createWidget_hook, (void**)&createWidget_original);
		initialized = true;
	}

}


namespace KenshiLib
{
	WidgetCallbackHandle RegisterWidgetCallback(const std::string& _name, const std::string& _type, OnWidgetCallback* callback)
	{
		if (!initialized) Initialize();
		callbacks.push_back(CallbackData(_name, _type, callback));

		return nullptr;
	}
}