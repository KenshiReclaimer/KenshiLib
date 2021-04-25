#include <stdafx.h>
#include <MyGUIHooks.h>
#include <vector>
#include <winternl.h>
#include <ogre/OgreString.h>
#include <psapi.h>
#include <mygui/MyGUI_WidgetManager.h>
#include <core/Hooker.h>
#include <mygui/MyGUI.h>

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
	std::vector<CallbackData> pre_callbacks;

	bool initialized = false;

	using createWidget_t = MyGUI::Widget* (MyGUI::WidgetManager* thisptr, MyGUI::WidgetStyle _style, const std::string& _type, const std::string& _skin, const MyGUI::IntCoord& _coord, MyGUI::Widget* _parent, MyGUI::ICroppedRectangle* _cropeedParent, const std::string& _name);
	createWidget_t* createWidget_original;


	class VersionBox : public MyGUI::TextBox {
	public:
		void setCaption(const MyGUI::UString& _value)
		{
			return MyGUI::TextBox::setCaption(_value + L"Reclaimed ALPHA v0.1.0");
		}

	};


	std::string versiontext;
	MyGUI::Widget* createWidget_hook(MyGUI::WidgetManager* thisptr, MyGUI::WidgetStyle _style, const std::string& _type, const std::string& _skin, const MyGUI::IntCoord& _coord, MyGUI::Widget* _parent, MyGUI::ICroppedRectangle* _croppedParent, const std::string& _name)
	{
		printf("createWidget_hook(name=%s,type=%s)\n", _name.c_str(), _type.c_str());

		auto name = _name;
		if (!name.compare(0, 9, "0,000,000")) {
			auto off = name.find_first_of('_');
			name = name.substr(off + 1);
			if (name == "VersionText") {
				versiontext = _name;
			}
			else if (name == "DefaultButton") {
				auto widget = MyGUI::Gui::getInstance().findWidget<MyGUI::TextBox>(versiontext);
				assert(widget);
				widget->setCaption(widget->getCaption() + L" - Reclaimed ALPHA v0.1.0");
			}
		}

		MyGUI::Widget* w = nullptr;
		for (auto& cb : pre_callbacks) {
			if (cb.name == name || cb.type == _type) {
				w = cb.callback(thisptr, w, name, _type, _skin, _parent);
			}
		}

		if (w == nullptr)
			w = createWidget_original(thisptr, _style, _type, _skin, _coord, _parent, _croppedParent, _name);

		for (auto& cb : callbacks) {
			if (cb.name == name || cb.type == _type) {
				w = cb.callback(thisptr, w, name, _type, _skin, _parent);
			}
		}
		return w;
	}


	void Initialize()
	{
		KenshiLib::g_mainHookManager = KenshiLib::HookManager(nullptr);
		createWidget_original = KenshiLib::g_mainHookManager.Getx86BranchOriginal<decltype(&MyGUI::WidgetManager::createWidget),decltype(createWidget_original)>(&MyGUI::WidgetManager::createWidget);
		KenshiLib::g_mainHookManager.WriteJump(&MyGUI::WidgetManager::createWidget, createWidget_hook);
		initialized = true;
	}

}


namespace KenshiLib
{
	WidgetCallbackHandle RegisterPreWidgetCallback(const std::string& _name, const std::string& _type, OnWidgetCallback* callback)
	{
		if (!initialized) Initialize();
		pre_callbacks.push_back(CallbackData(_name, _type, callback));
		return nullptr;

	}

	WidgetCallbackHandle RegisterWidgetCallback(const std::string& _name, const std::string& _type, OnWidgetCallback* callback)
	{
		if (!initialized) Initialize();
		callbacks.push_back(CallbackData(_name, _type, callback));

		return nullptr;
	}
}