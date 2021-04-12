#include <core/RVA.h>

#include <cassert>
#include <core/Scanner.h>
#include <stdexcept>

static size_t GetRegionSize(uintptr_t base)
{
    MEMORY_BASIC_INFORMATION mbi;
    assert(VirtualQuery((LPCVOID)base, &mbi, sizeof(mbi)));
    return static_cast<size_t>(mbi.RegionSize);
}
uintptr_t RVACore::c_base = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
size_t RVACore::c_size = GetRegionSize(RVACore::c_base + 0x1000);


RVACore::RVACore(offset_t rva) : m_addr(c_base + rva) {}

RVACore::RVACore(
    const std::string& pattern, 
    uintptr_t(*onFound)(uintptr_t),
    const char* moduleName
)
{
    uintptr_t base; size_t size;
    if (!moduleName) {
        base = c_base;
        size = c_size;
    }
    else GetModuleCodeRegion(moduleName, &base, &size);

    auto addr = FindPattern(pattern, base, size, 0);
    if (!addr)
        throw new std::runtime_error("Pattern Scan failed to find signature \"" + pattern + "\".");

    m_addr = onFound(addr);
}


uintptr_t ProtectedDeref(uintptr_t addr)
// Just here for placeholder, will probably use this in the future so fitting it now.
{
    return *(uintptr_t*)addr;
}

uintptr_t ProtectedDerefRel(uintptr_t addr)
// Just here for placeholder, will probably use this in the future so fitting it now.
{
    return (uintptr_t)addr + *(uintptr_t*)(addr + 1) + 5;
}