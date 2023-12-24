#include <kenshi/Kenshi.h>

#include <kenshi/GameWorld.h>
#include <kenshi/PlayerInterface.h>

#include <core/RVA.h>

#include <core/md5.h>

/**
 * Kenshi.cpp
 * 
 * This file will house the majority if not all memory-related actions to act as one centralized file that needs to be updated for new versions as they come out.
 * 
 */

std::string GetEXEHash()
{
    WCHAR path[MAX_PATH];
    GetModuleFileNameW(NULL, path, MAX_PATH);
    std::ifstream file(std::wstring(path), std::ios::ate | std::ios::binary);
    if (file.is_open())
    {
        size_t size = file.tellg();
        std::vector<char> fileBytes(size);
        file.seekg(0);
        file.read(&fileBytes[0], fileBytes.size());
        md5::md5_t hasher(&fileBytes[0], fileBytes.size());
        char hashStr[33];
        hasher.get_string(hashStr);
        return std::string(hashStr);
    }
    return "ERROR";
}

// nicer static initialization in C++03
template<typename T1, typename T2>
class StaticMap : public std::map<T1, T2>
{
public:
    StaticMap()
        : std::map<T1, T2>()
    {

    }
    StaticMap& Add(T1 key, T2 value)
    {
        this->insert(std::make_pair(key, value));
        return *this;
    }
};

StaticMap<std::string, Kenshi::BinaryVersion> HashToVersionMap = StaticMap<std::string, Kenshi::BinaryVersion>()
    .Add("83ea507cf9667bfe8de2d8a64e9ea57a", Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"))
    .Add("631763f867f8a674fc54a78cd5767235", Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"))
    .Add("c74140b9ac13995500cd1413b8cc0ba2", Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"))
    .Add("1d67d862b4ce17c5b54279790fbe8f8a", Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"));

// Game world address Steam 1.51.1 0x001AAE060
// Game world address GOG 1.51.1 0x001AADFB0
StaticMap<Kenshi::BinaryVersion, offset_t> GameWorldOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC9510)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x01ACA520)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC8460)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x01AC9470);

StaticMap<Kenshi::BinaryVersion, offset_t> NumAttackSlotsOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC92D8)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x01ACA2E8)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC8228)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x01AC9238);

StaticMap<Kenshi::BinaryVersion, offset_t> MaxFactionSizeOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC9350)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x01ACA360)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC82A0)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x01AC92B0);

StaticMap<Kenshi::BinaryVersion, offset_t> MaxSquadSizeOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC9348)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x01ACA358)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC8298)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x01AC92A8);

StaticMap<Kenshi::BinaryVersion, offset_t> MaxSquadsOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC934C)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x01ACA35C)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC829C)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x01AC92AC);

// Search for 2000.000f in non-writable and one of th ose will be the correct value
StaticMap<Kenshi::BinaryVersion, offset_t> MaxCameraDistanceOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x011F4E18)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x011F5D88)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x011F4B68)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x011F5AD8);

StaticMap<Kenshi::BinaryVersion, offset_t> MinCameraDistanceOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01188734)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x01189734)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01188704)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x01189704);

// easiest way to track this down is to find the vtable for: 
// Ogre::STLAllocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,InputHandler::Command>,Ogre::CategorisedAllocPolicy<0> >
// which is at offset 0x20
StaticMap<Kenshi::BinaryVersion, offset_t> InputHandlerOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC8950)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x01AC9960)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC78A0)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x01AC88B0);

// SaveManager**
// No vmt, find this by breakpointing SaveManager::saveGame() and backtrack from RCX
StaticMap<Kenshi::BinaryVersion, offset_t> SaveManagerOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC4D98)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x01AC5D88)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC3CE8)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x01AC4CD8);

// SaveFileSystem**
// easiest way to track this down is to find the vtable and backtrack
StaticMap<Kenshi::BinaryVersion, offset_t> SaveFileSystemOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC4DD8)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x01AC5DC8)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC3D28)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x01AC4D18);

StaticMap<Kenshi::BinaryVersion, offset_t> SaveManagerSaveGameFunction = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x002B5D30)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x002B5D90)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x002B5830)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x02B5890);

StaticMap<Kenshi::BinaryVersion, offset_t> ModLoadFunction = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x006BEF60)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x006BFFA0)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x006BE8E0)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x06BF910);

StaticMap<Kenshi::BinaryVersion, offset_t> CrashReportFunction = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x005CB0D0)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x005CC110)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x005CABD0)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x05CBC10);

// TODO remove after dropping support for old versions
StaticMap<Kenshi::BinaryVersion, offset_t> CurrentFontSizeOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x001AC8AF8)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x001AC7A48);

StaticMap<Kenshi::BinaryVersion, offset_t> UpdateFontsFunction = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x00311870)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x00311370);

std::string kenshiHash = GetEXEHash();
Kenshi::BinaryVersion kenshiVersion = HashToVersionMap.count(kenshiHash) > 0 ? HashToVersionMap.at(kenshiHash) : Kenshi::BinaryVersion(Kenshi::BinaryVersion::UNKNOWN, "UNKNOWN");

Kenshi::BinaryVersion Kenshi::GetKenshiVersion()
{
    return kenshiVersion;
}

