#pragma once

#include "util/hand.h"
#include "util/lektor.h"
#include "GameData.h"
#include "Enums.h"
#include "util/StringPair.h"
#include <ogre/OgreQuaternion.h>

class SensoryData;
class StateBroadcastData;
class Faction;
class RootObjectContainer;
class Ownerships;
class DatapanelGUI;
class Damages;
class CombatTechniqueData;
class InventoryLayout;
class PlatoonAI;
class InstanceID;

// TODO move?
class EffectType
{ 
public:
    enum Enum
    {
        NONE,
        CAMERA,
        POINT,
        WANDERING,
        GLOBAL,
        CAMERA_RAIN,
        CAMERA_ACID_RAIN,
        POINT_LIGHTING,
        WANDERING_STORM,
        WANDERING_GAS,
        GLOBAL_POINT
    };
};

class InstanceID
{
public:
    std::string uid; // 0x0 Member
    short baseIndex; // 0x28 Member
    short modIndex; // 0x2A Member
    bool modified; // 0x2C Member
    int getModIndex() const;// public RVA = 0x36E600 no arg names
    static short getModIndex(const std::string& s);// private RVA = 0x55D380
    InstanceID(const InstanceID& __that);// public RVA = 0x37E280
    void _CONSTRUCTOR(const InstanceID& __that);// public RVA = 0x37E280
    InstanceID(const std::string& uid, GameData::ObjectInstance& inst);// public RVA = 0x2C0950
    void _CONSTRUCTOR(const std::string& uid, GameData::ObjectInstance& inst);// public RVA = 0x2C0950
    InstanceID();// public RVA = 0x2BEA80 no arg names
    void _CONSTRUCTOR();// public RVA = 0x2BEA80 no arg names
    void assign(const std::string& id);// public RVA = 0x2C1280
    void clear();// public RVA = 0x4524C0 no arg names
    bool needsSaving(const std::string& mod) const;// public RVA = 0x2BC250
    void notifyChange();// public RVA = 0x36E590 no arg names
    bool hasChanges() const;// public RVA = 0x36E5A0 no arg names
    void notifySaved(const std::string& mod);// public RVA = 0x36E5B0
    bool empty() const;// public RVA = 0x2BC2A0 no arg names
    // no_addr const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & operator const class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > &();// public no arg names
    bool operator==(const std::string& s) const;// public RVA = 0x37A980
    int getBaseIndex() const;// public RVA = 0x36E5F0 no arg names
    ~InstanceID();// public RVA = 0x2BEAB0 no arg names
    void _DESTRUCTOR();// public RVA = 0x2BEAB0 no arg names
    InstanceID& operator=(const InstanceID& __that);// public RVA = 0x37EE40
    // no_addr void * __vecDelDtor(unsigned int a1);// public no arg names
};
    
// TODO move?
class GameSaveState
{
public:
    GameSaveState(const GameSaveState& __that);// public RVA = 0xAE220
    void _CONSTRUCTOR(const GameSaveState& __that);// public RVA = 0xAE220
    GameSaveState(GameDataContainer* source, GameData* _baseData, GameData* instanceCollectionSavingTo, const PosRotPair& _pos, PosRotPair* _offset, InstanceID* _instanceID);// public RVA = 0x2C2460
    void _CONSTRUCTOR(GameDataContainer* source, GameData* _baseData, GameData* instanceCollectionSavingTo, const PosRotPair& _pos, PosRotPair* _offset, InstanceID* _instanceID);// public RVA = 0x2C2460
    GameSaveState();// public RVA = 0x94530 no arg names
    void _CONSTRUCTOR();// public RVA = 0x94530 no arg names
    void generateNewInstanceID();// public RVA = 0x2C1FD0 no arg names
    void createFromSerialisedInstanceData(GameDataContainer* _container, GameData::ObjectInstance* _instance, const std::string& id);// public RVA = 0x2AD340
    std::string generateStateID(itemType type);// public RVA = 0x2121A0
    GameData* createState(itemType type);// public RVA = 0x2C2BA0
    void addState(GameData* state);// public RVA = 0x212270
    bool hasState(itemType type) const;// public RVA = 0xAC860
    GameData* getState(itemType type);// public RVA = 0xADB00
    int numStates() const;// public RVA = 0x2BC2B0 no arg names
    // no_addr void clearStates();// public no arg names
    // no_addr enum itemType getObjectType();// public no arg names
    Ogre::Vector3 getPos() const;// public RVA = 0x2BA9E0 no arg names
    Ogre::Quaternion getRot() const;// public RVA = 0x2BAA00 no arg names
    InstanceID getInstanceID() const;// public RVA = 0x454D80 no arg names
    const ogre_unordered_map<itemType, GameData*>::type& getAllStates() const;// public RVA = 0x565150 no arg names
    GameData* baseData; // 0x0 Member
    GameDataContainer* dataSource; // 0x8 Member
    bool firstTime; // 0x10 Member
    operator bool() const;// public RVA = 0x2BAA20 no arg names
    // no_addr const class GameSaveState & operator=(const class GameSaveState & a1);// public no arg names
    GameData::ObjectInstance* instance; // 0x18 Member
    GameData* getTheInstancesData();// public RVA = 0x2BAA40 no arg names
    Ogre::Vector3 pos; // 0x20 Member
    Ogre::Quaternion rot; // 0x2C Member
    std::string instanceID; // 0x40 Member
    ogre_unordered_map<itemType, GameData*>::type states; // 0x68 Member
    ~GameSaveState();// public RVA = 0x945E0 no arg names
    void _DESTRUCTOR();// public RVA = 0x945E0 no arg names
    // no_addr void * __vecDelDtor(unsigned int a1);// public no arg names
};

