#pragma once

#include <string>

uintptr_t FindPatternMask(const char* byteMask, const char* checkMask, uintptr_t address, size_t len, int instance);
void GetModuleCodeRegion(const char* moduleName, uintptr_t* o_base, size_t* o_size);
uintptr_t FindPattern(const std::string& pattern, const char* moduleName, int instance);
uintptr_t FindPattern(const std::string& pattern, uintptr_t address, size_t len, int instance);
uintptr_t FollowRelativeAddress(uintptr_t adr, int trail);