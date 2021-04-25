#pragma once

#include <string>
#include <mygui/MyGUI_Widget.h>


namespace KenshiLib
{
	using WidgetCallbackHandle = void*;
	using OnWidgetCallback = MyGUI::Widget* (MyGUI::WidgetManager* mgr, MyGUI::Widget* widget, const std::string& _name, const std::string& _type, const std::string& _skin, MyGUI::Widget* _parent);

	WidgetCallbackHandle RegisterPreWidgetCallback(const std::string& _name, const std::string& _type, OnWidgetCallback* callback);
	WidgetCallbackHandle RegisterWidgetCallback(const std::string& _name, const std::string& _type, OnWidgetCallback* callback);

}