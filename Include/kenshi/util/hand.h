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
    // void __fastcall hand::hand(hand *this, GameData *fromLoadedState, itemType typ)
    hand(GameData* fromLoadedState, itemType typ);// RVA = 0x60DA20
    hand(RootObjectBase* from);// RVA = 0x60ABC0
    hand(int from);// RVA = 0x94660
    hand(const hand& from);// RVA = 0x90ED0
    // void __fastcall hand::hand(hand *this, unsigned int _index, unsigned int _serial, itemType _type, unsigned int _container, unsigned int _containerSerial)
    hand(unsigned int _index, unsigned int _serial, itemType _type, unsigned int _container, unsigned int _containerSerial);// RVA = 0x8D230
    hand();// RVA = 0x8D210
    itemType type; // 0x8 Member
    unsigned int container; // 0xC Member
    unsigned int containerSerial; // 0x10 Member
    unsigned int index; // 0x14 Member
    unsigned int serial; // 0x18 Member
    std::string toString();// RVA = 0x7C71A0
    void fromString(const std::string& str);// RVA = 0x7CA320
    virtual bool operator==(bool a);// RVA = 0x8D2E0// vtable offset = 0x0
    bool operator==(const RootObjectBase* a);// RVA = 0x46DE40
    virtual bool operator==(const hand& a);// RVA = 0x8D260// vtable offset = 0x8
    bool operator!=(const RootObjectBase* a);// RVA = 0x46DEE0
    virtual bool operator!=(const hand& a);// RVA = 0x8D2A0// vtable offset = 0x10
    //bool operator bool();// RVA = 0x3BDE0
    Character* getCharacter();// RVA = 0x610690
    Platoon* getPlatoon();// RVA = 0x60AE90
    ActivePlatoon* getActivePlatoon();// RVA = 0x60AEC0
    Building* getBuilding();// RVA = 0x60AF10
    Item* getItem();// RVA = 0x60AF30
    RootObject* getRootObject();// RVA = 0x615A10
    RootObjectBase* getRootObjectBase();// RVA = 0x615A30
    TownBase* getTown();// RVA = 0x60AF80
    std::string debugWhatHappenedToMe();// RVA = 0x60D700
    bool operator<(const hand&);// RVA = 0xAED00
    hand& operator=(const hand&);// RVA = 0x8D300
    const hand& operator=(RootObjectBase*);// RVA = 0x60AC10
    const hand& operator=(const int&);// RVA = 0x1E73F0
    void setNull();// RVA = 0xEC640
    bool isNull();// RVA = 0x2ABB30
    bool isValid();// RVA = 0x1D2D60
    bool canCastToRootObject();// RVA = 0x27F310
    bool squadMatch(const hand&);// RVA = 0x27E6B0
    static const hand NULL_HAND; // Static Member
};