class RootObjectBase
{
public:
    // VTable         : (none)
    int validKey; // 0x8 Member
    // no_addr void RootObjectBase(const class RootObjectBase &);// public
    RootObjectBase(GameData* d, Faction* ownr, hand* h);// public RVA = 0x46DF80
    virtual ~RootObjectBase();// public RVA = 0x46EDB0 vtable offset = 0x0
    bool isValid() const;// public RVA = 0x27A000
    virtual std::string getName() const;// public RVA = 0x92B60 vtable offset = 0x8
    virtual void setName(const std::string& name);// public RVA = 0x92D80 vtable offset = 0x10
    virtual GameData* getGameData() const;// public RVA = 0x910B0 vtable offset = 0x18
    virtual itemType getDataType() const;// public RVA = 0x46DD00 vtable offset = 0x20
    virtual bool typeIsAnItem() const;// public RVA = 0x910C0 vtable offset = 0x28
    virtual bool isUnconcious() const;// public RVA = 0x91100 vtable offset = 0x30
    virtual Ogre::Vector3 getPositionForWaypoint(const Ogre::Vector3& from);// public RVA = 0x91110 vtable offset = 0x38
    virtual Ogre::Vector3 getPosition();// public RVA = 0x91130 vtable offset = 0x40
    virtual float getMovementSpeed() const;// public RVA = 0x91150 vtable offset = 0x48
    virtual Ogre::Vector3 getMovementDirection() const;// public RVA = 0x91160 vtable offset = 0x50
    virtual Faction* getFaction() const;// public RVA = 0x46E040 vtable offset = 0x58
    bool hasFaction() const;// public RVA = 0x46E0F0
    virtual int getFloor() const;// public RVA = 0x46EE00 vtable offset = 0x60
    virtual SensoryData* getSensoryData();// public RVA = 0x91180 vtable offset = 0x68
    virtual StateBroadcastData* getStateBroadcast();// public RVA = 0x91190 vtable offset = 0x70
    virtual TownBase* getCurrentTownLocation();// public RVA = 0x911A0 vtable offset = 0x78
    const hand& getHandle() const;// public RVA = 0x7C290
    virtual void setHandle(const hand& h);// public RVA = 0x911B0 vtable offset = 0x80
    virtual GameSaveState serialise(GameDataContainer*, GameData*, PosRotPair*) = 0;// public vtable offset = 0x88
    virtual void loadFromSerialise(GameSaveState*) = 0;// public vtable offset = 0x90
    virtual Ownerships* getOwnerships();// public RVA = 0x911D0 vtable offset = 0x98
    // no_addr bool operator==(const class hand &);// public
    // no_addr bool operator!=(const class hand &);// public
    Faction* owner; // 0x10 Member
    virtual void setFaction(Faction* p, ActivePlatoon* a);// public RVA = 0x46EE10 vtable offset = 0xA0
    std::string displayName; // 0x18 Member
    GameData* data; // 0x40 Member
    Ogre::Vector3 pos; // 0x48 Member
    hand handle; // 0x58 Member
    // no_addr class RootObjectBase & operator=(const class RootObjectBase &);// public
    //virtual void * __vecDelDtor(unsigned int) = 0;// public vtable offset = 0x0
};

