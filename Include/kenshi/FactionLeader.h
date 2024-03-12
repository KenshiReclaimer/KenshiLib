#pragma once

#include <kenshi/util/lektor.h>

class Faction;
class Character;
class RootObject;
class DatapanelGUI;
class GameData;

class FactionLeader
{
public:
    // no_addr void FactionLeader(const class FactionLeader & _a1);// public missing arg names
    FactionLeader(Faction * f);// public RVA = 0x807410
    void _CONSTRUCTOR(Faction * f);// public RVA = 0x807410
    void setNewLeader(Character * _a1);// public RVA = 0x9A8A10 missing arg names
    void getEnemyMissionTargetList(lektor<RootObject *> & out, GameData * mission);// public RVA = 0x9A5C00
    void getGUIData(DatapanelGUI * _a1, int cat);// public RVA = 0x2DD090
    Faction * faction; // 0x0 Member
    lektor<GameData *> biomeTerritory; // 0x8 Member
    Faction * worstEnemy; // 0x20 Member
    ~FactionLeader();// public RVA = 0x8074B0
    void _DESTRUCTOR();// public RVA = 0x8074B0
    // no_addr class FactionLeader & operator=(const class FactionLeader & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};
