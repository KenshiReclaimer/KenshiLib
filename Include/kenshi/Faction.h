#pragma once

#include "TimeOfDay.h"
#include "util/lektor.h"
#include "util/hand.h"

#include <ogre/OgreMemoryAllocatedObject.h>
#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>

namespace Kenshi 
{
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
    enum CharacterTypeEnum {}; // TODO
    enum DialogConditionEnum {}; // TODO
    enum ComparisonEnum {}; // TODO
    enum BuildingDesignation {}; // TODO
    enum UnloadedPlatoonJob {}; // TODO
    enum BuildingFunction {}; // TODO
    enum SquadType {}; // TODO
    
    // TODO move?
    class FactionLeader
    {
    public:
        // no_addr public void FactionLeader(const class FactionLeader &);
        FactionLeader(Faction*);// RVA = 0x66A2F0
        void setNewLeader(Character*);// RVA = 0x7BD7D0
        void getEnemyMissionTargetList(lektor<RootObject*>&, GameData*);// RVA = 0x7BA9C0
        void getGUIData(DatapanelGUI*, int);// RVA = 0x238FD0
        Faction* faction; // 0x0 Member
        lektor<GameData*> biomeTerritory; // 0x8 Member
        Faction* worstEnemy; // 0x20 Member
        ~FactionLeader();// RVA = 0x66A370
        // no_addr public class FactionLeader & operator=(const class FactionLeader &);
        // no_addr public void * __vecDelDtor(unsigned int);
    };

    // TODO move?
    class ProsperityManager
    {
    public:
        double actualProsperity; // 0x0 Member
        float maxProsperity; // 0x8 Member
        ProsperityManager();// RVA = 0x238F50
        void setup(GameData*);// RVA = 0x23BAE0
        void load(GameData*);// RVA = 0x23B960
        void save(GameData*);// RVA = 0x23BB90
        float getProsperityMultiplier();// RVA = 0x238F70
        void getGUIData(DatapanelGUI*, int);// RVA = 0x23A5E0
        void update(float);// RVA = 0x238F80
        void notifySquadDefeated(GameData*);// RVA = 0x55B290
        void notifySpecialNPCDead(GameData*);// RVA = 0x62F570
    };

    // TODO move?
    class FactionUniqueSquadManager
    {
        // VTable         : (none)
        // no_addr public void FactionUniqueSquadManager(const class FactionUniqueSquadManager &);
    public:
        FactionUniqueSquadManager();// RVA = 0x23B1B0
        virtual ~FactionUniqueSquadManager();// RVA = 0x23BC30// vtable offset = 0x0
        void clearAndReset();// RVA = 0x23A870
        void initialiseNew(Faction*, GameData*, Town*);// RVA = 0x239720
        GameData* chooseRandomSquadToSpawn(float);// RVA = 0x239090
        void periodicUpdate(float);// RVA = 0x239110
        void serialise(GameData*);// RVA = 0x23A930
        void load(GameData*, bool);// RVA = 0x23AB50
        void getGUIData(DatapanelGUI*, int);// RVA = 0x23AE30
        void endOfUniqueSquad(UniquePlatoon*);// RVA = 0x23A440
        ProsperityManager prosperityMgr; // 0x8 Member
        Faction* me; // 0x18 Member
        GameData* squadListData; // 0x20 Member
        Town* homeTown; // 0x28 Member
        class UniqueSpawnData
        {
        public:
            // no_addr public void UniqueSpawnData(const class FactionUniqueSquadManager::UniqueSpawnData &);
            UniqueSpawnData(GameData*, int);// RVA = 0x23B8E0
            GameData* squadTemplate; // 0x0 Member
            int desiredNumberToHave; // 0x8 Member
            float respawnTimer; // 0xC Member
            int currentNumber();// RVA = 0x23B630
            lektor<hand> existingSquadsList; // 0x10 Member
            ~UniqueSpawnData();// RVA = 0x23B680
            // no_addr public class FactionUniqueSquadManager::UniqueSpawnData & operator=(const class FactionUniqueSquadManager::UniqueSpawnData &);
            // no_addr public void * __vecDelDtor(unsigned int);
        };
        lektor<UniqueSpawnData*> squads; // 0x30 Member
        UniqueSpawnData* getExistingSquadsFor(GameData*);// RVA = 0x23B640
        UniquePlatoon* spawnNewUniqueSquad(GameData*);// RVA = 0x2390F0
        // no_addr public class FactionUniqueSquadManager & operator=(const class FactionUniqueSquadManager &);
        // no_addr public void __local_vftable_ctor_closure();
        // no_addr private virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };

    // TODO move?
    class FactionRelations
    {
    public:
        // VTable         : (none)
        Faction* me; // 0x8 Member
        // no_addr public void FactionRelations(const class FactionRelations &);
        FactionRelations();// RVA = 0x672BA0
        void setupPhase1(Faction*);// RVA = 0x556F50
        void setupPhase2();// RVA = 0x5570A0
        bool isEnemyByDefault();// RVA = 0x358D70
        void reset();// RVA = 0x672AA0
        virtual void save(GameData*);// RVA = 0x556780// vtable offset = 0x0
        virtual void load(GameData*, bool);// RVA = 0x557D90// vtable offset = 0x8
        virtual void update();// RVA = 0x5557A0// vtable offset = 0x10
        bool _isAlly(Faction*);// RVA = 0x555780
        bool _isEnemy(Faction*);// RVA = 0x5555A0
        bool isEnemy(Faction*);// RVA = 0x5556A0
        virtual void setEnemy(Faction*);// RVA = 0x556160// vtable offset = 0x18
        bool isAlly(Faction*);// RVA = 0x555600
        bool isCoexisting(Faction*);// RVA = 0x555390
        float getFactionRelation(Faction*);// RVA = 0x5553D0
        float getFactionRelationMultiplier(Faction*);// RVA = 0x555430
        float getFactionRelationMultiplierInverse(Faction*);// RVA = 0x555490
        void setRelation(Faction*, float);// RVA = 0x557D50
        enum FactionEvent
        {
            ATTACKED_US_DEFENSIVELY = 0x0,
            ATTACKED_US_AGGRESSIVELY = 0x1,
            DEFEATED_ONE_OF_US_DEFENSIVELY = 0x2,
            DEFEATED_ONE_OF_US_AGGRESSIVELY = 0x3,
            KILLED_ONE_OF_US_DIRECTLY = 0x4,
            KILLED_ONE_OF_US_INDIRECTLY = 0x5,
            EXECUTED_ONE_OF_US = 0x6,
            AIDED_US_IN_BATTLE = 0x7,
            FIRST_AIDED_US = 0x8,
            TAKEN_TO_BED = 0x9,
            DEFEATED_AN_ENEMY = 0xA,
            KILLED_AN_ENEMY = 0xB,
            CAPTURED_US = 0xC
        };

