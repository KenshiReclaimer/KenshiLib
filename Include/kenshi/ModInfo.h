#pragma once

#include <stdafx.h>
#include <kenshi/util/lektor.h>

namespace Kenshi
{
    struct ModInfo
    {
        std::string modName; // 0x00
        void* pad1;
        std::string filePath; // 0x28 // full path with filename
        void* pad2;
        std::string fileDir; // 0x50 // full path without filename
        void* pad3;
        long idk; // is 256
        std::string assetPath; // 0x80 // path within the mod file? looks like an "extraction path" for the game to use  
        void* pad4;
        std::string displayName; // 0xA8
        void* pad5;
        std::string author; // 0xD0
        void* pad6;
        std::string description; // 0x100
        void* pad7;
        // below is assumed from FCS GameData.Header.cs
        lektor<std::string> dependencies;
        lektor<std::string> referenced;
    };
}

