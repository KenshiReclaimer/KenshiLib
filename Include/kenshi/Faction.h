#pragma once

#include "TimeOfDay.h"
#include "util/lektor.h"
#include "util/hand.h"
#include "FitnessSelector.h"

#include "util/OgreUnordered.h"

class GameData;
class GameDataContainer;
class Platoon;
class Building;
class RootObject;
class ActivePlatoon;
class TownBase;
class DatapanelGUI;
class Character;
class Town;
class UniquePlatoon;
class CampaignTriggerData;
class CampaignInstance;
class CampaignData;
class AreaBiomeGroup;
class AIPlayer;
class PlayerInterface;
class Faction;

enum BuildingDesignation
{
    BD_NONE,
    BD_SHOP,
    BD_BARRACKS,
    BD_BAR,
    BD_HOSPITAL,
    BD_ARMOURY,
    BD_TREASURE,
    BD_PRISON,
    BD_HQ,
    BD_RESIDENTIAL,
    BD_SLAVE_STORAGE,
    BD_RESIDENTIAL_SMALL
};

enum UnloadedPlatoonJob
{
    UPJOB_NONE,
    UPJOB_PATROL_TOWN,
    UPJOB_PATROL_SHORTRANGE,
    UPJOB_PATROL_LONGRANGE,
    UPJOB_GOHOME,
    UPJOB_TRAVEL_TARGET,
    UPJOB_TRAVEL_TARGET_FAST
};

enum BuildingFunction
{
    BF_ANY,
    BF_MINE,
    BF_RESOURCE_STORAGE,
    BF_RESEARCH,
    BF_REFINERY,
    BF_GENERATOR,
    BF_BED,
    BF_TRAINING,
    BF_CAGE,
    BF_SHOP,
    BF_CRAFTING,
    BF_CORPSE_DISPOSAL,
    BF_TURRET,
    BF_GENERAL_STORAGE,
    BF_ITEM_FURNACE,
    BF_LIGHT,
    BF_TABLE,
    BF_CHAIR,
    BF_FLUFF,
    BF_SHELL_WITH_INTERIOR,
    BF_WALL,
    BF_GATE,
    BF_DOOR,
    BF_BATTERY,
    BF_THRONE,
    BF_SKELETON_BED,
    BF_RAIN_COLLECTOR,
    BF_MINE_NATURAL,
    BF_STEERING,
    BF_ENGINE,
    BF_LIQUID_TANK
};

enum SquadType
{
    SQ_UNKNOWN,
    SQ_RESIDENT,
    SQ_ROAMING
};
    
// TODO move?
class FactionLeader
{
public:
    // no_addr void FactionLeader(const class FactionLeader &);// public
    FactionLeader(Faction* f);// public RVA = 0x66A2F0
    void setNewLeader(Character*);// public RVA = 0x7BD7D0
    void getEnemyMissionTargetList(lektor<RootObject*>& out, GameData* mission);// public RVA = 0x7BA9C0
    void getGUIData(DatapanelGUI*, int cat);// public RVA = 0x238FD0
    Faction* faction; // 0x0 Member
    lektor<GameData*> biomeTerritory; // 0x8 Member
    Faction* worstEnemy; // 0x20 Member
    ~FactionLeader();// public RVA = 0x66A370
    // no_addr class FactionLeader & operator=(const class FactionLeader &);// public
    // no_addr void * __vecDelDtor(unsigned int);// public
};

// TODO move?
class ProsperityManager
{
public:
    double actualProsperity; // 0x0 Member
    float maxProsperity; // 0x8 Member
    ProsperityManager();// public RVA = 0x238F50
    void setup(GameData* faction);// public RVA = 0x23BAE0
    void load(GameData* state);// public RVA = 0x23B960
    void save(GameData* state);// public RVA = 0x23BB90
    float getProsperityMultiplier() const;// public RVA = 0x238F70
    void getGUIData(DatapanelGUI* panel, int cat);// public RVA = 0x23A5E0
    void update(float time);// public RVA = 0x238F80
    void notifySquadDefeated(GameData* squadTemplate);// public RVA = 0x55B290
    void notifySpecialNPCDead(GameData* npc);// public RVA = 0x62F570
};

