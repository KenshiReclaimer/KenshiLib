#pragma once

#include <stdint.h>

namespace OIS
{
	class Win32Keyboard;
}

namespace Kenshi
{
	// Names are made up
	struct KeyEvent
	{
		char unk[8];
		uint32_t eventCode;
		char unk2[12];
		// Don't know how long this is
		char eventName[16];
	};
	struct KeyBind
	{
		KeyBind* ptr1;
		KeyBind* ptr2;
		KeyBind* ptr3;
		uint32_t keyCode;
		char unk1[4];
		KeyEvent* keyEvent;
		char unk2;
		bool isLeaf; // 0x29 TODO re-check what this does?

	};
	class InputHandler
	{
	public:
		char unk1[0x20];
		// Ogre::STLAllocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,InputHandler::Command>,Ogre::CategorisedAllocPolicy<0> >
		char unk1_2[0x10];
		KeyBind* keyBindingsStart;
		char unk2[0x68];
		// offset 0x50 in Win32Keyboard contains MainListener object, might be interesting?
		OIS::Win32Keyboard* keyboardInput; // 0xA0
	};
}