#pragma once

#include <string>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <kenshi/util/hand.h>
#include <kenshi/util/lektor.h>
#include <kenshi/Enums.h>

class GameData;
class Faction;
class SensoryData;
class StateBroadcastData;
class TownBase;
class PosRotPair;
class Ownerships;
class ActivePlatoon;
class GameDataContainer;
class GameSaveState;

class RootObjectBase
{
public:
    // VTable         : (none)
    int validKey; // 0x8 Member
    // no_addr void RootObjectBase(const class RootObjectBase & _a1);// public missing arg names
    RootObjectBase(GameData * d, Faction * ownr, hand h);// public RVA = 0x593E00
    void _CONSTRUCTOR(GameData * d, Faction * ownr, hand h);// public RVA = 0x593E00
    virtual ~RootObjectBase();// public RVA = 0x594FC0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x594FC0 vtable offset = 0x0
    bool isValid() const;// public RVA = 0x32D8E0
    virtual std::string getName() const;// public RVA = 0xD3CA0 vtable offset = 0x8
    std::string _NV_getName() const;// public RVA = 0xD3CA0 vtable offset = 0x8
    virtual void setName(const std::string & name);// public RVA = 0xD3F40 vtable offset = 0x10
    void _NV_setName(const std::string & name);// public RVA = 0xD3F40 vtable offset = 0x10
    virtual GameData * getGameData() const;// public RVA = 0xD1D30 vtable offset = 0x18
    GameData * _NV_getGameData() const;// public RVA = 0xD1D30 vtable offset = 0x18
    virtual itemType getDataType() const;// public RVA = 0x593B80 vtable offset = 0x20
    itemType _NV_getDataType() const;// public RVA = 0x593B80 vtable offset = 0x20
    virtual bool typeIsAnItem() const;// public RVA = 0xD1D40 vtable offset = 0x28
    bool _NV_typeIsAnItem() const;// public RVA = 0xD1D40 vtable offset = 0x28
    virtual bool isUnconcious() const;// public RVA = 0xD1D90 vtable offset = 0x30
    bool _NV_isUnconcious() const;// public RVA = 0xD1D90 vtable offset = 0x30
    virtual Ogre::Vector3 getPositionForWaypoint(const Ogre::Vector3 & from);// public RVA = 0xD1DA0 vtable offset = 0x38
    Ogre::Vector3 _NV_getPositionForWaypoint(const Ogre::Vector3 & from);// public RVA = 0xD1DA0 vtable offset = 0x38
    virtual Ogre::Vector3 getPosition();// public RVA = 0xD1DC0 vtable offset = 0x40
    Ogre::Vector3 _NV_getPosition();// public RVA = 0xD1DC0 vtable offset = 0x40
    virtual float getMovementSpeed() const;// public RVA = 0xD1DE0 vtable offset = 0x48
    float _NV_getMovementSpeed() const;// public RVA = 0xD1DE0 vtable offset = 0x48
    virtual Ogre::Vector3 getMovementDirection() const;// public RVA = 0xD1DF0 vtable offset = 0x50
    Ogre::Vector3 _NV_getMovementDirection() const;// public RVA = 0xD1DF0 vtable offset = 0x50
    virtual Faction * getFaction() const;// public RVA = 0x593EC0 vtable offset = 0x58
    Faction * _NV_getFaction() const;// public RVA = 0x593EC0 vtable offset = 0x58
    bool hasFaction() const;// public RVA = 0x593F70
    virtual int getFloor() const;// public RVA = 0x595020 vtable offset = 0x60
    int _NV_getFloor() const;// public RVA = 0x595020 vtable offset = 0x60
    virtual SensoryData * getSensoryData();// public RVA = 0xD1E20 vtable offset = 0x68
    SensoryData * _NV_getSensoryData();// public RVA = 0xD1E20 vtable offset = 0x68
    virtual StateBroadcastData * getStateBroadcast();// public RVA = 0xD1E30 vtable offset = 0x70
    StateBroadcastData * _NV_getStateBroadcast();// public RVA = 0xD1E30 vtable offset = 0x70
    virtual TownBase * getCurrentTownLocation();// public RVA = 0xD1E40 vtable offset = 0x78
    TownBase * _NV_getCurrentTownLocation();// public RVA = 0xD1E40 vtable offset = 0x78
    const hand & getHandle() const;// public RVA = 0xB85D0
    virtual void setHandle(const hand & h);// public RVA = 0xD1E50 vtable offset = 0x80
    void _NV_setHandle(const hand & h);// public RVA = 0xD1E50 vtable offset = 0x80
    virtual GameSaveState serialise(GameDataContainer * _a1, GameData * _a2, PosRotPair * _a3) = 0;// public vtable offset = 0x88 missing arg names
    virtual void loadFromSerialise(GameSaveState * _a1) = 0;// public vtable offset = 0x90 missing arg names
    virtual Ownerships * getOwnerships();// public RVA = 0xD1E80 vtable offset = 0x98
    Ownerships * _NV_getOwnerships();// public RVA = 0xD1E80 vtable offset = 0x98
    // no_addr bool operator==(const class hand & _a1);// public missing arg names
    // no_addr bool operator!=(const class hand & _a1);// public missing arg names
    Faction * owner; // 0x10 Member
    virtual void setFaction(Faction * p, ActivePlatoon * a);// public RVA = 0x595030 vtable offset = 0xA0
    void _NV_setFaction(Faction * p, ActivePlatoon * a);// public RVA = 0x595030 vtable offset = 0xA0
    std::string displayName; // 0x18 Member
    GameData * data; // 0x40 Member
    Ogre::Vector3 pos; // 0x48 Member
    hand handle; // 0x58 Member
    // no_addr class RootObjectBase & operator=(const class RootObjectBase & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};