// TODO move?
class FactionUniqueSquadManager
{
public:
    // VTable         : (none)
    // no_addr void FactionUniqueSquadManager(const class FactionUniqueSquadManager &);// public
    FactionUniqueSquadManager();// private RVA = 0x23B1B0
    virtual ~FactionUniqueSquadManager();// private RVA = 0x23BC30 vtable offset = 0x0
    void clearAndReset();// private RVA = 0x23A870
    void initialiseNew(Faction* faction, GameData* mdat, Town* t);// private RVA = 0x239720
    GameData* chooseRandomSquadToSpawn(float time);// public RVA = 0x239090
    void periodicUpdate(float time);// public RVA = 0x239110
    void serialise(GameData* state);// public RVA = 0x23A930
    void load(GameData* state, bool import);// public RVA = 0x23AB50
    void getGUIData(DatapanelGUI* panel, int cat);// public RVA = 0x23AE30
    void endOfUniqueSquad(UniquePlatoon* who);// public RVA = 0x23A440
    ProsperityManager prosperityMgr; // 0x8 Member
    Faction* me; // 0x18 Member
    GameData* squadListData; // 0x20 Member
    Town* homeTown; // 0x28 Member
    class UniqueSpawnData
    {
    public:
        // no_addr void UniqueSpawnData(const class FactionUniqueSquadManager::UniqueSpawnData &);// public
        UniqueSpawnData(GameData* d, int num);// public RVA = 0x23B8E0
        GameData* squadTemplate; // 0x0 Member
        int desiredNumberToHave; // 0x8 Member
        float respawnTimer; // 0xC Member
        int currentNumber() const;// public RVA = 0x23B630
        lektor<hand> existingSquadsList; // 0x10 Member
        ~UniqueSpawnData();// public RVA = 0x23B680
        // no_addr class FactionUniqueSquadManager::UniqueSpawnData & operator=(const class FactionUniqueSquadManager::UniqueSpawnData &);// public
        // no_addr void * __vecDelDtor(unsigned int);// public
    };
    lektor<FactionUniqueSquadManager::UniqueSpawnData*> squads; // 0x30 Member
    FactionUniqueSquadManager::UniqueSpawnData* getExistingSquadsFor(GameData* squad);// private RVA = 0x23B640
    UniquePlatoon* spawnNewUniqueSquad(GameData* squadtemplate);// private RVA = 0x2390F0
    // no_addr class FactionUniqueSquadManager & operator=(const class FactionUniqueSquadManager &);// public
    // no_addr void __local_vftable_ctor_closure();// public
    //virtual void * __vecDelDtor(unsigned int) = 0;// private vtable offset = 0x0
};

