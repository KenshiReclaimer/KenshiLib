#pragma once

#include <string>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>
#include <map>
#include "util/lektor.h"
#include "util/hand.h"
#include "util/OgreUnordered.h"

class GameDataContainer;
class GameDataReference;
class GameSaveState;
class PosRotPair;
class TripleInt;

class GameData : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    int validity; // 0x8 Member
    GameDataContainer* sourceContainer; // 0x10 Member
    virtual ~GameData();// protected RVA = 0x7A290 vtable offset = 0x0
    void _DESTRUCTOR();// protected RVA = 0x7A290 vtable offset = 0x0
    // no_addr void GameData(const class GameData & _a1);// public missing arg names
    GameData();// protected RVA = 0x51C560
    void _CONSTRUCTOR();// protected RVA = 0x51C560
    bool isStandalone; // 0x18 Member
    bool isValid() const;// public RVA = 0x42EF10
    GameDataContainer* getSourceContainer() const;// public RVA = 0x8D330
    void destroy();// public RVA = 0x6530B0
    enum DataType
    {
        NONE,
        INT,
        FLOAT,
        BOOL,
        FILE,
        STRING
    };

    class ItemData
    {
    public:
        // no_addr void ItemData(const class GameData::ItemData & _a1);// public missing arg names
        // no_addr void ItemData(class std::basic_string<char,std::char_traits<char>,std::allocator<char> > _a1, bool _a2, class std::basic_string<char,std::char_traits<char>,std::allocator<char> > _a3, float _a4, float _a5, enum itemType _a6, int _a7, bool _a8);// public missing arg names
        // no_addr void ItemData();// public
        bool visible; // 0x0 Member
        std::string category; // 0x8 Member
        std::string description; // 0x30 Member
        std::string fileTypes; // 0x58 Member
        itemType objectType; // 0x80 Member
        int maxSize; // 0x84 Member
        int maxValue; // 0x88 Member
        int minValue; // 0x8C Member
        bool isSlider; // 0x90 Member
        // no_addr const class GameData::ItemData & operator=(const class GameData::ItemData & _a1);// public missing arg names
        // no_addr void ~ItemData();// public
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    int id; // 0x1C Member
    bool readOnly; // 0x20 Member
    std::string name; // 0x28 Member
    itemType type; // 0x50 Member
    std::string stringID; // 0x58 Member
    bool isFromActiveFile; // 0x80 Member
    void initialise(itemType t, bool isActive);// public RVA = 0x51B8F0
    bool loadFromFile(const std::string& path, itemType _type);// public RVA = 0x564D60
    bool saveToFile(const std::string& path);// public RVA = 0x561C20
    void storeHandleList(const ogre_unordered_set<hand>::type& handle, const std::string& _name);// public RVA = 0x55E1D0
    void storeHandleList(const lektor<hand>& handle, const std::string& _name);// public RVA = 0x55E0E0
    void getHandleList(ogre_unordered_set<hand>::type& out, const std::string& _name);// public RVA = 0x55E680
    void getHandleList(lektor<hand>& out, const std::string& _name);// public RVA = 0x55E500
    void storeHandle(const hand& handle, const std::string& _name, bool redirect);// public RVA = 0x55DD70
    bool getHandle(hand& handle, const std::string& _name);// public RVA = 0x55E2F0
    bool updateFrom(const GameData* from, bool mod);// public RVA = 0x240380
    bool isValueActive(const std::string& v) const;// public RVA = 0x23FF10
    // no_addr bool isRefDeleted(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & _a1);// public missing arg names
    bool isRefActive(const std::string& v) const;// public RVA = 0x23FC30
    void addFileName(const std::string& n, const std::string& v, std::string filestype, std::string category, bool vis);// public RVA = 0x2C2F20
    void addString(const std::string& n, const std::string& v, std::string category, bool vis);// public RVA = 0x77B20
    // no_addr void add(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & _a1, class Ogre::Quaternion _a2);// public missing arg names
    void add(const std::string& n, Ogre::Vector3 v);// public RVA = 0x77C20
    void add(const std::string& n, bool v, std::string category, bool vis);// public RVA = 0x76D50
    void add(const std::string& n, float v, std::string category, bool vis, bool isSlider);// public RVA = 0x77BA0
    void add(const std::string& n, unsigned int v, std::string category, bool vis);// public RVA = 0x4FA6A0
    void add(const std::string& n, int v, std::string category, bool vis);// public RVA = 0x76CD0
    GameDataReference* getGameDataReferenceObject(const std::string& list, const std::string& id);// public RVA = 0x7A3D0
    void addToList(const std::string& list, const std::string& id, int val, int val2, int val3);// public RVA = 0x7A4B0
    void removeFromList(const std::string& list, int id);// public RVA = 0x697090
    void removeFromList(const std::string& list, const std::string& id);// public RVA = 0x569600
    bool findInList(const std::string& list, const std::string& SID);// public RVA = 0x232B80
    void clearList(const std::string& n);// public RVA = 0x7A5C0
    // no_addr void clearAllLists();// public
    void clearEverything();// public RVA = 0x459890
    void clearInstances();// public RVA = 0x457720
    const std::string& getFromList(const std::string& n, int index) const;// public RVA = 0x70490
    const std::string& getFromList_random(const std::string& n) const;// public RVA = 0x55DB40
    int getListSize(const std::string& n) const;// public RVA = 0x93420
    bool listExists(const std::string& n) const;// public RVA = 0x46C0B0
    bool listExistsAndNotEmpty(const std::string& n) const;// public RVA = 0x70550
    void getAllFromList(const std::string& n, lektor<std::string >& list);// public RVA = 0x4FBFC0
    const Ogre::vector<GameDataReference>::type* getReferenceList(const std::string& listname);// public RVA = 0x43340
    const Ogre::vector<GameDataReference>::type* getReferenceListIfExists(const std::string& listname) const;// public RVA = 0x22ECC0
    Ogre::vector<GameDataReference>::type* _getReferenceList_nonConst(const std::string& listname);// public RVA = 0x939D0
    void getAllFromListAsDatas(const std::string& n, lektor<GameData*>& list, GameDataContainer* dataContainer, itemType type);// public RVA = 0x7A5E0
    GameData* getFromListAsData(const std::string& n, int index, GameDataContainer* dataContainer, itemType type);// public RVA = 0x7A710
    const TripleInt& getValueFromList(const std::string& n, int index) const;// public RVA = 0x8A7C0
    class ObjectInstance
    {
    public:
        ObjectInstance(const GameData::ObjectInstance& __that);// public RVA = 0xB6080
        void _CONSTRUCTOR(const GameData::ObjectInstance& __that);// public RVA = 0xB6080
        ObjectInstance();// public RVA = 0xB5160
        void _CONSTRUCTOR();// public RVA = 0xB5160
        Ogre::Vector3 pos; // 0x0 Member
        Ogre::Quaternion rot; // 0xC Member
        std::string refID; // 0x20 Member
        short created; // 0x48 Member
        short modified; // 0x4A Member
        lektor<std::string > stateIDs; // 0x50 Member
        const GameData::ObjectInstance& operator=(const GameData::ObjectInstance& a);// public RVA = 0x2C23F0
        void updateInstancedObjectAttachedDatas(const ogre_unordered_map<itemType, GameData*>::type& states);// public RVA = 0x55D950
        ~ObjectInstance();// public RVA = 0x65AD0
        void _DESTRUCTOR();// public RVA = 0x65AD0
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    // Typedef        : StringObjectInstanceMap
    void addSavedInstancedObject(const std::string& id, const std::string& refID, int modIndex, const Ogre::Vector3& pos, const Ogre::Quaternion& rot, const lektor<std::string >& states);// public RVA = 0x5693C0
    void deleteInstancedObject(const std::string& id, int modIndex);// public RVA = 0x569500
    // no_addr void updateInstancedObject(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & _a1, class Ogre::Vector3 _a2, class Ogre::Quaternion _a3);// public missing arg names
    void getInstances(lektor<GameData::ObjectInstance*>& out);// public RVA = 0x453AE0
    std::map<std::string, GameData::ObjectInstance, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData::ObjectInstance>, Ogre::GeneralAllocPolicy > > instances; // 0x88 Member
    int currentID; // 0xB0 Member
    int getNewID();// public RVA = 0x55D440
    boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > > activeValues; // 0xB8 Member
    boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::GeneralAllocPolicy > > bdata; // 0xF8 Member
    boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > > sdata; // 0x138 Member
    boost::unordered::unordered_map<std::string, int, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > > idata; // 0x178 Member
    boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::GeneralAllocPolicy > > fdata; // 0x1B8 Member
    boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::GeneralAllocPolicy > > filesdata; // 0x1F8 Member
    boost::unordered::unordered_map<std::string, Ogre::Vector3, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Vector3>, Ogre::GeneralAllocPolicy > > vecdata; // 0x238 Member
    boost::unordered::unordered_map<std::string, Ogre::Quaternion, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Quaternion>, Ogre::GeneralAllocPolicy > > quatdata; // 0x278 Member
    boost::unordered::unordered_map<std::string, Ogre::vector<GameDataReference>::type, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::vector<GameDataReference>::type >, Ogre::GeneralAllocPolicy > > objectReferences; // 0x2B8 Member
    unsigned short createdIndex; // 0x2F8 Member
    Ogre::ColourValue getColor(const std::string& name);// public RVA = 0x76DD0
    Ogre::Vector3 getColorVec(const std::string& name);// public RVA = 0x93660
    void setColor(const std::string& name, const Ogre::Vector3& c);// public RVA = 0x93730
    void setColor(const std::string& name, const Ogre::ColourValue& c);// public RVA = 0x936F0
    // no_addr enum GameData::DataType getDataType(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & _a1);// public missing arg names
    GameData::ObjectInstance* addANewInstancedObject(GameData::ObjectInstance* from);// public RVA = 0x5602E0
    void addANewInstancedObject(GameData* referenceObject, const PosRotPair& positionRotation);// public RVA = 0x5601F0
    void addANewInstancedObject(GameData* referenceObject);// public RVA = 0x560140
    GameData::ObjectInstance* addANewInstancedObject(const GameSaveState& referenceObject, const PosRotPair& position, PosRotPair* offsetPos);// public RVA = 0x564130
    void addDeletedInstance(const std::string& instanceID);// public RVA = 0x560460
    // no_addr class GameData & operator=(const class GameData & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};
