#include <kenshi/Kenshi.h>

#include <kenshi/GameWorld.h>
#include <kenshi/PlayerInterface.h>

#include <core/RVA.h>
#include <cassert>

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
    .Add("3327eaf22ec3c9653e22b6d7bf351736", Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.59")) // 1.0.59 has the same offsets as 1.0.55
    .Add("488c2f2795212943c12283d3c67cf52f", Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.60"))
    .Add("c74140b9ac13995500cd1413b8cc0ba2", Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59")); // 1.0.59 has the same offsets as 1.0.55

// Game world address Steam 1.51.1 0x001AAE060
// Game world address GOG 1.51.1 0x001AADFB0
StaticMap<Kenshi::BinaryVersion, offset_t> GameWorldOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC9510)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.59"), 0x01AC9510)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.60"), 0x01ACB530)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x1AC8460);

StaticMap<Kenshi::BinaryVersion, offset_t> NumAttackSlotsOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC92D8)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.59"), 0x01AC92D8)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.60"), 0x01ACB2F8)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC8228);

StaticMap<Kenshi::BinaryVersion, offset_t> MaxFactionSizeOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC9350)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.59"), 0x01AC9350)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.60"), 0x01ACB370)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC82A0);

StaticMap<Kenshi::BinaryVersion, offset_t> MaxSquadSizeOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC9348)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.59"), 0x01AC9348)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.60"), 0x01ACB368)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC8298);

StaticMap<Kenshi::BinaryVersion, offset_t> MaxSquadsOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC934C)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.59"), 0x01AC934C)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.60"), 0x01ACB36C)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC829C);

StaticMap<Kenshi::BinaryVersion, offset_t> MaxCameraDistanceOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x011F4E18)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.59"), 0x011F4E18)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.60"), 0x011F6CC8)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x011F4B68);

StaticMap<Kenshi::BinaryVersion, offset_t> MinCameraDistanceOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01188734)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.59"), 0x01188734)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.60"), 0x0118A734)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01188704);

StaticMap<Kenshi::BinaryVersion, offset_t> InputHandlerOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC8950)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.59"), 0x01AC8950)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.60"), 0x01ACA970)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC78A0);

StaticMap<Kenshi::BinaryVersion, offset_t> ModLoadFunction = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x006BEF60)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.59"), 0x006BEF60)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.60"), 0x006C07F0)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x006BE8E0);

// TODO other versions
StaticMap<Kenshi::BinaryVersion, offset_t> CrashReportFunction = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x005cabd0);

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