// TODO move?
class FactionRelations
{
public:
    // VTable         : (none)
    Faction* me; // 0x8 Member
    // no_addr void FactionRelations(const class FactionRelations &);// public
    FactionRelations();// public RVA = 0x672BA0
    void setupPhase1(Faction* f);// public RVA = 0x556F50
    void setupPhase2();// public RVA = 0x5570A0
    bool isEnemyByDefault() const;// public RVA = 0x358D70
    void reset();// public RVA = 0x672AA0
    virtual void save(GameData* factionsList);// public RVA = 0x556780 vtable offset = 0x0
    virtual void load(GameData* gamestate_faction, bool playerOnly);// public RVA = 0x557D90 vtable offset = 0x8
    virtual void update();// public RVA = 0x5557A0 vtable offset = 0x10
    bool _isAlly(Faction* c);// public RVA = 0x555780
    bool _isEnemy(Faction* c);// public RVA = 0x5555A0
    bool isEnemy(Faction* c);// public RVA = 0x5556A0
    virtual void setEnemy(Faction* c);// public RVA = 0x556160 vtable offset = 0x18
    bool isAlly(Faction* c);// public RVA = 0x555600
    bool isCoexisting(Faction* c);// public RVA = 0x555390
    float getFactionRelation(Faction* p);// public RVA = 0x5553D0
    float getFactionRelationMultiplier(Faction* p);// public RVA = 0x555430
    float getFactionRelationMultiplierInverse(Faction* p);// public RVA = 0x555490
    void setRelation(Faction* who, float setTo);// public RVA = 0x557D50
    enum FactionEvent
    {
        ATTACKED_US_DEFENSIVELY,
        ATTACKED_US_AGGRESSIVELY,
        DEFEATED_ONE_OF_US_DEFENSIVELY,
        DEFEATED_ONE_OF_US_AGGRESSIVELY,
        KILLED_ONE_OF_US_DIRECTLY,
        KILLED_ONE_OF_US_INDIRECTLY,
        EXECUTED_ONE_OF_US,
        AIDED_US_IN_BATTLE,
        FIRST_AIDED_US,
        TAKEN_TO_BED,
        DEFEATED_AN_ENEMY,
        KILLED_AN_ENEMY,
        CAPTURED_US
    };

    virtual void affectRelations(Faction* p, float amount, float mult);// public RVA = 0x555E70 vtable offset = 0x20
    virtual void affectRelations(Faction* p, FactionRelations::FactionEvent e, float mult);// public RVA = 0x555CF0 vtable offset = 0x28
    virtual void affectTrust(Faction* p, float amount, float mult);// public RVA = 0x555530 vtable offset = 0x30
    virtual void setNoLongerEnemies(Faction* p);// public RVA = 0x555F60 vtable offset = 0x38
    virtual void declareWar(Faction* p);// public RVA = 0x555FD0 vtable offset = 0x40
    virtual void affectReputation(Faction* p, float amount);// public RVA = 0x555500 vtable offset = 0x48
    int playerRank; // 0x10 Member
    class RelationData
    {
    public:
        // no_addr void RelationData(const class FactionRelations::RelationData &);// public
        RelationData(float rel, bool ally);// public RVA = 0x55A770
        RelationData();// public RVA = 0x55A740
        void save(GameData* factionsList, const std::string& ID, Faction* who);// public RVA = 0x5562D0
        void load(GameData* gamestate_faction, const std::string& ID, Faction* who);// public RVA = 0x5568A0
        bool alliance; // 0x0 Member
        bool peaceTreaty; // 0x1 Member
        bool war; // 0x2 Member
        bool coexists; // 0x3 Member
        float relation; // 0x4 Member
        float trustPositives; // 0x8 Member
        float trustNegatives; // 0xC Member
        // no_addr float getTrust();// public
        float percievedStrength; // 0x10 Member
        // no_addr void setStateVar(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, int);// public
        // no_addr int getStateVar(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);// public
        std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > > stateVariables; // 0x18 Member
        ~RelationData();// public RVA = 0x55A5D0
        FactionRelations::RelationData& operator=(const FactionRelations::RelationData& __that);// public RVA = 0x55A9D0
        // no_addr void * __vecDelDtor(unsigned int);// public
    };
    float globalReputationTrust; // 0x14 Member
    float globalReputationForBadassery; // 0x18 Member
    virtual FactionRelations::RelationData* getRelationData(Faction* p);// public RVA = 0x557C30 vtable offset = 0x50
    void getGUIData(DatapanelGUI* panel, int category);// public RVA = 0x65A620
    void getRelationsData(ogre_unordered_map<Faction*, float>::type& data);// public RVA = 0x555800
    // no_addr void setStateVar(class Faction *, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, int);// public
    // no_addr int getStateVar(class Faction *, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);// public
    bool checkStateCondition(DialogConditionEnum conditionName, ComparisonEnum compareBy, int val, Faction* yourFaction);// public RVA = 0x520FF0
    ogre_unordered_map<Faction*, FactionRelations::RelationData>::type _factionRelations; // 0x20 Member
    float defaultFactionRelation; // 0x60 Member
    ~FactionRelations();// public RVA = 0x672C00
    // no_addr class FactionRelations & operator=(const class FactionRelations &);// public
    // no_addr void * __vecDelDtor(unsigned int);// public
};

