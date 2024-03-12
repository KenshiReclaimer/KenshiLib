#pragma once

#include <string>

class GameData;

class GameplayOptions
{
public:
    GameplayOptions();// public RVA = 0x2BAB50
    void _CONSTRUCTOR();// public RVA = 0x2BAB50
    void reset();// public RVA = 0x310D00
    float deathFrequency; // 0x0 Member
    bool easyProspecting; // 0x4 Member
    float globalDamageMultiplier; // 0x8 Member
    float buildingSpeed; // 0xC Member
    float numNestsMult; // 0x10 Member
    float researchSpeed; // 0x14 Member
    float productionSpeed; // 0x18 Member
    float hungerTime; // 0x1C Member
    bool banditsLootPlayer; // 0x20 Member
    bool animalsEat; // 0x21 Member
    bool difficultHealing; // 0x22 Member
    float getStarvationTimeInHours();// public RVA = 0x310D50
    void save(GameData* data);// public RVA = 0x318040
    void load(GameData* data);// public RVA = 0x318650
};

struct SaveInfo
{
    std::string version; // 0x0 Member
    std::string name; // 0x28 Member
    std::string area; // 0x50 Member
    __int64 time; // 0x78 Member
    std::string faction; // 0x80 Member
    int money; // 0xA8 Member
    int size; // 0xAC Member
    int days; // 0xB0 Member
    std::string location; // 0xB8 Member
    GameplayOptions advanced; // 0xE0 Member
    SaveInfo(const SaveInfo & __that);// public RVA = 0x487EE0
    void _CONSTRUCTOR(const SaveInfo & __that);// public RVA = 0x487EE0
    SaveInfo();// public RVA = 0x3824A0
    void _CONSTRUCTOR();// public RVA = 0x3824A0
    ~SaveInfo();// public RVA = 0x382550
    void _DESTRUCTOR();// public RVA = 0x382550
    SaveInfo & operator=(const SaveInfo & __that);// public RVA = 0x488AC0
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};
