#pragma once

#include <stdafx.h>

#include <kenshi/util/lektor.h>

namespace Kenshi
{
    struct PlayerInterface
    {
        // FactoryCallbackInterface
        virtual ~PlayerInterface();
	    
        std::string faction; //0x0008
        char pad_0028[8]; //0x0028
        class N00000F7A *N000000E5; //0x0030
        class ResearchManager *research; //0x0038
        char pad_0040[16]; //0x0040
        class lektor<int> N000000EC; //0x0050 int
        char pad_0068[584]; //0x0068
        class lektor<Character*> controlledCharacters; //0x02B0 Character*
        char pad_02C8[104]; //0x02C8
	
    };
}