// TODO move?
class Ownerships
{
public:
    // VTable         : (none)
    // no_addr void Ownerships(const class Ownerships &);// public
    Ownerships(Faction * f, Platoon * p);// public RVA = 0x638DC0
    void setHandle(Platoon * h);// public RVA = 0x653100
    void addOwnedObject(const hand & what);// public RVA = 0x653FB0
    void removeOwnedObject(const hand & what);// public RVA = 0x6535A0
    bool isOwned(const hand & what);// public RVA = 0x6536A0
    virtual bool takeMoney(int val);// public RVA = 0x638E70 vtable offset = 0x0
    virtual void takeMoneyByForce(int val);// public RVA = 0x638E60 vtable offset = 0x8
    int getMoney();// public RVA = 0x2BAAC0
    void addMoney(int amount);// public RVA = 0x27A1C0
    void setMoney(int amount);// public RVA = 0x2BAAD0
    void setHomeBuildingDesignation(BuildingDesignation d);// public RVA = 0x60AB70
    void copyFrom(Ownerships * other);// public RVA = 0x633960
    std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > slaves; // 0x8 Member
    void serialise(GameData * state);// public RVA = 0x4E3170
    void load(GameData * state, SquadType st);// public RVA = 0x4E3690
    TownBase* _homeTown; // 0x30 Member
    hand _homeBuilding; // 0x38 Member
    void setHomeTown(TownBase * t, SquadType squadtype);// public RVA = 0x653D80
    void setHomeBuilding(const hand & h, SquadType t);// public RVA = 0x653E90
    void getOwnedBuildingsH(lektor<hand> &out);// public RVA = 0x482640
    void getOwnedBuildingPtrs(lektor<Building*> &out, TownBase * town);// public RVA = 0x60CA20
    // no_addr int getOwnedBuildingPtrs(class lektor<Building *> &);// public
    void getHomeFurnitureOfType(lektor<Building*> &out, BuildingFunction type);// public RVA = 0x60B8F0
    int getOwnedPtrs(lektor<RootObject*> &out, itemType type);// public RVA = 0x7BA2C0
    void getBuildingsWithFunction(lektor<Building*> &out, BuildingFunction bf);// public RVA = 0x4E0630
    bool isMyTown(TownBase * t);// public RVA = 0x4E0230
    bool canIUseThisBuilding(Building * b, Character * _me);// public RVA = 0x4E0280
    void declareOccupiedTown(TownBase * t);// public RVA = 0x1F29D0
    Faction* getOccupiedTownFaction();// public RVA = 0x4E03E0
    lektor<hand> stuff; // 0x58 Member
    Faction* faction; // 0x70 Member
    Platoon* me; // 0x78 Member
    TownBase* occupiedTown; // 0x80 Member
    int money; // 0x88 Member
    ~Ownerships();// public RVA = 0x6381C0
    // no_addr class Ownerships & operator=(const class Ownerships &);// public
    // no_addr void * __vecDelDtor(unsigned int);// public
};

