#include <stdafx.h>

#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cassert>

// Shamelessly stolen from https://github.com/rafzi/hacklib due to laziness

static bool MatchMaskedPattern(uintptr_t address, const char* byteMask, const char* checkMask)
{
    for (; *checkMask; ++checkMask, ++address, ++byteMask)
        if (*checkMask == 'x' && *(char*)address != *byteMask)
            return false;
    return *checkMask == 0;
}


uintptr_t FindPatternMask(const char* byteMask, const char* checkMask, uintptr_t address, size_t len, int instance)
{
    uintptr_t end = address + len - strlen(checkMask) + 1;
    for (uintptr_t i = address; i < end; i++)
    {
        if (MatchMaskedPattern(i, byteMask, checkMask))
        {
            if (!instance--)
                return i;
        }
    }
    return 0;
}

void GetModuleCodeRegion(const char* moduleName, uintptr_t* o_base, size_t* o_size)
{
    uintptr_t base = (uintptr_t)GetModuleHandleA(moduleName) + 0x1000;

    MEMORY_BASIC_INFORMATION mbi;
    assert(VirtualQuery((LPCVOID)base, &mbi,sizeof(mbi)));

    *o_base = base;
    *o_size = mbi.RegionSize;
}

uintptr_t FindPattern(const std::string& pattern, uintptr_t address, size_t len, int instance)
{
    std::vector<char> byteMask;
    std::vector<char> checkMask;

    std::string lowPattern = pattern;
    std::transform(lowPattern.begin(), lowPattern.end(), lowPattern.begin(), ::tolower);
    lowPattern += " ";

    for (size_t i = 0; i < lowPattern.size() / 3; i++)
    {
        if (lowPattern[3 * i + 2] == ' ' && lowPattern[3 * i] == '?')
        {
            byteMask.push_back(0);
            checkMask.push_back('?');
        }
        else if (lowPattern[3 * i + 2] == ' ' &&
                 ((lowPattern[3 * i] >= '0' && lowPattern[3 * i] <= '9') ||
                  (lowPattern[3 * i] >= 'a' && lowPattern[3 * i] <= 'f')) &&
                 ((lowPattern[3 * i + 1] >= '0' && lowPattern[3 * i + 1] <= '9') ||
                  (lowPattern[3 * i + 1] >= 'a' && lowPattern[3 * i + 1] <= 'f')))

        {
            auto value = strtol(lowPattern.data() + 3 * i, nullptr, 16);
            byteMask.push_back((char)value);
            checkMask.push_back('x');
        }
        else
        {
            throw std::runtime_error("invalid format of pattern string");
        }
    }

    // Terminate mask string, because it is used to determine length.
    checkMask.push_back('\0');

    return FindPatternMask(byteMask.data(), checkMask.data(), address, len, instance);
}

uintptr_t FindPattern(const std::string& pattern, const char* moduleName, int instance)
{
    uintptr_t result = 0;

    uintptr_t base;
    size_t size;
    GetModuleCodeRegion(moduleName, &base, &size);

    result = FindPattern(pattern, base, size, instance);
    return result;
}


uintptr_t FollowRelativeAddress(uintptr_t adr, int trail)
{
    // Hardcoded 32-bit dereference to make it work with 64-bit code.
    return *(int32_t*)adr + adr + 4 + trail;
}


