#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>
#include <string>
#include <ogre/OgreVector3.h>
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/util/lektor.h>
#include <kenshi/FitnessSelector.h>
#include <kenshi/FactionLeader.h>
#include <kenshi/TradeCulture.h>
#include <kenshi/Enums.h>

class GameData;
class FactionUniqueSquadManager;
class FactionRelations;
class AIPlayer;
class Platoon;
class GameDataContainer;
class TownBase;
class FactionWarMgr;
class ActivePlatoon;
class Building;
class Ownerships;
class PlayerInterface;

class Faction : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    class BuildingSwaps
    {
    public:
        // no_addr void BuildingSwaps(const class Faction::BuildingSwaps & _a1);// public missing arg names
        BuildingSwaps(GameData * data);// public RVA = 0x7FBEC0
        void _CONSTRUCTOR(GameData * data);// public RVA = 0x7FBEC0
        BuildingSwaps();// public RVA = 0x7F3C40
        void _CONSTRUCTOR();// public RVA = 0x7F3C40
        bool hasReplacement(GameData * building) const;// public RVA = 0x7F3060
        GameData * getReplacement(GameData * building) const;// public RVA = 0x7F2840
        ogre_unordered_set<GameData *>::type toReplace; // 0x0 Member
        FitnessSelector<GameData *> replaceWith; // 0x40 Member
        ~BuildingSwaps();// public RVA = 0x80FA50
        void _DESTRUCTOR();// public RVA = 0x80FA50
        Faction::BuildingSwaps & operator=(const Faction::BuildingSwaps & __that);// public RVA = 0x8106B0
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    bool _antiSlavery; // 0x8 Member
    struct CharacteristicsData
    {
        float fleeRatio_squadSize; // 0x0 Member
        float fleeRatio_relativeEnemy; // 0x4 Member
    };
    Faction::CharacteristicsData characteristicsData; // 0xC Member
    // no_addr void Faction(const class Faction & _a1);// public missing arg names
    Faction(const std::string & _name);// public RVA = 0x800E00
    void _CONSTRUCTOR(const std::string & _name);// public RVA = 0x800E00
    ~Faction();// public RVA = 0x801080
    void _DESTRUCTOR();// public RVA = 0x801080
    lektor<std::string > ranks; // 0x18 Member
    bool allowSlavesWeapons; // 0x30 Member
    CharacterTypeEnum fundamentalNPCType; // 0x34 Member
    CharacterTypeEnum getFundamentalNPCType();// public RVA = 0x289F20
    float getProsperityMultiplier();// public RVA = 0x2DD080
    void clearAndDestroy();// public RVA = 0x8001B0
    bool setup(GameData * _data);// public RVA = 0x7FD010
    bool setup2();// public RVA = 0x7F14F0
    void setup3();// public RVA = 0x7F3CE0
    std::string getNewPlatoonID();// public RVA = 0x7F2320
    void resetPlatoonID();// public RVA = 0x7F14D0
    Platoon * createNewEmptyUnloadedPlatoon(GameData * squadTemplate, const Ogre::Vector3 & pos, GameDataContainer * forcecharacterDatas, bool persistent);// public RVA = 0x7F3090
    Platoon * createNewEmptyActivePlatoon(GameData * squadTemplate, bool permanent, const Ogre::Vector3 & p);// public RVA = 0x7F31C0
    void createPlatoonUnloaded(GameData * platoonstate, GameDataContainer * charactersState, GameData * squadTemplate, const Ogre::Vector3 & pos, bool persistent);// public RVA = 0x7F1E20
    void createPlatoonAuto(GameData * platoonstate, GameData * squadTemplate, const Ogre::Vector3 & pos);// public RVA = 0x7F7390
    void createPlatoonsAuto(lektor<GameData *> & platoons);// public RVA = 0x7F7660
    void createReplacementPlatoonForPlayerWhenSavegameIsCorrupt(const std::string & src);// public RVA = 0x7F2850
    void restorePlatoon(Platoon * p);// public RVA = 0x6BA2B0
    bool resetSquadPositions(const Ogre::Vector3 & target);// public RVA = 0x36AE50
    int countPopulation(TownBase * t);// public RVA = 0x6B93B0
    int countNumSquads(GameData * squadTemplate, TownBase * squadHome);// public RVA = 0x6B9490
    void destroyPlatoon(Platoon * platoon);// public RVA = 0x6B9F90
    void removePlatoon(Platoon * platoon);// public RVA = 0x6B9090
    int getRandomLockLevel(GameData * objData) const;// public RVA = 0x29D3B0
    GameData * getData() const;// public RVA = 0x6E000
    void getGUIData(DatapanelGUI * panel, int category);// public RVA = 0x7F38A0
    GameData * getDefaultDivision();// public RVA = 0x7F3DA0
    GameData * getFactionColorScheme();// public RVA = 0x7F3FA0
    void loadState(GameDataContainer * saveSource, GameData * gamestate_faction);// public RVA = 0x36EDC0
    GameData * saveState(GameDataContainer * container, bool leveleditor);// public RVA = 0x372540
    void _activateUnloadedPlatoons();// public RVA = 0x6B9170
    virtual void getCharactersInArea(lektor<RootObject *> & out, const Ogre::Vector3 & pos, float radius, bool standingOnly);// public RVA = 0x6B9DE0 vtable offset = 0x0
    void _NV_getCharactersInArea(lektor<RootObject *> & out, const Ogre::Vector3 & pos, float radius, bool standingOnly);// public RVA = 0x6B9DE0 vtable offset = 0x0
    virtual void getSelectedObjects(lektor<RootObject *> & out, itemType type, bool selectedOnly);// public RVA = 0x6B9680 vtable offset = 0x8
    void _NV_getSelectedObjects(lektor<RootObject *> & out, itemType type, bool selectedOnly);// public RVA = 0x6B9680 vtable offset = 0x8
    virtual void removeObject(RootObject * c);// public RVA = 0x6B8E10 vtable offset = 0x10
    void _NV_removeObject(RootObject * c);// public RVA = 0x6B8E10 vtable offset = 0x10
    virtual void destroyObject(RootObject * c);// public RVA = 0x6B8E00 vtable offset = 0x18
    void _NV_destroyObject(RootObject * c);// public RVA = 0x6B8E00 vtable offset = 0x18
    virtual void processKillList();// public RVA = 0x6B9000 vtable offset = 0x20
    void _NV_processKillList();// public RVA = 0x6B9000 vtable offset = 0x20
    virtual bool addActiveObject(RootObject * c, ActivePlatoon * p);// public RVA = 0x6B9EE0 vtable offset = 0x28
    bool _NV_addActiveObject(RootObject * c, ActivePlatoon * p);// public RVA = 0x6B9EE0 vtable offset = 0x28
    ActivePlatoon * choosePlatoon();// public RVA = 0x6B9220
    const lektor<Platoon *> * getActivePlatoons() const;// public RVA = 0x2E6D60
    const lektor<Platoon *> * getUnloadedPlatoons() const;// public RVA = 0x37D710
    int getFactionSize() const;// public RVA = 0x7F1BB0
    void update(float time);// public RVA = 0x6BA2C0
    bool periodicUpdateThreaded();// public RVA = 0x6B8E90
    bool periodicUpdateMT();// public RVA = 0x6B8D80
    bool isThePlayer() const;// public RVA = 0xD5FC0
    bool isNotARealFaction() const;// public RVA = 0x166EA0
    // no_addr void levelEditorMode(bool _a1);// public missing arg names
    const std::string & getName();// public RVA = 0x286780
    // no_addr class AIPlayer * getAI();// public
    int getNumPlatoons(GameData * squadTemplate, bool tempsOnly, TownBase * hometown) const;// public RVA = 0x6B92D0
    Platoon * getSquadThatOwns(Building * what);// public RVA = 0x6B8E60
    void getAllSquadsThatOwn(lektor<Platoon *> & out, Building * what);// public RVA = 0x6B9B30
    const lektor<Platoon *> * getAllActiveSquads();// public RVA = 0x670B40
    float getRoadPreference() const;// public RVA = 0x663EB0
    bool isAntiSlavery();// public RVA = 0x338000
    Faction * myLawEnforcementFaction; // 0x38 Member
    bool isALawEnforcementFaction; // 0x40 Member
    Faction * getLawEnforcementFaction();// public RVA = 0x850A20
    FactionLeader factionLeader; // 0x48 Member
    FactionUniqueSquadManager * diplomatMgr; // 0x70 Member
    FactionRelations * relations; // 0x78 Member
    Ownerships * factionOwnerships; // 0x80 Member
    GameData * chooseARace(GameData * character, GameData * squadTemplate);// public RVA = 0x7FDF40
    void setName(const std::string & _name);// public RVA = 0x385290
    GameData * getBuildingReplacement(GameData * building);// public RVA = 0x7F3510
    FactionWarMgr * warMgr; // 0x88 Member
    TradeCulture tradeCulture; // 0x90 Member
    void _switchToUnloadedPlatoon(ActivePlatoon * platoon);// public RVA = 0x6B8DC0
    FitnessSelector<GameData *> raceSelector; // 0x148 Member
    Platoon * _newPlatoon(Faction * f, GameData * squadTemplate, GameData * platoonState, const Ogre::Vector3 & pos, bool persistent);// protected RVA = 0x57BF70
    void _addActivePlatoonToList(Platoon * platoon);// protected RVA = 0x7F1EB0
    void addPlatoon(Platoon * platoon);// protected RVA = 0x7F20A0
    void changePlatoonIndex(Platoon * platoon, int index);// protected RVA = 0x7F21E0
    void deactivatePlatoon(Platoon * p);// protected RVA = 0x7F1FE0
    void activatePlatoon(Platoon * p);// protected RVA = 0x7F2370
    void updateUnloadedPlatoons(float time);// protected RVA = 0x6B8F30
    void updateActivePlatoons(float time);// protected RVA = 0x6BA120
    void spawnSquadMissionsUpdate();// protected RVA = 0x2DD070
    bool _spawnASquad(const std::string & listname, float sizeMultiplier);// protected RVA = 0x2DD5B0
    std::string name; // 0x1A8 Member
    bool notARealFaction; // 0x1D0 Member
    float roadPreference; // 0x1D4 Member
    lektor<Platoon *> platoonKillList; // 0x1D8 Member
    lektor<Platoon *> platoonRemoveList; // 0x1F0 Member
    lektor<Platoon *> activePlatoons; // 0x208 Member
    lektor<Platoon *> unloadedPlatoons; // 0x220 Member
    int periodicUpdateCounter_active; // 0x238 Member
    int periodicUpdateCounter_unloaded; // 0x23C Member
    GameData * data; // 0x240 Member
    AIPlayer * isAI; // 0x248 Member
    PlayerInterface * isPlayer; // 0x250 Member
    int spawnTimeStamp; // 0x258 Member
    int diplomatTimeStamp; // 0x25C Member
    int platoonIDs; // 0x260 Member
    float p_TIME; // 0x264 Member
    int platoonPeriodicUpdateIndex; // 0x268 Member
    lektor<Faction::BuildingSwaps> buildingSwaps; // 0x270 Member
    // no_addr class Faction & operator=(const class Faction & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};
