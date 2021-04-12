/*
 * This source file is part of MyGUI. For the latest info, see http://mygui.info/
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#ifndef MYGUI_SINGLETON_H_
#define MYGUI_SINGLETON_H_

#include "MyGUI_Diagnostic.h"

namespace MyGUI
{

#if MYGUI_COMPILER == MYGUI_COMPILER_MSVC || MYGUI_PLATFORM == MYGUI_PLATFORM_APPLE
	template <class T>
	class Singleton
#else
	template <class T>
	class MYGUI_EXPORT Singleton
#endif
	{
	public:
		typedef Singleton<T> Base;

		Singleton();

		virtual ~Singleton();

		static T& getInstance();
		static T* getInstancePtr();
		static const char* getClassTypeName();

	private:
		static T* msInstance;
		static const char* mClassTypeName;
	};

} // namespace MyGUI

#endif // MYGUI_SINGLETON_H_