class InstanceID;
class ZoneMap;
class RaceData;
class Inventory;

namespace Ogre
{
    class Aabb;
};

class RootObject : public RootObjectBase
{
public:
    // RootObjectBase offset = 0x0, length = 0x78
    // no_addr void RootObject(const class RootObject & a1);// public no arg names
    RootObject(GameData* d, Faction* ownr, hand _h);// public RVA = 0x46E200
    void _CONSTRUCTOR(GameData* d, Faction* ownr, hand _h);// public RVA = 0x46E200
    virtual ~RootObject();// public RVA = 0x46E340 vtable offset = 0x0 no arg names
    void _DESTRUCTOR();// public RVA = 0x46E340 vtable offset = 0x0 no arg names
    virtual bool needsSaving(const std::string& s) const;// public RVA = 0x911E0 vtable offset = 0xA8
    bool _NV_needsSaving(const std::string& s) const;// public RVA = 0x911E0 vtable offset = 0xA8
    virtual InstanceID* getInstanceID();// public RVA = 0x911F0 vtable offset = 0xB0 no arg names
    InstanceID* _NV_getInstanceID();// public RVA = 0x911F0 vtable offset = 0xB0 no arg names
    virtual const std::string& getLayoutInstanceID();// public RVA = 0x91200 vtable offset = 0xB8 no arg names
    const std::string& _NV_getLayoutInstanceID();// public RVA = 0x91200 vtable offset = 0xB8 no arg names
    virtual Ogre::Quaternion getOrientation() const;// public RVA = 0x91210 vtable offset = 0xC0 no arg names
    Ogre::Quaternion _NV_getOrientation() const;// public RVA = 0x91210 vtable offset = 0xC0 no arg names
    virtual ZoneMap* getZoneMapLocation();// public RVA = 0x46DD10 vtable offset = 0xC8 no arg names
    ZoneMap* _NV_getZoneMapLocation();// public RVA = 0x46DD10 vtable offset = 0xC8 no arg names
    virtual RaceData* getRace() const;// public RVA = 0x91240 vtable offset = 0xD0 no arg names
    RaceData* _NV_getRace() const;// public RVA = 0x91240 vtable offset = 0xD0 no arg names
    // no_addr class Ogre::Matrix3 getMatrix();// public no arg names
    virtual void threadedUpdate();// public RVA = 0x91250 vtable offset = 0xD8 no arg names
    void _NV_threadedUpdate();// public RVA = 0x91250 vtable offset = 0xD8 no arg names
    virtual void update();// public RVA = 0x46DC80 vtable offset = 0xE0 no arg names
    void _NV_update();// public RVA = 0x46DC80 vtable offset = 0xE0 no arg names
    virtual void periodicUpdate();// public RVA = 0x46DCF0 vtable offset = 0xE8 no arg names
    void _NV_periodicUpdate();// public RVA = 0x46DCF0 vtable offset = 0xE8 no arg names
    virtual const Ogre::Aabb& getAABB() const;// public RVA = 0x91260 vtable offset = 0xF0 no arg names
    const Ogre::Aabb& _NV_getAABB() const;// public RVA = 0x91260 vtable offset = 0xF0 no arg names
    virtual bool isPhysical() = 0;// public vtable offset = 0xF8 no arg names
    virtual void setVisible(bool a1) = 0;// public vtable offset = 0x100 no arg names
    virtual bool getVisible() const;// public RVA = 0x93BD0 vtable offset = 0x108 no arg names
    bool _NV_getVisible() const;// public RVA = 0x93BD0 vtable offset = 0x108 no arg names
    virtual bool isDisabled();// public RVA = 0x91270 vtable offset = 0x110 no arg names
    bool _NV_isDisabled();// public RVA = 0x91270 vtable offset = 0x110 no arg names
    virtual void setFaction(Faction* p, ActivePlatoon* a);// public RVA = 0x46DDE0 vtable offset = 0x0
    void _NV_setFaction(Faction* p, ActivePlatoon* a);// public RVA = 0x46DDE0 vtable offset = 0x0
    virtual int amInsideTownWalls();// public RVA = 0x46E1B0 vtable offset = 0x118 no arg names
    int _NV_amInsideTownWalls();// public RVA = 0x46E1B0 vtable offset = 0x118 no arg names
    virtual void setInsideTownWalls(int s);// public RVA = 0x91280 vtable offset = 0x120
    void _NV_setInsideTownWalls(int s);// public RVA = 0x91280 vtable offset = 0x120
    virtual int getFloor() const;// public RVA = 0x91290 vtable offset = 0x0 no arg names
    int _NV_getFloor() const;// public RVA = 0x91290 vtable offset = 0x0 no arg names
    virtual void setFloor(int f);// public RVA = 0x912A0 vtable offset = 0x128
    void _NV_setFloor(int f);// public RVA = 0x912A0 vtable offset = 0x128
    virtual void select();// public RVA = 0x912B0 vtable offset = 0x130 no arg names
    void _NV_select();// public RVA = 0x912B0 vtable offset = 0x130 no arg names
    virtual void unselect();// public RVA = 0x912C0 vtable offset = 0x138 no arg names
    void _NV_unselect();// public RVA = 0x912C0 vtable offset = 0x138 no arg names
    virtual void getGUIData(DatapanelGUI* a1, int category);// public RVA = 0x93BE0 vtable offset = 0x140
    void _NV_getGUIData(DatapanelGUI* a1, int category);// public RVA = 0x93BE0 vtable offset = 0x140
    virtual void getGUIDataCategories(lektor<StringPair>& out);// public RVA = 0x912D0 vtable offset = 0x148
    void _NV_getGUIDataCategories(lektor<StringPair>& out);// public RVA = 0x912D0 vtable offset = 0x148
    virtual void setStandingOrder(MessageForB::StandingOrder  a1);// public RVA = 0x912E0 vtable offset = 0x150 no arg names
    void _NV_setStandingOrder(MessageForB::StandingOrder  a1);// public RVA = 0x912E0 vtable offset = 0x150 no arg names
    virtual void getOrders(lektor<std::string >& a1);// public RVA = 0x912F0 vtable offset = 0x158 no arg names
    void _NV_getOrders(lektor<std::string >& a1);// public RVA = 0x912F0 vtable offset = 0x158 no arg names
    virtual Inventory* getInventory() const;// public RVA = 0x2C9AF0 vtable offset = 0x160 no arg names
    Inventory* _NV_getInventory() const;// public RVA = 0x2C9AF0 vtable offset = 0x160 no arg names
    virtual bool giveItem(Item* item, bool dropOnFail, bool destroyOnFail);// public RVA = 0x46DB40 vtable offset = 0x168
    bool _NV_giveItem(Item* item, bool dropOnFail, bool destroyOnFail);// public RVA = 0x46DB40 vtable offset = 0x168
    virtual bool hasRoomForItem(GameData* item);// public RVA = 0x46DBC0 vtable offset = 0x170
    bool _NV_hasRoomForItem(GameData* item);// public RVA = 0x46DBC0 vtable offset = 0x170
    virtual bool hasItem(GameData* item);// public RVA = 0x46DC20 vtable offset = 0x178
    bool _NV_hasItem(GameData* item);// public RVA = 0x46DC20 vtable offset = 0x178
    virtual InventoryLayout* createInventoryLayout();// public RVA = 0x91300 vtable offset = 0x180 no arg names
    InventoryLayout* _NV_createInventoryLayout();// public RVA = 0x91300 vtable offset = 0x180 no arg names
    virtual bool ImStealingDoYouNotice(RootObject* thief);// public RVA = 0x91310 vtable offset = 0x188
    bool _NV_ImStealingDoYouNotice(RootObject* thief);// public RVA = 0x91310 vtable offset = 0x188
    virtual bool stolenGoodsDetectionCheck(Item* item, RootObject* thief);// public RVA = 0x91320 vtable offset = 0x190
    bool _NV_stolenGoodsDetectionCheck(Item* item, RootObject* thief);// public RVA = 0x91320 vtable offset = 0x190
    virtual void equipItem(const std::string& a1, Item* a2);// public RVA = 0x91330 vtable offset = 0x198 no arg names
    void _NV_equipItem(const std::string& a1, Item* a2);// public RVA = 0x91330 vtable offset = 0x198 no arg names
    virtual void unequipItem(const std::string& a1, Item* a2);// public RVA = 0x91340 vtable offset = 0x1A0 no arg names
    void _NV_unequipItem(const std::string& a1, Item* a2);// public RVA = 0x91340 vtable offset = 0x1A0 no arg names
    virtual void dropItem(RootObject* a1);// public RVA = 0x91350 vtable offset = 0x1A8 no arg names
    void _NV_dropItem(RootObject* a1);// public RVA = 0x91350 vtable offset = 0x1A8 no arg names
    virtual bool takeMoney(int  a1);// public RVA = 0x91360 vtable offset = 0x1B0 no arg names
    bool _NV_takeMoney(int  a1);// public RVA = 0x91360 vtable offset = 0x1B0 no arg names
    virtual int getMoney() const;// public RVA = 0x91370 vtable offset = 0x1B8 no arg names
    int _NV_getMoney() const;// public RVA = 0x91370 vtable offset = 0x1B8 no arg names
    virtual void say(const std::string& a1);// public RVA = 0x91380 vtable offset = 0x1C0 no arg names
    void _NV_say(const std::string& a1);// public RVA = 0x91380 vtable offset = 0x1C0 no arg names
    virtual void notifyIndoors(const hand& in);// public RVA = 0x46DC90 vtable offset = 0x1C8
    void _NV_notifyIndoors(const hand& in);// public RVA = 0x46DC90 vtable offset = 0x1C8
    virtual void notifyOutdoors();// public RVA = 0x46DCD0 vtable offset = 0x1D0 no arg names
    void _NV_notifyOutdoors();// public RVA = 0x46DCD0 vtable offset = 0x1D0 no arg names
    virtual const hand& isIndoors() const;// public RVA = 0x91390 vtable offset = 0x1D8 no arg names
    const hand& _NV_isIndoors() const;// public RVA = 0x91390 vtable offset = 0x1D8 no arg names
    virtual bool isOnARoof();// public RVA = 0x913A0 vtable offset = 0x1E0 no arg names
    bool _NV_isOnARoof();// public RVA = 0x913A0 vtable offset = 0x1E0 no arg names
    virtual float getIntendedAggression();// public RVA = 0x913B0 vtable offset = 0x1E8 no arg names
    float _NV_getIntendedAggression();// public RVA = 0x913B0 vtable offset = 0x1E8 no arg names
    virtual HitMaterialType hitByMeleeAttack(CutDirection dir, Damages& damage, Character* who, CombatTechniqueData* attack, int comboID);// public RVA = 0x913C0 vtable offset = 0x1F0
    HitMaterialType _NV_hitByMeleeAttack(CutDirection dir, Damages& damage, Character* who, CombatTechniqueData* attack, int comboID);// public RVA = 0x913C0 vtable offset = 0x1F0
    virtual PlatoonAI* getPlatoonAI();// public RVA = 0x913D0 vtable offset = 0x1F8 no arg names
    PlatoonAI* _NV_getPlatoonAI();// public RVA = 0x913D0 vtable offset = 0x1F8 no arg names
    virtual bool createPhysical() = 0;// public vtable offset = 0x200 no arg names
    virtual void destroyPhysical() = 0;// public vtable offset = 0x208 no arg names
    virtual void setIsInsideBuilding(const hand& h);// public RVA = 0x913E0 vtable offset = 0x210
    void _NV_setIsInsideBuilding(const hand& h);// public RVA = 0x913E0 vtable offset = 0x210
    virtual void notifyEffect(EffectType::Enum type, WeatherAffecting what, float strength);// public RVA = 0x91410 vtable offset = 0x218
    void _NV_notifyEffect(EffectType::Enum type, WeatherAffecting what, float strength);// public RVA = 0x91410 vtable offset = 0x218
    RootObjectContainer* container; // 0x78 Member
    hand isInsideBuilding; // 0x80 Member
    int isInsideTownWalls; // 0xA0 Member
    int floorNum; // 0xA4 Member
    unsigned int spacialKey; // 0xA8 Member
    int outdoorDelayNotification_timer; // 0xAC Member
    Ogre::Quaternion rot; // 0xB0 Member
    virtual void loadUnloadCheck();// protected RVA = 0x46DD50 vtable offset = 0x220 no arg names
    void _NV_loadUnloadCheck();// protected RVA = 0x46DD50 vtable offset = 0x220 no arg names
    // no_addr class RootObject & operator=(const class RootObject & a1);// public no arg names
    //virtual void * __vecDelDtor(unsigned int a1) = 0;// public vtable offset = 0x0 no arg names
};