void* Kenshi::GetModLoadFunction()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t modLoadFunction = ModLoadFunction.at(kenshiVersion);
    static RVAPtr<void> c_inst(modLoadFunction);
    return c_inst.GetPtr();
}

void* Kenshi::GetCrashReporterFunction()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t crashReportFunction = CrashReportFunction.at(kenshiVersion);
    static RVAPtr<void> c_inst(crashReportFunction);
    return c_inst.GetPtr();
}

// On 1.0.55 + 1.0.59 Kenshi doesn't initailize MyGUI with this properly
// TODO remove after dropping support for old versions
float& Kenshi::GetCurrentFontSize()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t currentFontSizeOffset = CurrentFontSizeOffset.at(kenshiVersion);
    static RVAPtr<float> c_inst(currentFontSizeOffset);
    return *c_inst.GetPtr();
}

// this takes args, but it doesn't access them, so we can pretend it's a void(void)
// It appears it has to be called *after* the UI is created
void* Kenshi::GetUpdateFonts()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t currentFontSizeOffset = UpdateFontsFunction.at(kenshiVersion);
    static RVAPtr<float> c_inst(currentFontSizeOffset);
    return c_inst.GetPtr();
}

Kenshi::GameWorld& Kenshi::GetGameWorld()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t gameWorldOffset = GameWorldOffset.at(kenshiVersion);
    static RVAPtr<GameWorld> c_inst(gameWorldOffset);
    return *c_inst.GetPtr();
}

int& Kenshi::GetNumAttackSlots()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t attackSlotsOffset = NumAttackSlotsOffset.at(kenshiVersion);
    static RVAPtr<int> c_inst(attackSlotsOffset);
    return *c_inst.GetPtr();
}

int& Kenshi::GetMaxFactionSize()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t attackSlotsOffset = MaxFactionSizeOffset.at(kenshiVersion);
    static RVAPtr<int> c_inst(attackSlotsOffset);
    return *c_inst.GetPtr();
}

int& Kenshi::GetMaxSquadSize()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t attackSlotsOffset = MaxSquadSizeOffset.at(kenshiVersion);
    static RVAPtr<int> c_inst(attackSlotsOffset);
    return *c_inst.GetPtr();
}

int& Kenshi::GetMaxSquads()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t attackSlotsOffset = MaxSquadsOffset.at(kenshiVersion);
    static RVAPtr<int> c_inst(attackSlotsOffset);
    return *c_inst.GetPtr();
}

float& Kenshi::GetMaxCameraDistance()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t maxCameraDistanceOffset = MaxCameraDistanceOffset.at(kenshiVersion);
    static RVAPtr<float> c_inst(maxCameraDistanceOffset);
    return *c_inst.GetPtr();
}

float& Kenshi::GetMinCameraDistance()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t minCameraDistanceOffset = MinCameraDistanceOffset.at(kenshiVersion);
    static RVAPtr<float> c_inst(minCameraDistanceOffset);
    return *c_inst.GetPtr();
}

Kenshi::InputHandler& Kenshi::GetInputHandler()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t inputHandlerOffset = InputHandlerOffset.at(kenshiVersion);
    static RVAPtr<InputHandler> c_inst(inputHandlerOffset);
    return *c_inst.GetPtr();
}

Kenshi::SaveManager* Kenshi::GetSaveManager()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t saveManagerPtrOffset = SaveManagerOffset.at(kenshiVersion);
    static RVAPtr<SaveManager*> c_inst(saveManagerPtrOffset);
    return *c_inst.GetPtr();
}

Kenshi::SaveFileSystem* Kenshi::GetSaveFileSystem()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t saveFileSystemPtrOffset = SaveFileSystemOffset.at(kenshiVersion);
    static RVAPtr<SaveFileSystem*> c_inst(saveFileSystemPtrOffset);
    return *c_inst.GetPtr();
}

Kenshi::SaveGameFunc* Kenshi::GetSaveManagerSaveGameFunction()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t saveManagerSaveGameFunction = SaveManagerSaveGameFunction.at(kenshiVersion);
    static RVAPtr<SaveGameFunc> c_inst(saveManagerSaveGameFunction);
    return c_inst.GetPtr();
}

// TODO templateize
// Kenshi prefixes it's widgets with a bunch of non-usefull stuff
MyGUI::WidgetPtr Kenshi::FindWidget(MyGUI::EnumeratorWidgetPtr enumerator, std::string name)
{
    while (enumerator.next())
    {
        std::string widgetName = enumerator.current()->getName();
        size_t splitPos = widgetName.find('_');

        if (splitPos != std::string::npos && widgetName.substr(splitPos + 1) == name)
            return enumerator.current();
        if (enumerator.current()->getChildCount() > 0)
        {
            MyGUI::WidgetPtr childFoundWidget = Kenshi::FindWidget(enumerator.current()->getEnumerator(), name);
            if (childFoundWidget != nullptr)
                return childFoundWidget;
        }
    }
    return nullptr;
}

#if 0
Kenshi::PlayerInterface& Kenshi::GetPlayerInterface()
{
   return *Kenshi::GetGameWorld().player_interface;
}
#endif