        virtual void affectRelations(Faction*, float, float);// RVA = 0x555E70// vtable offset = 0x20
        virtual void affectRelations(Faction*, FactionRelations::FactionEvent, float);// RVA = 0x555CF0// vtable offset = 0x28
        virtual void affectTrust(Faction*, float, float);// RVA = 0x555530// vtable offset = 0x30
        virtual void setNoLongerEnemies(Faction*);// RVA = 0x555F60// vtable offset = 0x38
        virtual void declareWar(Faction*);// RVA = 0x555FD0// vtable offset = 0x40
        virtual void affectReputation(Faction*, float);// RVA = 0x555500// vtable offset = 0x48
        int playerRank; // 0x10 Member
        class RelationData
        {
            // no_addr public void RelationData(const class FactionRelations::RelationData &);
        public:
            RelationData(float, bool);// RVA = 0x55A770
            RelationData();// RVA = 0x55A740
            void save(GameData*, const std::string&, Faction*);// RVA = 0x5562D0
            void load(GameData*, const std::string&, Faction*);// RVA = 0x5568A0
            bool alliance; // 0x0 Member
            bool peaceTreaty; // 0x1 Member
            bool war; // 0x2 Member
            bool coexists; // 0x3 Member
            float relation; // 0x4 Member
            float trustPositives; // 0x8 Member
            float trustNegatives; // 0xC Member
            // no_addr public float getTrust();
            float percievedStrength; // 0x10 Member
            // no_addr public void setStateVar(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, int);
            // no_addr public int getStateVar(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
            // TODO map type
            std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > stateVariables; // 0x18 Member
            ~RelationData();// RVA = 0x55A5D0
            FactionRelations::RelationData& operator=(const FactionRelations::RelationData&);// RVA = 0x55A9D0
            // no_addr public void * __vecDelDtor(unsigned int);
        };
        float globalReputationTrust; // 0x14 Member
        float globalReputationForBadassery; // 0x18 Member
        virtual FactionRelations::RelationData* getRelationData(Faction*);// RVA = 0x557C30// vtable offset = 0x50
        void getGUIData(DatapanelGUI*, int);// RVA = 0x65A620
        void getRelationsData(boost::unordered::unordered_map<Faction*, float, boost::hash<Faction*>, std::equal_to<Faction*>, Ogre::STLAllocator<std::pair<Faction* const, float>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x555800
        // no_addr public void setStateVar(class Faction *, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, int);
        // no_addr public int getStateVar(class Faction *, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
        bool checkStateCondition(DialogConditionEnum, ComparisonEnum, int, Faction*);// RVA = 0x520FF0
        // TODO map
        boost::unordered::unordered_map<Faction*, FactionRelations::RelationData, boost::hash<Faction*>, std::equal_to<Faction*>, Ogre::STLAllocator<std::pair<Faction* const, FactionRelations::RelationData>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > _factionRelations; // 0x20 Member
        float defaultFactionRelation; // 0x60 Member
        ~FactionRelations();// RVA = 0x672C00
        // no_addr public class FactionRelations & operator=(const class FactionRelations &);
        // no_addr public void * __vecDelDtor(unsigned int);
    };

    template<typename T>
    class FitnessSelector
    {
        // no_addr public void FitnessSelector<GameData *>(const class FitnessSelector<GameData *> &);
        // no_addr public void FitnessSelector<GameData *>();
        // no_addr public void reset();
        // no_addr public void deleteAll();
        // no_addr public int size();
        // no_addr public bool hasItem(class GameData * const);
        // no_addr public bool empty();
        // no_addr public float getItemScore(class GameData * const);
        // no_addr public void addItem(class GameData *, const float);
        // no_addr public bool removeItem(class GameData * const);
        // no_addr public class GameData * chooseAnItem(class boost::random::mersenne_twister_engine<unsigned int,32,624,397,31,2567483615,11,4294967295,7,2636928640,15,4022730752,18,1812433253> &);
        // no_addr public class GameData * chooseAnItem();
        // no_addr public class GameData * chooseAnItem_absoluteScore();
        // no_addr public class GameData * chooseHighest();
        // no_addr public class GameData * takeHighest();
        // no_addr public class GameData * takeRandom();
        // TODO figure out map template
        std::map<float, T, std::less<float>, Ogre::STLAllocator<std::pair<float const, T>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > list; // 0x0 Member
        std::map<T, float, std::less<T>, Ogre::STLAllocator<std::pair<GameData* const, float>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > itemsScores; // 0x28 Member
        float totalScore; // 0x50 Member
        float highestScore; // 0x54 Member
        GameData* highestItem; // 0x58 Member
        // no_addr public void ~FitnessSelector<GameData *>();
        // no_addr public class FitnessSelector<GameData *> & operator=(const class FitnessSelector<GameData *> &);
        // no_addr public void * __vecDelDtor(unsigned int);
    };