// TODO move?
class FactionWarMgr : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::GeneralAllocatedObject offset = 0x0, length = 0x1
    // no_addr void FactionWarMgr(const class FactionWarMgr &);// public
    FactionWarMgr(Faction* f);// public RVA = 0x670740
    ~FactionWarMgr();// public RVA = 0x671C10
    Faction* me; // 0x0 Member
    int lastID; // 0x8 Member
    void reset();// public RVA = 0x7D21D0
    void save(GameData* s);// public RVA = 0x7D4AD0
    void load(GameData* s);// public RVA = 0x7D8000
    void removePlatoon(Platoon* p);// public RVA = 0x55D310
    void addPlatoon(Platoon* p);// public RVA = 0x7D26B0
    void getGUIData(DatapanelGUI* panel, int cat, bool playeronly);// public RVA = 0x624FC0
    bool areAnyHostileCampaignsRunning(bool playeronly);// public RVA = 0x60B940
    void endCampaign(CampaignInstance* c);// public RVA = 0x7DDA30
    void getAllTheForces(RootObjectBase* target, CampaignInstance* c);// public RVA = 0x7D3280
    void _generateForcesForTown(TownBase* t, CampaignInstance* c);// public RVA = 0x7D2390
    bool canGenerateThisManyForces(int num);// public RVA = 0x7D20C0
    void periodicUpdate();// public RVA = 0x7D9550
    void debugButton();// public RVA = 0x7D1980
    CampaignInstance* triggerCampaign(RootObjectBase* targetTown, CampaignData* data, TownBase* home);// public RVA = 0x7D7A70
    void triggerCampaign(RootObjectBase* targetTown, GameData* _data, float minTime, float maxTime, TownBase* hometown, bool forceDuplicate, Faction* triggeringFaction);// public RVA = 0x7D7650
    void triggerCampaign(const FitnessSelector<CampaignTriggerData*>& randomTriggers, RootObjectBase* targetTown, TownBase* hometown, bool forceDuplicate, Faction* triggeringFaction);// public RVA = 0x7D9DE0
    CampaignInstance* getCurrentCampaign(Platoon* who);// public RVA = 0x1EFCE0
    // no_addr class GameData * getAIPackage(class Platoon *);// public
    hand getAITarget(Platoon* who);// public RVA = 0x1EFDD0
    UnloadedPlatoonJob getMyUnloadedAI(Platoon* who);// public RVA = 0x7D2D00
    lektor<TownBase*> myTowns; // 0x10 Member
    std::map<Platoon*, CampaignInstance*, std::less<Platoon*>, Ogre::STLAllocator<std::pair<Platoon* const, CampaignInstance*>, Ogre::GeneralAllocPolicy > > forces; // 0x28 Member
    lektor<hand> hiredForces; // 0x50 Member
    lektor<CampaignInstance*> activeCampaigns; // 0x68 Member
    lektor<AreaBiomeGroup*> biomeTerritories; // 0x80 Member
    lektor<AreaBiomeGroup*> biomeNoGoZones; // 0x98 Member
    bool isBiomeHomeTerritory(AreaBiomeGroup* area);// public RVA = 0x7D1D70
    TownBase* getNearestTown(const Ogre::Vector3& p);// public RVA = 0x7D1F10
    void getTownsInBiome(lektor<TownBase*>& out, AreaBiomeGroup* b);// public RVA = 0x7D1E70
    void getMyTownsWithEnoughFreePopulation(lektor<TownBase*>& out, int popNeeded);// public RVA = 0x7D2000
    CampaignInstance* getActiveCampaign(int uniqueID);// public RVA = 0x7D1DB0
    void setup();// private RVA = 0x7D8E10
    TimeOfDay nextUpdateTime; // 0xB0 Member
    class CampaignRequest
    {
    public:
        // no_addr void CampaignRequest(const class FactionWarMgr::CampaignRequest &);// public
        CampaignRequest();// public RVA = 0x7D1910
        TimeOfDay timeToStart; // 0x0 Member
        CampaignData* data; // 0x8 Member
        hand target; // 0x10 Member
        hand homeBase; // 0x30 Member
        Faction* enemy; // 0x50 Member
        int numAttempts; // 0x58 Member
        bool tryToChangeTarget();// public RVA = 0x7D2E30
        // no_addr class FactionWarMgr::CampaignRequest & operator=(const class FactionWarMgr::CampaignRequest &);// public
    };
    lektor<FactionWarMgr::CampaignRequest*> campaignRequests; // 0xB8 Member
    CampaignData* _createCampaignData(GameData* dat);// private RVA = 0x7D74C0
    lektor<CampaignData*> possibleCampaigns; // 0xD0 Member
    // no_addr class FactionWarMgr & operator=(const class FactionWarMgr &);// public
    // no_addr void * __vecDelDtor(unsigned int);// public
};

