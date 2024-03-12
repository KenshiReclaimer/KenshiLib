#pragma once

#include <kenshi/RootObjectBase.h>
#include <string>
#include <ogre/OgreQuaternion.h>
#include <kenshi/util/StringPair.h>

class InstanceID;
class ZoneMap;
class RaceData;
class DatapanelGUI;
class InventoryLayout;
class Damages;
class CombatTechniqueData;
class PlatoonAI;
class RootObjectContainer;
class Inventory;

// TODO move?
namespace EffectType
{
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
}

class RootObject : public RootObjectBase
{
public:
    // RootObjectBase offset = 0x0, length = 0x78
    // no_addr void RootObject(const class RootObject & _a1);// public missing arg names
    RootObject(GameData * d, Faction * ownr, hand _h);// public RVA = 0x594080
    void _CONSTRUCTOR(GameData * d, Faction * ownr, hand _h);// public RVA = 0x594080
    virtual ~RootObject();// public RVA = 0x5941C0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x5941C0 vtable offset = 0x0
    virtual bool needsSaving(const std::string & s) const;// public RVA = 0xD1E90 vtable offset = 0xA8
    bool _NV_needsSaving(const std::string & s) const;// public RVA = 0xD1E90 vtable offset = 0xA8
    virtual InstanceID * getInstanceID();// public RVA = 0xD1EA0 vtable offset = 0xB0
    InstanceID * _NV_getInstanceID();// public RVA = 0xD1EA0 vtable offset = 0xB0
    virtual const std::string & getLayoutInstanceID();// public RVA = 0xD1EB0 vtable offset = 0xB8
    const std::string & _NV_getLayoutInstanceID();// public RVA = 0xD1EB0 vtable offset = 0xB8
    virtual Ogre::Quaternion getOrientation() const;// public RVA = 0xD1EC0 vtable offset = 0xC0
    Ogre::Quaternion _NV_getOrientation() const;// public RVA = 0xD1EC0 vtable offset = 0xC0
    virtual ZoneMap * getZoneMapLocation();// public RVA = 0x593B90 vtable offset = 0xC8
    ZoneMap * _NV_getZoneMapLocation();// public RVA = 0x593B90 vtable offset = 0xC8
    virtual RaceData * getRace() const;// public RVA = 0xD1EF0 vtable offset = 0xD0
    RaceData * _NV_getRace() const;// public RVA = 0xD1EF0 vtable offset = 0xD0
    // no_addr class Ogre::Matrix3 getMatrix();// public
    virtual void threadedUpdate();// public RVA = 0xD1F00 vtable offset = 0xD8
    void _NV_threadedUpdate();// public RVA = 0xD1F00 vtable offset = 0xD8
    virtual void update();// public RVA = 0x593B00 vtable offset = 0xE0
    void _NV_update();// public RVA = 0x593B00 vtable offset = 0xE0
    virtual void periodicUpdate();// public RVA = 0x593B70 vtable offset = 0xE8
    void _NV_periodicUpdate();// public RVA = 0x593B70 vtable offset = 0xE8
    virtual const Ogre::Aabb & getAABB() const;// public RVA = 0xD1F10 vtable offset = 0xF0
    const Ogre::Aabb & _NV_getAABB() const;// public RVA = 0xD1F10 vtable offset = 0xF0
    virtual bool isPhysical() = 0;// public vtable offset = 0xF8
    virtual void setVisible(bool _a1) = 0;// public vtable offset = 0x100 missing arg names
    virtual bool getVisible() const;// public RVA = 0xD5290 vtable offset = 0x108
    bool _NV_getVisible() const;// public RVA = 0xD5290 vtable offset = 0x108
    virtual bool isDisabled();// public RVA = 0xD1F20 vtable offset = 0x110
    bool _NV_isDisabled();// public RVA = 0xD1F20 vtable offset = 0x110
    virtual void setFaction(Faction * p, ActivePlatoon * a);// public RVA = 0x593C60 vtable offset = 0x0
    void _NV_setFaction(Faction * p, ActivePlatoon * a);// public RVA = 0x593C60 vtable offset = 0x0
    virtual int amInsideTownWalls();// public RVA = 0x594030 vtable offset = 0x118
    int _NV_amInsideTownWalls();// public RVA = 0x594030 vtable offset = 0x118
    virtual void setInsideTownWalls(int s);// public RVA = 0xD1F30 vtable offset = 0x120
    void _NV_setInsideTownWalls(int s);// public RVA = 0xD1F30 vtable offset = 0x120
    virtual int getFloor() const;// public RVA = 0xD1F40 vtable offset = 0x0
    int _NV_getFloor() const;// public RVA = 0xD1F40 vtable offset = 0x0
    virtual void setFloor(int f);// public RVA = 0xD1F50 vtable offset = 0x128
    void _NV_setFloor(int f);// public RVA = 0xD1F50 vtable offset = 0x128
    virtual void select();// public RVA = 0xD1F60 vtable offset = 0x130
    void _NV_select();// public RVA = 0xD1F60 vtable offset = 0x130
    virtual void unselect();// public RVA = 0xD1F70 vtable offset = 0x138
    void _NV_unselect();// public RVA = 0xD1F70 vtable offset = 0x138
    virtual void getGUIData(DatapanelGUI * _a1, int category);// public RVA = 0xD52A0 vtable offset = 0x140
    void _NV_getGUIData(DatapanelGUI * _a1, int category);// public RVA = 0xD52A0 vtable offset = 0x140
    virtual void getGUIDataCategories(lektor<StringPair> & out);// public RVA = 0xD1F80 vtable offset = 0x148
    void _NV_getGUIDataCategories(lektor<StringPair> & out);// public RVA = 0xD1F80 vtable offset = 0x148
    virtual void setStandingOrder(MessageForB::StandingOrder _a1);// public RVA = 0xD1F90 vtable offset = 0x150 missing arg names
    void _NV_setStandingOrder(MessageForB::StandingOrder _a1);// public RVA = 0xD1F90 vtable offset = 0x150 missing arg names
    virtual void getOrders(lektor<std::string > & _a1);// public RVA = 0xD1FA0 vtable offset = 0x158 missing arg names
    void _NV_getOrders(lektor<std::string > & _a1);// public RVA = 0xD1FA0 vtable offset = 0x158 missing arg names
    virtual Inventory * getInventory() const;// public RVA = 0x38F960 vtable offset = 0x160
    Inventory * _NV_getInventory() const;// public RVA = 0x38F960 vtable offset = 0x160
    virtual bool giveItem(Item * item, bool dropOnFail, bool destroyOnFail);// public RVA = 0x5939C0 vtable offset = 0x168
    bool _NV_giveItem(Item * item, bool dropOnFail, bool destroyOnFail);// public RVA = 0x5939C0 vtable offset = 0x168
    virtual bool hasRoomForItem(GameData * item);// public RVA = 0x593A40 vtable offset = 0x170
    bool _NV_hasRoomForItem(GameData * item);// public RVA = 0x593A40 vtable offset = 0x170
    virtual bool hasItem(GameData * item);// public RVA = 0x593AA0 vtable offset = 0x178
    bool _NV_hasItem(GameData * item);// public RVA = 0x593AA0 vtable offset = 0x178
    virtual InventoryLayout * createInventoryLayout();// public RVA = 0xD1FB0 vtable offset = 0x180
    InventoryLayout * _NV_createInventoryLayout();// public RVA = 0xD1FB0 vtable offset = 0x180
    virtual bool ImStealingDoYouNotice(RootObject * thief);// public RVA = 0xD1FC0 vtable offset = 0x188
    bool _NV_ImStealingDoYouNotice(RootObject * thief);// public RVA = 0xD1FC0 vtable offset = 0x188
    virtual bool stolenGoodsDetectionCheck(Item * item, RootObject * thief);// public RVA = 0xD1FD0 vtable offset = 0x190
    bool _NV_stolenGoodsDetectionCheck(Item * item, RootObject * thief);// public RVA = 0xD1FD0 vtable offset = 0x190
    virtual void equipItem(const std::string & _a1, Item * _a2);// public RVA = 0xD1FE0 vtable offset = 0x198 missing arg names
    void _NV_equipItem(const std::string & _a1, Item * _a2);// public RVA = 0xD1FE0 vtable offset = 0x198 missing arg names
    virtual void unequipItem(const std::string & _a1, Item * _a2);// public RVA = 0xD1FF0 vtable offset = 0x1A0 missing arg names
    void _NV_unequipItem(const std::string & _a1, Item * _a2);// public RVA = 0xD1FF0 vtable offset = 0x1A0 missing arg names
    virtual void dropItem(RootObject * _a1);// public RVA = 0xD2000 vtable offset = 0x1A8 missing arg names
    void _NV_dropItem(RootObject * _a1);// public RVA = 0xD2000 vtable offset = 0x1A8 missing arg names
    virtual bool takeMoney(int _a1);// public RVA = 0xD2010 vtable offset = 0x1B0 missing arg names
    bool _NV_takeMoney(int _a1);// public RVA = 0xD2010 vtable offset = 0x1B0 missing arg names
    virtual int getMoney() const;// public RVA = 0xD2020 vtable offset = 0x1B8
    int _NV_getMoney() const;// public RVA = 0xD2020 vtable offset = 0x1B8
    virtual void say(const std::string & _a1);// public RVA = 0xD2030 vtable offset = 0x1C0 missing arg names
    void _NV_say(const std::string & _a1);// public RVA = 0xD2030 vtable offset = 0x1C0 missing arg names
    virtual void notifyIndoors(const hand & in);// public RVA = 0x593B10 vtable offset = 0x1C8
    void _NV_notifyIndoors(const hand & in);// public RVA = 0x593B10 vtable offset = 0x1C8
    virtual void notifyOutdoors();// public RVA = 0x593B50 vtable offset = 0x1D0
    void _NV_notifyOutdoors();// public RVA = 0x593B50 vtable offset = 0x1D0
    virtual const hand & isIndoors() const;// public RVA = 0xD2040 vtable offset = 0x1D8
    const hand & _NV_isIndoors() const;// public RVA = 0xD2040 vtable offset = 0x1D8
    virtual bool isOnARoof();// public RVA = 0xD2050 vtable offset = 0x1E0
    bool _NV_isOnARoof();// public RVA = 0xD2050 vtable offset = 0x1E0
    virtual float getIntendedAggression();// public RVA = 0xD2060 vtable offset = 0x1E8
    float _NV_getIntendedAggression();// public RVA = 0xD2060 vtable offset = 0x1E8
    virtual HitMaterialType hitByMeleeAttack(CutDirection dir, Damages & damage, Character * who, CombatTechniqueData * attack, int comboID);// public RVA = 0xD2070 vtable offset = 0x1F0
    HitMaterialType _NV_hitByMeleeAttack(CutDirection dir, Damages & damage, Character * who, CombatTechniqueData * attack, int comboID);// public RVA = 0xD2070 vtable offset = 0x1F0
    virtual PlatoonAI * getPlatoonAI();// public RVA = 0xD2080 vtable offset = 0x1F8
    PlatoonAI * _NV_getPlatoonAI();// public RVA = 0xD2080 vtable offset = 0x1F8
    virtual bool createPhysical() = 0;// public vtable offset = 0x200
    virtual void destroyPhysical() = 0;// public vtable offset = 0x208
    virtual void setIsInsideBuilding(const hand & h);// public RVA = 0xD2090 vtable offset = 0x210
    void _NV_setIsInsideBuilding(const hand & h);// public RVA = 0xD2090 vtable offset = 0x210
    virtual void notifyEffect(EffectType::Enum type, WeatherAffecting what, float strength);// public RVA = 0xD20D0 vtable offset = 0x218
    void _NV_notifyEffect(EffectType::Enum type, WeatherAffecting what, float strength);// public RVA = 0xD20D0 vtable offset = 0x218
    RootObjectContainer * container; // 0x78 Member
    hand isInsideBuilding; // 0x80 Member
    int isInsideTownWalls; // 0xA0 Member
    int floorNum; // 0xA4 Member
    unsigned int spacialKey; // 0xA8 Member
    int outdoorDelayNotification_timer; // 0xAC Member
    Ogre::Quaternion rot; // 0xB0 Member
    virtual void loadUnloadCheck();// protected RVA = 0x593BD0 vtable offset = 0x220
    void _NV_loadUnloadCheck();// protected RVA = 0x593BD0 vtable offset = 0x220
    // no_addr class RootObject & operator=(const class RootObject & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};
