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
 * Kenshi v1.0.51
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
    .Add("a5f78908f3f26591a6a3717bfbfafbca", Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.51")) // RE_Kenshi 0.1 modified EXE
    .Add("57679de0ae258ead45a96949974517e2", Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.51")) // Unmodified
    .Add("525261fca4d339da67999c114118c6c6", Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.51"))
    .Add("83ea507cf9667bfe8de2d8a64e9ea57a", Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"));

// Game world address Steam 1.51.1 0x001AAE060
// Game world address GOG 1.51.1 0x001AADFB0
StaticMap<Kenshi::BinaryVersion, offset_t> GameWorldOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.51"), 0x01AAE060)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.51"), 0x01AADFB0)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC9510);

// TODO add other pointers before release
StaticMap<Kenshi::BinaryVersion, offset_t> NumAttackSlotsOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.51"), 0x01AADE28)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.51"), 0x01AADD78)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC92D8);


std::string kenshiHash = GetEXEHash();
Kenshi::BinaryVersion kenshiVersion = HashToVersionMap.count(kenshiHash) > 0 ? HashToVersionMap.at(kenshiHash) : Kenshi::BinaryVersion(Kenshi::BinaryVersion::UNKNOWN, "UNKNOWN");

Kenshi::BinaryVersion Kenshi::GetKenshiVersion()
{
    return kenshiVersion;
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

// TODO templateize
// Kenshi prefixes it's widgets with a bunch of non-usefull stuff
MyGUI::WidgetPtr Kenshi::FindWidget(MyGUI::EnumeratorWidgetPtr enumerator, std::string name)
{
    while (enumerator.next())
    {
        std::string widgetName = enumerator.current()->getName();
        size_t splitPos = widgetName.find('_');
        /*
        debug_out << widgetName;
        if(splitPos != std::string::npos)
            debug_out << " " << widgetName.substr(splitPos+1);
        debug_out << "\n";
        */
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