// TODO move?
class TradeCulture
{
public:
    void reset();// public RVA = 0x76C0C0
    void setupTradeCulture(GameData * dat);// public RVA = 0x663AA0
    lektor<GameData *> forbiddenItems; // 0x0 Member
    std::set<GameData *,std::less<GameData *>,Ogre::STLAllocator<GameData *,Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > illegalBuildings; // 0x18 Member
    std::set<GameData *,std::less<GameData *>,Ogre::STLAllocator<GameData *,Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > happyBuildings; // 0x40 Member
    std::set<GameData *,std::less<GameData *>,Ogre::STLAllocator<GameData *,Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > illegalItems; // 0x68 Member
    std::map<GameData *,float,std::less<GameData *>,Ogre::STLAllocator<std::pair<GameData * const,float>,Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > tradeGoodsMults; // 0x90 Member
    const lektor<GameData *> & getForbiddenItemsList();// public RVA = 0x77F280
    bool isItemIllegal(GameData * item);// public RVA = 0x5ABDF0
    const std::set<GameData *,std::less<GameData *>,Ogre::STLAllocator<GameData *,Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > * getAllIllegalItems();// public RVA = 0x520D70
    float getTradePriceMultiplier(GameData * item);// public RVA = 0x76FDC0
    bool hasTradePriceMultiplier(GameData * item);// public RVA = 0x76D580
    // no_addr void TradeCulture(const class TradeCulture &);// public
    TradeCulture();// public RVA = 0x670900
    ~TradeCulture();// public RVA = 0x670990
    // no_addr class TradeCulture & operator=(const class TradeCulture &);// public
    // no_addr void * __vecDelDtor(unsigned int);// public
};

