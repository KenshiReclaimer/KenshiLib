#pragma once

#include <string>

#include <kenshi/Enums.h>

class GameData;
class RootObjectBase;
class ActivePlatoon;
class Character;
class Platoon;
class Building;
class Item;
class RootObject;
class TownBase;

class hand
{
public:
    // VTable         : (none)
    hand(GameData* fromLoadedState, itemType typ);// public RVA = 0x7941C0
    void _CONSTRUCTOR(GameData* fromLoadedState, itemType typ);// public RVA = 0x7941C0
    hand(RootObjectBase* from);// public RVA = 0x791360
    void _CONSTRUCTOR(RootObjectBase* from);// public RVA = 0x791360
    hand(const int from);// public RVA = 0xD5EF0
    void _CONSTRUCTOR(const int from);// public RVA = 0xD5EF0
    hand(const hand& from);// public RVA = 0xD1AE0
    void _CONSTRUCTOR(const hand& from);// public RVA = 0xD1AE0
    hand(unsigned int _index, unsigned int _serial, itemType _type, unsigned int _container, unsigned int _containerSerial);// public RVA = 0xCCFF0
    void _CONSTRUCTOR(unsigned int _index, unsigned int _serial, itemType _type, unsigned int _container, unsigned int _containerSerial);// public RVA = 0xCCFF0
    hand();// public RVA = 0xCCFC0
    void _CONSTRUCTOR();// public RVA = 0xCCFC0
    itemType type; // 0x8 Member
    unsigned int container; // 0xC Member
    unsigned int containerSerial; // 0x10 Member
    unsigned int index; // 0x14 Member
    unsigned int serial; // 0x18 Member
    std::string toString() const;// public RVA = 0x9B3FA0
    void fromString(const std::string& str);// public RVA = 0x9B7120
    virtual bool operator==(bool a) const;// public RVA = 0xCD0C0 vtable offset = 0x0
    bool _NV_operator_equal(bool a) const;// public RVA = 0xCD0C0 vtable offset = 0x0
    bool operator==(const RootObjectBase* a) const;// public RVA = 0x593CC0
    virtual bool operator==(const hand& a) const;// public RVA = 0xCD020 vtable offset = 0x8
    bool _NV_operator_equal(const hand& a) const;// public RVA = 0xCD020 vtable offset = 0x8
    bool operator!=(const RootObjectBase* a) const;// public RVA = 0x593D60
    virtual bool operator!=(const hand& a) const;// public RVA = 0xCD070 vtable offset = 0x10
    bool _NV_operator_notequal(const hand& a) const;// public RVA = 0xCD070 vtable offset = 0x10
    operator bool() const;// public RVA = 0x64540
    Character* getCharacter() const;// public RVA = 0x796E30
    Platoon* getPlatoon() const;// public RVA = 0x791630
    ActivePlatoon* getActivePlatoon() const;// public RVA = 0x791660
    Building* getBuilding() const;// public RVA = 0x7916B0
    Item* getItem() const;// public RVA = 0x7916D0
    RootObject* getRootObject() const;// public RVA = 0x79C1B0
    RootObjectBase* getRootObjectBase() const;// public RVA = 0x79C1D0
    TownBase* getTown() const;// public RVA = 0x791720
    std::string debugWhatHappenedToMe();// public RVA = 0x793EA0
    bool operator<(const hand& h) const;// public RVA = 0xF6A60
    hand& operator=(const hand& __that);// public RVA = 0xCD0E0
    const hand& operator=(RootObjectBase* a);// public RVA = 0x7913B0
    const hand& operator=(const int& a);// public RVA = 0x278BA0
    void setNull();// public RVA = 0x143CF0
    bool isNull() const;// public RVA = 0x36ABE0
    bool isValid() const;// public RVA = 0x25FB40
    bool canCastToRootObject() const;// public RVA = 0x333EF0
    bool squadMatch(const hand& h) const;// public RVA = 0x333020
    static const hand NULL_HAND; // Static Member
};