#include <stdafx.h>
#include <MyGUIHooks.h>
#include <vector>
#include <winternl.h>
#include <ogre/OgreString.h>


using createWidgetT_t = MyGUI::Widget* (MyGUI::Widget* thisptr, const std::string& _type, const std::string& _skin, const MyGUI::IntCoord& _coord, MyGUI::Align _align, const std::string& _name);

/** See Widget::createWidgetT(const std::string& _type, const std::string& _skin, const IntCoord& _coord, Align _align, const std::string& _name = "") */
using createWidgetT2_t = MyGUI::Widget* (MyGUI::Widget* thisptr, const std::string& _type, const std::string& _skin, int _left, int _top, int _width, int _height, MyGUI::Align _align, const std::string& _name);

/** Create widget using coordinates relative to parent. see Widget::createWidgetT(const std::string& _type, const std::string& _skin, const IntCoord& _coord, Align _align, const std::string& _name = "") */
using createWidgetRealT_t = MyGUI::Widget* (MyGUI::Widget* thisptr, const std::string& _type, const std::string& _skin, const MyGUI::FloatCoord& _coord, MyGUI::Align _align, const std::string& _name);

/** Create widget using coordinates relative to parent. see Widget::createWidgetT(const std::string& _type, const std::string& _skin, const IntCoord& _coord, Align _align, const std::string& _name = "") */
using createWidgetRealT2_t = MyGUI::Widget* (MyGUI::Widget* thisptr, const std::string& _type, const std::string& _skin, float _left, float _top, float _width, float _height, MyGUI::Align _align, const std::string& _name);