class Faction : public Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    class BuildingSwaps
    {
    public:
        // no_addr void BuildingSwaps(const class Faction::BuildingSwaps &);// public
        BuildingSwaps(GameData* data);// public RVA = 0x663220
        BuildingSwaps();// public RVA = 0x65AFA0
        bool hasReplacement(GameData* building);// public RVA = 0x65A3C0
        GameData* getReplacement(GameData* building);// public RVA = 0x659BA0
        boost::unordered::unordered_set<GameData*, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<GameData*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > toReplace; // 0x0 Member
        FitnessSelector<GameData*> replaceWith; // 0x40 Member
        ~BuildingSwaps();// public RVA = 0x6711B0
        Faction::BuildingSwaps& operator=(const Faction::BuildingSwaps& __that);// public RVA = 0x671BC0
        // no_addr void * __vecDelDtor(unsigned int);// public
    };
    bool _antiSlavery; // 0x8 Member
    struct CharacteristicsData
    {
        float fleeRatio_squadSize; // 0x0 Member
        float fleeRatio_relativeEnemy; // 0x4 Member
    };
    Faction::CharacteristicsData characteristicsData; // 0xC Member
    // no_addr void Faction(const class Faction &);// public
    Faction(const std::string& _name);// public RVA = 0x668160
    ~Faction();// public RVA = 0x6683E0
    lektor<std::string > ranks; // 0x18 Member
    bool allowSlavesWeapons; // 0x30 Member
    CharacterTypeEnum fundamentalNPCType; // 0x34 Member
    CharacterTypeEnum getFundamentalNPCType();// public RVA = 0x1F5810
    float getProsperityMultiplier();// public RVA = 0x238FC0
    void clearAndDestroy();// public RVA = 0x667510
    bool setup(GameData* _data);// public RVA = 0x664370
    bool setup2();// public RVA = 0x658850
    void setup3();// public RVA = 0x65B040
    std::string getNewPlatoonID();// public RVA = 0x659680
    void resetPlatoonID();// public RVA = 0x658830
    Platoon* createNewEmptyUnloadedPlatoon(GameData* squadTemplate, const Ogre::Vector3& pos, GameDataContainer* forcecharacterDatas, bool persistent);// public RVA = 0x65A3F0
    Platoon* createNewEmptyActivePlatoon(GameData* squadTemplate, bool permanent, const Ogre::Vector3& p);// public RVA = 0x65A520
    void createPlatoonUnloaded(GameData* platoonstate, GameDataContainer* charactersState, GameData* squadTemplate, const Ogre::Vector3& pos, bool persistent);// public RVA = 0x659180
    void createPlatoonAuto(GameData* platoonstate, GameData* squadTemplate, const Ogre::Vector3& pos);// public RVA = 0x65E6F0
    void createPlatoonsAuto(lektor<GameData*>& platoons);// public RVA = 0x65E9C0
    void createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(const std::string& src);// public RVA = 0x659BB0
    void restorePlatoon(Platoon* p);// public RVA = 0x55C7E0
    bool resetSquadPositions(const Ogre::Vector3& target);// public RVA = 0x2ABDA0
    int countPopulation(TownBase* t);// public RVA = 0x55B8E0
    int countNumSquads(GameData* squadTemplate, TownBase* squadHome);// public RVA = 0x55B9C0
    void destroyPlatoon(Platoon* platoon);// public RVA = 0x55C4C0
    void removePlatoon(Platoon* platoon);// public RVA = 0x55B5C0
    int getRandomLockLevel(GameData* objData);// public RVA = 0x206820
    GameData* getData();// public RVA = 0x43430
    void getGUIData(DatapanelGUI* panel, int category);// public RVA = 0x65AC00
    GameData* getDefaultDivision();// public RVA = 0x65B100
    GameData* getFactionColorScheme();// public RVA = 0x65B300
    void loadState(GameDataContainer* saveSource, GameData* gamestate_faction);// public RVA = 0x2AFD10
    GameData* saveState(GameDataContainer* container, bool leveleditor);// public RVA = 0x2B3490
    void _activateUnloadedPlatoons();// public RVA = 0x55B6A0
    virtual void getCharactersInArea(lektor<RootObject*>& out, const Ogre::Vector3& pos, float radius, bool standingOnly);// public RVA = 0x55C310 vtable offset = 0x0
    virtual void getSelectedObjects(lektor<RootObject*>& out, itemType type, bool selectedOnly);// public RVA = 0x55BBB0 vtable offset = 0x8
    virtual void removeObject(RootObject* c);// public RVA = 0x55B340 vtable offset = 0x10
    virtual void destroyObject(RootObject* c);// public RVA = 0x55B330 vtable offset = 0x18
    virtual void processKillList();// public RVA = 0x55B530 vtable offset = 0x20
    virtual bool addActiveObject(RootObject* c, ActivePlatoon* p);// public RVA = 0x55C410 vtable offset = 0x28
    ActivePlatoon* choosePlatoon();// public RVA = 0x55B750
    const lektor<Platoon*>* getActivePlatoons();// public RVA = 0x240E50
    const lektor<Platoon*>* getUnloadedPlatoons();// public RVA = 0x2BAAB0
    int getFactionSize();// public RVA = 0x658F10
    void update(float time);// public RVA = 0x55C7F0
    bool periodicUpdateThreaded();// public RVA = 0x55B3C0
    bool periodicUpdateMT();// public RVA = 0x55B2B0
    bool isThePlayer();// public RVA = 0x94710
    bool isNotARealFaction();// public RVA = 0x108A60
    // no_addr void levelEditorMode(bool);// public
    const std::string& getName();// public RVA = 0x1F29E0
    // no_addr class AIPlayer * getAI();// public
    int getNumPlatoons(GameData* squadTemplate, bool tempsOnly, TownBase* hometown);// public RVA = 0x55B800
    Platoon* getSquadThatOwns(Building* what);// public RVA = 0x55B390
    void getAllSquadsThatOwn(lektor<Platoon*>& out, Building* what);// public RVA = 0x55C060
    const lektor<Platoon*>* getAllActiveSquads();// public RVA = 0x520D80
    float getRoadPreference();// public RVA = 0x5168D0
    bool isAntiSlavery();// public RVA = 0x282920
    Faction* myLawEnforcementFaction; // 0x38 Member
    bool isALawEnforcementFaction; // 0x40 Member
    Faction* getLawEnforcementFaction();// public RVA = 0x6A59B0
    FactionLeader factionLeader; // 0x48 Member
    FactionUniqueSquadManager* diplomatMgr; // 0x70 Member
    FactionRelations* relations; // 0x78 Member
    Ownerships* factionOwnerships; // 0x80 Member
    GameData* chooseARace(GameData* character, GameData* squadTemplate);// public RVA = 0x6652A0
    void setName(const std::string& _name);// public RVA = 0x2C1300
    GameData* getBuildingReplacement(GameData* building);// public RVA = 0x65A870
    FactionWarMgr* warMgr; // 0x88 Member
    TradeCulture tradeCulture; // 0x90 Member
    void _switchToUnloadedPlatoon(ActivePlatoon* platoon);// public RVA = 0x55B2F0
    FitnessSelector<GameData*> raceSelector; // 0x148 Member
    Platoon* _newPlatoon(Faction* f, GameData* squadTemplate, GameData* platoonState, const Ogre::Vector3& pos, bool persistent);// protected RVA = 0x45A960
    void _addActivePlatoonToList(Platoon* platoon);// protected RVA = 0x659210
    void addPlatoon(Platoon* platoon);// protected RVA = 0x659400
    void changePlatoonIndex(Platoon* platoon, int index);// protected RVA = 0x659540
    void deactivatePlatoon(Platoon* p);// protected RVA = 0x659340
    void activatePlatoon(Platoon* p);// protected RVA = 0x6596D0
    void updateUnloadedPlatoons(float time);// protected RVA = 0x55B460
    void updateActivePlatoons(float time);// protected RVA = 0x55C650
    void spawnSquadMissionsUpdate();// protected RVA = 0x238FB0
    bool _spawnASquad(const std::string& listname, float sizeMultiplier);// protected RVA = 0x2394F0
    std::string name; // 0x1A8 Member
    bool notARealFaction; // 0x1D0 Member
    float roadPreference; // 0x1D4 Member
    lektor<Platoon*> platoonKillList; // 0x1D8 Member
    lektor<Platoon*> platoonRemoveList; // 0x1F0 Member
    lektor<Platoon*> activePlatoons; // 0x208 Member
    lektor<Platoon*> unloadedPlatoons; // 0x220 Member
    int periodicUpdateCounter_active; // 0x238 Member
    int periodicUpdateCounter_unloaded; // 0x23C Member
    GameData* data; // 0x240 Member
    AIPlayer* isAI; // 0x248 Member
    PlayerInterface* isPlayer; // 0x250 Member
    int spawnTimeStamp; // 0x258 Member
    int diplomatTimeStamp; // 0x25C Member
    int platoonIDs; // 0x260 Member
    float p_TIME; // 0x264 Member
    int platoonPeriodicUpdateIndex; // 0x268 Member
    lektor<Faction::BuildingSwaps> buildingSwaps; // 0x270 Member
    // no_addr class Faction & operator=(const class Faction &);// public
    // no_addr void * __vecDelDtor(unsigned int);// public
};
