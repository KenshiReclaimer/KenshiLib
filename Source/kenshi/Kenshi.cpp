#include <kenshi/Kenshi.h>

#include <kenshi/GameWorld.h>
#include <kenshi/PlayerInterface.h>
#include <kenshi/GlobalConstants.h>
#include <kenshi/util/functions.h>

#include <core/RVA.h>

#include <core/md5.h>

#include <Debug.h>
#include <Release_Assert.h>

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
// ou
StaticMap<Kenshi::BinaryVersion, offset_t> GameWorldOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC9510)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x01ACA520)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x01AC8460)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x01AC9470);

// Search for 2000.000f in non-writable and one of th ose will be the correct value
// CAMERA_FAR
StaticMap<Kenshi::BinaryVersion, offset_t> MaxCameraDistanceOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x011F4E18)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x011F5D88)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.59"), 0x011F4B68)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x011F5AD8);

// CAMERA_CLOSE
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

// read at 0x006C1325 Steam 1.0.64
// the numbers check out
// GlobalConstants con; // 0x001ACA1E0
// int MAX_SQUAD_SIZE; // 0x178 Member // 0x01ACA358
StaticMap<Kenshi::BinaryVersion, offset_t> GlobalConOffset = StaticMap<Kenshi::BinaryVersion, offset_t>()
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.55"), 0x01AC91D0)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::STEAM, "1.0.64"), 0x01ACA1E0)
    .Add(Kenshi::BinaryVersion(Kenshi::BinaryVersion::GOG, "1.0.64"), 0x01AC8120);

std::string kenshiHash = GetEXEHash();
Kenshi::BinaryVersion kenshiVersion = HashToVersionMap.count(kenshiHash) > 0 ? HashToVersionMap.at(kenshiHash) : Kenshi::BinaryVersion(Kenshi::BinaryVersion::UNKNOWN, "UNKNOWN");

void Kenshi::Init()
{
    assert_release(FUNCTION_ERROR == 0);

    // binary RVA path
    std::string RVAFilePath = "RE_Kenshi/RVAs/" + kenshiVersion.GetPlatformStr() + "_" + kenshiVersion.GetVersion() + ".br";
    std::ifstream rvaFile(RVAFilePath, std::ios::ate | std::ios::binary);
    if (!rvaFile.is_open())
        ErrorLog("Unable to open RVA file at " + RVAFilePath);
    assert_release(rvaFile.is_open());
    size_t end = rvaFile.tellg();
    assert_release(end == (FUNCTION_BUFF_LENGTH * sizeof(intptr_t) / 2));
    rvaFile.seekg(0);

    for (int i = 0; i < FUNCTION_BUFF_LENGTH; ++i)
    {
        int offset;
        rvaFile.read((char*)(&offset), 4);

        RVAPtr<void> c_inst(offset);
        function_pointers[i] = (intptr_t)c_inst.GetPtr();
    }
    DebugLog("RVAs loaded");
}

Kenshi::BinaryVersion Kenshi::GetKenshiVersion()
{
    return kenshiVersion;
}

GameWorld& Kenshi::GetGameWorld()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t gameWorldOffset = GameWorldOffset.at(kenshiVersion);
    static RVAPtr<GameWorld> c_inst(gameWorldOffset);
    return *c_inst.GetPtr();
}

GlobalConstants* Kenshi::GetCon() 
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t conOffset = GlobalConOffset.at(kenshiVersion);
    static RVAPtr<GlobalConstants> c_inst(conOffset);
    return c_inst.GetPtr();
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

InputHandler& Kenshi::GetInputHandler()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t inputHandlerOffset = InputHandlerOffset.at(kenshiVersion);
    static RVAPtr<InputHandler> c_inst(inputHandlerOffset);
    return *c_inst.GetPtr();
}

SaveManager* Kenshi::GetSaveManager()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t saveManagerPtrOffset = SaveManagerOffset.at(kenshiVersion);
    static RVAPtr<SaveManager*> c_inst(saveManagerPtrOffset);
    return *c_inst.GetPtr();
}

SaveFileSystem* Kenshi::GetSaveFileSystem()
{
    Kenshi::BinaryVersion kenshiVersion = GetKenshiVersion();
    offset_t saveFileSystemPtrOffset = SaveFileSystemOffset.at(kenshiVersion);
    static RVAPtr<SaveFileSystem*> c_inst(saveFileSystemPtrOffset);
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