using createWidgetTStyled_t = MyGUI::Widget* (MyGUI::Widget* thisptr, MyGUI::WidgetStyle _style, const std::string& _type, const std::string& _skin, const MyGUI::IntCoord& _coord, MyGUI::Align _align, const std::string& _layer, const std::string& _name);


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

	createWidgetT_t* createWidgetT_original;
	createWidgetT2_t* createWidgetT2_original;
	createWidgetRealT_t* createWidgetRealT_original;
	createWidgetRealT2_t* createWidgetRealT2_original;
	createWidgetTStyled_t* createWidgetTStyled_original;
	bool initialized = false;

	MyGUI::Widget* createWidgetT_hook(MyGUI::Widget* thisptr, const std::string& _type, const std::string& _skin, const MyGUI::IntCoord& _coord, MyGUI::Align _align, const std::string& _name)
	{
		printf("createWidgetT_hook(name=%s,type=%s)\n", _name.c_str(), _type.c_str());
		MyGUI::Widget* w = createWidgetT_original(thisptr, _type, _skin, _coord, _align, _name);
		for (auto& cb : callbacks) {
			if (cb.name == _name || cb.type == _type) {
				w = cb.callback(w, _name, _type, _skin);
			}
		}
		return w;
	}

	/** See Widget::createWidgetT(const std::string& _type, const std::string& _skin, const IntCoord& _coord, Align _align, const std::string& _name = "") */
	MyGUI::Widget* createWidgetT2_hook(MyGUI::Widget* thisptr, const std::string& _type, const std::string& _skin, int _left, int _top, int _width, int _height, MyGUI::Align _align, const std::string& _name)
	{
		printf("createWidgetT2_hook(name=%s,type=%s)\n", _name.c_str(), _type.c_str());
		MyGUI::Widget* w = createWidgetT2_original(thisptr, _type, _skin, _left, _top, _width, _height, _align, _name);
		for (auto& cb : callbacks) {
			if (cb.name == _name || cb.type == _type) {
				w = cb.callback(w, _name, _type, _skin);
			}
		}
		return w;
	}

	/** Create widget using coordinates relative to parent. see Widget::createWidgetT(const std::string& _type, const std::string& _skin, const IntCoord& _coord, Align _align, const std::string& _name = "") */
	MyGUI::Widget* createWidgetRealT_hook(MyGUI::Widget* thisptr, const std::string& _type, const std::string& _skin, const MyGUI::FloatCoord& _coord, MyGUI::Align _align, const std::string& _name)
	{
		printf("createWidgetRealT_hook(name=%s,type=%s)\n", _name.c_str(), _type.c_str());
		MyGUI::Widget* w = createWidgetRealT_original(thisptr, _type, _skin, _coord, _align, _name);
		for (auto& cb : callbacks) {
			if (cb.name == _name || cb.type == _type) {
				w = cb.callback(w, _name, _type, _skin);
			}
		}
		return w;
	}

	/** Create widget using coordinates relative to parent. see Widget::createWidgetT(const std::string& _type, const std::string& _skin, const IntCoord& _coord, Align _align, const std::string& _name = "") */
	MyGUI::Widget* createWidgetRealT2_hook(MyGUI::Widget* thisptr, const std::string& _type, const std::string& _skin, float _left, float _top, float _width, float _height, MyGUI::Align _align, const std::string& _name)
	{
		printf("createWidgetRealT2_hook(name=%s,type=%s)\n", _name.c_str(), _type.c_str());
		MyGUI::Widget* w = createWidgetRealT2_original(thisptr, _type, _skin, _left, _top, _width, _height, _align, _name);
		for (auto& cb : callbacks) {
			if (cb.name == _name || cb.type == _type) {
				w = cb.callback(w, _name, _type, _skin);
			}
		}
		return w;
	}

	/** Create widget using coordinates relative to parent. see Widget::createWidgetT(const std::string& _type, const std::string& _skin, const IntCoord& _coord, Align _align, const std::string& _name = "") */
	MyGUI::Widget* createWidgetTStyled_hook(MyGUI::Widget* thisptr, MyGUI::WidgetStyle _style, const std::string& _type, const std::string& _skin, const MyGUI::IntCoord& _coord, MyGUI::Align _align, const std::string& _layer, const std::string& _name)
	{
		printf("createWidgetTStyled_hook(name=%s,type=%s)\n", _name.c_str(), _type.c_str());
		MyGUI::Widget* w = createWidgetTStyled_original(thisptr, _style, _type, _skin, _coord, _align, _layer, _name);
		for (auto& cb : callbacks) {
			if (cb.name == _name || cb.type == _type) {
				w = cb.callback(w, _name, _type, _skin);
			}
		}
		return w;
	}

	MyGUI::Widget* createWidget(MyGUI::WidgetManager* thisptr, MyGUI::WidgetStyle _style, const std::string& _type, const std::string& _skin, const MyGUI::IntCoord& _coord, MyGUI::Widget* _parent, MyGUI::ICroppedRectangle* _cropeedParent, const std::string& _name)
	{

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


	void Initialize()
	{

		/*HookIAT(NULL, "?createWidgetT@Widget@MyGUI@@QEAAPEAV12@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0AEBU?$TCoord@H@types@2@UAlign@2@0@Z", createWidgetT_hook, (void**)&createWidgetT_original);
		HookIAT(NULL, "?createWidgetT@Widget@MyGUI@@QEAAPEAV12@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0HHHHUAlign@2@0@Z", createWidgetT2_hook, (void**)&createWidgetT2_original);
		HookIAT(NULL, "?createWidgetRealT@Gui@MyGUI@@QEAAPEAVWidget@2@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0AEBU?$TCoord@M@types@2@UAlign@2@00@Z", createWidgetRealT_hook, (void**)&createWidgetRealT_original);
		HookIAT(NULL, "?createWidgetRealT@Gui@MyGUI@@QEAAPEAVWidget@2@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0MMMMUAlign@2@00@Z", createWidgetRealT2_hook, (void**)&createWidgetRealT2_original);
		HookIAT(NULL, "?createWidgetT@Widget@MyGUI@@QEAAPEAV12@UWidgetStyle@2@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1AEBU?$TCoord@H@types@2@UAlign@2@11@Z", createWidgetTStyled_hook, (void**)&createWidgetTStyled_original);*/
		HookIAT(NULL,"?createWidget@WidgetManager@MyGUI@@QEAAPEAVWidget@2@UWidgetStyle@2@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1AEBU?$TCoord@H@types@2@PEAV32@PEAVICroppedRectangle@2@1@Z",)
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