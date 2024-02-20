#pragma once

#include "../Enums.h"

#include <stdafx.h>
#include <string>

class RootObject;
class RootObjectBase;
class GameData;
class Platoon;
class ActivePlatoon;
class Item;
class TownBase;
class Building;
class Character;

class hand
{
public:
    // VTable         : (none)
    hand(GameData* fromLoadedState, itemType typ);// public RVA = 0x60DA20
    void _CONSTRUCTOR(GameData* fromLoadedState, itemType typ);// public RVA = 0x60DA20
    hand(RootObjectBase* from);// public RVA = 0x60ABC0
    void _CONSTRUCTOR(RootObjectBase* from);// public RVA = 0x60ABC0
    hand(const int from);// public RVA = 0x94660
    void _CONSTRUCTOR(const int from);// public RVA = 0x94660
    hand(const hand& from);// public RVA = 0x90ED0
    void _CONSTRUCTOR(const hand& from);// public RVA = 0x90ED0
    hand(unsigned int _index, unsigned int _serial, itemType _type, unsigned int _container, unsigned int _containerSerial);// public RVA = 0x8D230
    void _CONSTRUCTOR(unsigned int _index, unsigned int _serial, itemType _type, unsigned int _container, unsigned int _containerSerial);// public RVA = 0x8D230
    hand();// public RVA = 0x8D210 no arg names
    void _CONSTRUCTOR();// public RVA = 0x8D210 no arg names
    itemType type; // 0x8 Member
    unsigned int container; // 0xC Member
    unsigned int containerSerial; // 0x10 Member
    unsigned int index; // 0x14 Member
    unsigned int serial; // 0x18 Member
    std::string toString() const;// public RVA = 0x7C71A0 no arg names
    void fromString(const std::string& str);// public RVA = 0x7CA320
    virtual bool operator==(bool a) const;// public RVA = 0x8D2E0 vtable offset = 0x0
    bool operator==(const RootObjectBase* a) const;// public RVA = 0x46DE40
    virtual bool operator==(const hand& a) const;// public RVA = 0x8D260 vtable offset = 0x8
    bool operator!=(const RootObjectBase* a) const;// public RVA = 0x46DEE0
    virtual bool operator!=(const hand& a) const;// public RVA = 0x8D2A0 vtable offset = 0x10
    operator bool() const;// public RVA = 0x3BDE0 no arg names
    Character* getCharacter() const;// public RVA = 0x610690 no arg names
    Platoon* getPlatoon() const;// public RVA = 0x60AE90 no arg names
    ActivePlatoon* getActivePlatoon() const;// public RVA = 0x60AEC0 no arg names
    Building* getBuilding() const;// public RVA = 0x60AF10 no arg names
    Item* getItem() const;// public RVA = 0x60AF30 no arg names
    RootObject* getRootObject() const;// public RVA = 0x615A10 no arg names
    RootObjectBase* getRootObjectBase() const;// public RVA = 0x615A30 no arg names
    TownBase* getTown() const;// public RVA = 0x60AF80 no arg names
    std::string debugWhatHappenedToMe();// public RVA = 0x60D700 no arg names
    bool operator<(const hand& h) const;// public RVA = 0xAED00
    hand& operator=(const hand& __that);// public RVA = 0x8D300
    const hand& operator=(RootObjectBase* a);// public RVA = 0x60AC10
    const hand& operator=(const int& a);// public RVA = 0x1E73F0
    void setNull();// public RVA = 0xEC640 no arg names
    bool isNull() const;// public RVA = 0x2ABB30 no arg names
    bool isValid() const;// public RVA = 0x1D2D60 no arg names
    bool canCastToRootObject() const;// public RVA = 0x27F310 no arg names
    bool squadMatch(const hand& h) const;// public RVA = 0x27E6B0
    static const hand NULL_HAND; // Static Member
};