    // TODO move?
    class Ownerships
    {
    public:
        // VTable         : (none)
        // no_addr public void Ownerships(const class Ownerships &);
        Ownerships(Faction*, Platoon*);// RVA = 0x638DC0
        void setHandle(Platoon*);// RVA = 0x653100
        void addOwnedObject(const hand&);// RVA = 0x653FB0
        void removeOwnedObject(const hand&);// RVA = 0x6535A0
        bool isOwned(const hand&);// RVA = 0x6536A0
        virtual bool takeMoney(int);// RVA = 0x638E70// vtable offset = 0x0
        virtual void takeMoneyByForce(int);// RVA = 0x638E60// vtable offset = 0x8
        int getMoney();// RVA = 0x2BAAC0
        void addMoney(int);// RVA = 0x27A1C0
        void setMoney(int);// RVA = 0x2BAAD0
        void setHomeBuildingDesignation(BuildingDesignation);// RVA = 0x60AB70
        void copyFrom(Ownerships*);// RVA = 0x633960
        std::set<hand, std::less<hand>, Ogre::STLAllocator<hand, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > slaves; // 0x8 Member
        void serialise(GameData*);// RVA = 0x4E3170
        void load(GameData*, SquadType);// RVA = 0x4E3690
        TownBase* _homeTown; // 0x30 Member
        hand _homeBuilding; // 0x38 Member
        void setHomeTown(TownBase*, SquadType);// RVA = 0x653D80
        void setHomeBuilding(const hand&, SquadType);// RVA = 0x653E90
        void getOwnedBuildingsH(lektor<hand>&);// RVA = 0x482640
        void getOwnedBuildingPtrs(lektor<Building*>&, TownBase*);// RVA = 0x60CA20
        // no_addr public int getOwnedBuildingPtrs(class lektor<Building *> &);
        void getHomeFurnitureOfType(lektor<Building*>&, BuildingFunction);// RVA = 0x60B8F0
        int getOwnedPtrs(lektor<RootObject*>&, itemType);// RVA = 0x7BA2C0
        void getBuildingsWithFunction(lektor<Building*>&, BuildingFunction);// RVA = 0x4E0630
        bool isMyTown(TownBase*);// RVA = 0x4E0230
        bool canIUseThisBuilding(Building*, Character*);// RVA = 0x4E0280
        void declareOccupiedTown(TownBase*);// RVA = 0x1F29D0
        Faction* getOccupiedTownFaction();// RVA = 0x4E03E0
        lektor<hand> stuff; // 0x58 Member
        Faction* faction; // 0x70 Member
        Platoon* me; // 0x78 Member
        TownBase* occupiedTown; // 0x80 Member
        int money; // 0x88 Member
        ~Ownerships();// RVA = 0x6381C0
        // no_addr public class Ownerships & operator=(const class Ownerships &);
        // no_addr public void * __vecDelDtor(unsigned int);
    };

    // TODO move?
    class FactionWarMgr : Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
    {
    public:
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
        // no_addr public void FactionWarMgr(const class FactionWarMgr &);
        FactionWarMgr(Faction*);// RVA = 0x670740
        ~FactionWarMgr();// RVA = 0x671C10
        Faction* me; // 0x0 Member
        int lastID; // 0x8 Member
        void reset();// RVA = 0x7D21D0
        void save(GameData*);// RVA = 0x7D4AD0
        void load(GameData*);// RVA = 0x7D8000
        void removePlatoon(Platoon*);// RVA = 0x55D310
        void addPlatoon(Platoon*);// RVA = 0x7D26B0
        void getGUIData(DatapanelGUI*, int, bool);// RVA = 0x624FC0
        bool areAnyHostileCampaignsRunning(bool);// RVA = 0x60B940
        void endCampaign(CampaignInstance*);// RVA = 0x7DDA30
        void getAllTheForces(RootObjectBase*, CampaignInstance*);// RVA = 0x7D3280
        void _generateForcesForTown(TownBase*, CampaignInstance*);// RVA = 0x7D2390
        bool canGenerateThisManyForces(int);// RVA = 0x7D20C0
        void periodicUpdate();// RVA = 0x7D9550
        void debugButton();// RVA = 0x7D1980
        CampaignInstance* triggerCampaign(RootObjectBase*, CampaignData*, TownBase*);// RVA = 0x7D7A70
        void triggerCampaign(RootObjectBase*, GameData*, float, float, TownBase*, bool, Faction*);// RVA = 0x7D7650
        void triggerCampaign(const FitnessSelector<CampaignTriggerData*>&, RootObjectBase*, TownBase*, bool, Faction*);// RVA = 0x7D9DE0
        CampaignInstance* getCurrentCampaign(Platoon*);// RVA = 0x1EFCE0
        // no_addr public class GameData * getAIPackage(class Platoon *);
        hand getAITarget(Platoon*);// RVA = 0x1EFDD0
        UnloadedPlatoonJob getMyUnloadedAI(Platoon*);// RVA = 0x7D2D00
        lektor<TownBase*> myTowns; // 0x10 Member
        std::map<Platoon*, CampaignInstance*, std::less<Platoon*>, Ogre::STLAllocator<std::pair<Platoon* const, CampaignInstance*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > forces; // 0x28 Member
        lektor<hand> hiredForces; // 0x50 Member
        lektor<CampaignInstance*> activeCampaigns; // 0x68 Member
        lektor<AreaBiomeGroup*> biomeTerritories; // 0x80 Member
        lektor<AreaBiomeGroup*> biomeNoGoZones; // 0x98 Member
        bool isBiomeHomeTerritory(AreaBiomeGroup*);// RVA = 0x7D1D70
        TownBase* getNearestTown(const Ogre::Vector3&);// RVA = 0x7D1F10
        void getTownsInBiome(lektor<TownBase*>&, AreaBiomeGroup*);// RVA = 0x7D1E70
        void getMyTownsWithEnoughFreePopulation(lektor<TownBase*>&, int);// RVA = 0x7D2000
        CampaignInstance* getActiveCampaign(int);// RVA = 0x7D1DB0
        void setup();// RVA = 0x7D8E10
        TimeOfDay nextUpdateTime; // 0xB0 Member
        class CampaignRequest
        {
        public:
            // no_addr public void CampaignRequest(const class FactionWarMgr::CampaignRequest &);
            CampaignRequest();// RVA = 0x7D1910
            TimeOfDay timeToStart; // 0x0 Member
            CampaignData* data; // 0x8 Member
            hand target; // 0x10 Member
            hand homeBase; // 0x30 Member
            Faction* enemy; // 0x50 Member
            int numAttempts; // 0x58 Member
            bool tryToChangeTarget();// RVA = 0x7D2E30
            // no_addr public class FactionWarMgr::CampaignRequest & operator=(const class FactionWarMgr::CampaignRequest &);
        };
        lektor<FactionWarMgr::CampaignRequest*> campaignRequests; // 0xB8 Member
        CampaignData* _createCampaignData(GameData*);// RVA = 0x7D74C0
        lektor<CampaignData*> possibleCampaigns; // 0xD0 Member
        // no_addr public class FactionWarMgr & operator=(const class FactionWarMgr &);
        // no_addr public void * __vecDelDtor(unsigned int);
    };

    // TODO move?
    class TradeCulture
    {
    public:
        void reset();// RVA = 0x76C0C0
        void setupTradeCulture(GameData*);// RVA = 0x663AA0
        lektor<GameData*> forbiddenItems; // 0x0 Member
        // TODO sets + maps
        std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > illegalBuildings; // 0x18 Member
        std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > happyBuildings; // 0x40 Member
        std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > illegalItems; // 0x68 Member
        std::map<GameData*, float, std::less<GameData*>, Ogre::STLAllocator<std::pair<GameData* const, float>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > tradeGoodsMults; // 0x90 Member
        const lektor<GameData*>& getForbiddenItemsList();// RVA = 0x77F280
        bool isItemIllegal(GameData*);// RVA = 0x5ABDF0
        const std::set<GameData*, std::less<GameData*>, Ogre::STLAllocator<GameData*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >* getAllIllegalItems();// RVA = 0x520D70
        float getTradePriceMultiplier(GameData*);// RVA = 0x76FDC0
        bool hasTradePriceMultiplier(GameData*);// RVA = 0x76D580
        // no_addr public void TradeCulture(const class TradeCulture &);
        TradeCulture();// RVA = 0x670900
        ~TradeCulture();// RVA = 0x670990
        // no_addr public class TradeCulture & operator=(const class TradeCulture &);
        // no_addr public void * __vecDelDtor(unsigned int);
    };

    class Faction : Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
    {
    public:
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
        // VTable         : (none)
        
        class BuildingSwaps
        {
        public:
            // no_addr public void BuildingSwaps(const class Faction::BuildingSwaps &);
            BuildingSwaps(GameData*);// RVA = 0x663220
            BuildingSwaps();// RVA = 0x65AFA0
            bool hasReplacement(GameData*);// RVA = 0x65A3C0
            GameData* getReplacement(GameData*);// RVA = 0x659BA0
            boost::unordered::unordered_set<GameData*, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<GameData*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > toReplace; // 0x0 Member
            FitnessSelector<GameData*> replaceWith; // 0x40 Member
            ~BuildingSwaps();// RVA = 0x6711B0
            BuildingSwaps& operator=(const BuildingSwaps&);// RVA = 0x671BC0
            // no_addr public void * __vecDelDtor(unsigned int);
        };
        struct CharacteristicsData
        {
            float fleeRatio_squadSize; // 0x0 Member
            float fleeRatio_relativeEnemy; // 0x4 Member
        };
        bool _antiSlavery; // 0x8 Member
        CharacteristicsData characteristicsData; // 0xC Member
        // no_addr public void Faction(const class Faction &);
        Faction(const std::string&);// RVA = 0x668160
        ~Faction();// RVA = 0x6683E0
        lektor<std::string> ranks; // 0x18 Member
        bool allowSlavesWeapons; // 0x30 Member
        CharacterTypeEnum fundamentalNPCType; // 0x34 Member
        CharacterTypeEnum getFundamentalNPCType();// RVA = 0x1F5810
        float getProsperityMultiplier();// RVA = 0x238FC0
        void clearAndDestroy();// RVA = 0x667510
        bool setup(GameData*);// RVA = 0x664370
        bool setup2();// RVA = 0x658850
        void setup3();// RVA = 0x65B040
        std::string getNewPlatoonID();// RVA = 0x659680
        void resetPlatoonID();// RVA = 0x658830
        Platoon* createNewEmptyUnloadedPlatoon(GameData*, const Ogre::Vector3&, GameDataContainer*, bool);// RVA = 0x65A3F0
        Platoon* createNewEmptyActivePlatoon(GameData*, bool, const Ogre::Vector3&);// RVA = 0x65A520
        void createPlatoonUnloaded(GameData*, GameDataContainer*, GameData*, const Ogre::Vector3&, bool);// RVA = 0x659180
        void createPlatoonAuto(GameData*, GameData*, const Ogre::Vector3&);// RVA = 0x65E6F0
        void createPlatoonsAuto(lektor<GameData*>&);// RVA = 0x65E9C0
        void createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(const std::string&);// RVA = 0x659BB0
        void restorePlatoon(Platoon*);// RVA = 0x55C7E0
        bool resetSquadPositions(const Ogre::Vector3&);// RVA = 0x2ABDA0
        int countPopulation(TownBase*);// RVA = 0x55B8E0
        int countNumSquads(GameData*, TownBase*);// RVA = 0x55B9C0
        void destroyPlatoon(Platoon*);// RVA = 0x55C4C0
        void removePlatoon(Platoon*);// RVA = 0x55B5C0
        int getRandomLockLevel(GameData*);// RVA = 0x206820
        GameData* getData();// RVA = 0x43430
        void getGUIData(DatapanelGUI*, int);// RVA = 0x65AC00
        GameData* getDefaultDivision();// RVA = 0x65B100
        GameData* getFactionColorScheme();// RVA = 0x65B300
        void loadState(GameDataContainer*, GameData*);// RVA = 0x2AFD10
        GameData* saveState(GameDataContainer*, bool);// RVA = 0x2B3490
        void _activateUnloadedPlatoons();// RVA = 0x55B6A0
        void getCharactersInArea(lektor<RootObject*>&, const Ogre::Vector3&, float, bool);// RVA = 0x55C310// vtable offset = 0x0
        void getSelectedObjects(lektor<RootObject*>&, itemType, bool);// RVA = 0x55BBB0// vtable offset = 0x8
        void removeObject(RootObject*);// RVA = 0x55B340// vtable offset = 0x10
        void destroyObject(RootObject*);// RVA = 0x55B330// vtable offset = 0x18
        void processKillList();// RVA = 0x55B530// vtable offset = 0x20
        bool addActiveObject(RootObject*, ActivePlatoon*);// RVA = 0x55C410// vtable offset = 0x28
        ActivePlatoon* choosePlatoon();// RVA = 0x55B750
        const lektor<Platoon*>* getActivePlatoons();// RVA = 0x240E50
        const lektor<Platoon*>* getUnloadedPlatoons();// RVA = 0x2BAAB0
        int getFactionSize();// RVA = 0x658F10
        void update(float);// RVA = 0x55C7F0
        bool periodicUpdateThreaded();// RVA = 0x55B3C0
        bool periodicUpdateMT();// RVA = 0x55B2B0
        bool isThePlayer();// RVA = 0x94710
        bool isNotARealFaction();// RVA = 0x108A60
        // no_addr public void levelEditorMode(bool);
        std::string& getName();// RVA = 0x1F29E0
        // no_addr public class AIPlayer * getAI();
        int getNumPlatoons(GameData*, bool, TownBase*);// RVA = 0x55B800
        Platoon* getSquadThatOwns(Building*);// RVA = 0x55B390
        void getAllSquadsThatOwn(lektor<Platoon*>&, Building*);// RVA = 0x55C060
        const lektor<Platoon*>* getAllActiveSquads();// RVA = 0x520D80
        float getRoadPreference();// RVA = 0x5168D0
        bool isAntiSlavery();// RVA = 0x282920
        Faction* myLawEnforcementFaction; // 0x38 Member
        bool isALawEnforcementFaction; // 0x40 Member
        Faction* getLawEnforcementFaction();// RVA = 0x6A59B0
        FactionLeader factionLeader; // 0x48 Member
        FactionUniqueSquadManager* diplomatMgr; // 0x70 Member
        FactionRelations* relations; // 0x78 Member
        Ownerships* factionOwnerships; // 0x80 Member
        GameData* chooseARace(GameData*, GameData*);// RVA = 0x6652A0
        void setName(const std::string&);// RVA = 0x2C1300
        GameData* getBuildingReplacement(GameData*);// RVA = 0x65A870
        FactionWarMgr* warMgr; // 0x88 Member
        TradeCulture tradeCulture; // 0x90 Member
        void _switchToUnloadedPlatoon(ActivePlatoon*);// RVA = 0x55B2F0
        FitnessSelector<GameData*> raceSelector; // 0x148 Member
        Platoon* _newPlatoon(Faction*, GameData*, GameData*, const Ogre::Vector3&, bool);// RVA = 0x45A960
        void _addActivePlatoonToList(Platoon*);// RVA = 0x659210
        void addPlatoon(Platoon*);// RVA = 0x659400
        void changePlatoonIndex(Platoon*, int);// RVA = 0x659540
        void deactivatePlatoon(Platoon*);// RVA = 0x659340
        void activatePlatoon(Platoon*);// RVA = 0x6596D0
        void updateUnloadedPlatoons(float);// RVA = 0x55B460
        void updateActivePlatoons(float);// RVA = 0x55C650
        void spawnSquadMissionsUpdate();// RVA = 0x238FB0
        bool _spawnASquad(const std::string&, float);// RVA = 0x2394F0
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
        lektor<BuildingSwaps> buildingSwaps; // 0x270 Member
        // no_addr public class Faction & operator=(const class Faction &);
        // no_addr public void * __vecDelDtor(unsigned int);
    };
    
};