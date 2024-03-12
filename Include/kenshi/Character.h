#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>
#include <kenshi/RootObject.h>
#include <kenshi/MedicalSystem.h>
#include <kenshi/BountyManager.h>
#include <kenshi/util/YesNoMaybe.h>
#include <kenshi/util/OgreUnordered.h>
#include <ogre/OgreVector3.h>
#include <string>
#include <ogre/OgreQuaternion.h>

class GameData;
class CampaignInstance;
class CharacterAnimal;
class Platoon;
class Item;
class Tasker;
class Formation;
class Crossbow;
class StorageBuilding;
class Inventory;
class ContainerItem;
class CharacterHuman;
class DoorLock;
class Building;
class GameDataCopyStandalone;
class GameSaveState;
class GameDataContainer;
class CharBody;
class CombatClass;
class CharStats;
class AI;
class CharacterMemory;
class Dialogue;
class AnimationClass;
class Weapon;
class RangedCombatClass;
class CharacterNameTag;
class CharMovement;
class AppearanceBase;
class Blackboard;
class OrdersReceiver;
class UseableStuff;
class LockedArmour;
class SoundEmitter;
class Effect;
class Sword;

// TODO move?
enum ProneState
{
    PS_NORMAL,
    PS_STAYING_LOW,
    PS_CRIPPLED,
    PS_PLAYING_DEAD,
    PS_KO
};

// TODO move?
class WaterState
{
public:
    enum Enum
    {
        NO_WATER,
        VERY_SHALLOW_WATER,
        THIGH_DEEP_WATER,
        DEEP_WATER
    };
};

// TODO move?
namespace RagdollPart
{
    enum Enum
    {
        NONE,
        WHOLE,
        RIGHT_ARM,
        LEFT_ARM = 0x4,
        HEAD = 0x8,
        RIGHT_LEG = 0x10,
        LEFT_LEG = 0x20,
        CARRY_MODE = 0x800,
        ARMS = 0x6,
        LEGS = 0x30,
        ALL = 0xFFFF8000
    };
};

enum CharacterPerceptionTags_ShortTerm
{
    ST_NONE,
    ST_INTRUDER,
    ST_AGGRESSOR,
    ST_TEMPORARY_ALLY,
    ST_TEMPORARY_ENEMY,
    ST_PRISONER,
    ST_HAS_BEEN_LOOTED,
    ST_CRIMINAL
};

enum CharacterPerceptionTags_LongTerm
{
    LT_NONE,
    LT_MY_INTRUDER,
    LT_MY_LIFESAVER,
    LT_FREED_ME,
    LT_STOLE_FROM_ME,
    LT_MY_CAPTOR,
    LT_FRIENDLY_AQUAINTANCE,
    LT_DEFEATED_MY_SQUAD_ONCE,
    LT_SQUAD_LOST_TO_ME_ONCE,
    LT_KILLED_MY_FRIEND,
    LT_I_SCREWED_THIS_GUY,
    LT_MAX
};

enum SoundRange
{
    SOUNDRANGE_SHORT = 0xFFFF9C40,
    SOUNDRANGE_LONG = 0xF4240,
    SOUNDRANGE_ALWAYS = 0x0
};

enum SquadMemberType
{
    SQUAD_1,
    SQUAD_2,
    SQUAD_LEADER,
    SQUAD_SIGNALS_PLAN,
    SQUAD_SLAVE
};

enum MoveSpeed
{
    WALK,
    JOG,
    RUN,
    GROUPED,
    NO_SPEED_CHANGE
};

enum CharacterMessage
{
    ATTACKING_MELEE
};

enum GroundType
{
    GROUND_SAND,
    GROUND_GRASS,
    GROUND_CONCRETE,
    GROUND_WOOD,
    GROUND_METAL,
    GROUND_WATER,
    GROUND_MUD,
    GROUND_SNOW,
    GROUND_DIRT
};

struct AkVector
{
    float X; // 0x0 Member
    float Y; // 0x4 Member
    float Z; // 0x8 Member
};

// TODO move?
struct AkSoundPosition
{
    AkVector Position; // 0x0 Member
    AkVector Orientation; // 0xC Member
};

enum UseStuffState
{
    IN_NOTHING,
    IN_BED,
    IN_PRISON
};

enum SlaveStateEnum
{
    NOT_SLAVE,
    IS_SLAVE,
    ESCAPING_SLAVE,
    EX_SLAVE
};

class Character : public RootObject, public Ogre::GeneralAllocatedObject
{
public:
    // RootObject offset = 0x0, length = 0xC0
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0xC0, length = 0x1
    // no_addr void Character(class Character & _a1);// public missing arg names
    Character(GameData * dat, Faction * own, const hand & _handle);// protected RVA = 0x621C70
    void _CONSTRUCTOR(GameData * dat, Faction * own, const hand & _handle);// protected RVA = 0x621C70
    bool isImmuneToOffscreenMode();// protected RVA = 0x5C7240
    virtual void init();// protected RVA = 0x620A10 vtable offset = 0x228
    void _NV_init();// protected RVA = 0x620A10 vtable offset = 0x228
    float offscreenFrameTime; // 0xC0 Member
    float frameTIME; // 0xC4 Member
    float frameTIMEfour; // 0xC8 Member
    float frameTIME_P; // 0xCC Member
    float bodyDecayTimer; // 0xD0 Member
    bool stealthMode; // 0xD4 Member
    bool _isOnARoof; // 0xD5 Member
    float _lightLevel; // 0xD8 Member
    bool needsLightLevel; // 0xDC Member
    ProneState _currentProneState; // 0xE0 Member
    virtual ~Character();// public RVA = 0x622300 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x622300 vtable offset = 0x0
    bool isVisibleUpdateMode; // 0xE4 Member
    bool setVisibleMsg; // 0xE5 Member
    YesNoMaybe stealthUnseen; // 0xE8 Member
    virtual bool isOnARoof();// public RVA = 0x5E16E0 vtable offset = 0x0
    bool _NV_isOnARoof();// public RVA = 0x5E16E0 vtable offset = 0x0
    virtual bool isOnAWall();// public RVA = 0x5C8340 vtable offset = 0x230
    bool _NV_isOnAWall();// public RVA = 0x5C8340 vtable offset = 0x230
    float getLightLevel();// public RVA = 0x643240
    virtual float getHPMultiplier() const;// public RVA = 0x5E51C0 vtable offset = 0x238
    float _NV_getHPMultiplier() const;// public RVA = 0x5E51C0 vtable offset = 0x238
    void healCompletely();// public RVA = 0x645D40
    void resetRagdollNavmeshSafePos();// public RVA = 0x7D00B0
    void setRagdollNavmeshSafePos();// public RVA = 0x65DF40
    float getFrameTime() const;// public RVA = 0x32DAA0
    void frameSkip();// public RVA = 0x788AF0
    float getCurrentNoiseRange();// public RVA = 0x850780
    virtual bool isDestroyed() const;// public RVA = 0x5E1720 vtable offset = 0x240
    bool _NV_isDestroyed() const;// public RVA = 0x5E1720 vtable offset = 0x240
    bool isLawEnforcement();// public RVA = 0x598E80
    bool canAssignBounties();// public RVA = 0x5A3CF0
    virtual itemType getDataType() const;// public RVA = 0x5E1730 vtable offset = 0x0
    itemType _NV_getDataType() const;// public RVA = 0x5E1730 vtable offset = 0x0
    bool isDiplomaticStatus(bool factorInBiome);// public RVA = 0x794FE0
    bool isLeadingAWarCampaign();// public RVA = 0x9C3360
    CampaignInstance * isInAWarCampaign();// public RVA = 0x9C33E0
    bool playerWantsMeToGetUp; // 0xEC Member
    bool wantsToTriggerCampaigns();// public RVA = 0x9C35C0
    bool isUnique();// public RVA = 0x5061E0
    bool canSpeakNormally();// public RVA = 0x5E8240
    virtual CharacterAnimal * isAnimal();// public RVA = 0x5E51D0 vtable offset = 0x248
    CharacterAnimal * _NV_isAnimal();// public RVA = 0x5E51D0 vtable offset = 0x248
    virtual CharacterHuman * isHuman();// public RVA = 0x5E1740 vtable offset = 0x250
    CharacterHuman * _NV_isHuman();// public RVA = 0x5E1740 vtable offset = 0x250
    virtual bool takeMoney(int n);// public RVA = 0x795390 vtable offset = 0x0
    bool _NV_takeMoney(int n);// public RVA = 0x795390 vtable offset = 0x0
    virtual int getMoney() const;// public RVA = 0x790400 vtable offset = 0x0
    int _NV_getMoney() const;// public RVA = 0x790400 vtable offset = 0x0
    void setSquadMemberType(SquadMemberType memType);// public RVA = 0x620E40
    TownBase * isResident() const;// public RVA = 0x5CDE70
    BountyManager crimes; // 0xF0 Member
    StatsEnumerated currentSkillUsing; // 0x198 Member
    void dailyUpdate();// public RVA = 0x5D2010
    StateBroadcastData * stateBroadcast; // 0x1A0 Member
    bool isVisibleAndNear; // 0x1A8 Member
    bool isOnScreen; // 0x1A9 Member
    bool updateOnScreenCheck();// public RVA = 0x5C97E0
    void offscreenUpdate();// public RVA = 0x5C7320
    void updateTimes();// public RVA = 0x5C7360
    virtual SensoryData * getSensoryData();// public RVA = 0x5C7F80 vtable offset = 0x0
    SensoryData * _NV_getSensoryData();// public RVA = 0x5C7F80 vtable offset = 0x0
    virtual StateBroadcastData * getStateBroadcast();// public RVA = 0x5E1750 vtable offset = 0x0
    StateBroadcastData * _NV_getStateBroadcast();// public RVA = 0x5E1750 vtable offset = 0x0
    virtual Formation * getFormation() const;// public RVA = 0x5C9160 vtable offset = 0x258
    Formation * _NV_getFormation() const;// public RVA = 0x5C9160 vtable offset = 0x258
    virtual Formation * getEnemyFormation() const;// public RVA = 0x5C9180 vtable offset = 0x260
    Formation * _NV_getEnemyFormation() const;// public RVA = 0x5C9180 vtable offset = 0x260
    void formationUpdateCallback(const Ogre::Vector3 & pos, const hand & target, const Ogre::Vector3 & heading, Formation * from);// public RVA = 0x5C91A0
    bool AIDestinationIndoorOutdoorCheck(RootObject * who);// public RVA = 0x50C210
    virtual void setHandle(const hand & h);// public RVA = 0x6231A0 vtable offset = 0x0
    void _NV_setHandle(const hand & h);// public RVA = 0x6231A0 vtable offset = 0x0
    virtual void update();// public RVA = 0x5CE9B0 vtable offset = 0x0
    void _NV_update();// public RVA = 0x5CE9B0 vtable offset = 0x0
    virtual void postUpdate();// public RVA = 0x5CD2A0 vtable offset = 0x268
    void _NV_postUpdate();// public RVA = 0x5CD2A0 vtable offset = 0x268
    void ragdollUpdatesUT();// public RVA = 0x5D24B0
    void fourFrameUpdate();// public RVA = 0x5CF610
    virtual void periodicUpdate();// public RVA = 0x5CC610 vtable offset = 0x0
    void _NV_periodicUpdate();// public RVA = 0x5CC610 vtable offset = 0x0
    virtual void pausedUpdate();// public RVA = 0x5C73A0 vtable offset = 0x270
    void _NV_pausedUpdate();// public RVA = 0x5C73A0 vtable offset = 0x270
    void updateUT();// public RVA = 0x5C7470
    virtual void threadedUpdate();// public RVA = 0x5C74B0 vtable offset = 0x0
    void _NV_threadedUpdate();// public RVA = 0x5C74B0 vtable offset = 0x0
    virtual void threadedUpdate4();// public RVA = 0x5C75C0 vtable offset = 0x278
    void _NV_threadedUpdate4();// public RVA = 0x5C75C0 vtable offset = 0x278
    virtual void threadedUpdatePeriodic();// public RVA = 0x5CF930 vtable offset = 0x280
    void _NV_threadedUpdatePeriodic();// public RVA = 0x5CF930 vtable offset = 0x280
    bool pathExists(const Ogre::Vector3 & v);// public RVA = 0x65D3E0
    virtual void weatherUpdate(float _a1);// public RVA = 0x5C77E0 vtable offset = 0x288 missing arg names
    void _NV_weatherUpdate(float _a1);// public RVA = 0x5C77E0 vtable offset = 0x288 missing arg names
    void stealthUpdate(float _time);// public RVA = 0x857140
    float lineOfSightCheck(Character * who);// public RVA = 0x852090
    float getPerceptionMult();// public RVA = 0x851430
    bool isWithThePlayer();// public RVA = 0x855630
    void notifyICanSeeYouSneaking(Character * who, YesNoMaybe seeing, float maybeProgress01);// public RVA = 0x8549A0
    bool isItSafeToGetUp();// public RVA = 0x5C9CD0
    Platoon * separateIntoMyOwnSquad(bool permanent);// public RVA = 0x5CDD60
    void dropGearOnDeath(bool vampiricDeath);// public RVA = 0x5CB090
    virtual bool isItOkForMeToLoot(RootObject * _victim, Item * item);// public RVA = 0x7926E0 vtable offset = 0x290
    bool _NV_isItOkForMeToLoot(RootObject * _victim, Item * item);// public RVA = 0x7926E0 vtable offset = 0x290
    virtual bool ImStealingDoYouNotice(RootObject * stealFrom, Item * item);// public RVA = 0x7935B0 vtable offset = 0x298
    bool _NV_ImStealingDoYouNotice(RootObject * stealFrom, Item * item);// public RVA = 0x7935B0 vtable offset = 0x298
    float getFencingSuccessChance(Item * item, RootObject * thief);// public RVA = 0x792230
    virtual bool stolenGoodsDetectionCheck(Item * item, RootObject * thief);// public RVA = 0x792510 vtable offset = 0x0
    bool _NV_stolenGoodsDetectionCheck(Item * item, RootObject * thief);// public RVA = 0x792510 vtable offset = 0x0
    virtual bool sellingUniformDetectionCheck(Item * item, Character * thief);// public RVA = 0x792460 vtable offset = 0x2A0
    bool _NV_sellingUniformDetectionCheck(Item * item, Character * thief);// public RVA = 0x792460 vtable offset = 0x2A0
    virtual YesNoMaybe smugglingTradeCheck(Item * item, Character * who);// public RVA = 0x793C20 vtable offset = 0x2A8
    YesNoMaybe _NV_smugglingTradeCheck(Item * item, Character * who);// public RVA = 0x793C20 vtable offset = 0x2A8
    float getStealingSuccessChance(RootObject * stealFrom, Item * item, Character * * victimOut);// public RVA = 0x793270
    WeatherAffecting getCurrentWeatherAffectStatus() const;// public RVA = 0x5C7F40
    float getCurrentWeatherAffectStrength() const;// public RVA = 0x5C7F60
    WaterState::Enum getWaterLevel();// public RVA = 0x5C7850
    void setTerrainHeightPosition(float height);// public RVA = 0x5C7050
    float getTerrainHeightPosition();// public RVA = 0x5B0920
    enum DisguiseGUIFeedback
    {
        DGF_SAME_FACTION,
        DGF_MY_SLAVE,
        DGF_I_HATE_YOU    
    };

    void setDisguiseMessage(Character::DisguiseGUIFeedback msg);// public RVA = 0x861FE0
    ogre_unordered_map<Character::DisguiseGUIFeedback,float>::type disguiseGUIFeedbacks; // 0x1B0 Member
    class WhoSeesMe
    {
    public:
        // no_addr void WhoSeesMe(class Character::WhoSeesMe & _a1);// public missing arg names
        WhoSeesMe(double timestamp, YesNoMaybe what, float prog);// public RVA = 0x85C5E0
        void _CONSTRUCTOR(double timestamp, YesNoMaybe what, float prog);// public RVA = 0x85C5E0
        WhoSeesMe();// public RVA = 0x85C5D0
        void _CONSTRUCTOR();// public RVA = 0x85C5D0
        double lastUpdated; // 0x0 Member
        YesNoMaybe seeState; // 0x8 Member
        float progressOfMaybe; // 0xC Member
    };
    ogre_unordered_map<hand,Character::WhoSeesMe>::type whoSeesMeSneaking; // 0x1F0 Member
    class AttachedArrowManager
    {
    public:
        ~AttachedArrowManager();// public RVA = 0x5CA8D0
        void _DESTRUCTOR();// public RVA = 0x5CA8D0
        void clearAll();// public RVA = 0x5C9E30
        void updateStart();// public RVA = 0x5C7BA0
        void addArrow(Ogre::Vector3 & pos, Ogre::Vector3 & targ, int color);// public RVA = 0x5DC050
        void updateEnd();// public RVA = 0x5C9EA0
        lektor<Ogre::Entity *> ents; // 0x0 Member
        int index; // 0x18 Member
        // no_addr void AttachedArrowManager(const class Character::AttachedArrowManager & _a1);// public missing arg names
        AttachedArrowManager();// public RVA = 0x636870
        void _CONSTRUCTOR();// public RVA = 0x636870
        // no_addr class Character::AttachedArrowManager & operator=(const class Character::AttachedArrowManager & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    Character::AttachedArrowManager stealthMarkerArrows; // 0x230 Member
    void uniqueStateUpdate();// protected RVA = 0x5CECF0
    virtual void foodUpdate();// protected RVA = 0x5D2240 vtable offset = 0x2B0
    void _NV_foodUpdate();// protected RVA = 0x5D2240 vtable offset = 0x2B0
    bool eatItem(Item * food, Inventory * from);// public RVA = 0x5D0000
    virtual GameSaveState serialise(GameDataContainer * container, GameData * refList, PosRotPair * offsetPosToSubtract);// public RVA = 0x627920 vtable offset = 0x0
    GameSaveState _NV_serialise(GameDataContainer * container, GameData * refList, PosRotPair * offsetPosToSubtract);// public RVA = 0x627920 vtable offset = 0x0
    virtual void loadFromSerialise(GameSaveState * state);// public RVA = 0x6267D0 vtable offset = 0x0
    void _NV_loadFromSerialise(GameSaveState * state);// public RVA = 0x6267D0 vtable offset = 0x0
    virtual void loadFromSerialisePostCreationStage(GameSaveState * gd);// public RVA = 0x6273B0 vtable offset = 0x2B8
    void _NV_loadFromSerialisePostCreationStage(GameSaveState * gd);// public RVA = 0x6273B0 vtable offset = 0x2B8
    virtual bool setupInventorySections(GameSaveState * state);// public RVA = 0x622700 vtable offset = 0x2C0
    bool _NV_setupInventorySections(GameSaveState * state);// public RVA = 0x622700 vtable offset = 0x2C0
    virtual Ogre::Vector3 getPosition();// public RVA = 0x5CDF00 vtable offset = 0x0
    Ogre::Vector3 _NV_getPosition();// public RVA = 0x5CDF00 vtable offset = 0x0
    Ogre::Vector3 _getRawPosition() const;// public RVA = 0x663C30
    Ogre::Vector3 getRawEntityPosition();// public RVA = 0x5C7950
    virtual float getMovementSpeed() const;// public RVA = 0x5C7C50 vtable offset = 0x0
    float _NV_getMovementSpeed() const;// public RVA = 0x5C7C50 vtable offset = 0x0
    virtual MoveSpeed getMovementSpeedOrders() const;// public RVA = 0x5C7C90 vtable offset = 0x2C8
    MoveSpeed _NV_getMovementSpeedOrders() const;// public RVA = 0x5C7C90 vtable offset = 0x2C8
    virtual Ogre::Vector3 getMovementDirection() const;// public RVA = 0x5C7CB0 vtable offset = 0x0
    Ogre::Vector3 _NV_getMovementDirection() const;// public RVA = 0x5C7CB0 vtable offset = 0x0
    // no_addr int getSquadMemberID();// public
    virtual bool isPhysical() const;// public RVA = 0x5C8040 vtable offset = 0x0
    bool _NV_isPhysical() const;// public RVA = 0x5C8040 vtable offset = 0x0
    virtual void setVisible(bool on);// public RVA = 0x5C8070 vtable offset = 0x0
    void _NV_setVisible(bool on);// public RVA = 0x5C8070 vtable offset = 0x0
    virtual bool getVisible() const;// public RVA = 0x5C8100 vtable offset = 0x0
    bool _NV_getVisible() const;// public RVA = 0x5C8100 vtable offset = 0x0
    void switchLights(bool on);// public RVA = 0x52C580
    virtual bool isDisabled();// public RVA = 0x5C8130 vtable offset = 0x0
    bool _NV_isDisabled();// public RVA = 0x5C8130 vtable offset = 0x0
    virtual void setInsideTownWalls(int s);// public RVA = 0x790D80 vtable offset = 0x0
    void _NV_setInsideTownWalls(int s);// public RVA = 0x790D80 vtable offset = 0x0
    virtual void sheatheWeapon();// public RVA = 0x640D80 vtable offset = 0x2D0
    void _NV_sheatheWeapon();// public RVA = 0x640D80 vtable offset = 0x2D0
    virtual void select();// public RVA = 0x5C8D70 vtable offset = 0x0
    void _NV_select();// public RVA = 0x5C8D70 vtable offset = 0x0
    virtual void unselect();// public RVA = 0x5C8DA0 vtable offset = 0x0
    void _NV_unselect();// public RVA = 0x5C8DA0 vtable offset = 0x0
    virtual void getGUIData(DatapanelGUI * datapanel, int category);// public RVA = 0x5D3AE0 vtable offset = 0x0
    void _NV_getGUIData(DatapanelGUI * datapanel, int category);// public RVA = 0x5D3AE0 vtable offset = 0x0
    virtual TownBase * getCurrentTownLocation();// public RVA = 0x5C8230 vtable offset = 0x0
    TownBase * _NV_getCurrentTownLocation();// public RVA = 0x5C8230 vtable offset = 0x0
    virtual void say_WithARepeatLimiter(const std::string & s);// public RVA = 0x5CA790 vtable offset = 0x2D8
    void _NV_say_WithARepeatLimiter(const std::string & s);// public RVA = 0x5CA790 vtable offset = 0x2D8
    virtual void say(const std::string & s);// public RVA = 0x5C91D0 vtable offset = 0x0
    void _NV_say(const std::string & s);// public RVA = 0x5C91D0 vtable offset = 0x0
    virtual bool isInventoryVisible() const;// public RVA = 0x5C8DD0 vtable offset = 0x2E0
    bool _NV_isInventoryVisible() const;// public RVA = 0x5C8DD0 vtable offset = 0x2E0
    virtual bool giveItem(Item * item, bool dropOnFail, bool destroyOnFail);// public RVA = 0x5CAC80 vtable offset = 0x0
    bool _NV_giveItem(Item * item, bool dropOnFail, bool destroyOnFail);// public RVA = 0x5CAC80 vtable offset = 0x0
    virtual bool hasRoomForItem(GameData * item);// public RVA = 0x5CADA0 vtable offset = 0x0
    bool _NV_hasRoomForItem(GameData * item);// public RVA = 0x5CADA0 vtable offset = 0x0
    virtual bool hasItem(GameData * item);// public RVA = 0x5CAE30 vtable offset = 0x0
    bool _NV_hasItem(GameData * item);// public RVA = 0x5CAE30 vtable offset = 0x0
    virtual bool hasAmmoFor(Crossbow * c);// public RVA = 0x5C8E00 vtable offset = 0x2E8
    bool _NV_hasAmmoFor(Crossbow * c);// public RVA = 0x5C8E00 vtable offset = 0x2E8
    virtual int getNumFoodItems();// public RVA = 0x596B50 vtable offset = 0x2F0
    int _NV_getNumFoodItems();// public RVA = 0x596B50 vtable offset = 0x2F0
    virtual bool hasSimilarItem(itemType ty);// public RVA = 0x5CBDE0 vtable offset = 0x2F8
    bool _NV_hasSimilarItem(itemType ty);// public RVA = 0x5CBDE0 vtable offset = 0x2F8
    bool ifImASmithShouldIDitchMyBackWeapon();// public RVA = 0x5CBD30
    virtual bool hasItemsFrom(StorageBuilding * from, ogre_unordered_set<GameData *>::type & allTheOnesWeHave);// public RVA = 0x5A3D90 vtable offset = 0x300
    bool _NV_hasItemsFrom(StorageBuilding * from, ogre_unordered_set<GameData *>::type & allTheOnesWeHave);// public RVA = 0x5A3D90 vtable offset = 0x300
    virtual Inventory * getInventory() const;// public RVA = 0x5E1760 vtable offset = 0x0
    Inventory * _NV_getInventory() const;// public RVA = 0x5E1760 vtable offset = 0x0
    ContainerItem * hasABackpackOn() const;// public RVA = 0x5CABA0
    bool isATrader() const;// public RVA = 0x5CF7F0
    bool isFemale();// public RVA = 0x2955A0
    bool isFleeing();// public RVA = 0x5C9410
    virtual InventoryLayout * createInventoryLayout();// public RVA = 0x5CB1F0 vtable offset = 0x0
    InventoryLayout * _NV_createInventoryLayout();// public RVA = 0x5CB1F0 vtable offset = 0x0
    bool _isEngagedWithAPlayer; // 0x250 Member
    hand isUsingTurret; // 0x258 Member
    float getStealthKOChance(Character * victim, bool factors);// public RVA = 0x883B40
    float getKidnappingChance(Character * victim);// public RVA = 0x883E50
    float getKidnappingEscapeChance_skill(Character * captor);// public RVA = 0x884110
    float getKidnappingEscapeChance_strength(Character * captor);// public RVA = 0x884360
    float getLockpickChance(DoorLock * victim);// public RVA = 0x8844E0
    bool shouldIHelpThisGuy(Character * who);// public RVA = 0x599EF0
    bool shouldIScrewThisGuyOver(Character * who);// public RVA = 0x59A030
    bool ILoveThisGuyBecauseOfStuffThatHappened(Character * who);// public RVA = 0x598E10
    bool IHateThisGuyBecauseOfStuffThatHappened(Character * who);// public RVA = 0x598E50
    int getRoughLevel();// public RVA = 0x59A1A0
    virtual void setStandingOrder(MessageForB::StandingOrder orderID, bool on);// public RVA = 0x5CA2D0 vtable offset = 0x308
    void _NV_setStandingOrder(MessageForB::StandingOrder orderID, bool on);// public RVA = 0x5CA2D0 vtable offset = 0x308
    bool getStandingOrder(MessageForB::StandingOrder orderID) const;// public RVA = 0x5C8F40
    void setStealthMode(bool on);// public RVA = 0x5CA220
    bool isStealthMode() const;// public RVA = 0x5C8FD0
    bool isStealthModeOrCrawling() const;// public RVA = 0x663C50
    void declareDead();// public RVA = 0x7A4FA0
    void updateGUIStatsDetails(DatapanelGUI * datapanel, const std::string & name, int statId);// public RVA = 0x8AFAA0
    void _printRaceXPBonusLine(DatapanelGUI * panel, StatsEnumerated s);// public RVA = 0x8A97D0
    void addGoal(TaskType t, RootObjectBase * subject);// public RVA = 0x5C88A0
    // no_addr void removeGoal(enum TaskType _a1);// public missing arg names
    void addJob(TaskType t, RootObject * subject, bool shift, bool addDontClear, const Ogre::Vector3 & location);// public RVA = 0x5C8620
    void removeJob(TaskType t);// public RVA = 0x5C8730
    void removePermajob(int t);// public RVA = 0x5C8880
    void clearPermajobs();// public RVA = 0x5C8860
    void movePermajob(int taskIdx, int targetIdx);// public RVA = 0x5C8840
    const std::string & getPermajobName(int slot) const;// public RVA = 0x5C8750
    TaskType getPermajob(int slot) const;// public RVA = 0x5C8770
    const Tasker * getPermajobData(int slot) const;// public RVA = 0x5C8790
    int getPermajobCount() const;// public RVA = 0x5C87B0
    virtual const Ogre::Aabb & getAABB() const;// public RVA = 0x5C87D0 vtable offset = 0x0
    const Ogre::Aabb & _NV_getAABB() const;// public RVA = 0x5C87D0 vtable offset = 0x0
    void addOrder(Building * dest, TaskType t, RootObject * subject, bool shift, bool clear, const Ogre::Vector3 & location);// public RVA = 0x5D1950
    virtual void updateLastTask(Building * dest, TaskType t, RootObject * subject, const Ogre::Vector3 & location);// public RVA = 0x5C89B0 vtable offset = 0x310
    void _NV_updateLastTask(Building * dest, TaskType t, RootObject * subject, const Ogre::Vector3 & location);// public RVA = 0x5C89B0 vtable offset = 0x310
    virtual void playerMoveOrderDefault(Building * dest, RootObject * subject, const Ogre::Vector3 & location);// public RVA = 0x5D1B30 vtable offset = 0x318
    void _NV_playerMoveOrderDefault(Building * dest, RootObject * subject, const Ogre::Vector3 & location);// public RVA = 0x5D1B30 vtable offset = 0x318
    void endCombatMode();// public RVA = 0x5C8A40
    virtual float getTotalRelativeStrengthOfAttackers();// public RVA = 0x5C8AB0 vtable offset = 0x320
    float _NV_getTotalRelativeStrengthOfAttackers();// public RVA = 0x5C8AB0 vtable offset = 0x320
    virtual bool canGoIndoors(Building * b) const;// public RVA = 0x5E51E0 vtable offset = 0x328
    bool _NV_canGoIndoors(Building * b) const;// public RVA = 0x5E51E0 vtable offset = 0x328
    virtual const hand & isIndoors() const;// public RVA = 0x5CD8A0 vtable offset = 0x0
    const hand & _NV_isIndoors() const;// public RVA = 0x5CD8A0 vtable offset = 0x0
    virtual const hand & isStandingOnBuilding() const;// public RVA = 0x5C7FA0 vtable offset = 0x330
    const hand & _NV_isStandingOnBuilding() const;// public RVA = 0x5C7FA0 vtable offset = 0x330
    virtual bool isIndoorsRagdoll() const;// public RVA = 0x5C7FC0 vtable offset = 0x338
    bool _NV_isIndoorsRagdoll() const;// public RVA = 0x5C7FC0 vtable offset = 0x338
    virtual void notifyIndoors(const hand & in);// public RVA = 0x7910B0 vtable offset = 0x0
    void _NV_notifyIndoors(const hand & in);// public RVA = 0x7910B0 vtable offset = 0x0
    hand destinationIndoors(RootObject * r) const;// public RVA = 0x791FD0
    int destinationInsideWalls(RootObject * r);// public RVA = 0x790D90
    void setDestinationIndoors(const hand & h);// public RVA = 0x7BF300
    // no_addr void setDestinationInsideWalls(int _a1);// public missing arg names
    virtual float getIntendedAggression();// public RVA = 0x598410 vtable offset = 0x0
    float _NV_getIntendedAggression();// public RVA = 0x598410 vtable offset = 0x0
    Ogre::Vector3 getPositionBip01();// public RVA = 0x2ADB60
    virtual int amInsideTownWalls();// public RVA = 0x790FA0 vtable offset = 0x0
    int _NV_amInsideTownWalls();// public RVA = 0x790FA0 vtable offset = 0x0
    virtual void setName(const std::string & name);// public RVA = 0x5CBB50 vtable offset = 0x0
    void _NV_setName(const std::string & name);// public RVA = 0x5CBB50 vtable offset = 0x0
    void setNameTagVisible(bool value);// public RVA = 0x5C8430
    void ragdollMode(bool on, RagdollPart::Enum part);// public RVA = 0x5CB5E0
    bool isRagdoll() const;// public RVA = 0x7D01E0
    bool isDown();// public RVA = 0x28D910
    Ogre::Vector3 getRagdollPhysicsRootPos();// public RVA = 0x7D0490
    virtual bool amSomeoneWhoNeedsToEatToLive();// public RVA = 0x5C9610 vtable offset = 0x340
    bool _NV_amSomeoneWhoNeedsToEatToLive();// public RVA = 0x5C9610 vtable offset = 0x340
    virtual float getMagicHungerSetting();// public RVA = 0x5C9520 vtable offset = 0x348
    float _NV_getMagicHungerSetting();// public RVA = 0x5C9520 vtable offset = 0x348
    bool wantsToEatNow();// public RVA = 0x5C77F0
    virtual bool isKidnapped();// public RVA = 0x790AF0 vtable offset = 0x350
    bool _NV_isKidnapped();// public RVA = 0x790AF0 vtable offset = 0x350
    virtual bool isLiterallyUnconciousNotPretending() const;// public RVA = 0x5C9670 vtable offset = 0x358
    bool _NV_isLiterallyUnconciousNotPretending() const;// public RVA = 0x5C9670 vtable offset = 0x358
    virtual bool isUnconcious() const;// public RVA = 0x5C9690 vtable offset = 0x0
    bool _NV_isUnconcious() const;// public RVA = 0x5C9690 vtable offset = 0x0
    virtual bool isCrippled() const;// public RVA = 0x5E1770 vtable offset = 0x360
    bool _NV_isCrippled() const;// public RVA = 0x5E1770 vtable offset = 0x360
    virtual ProneState getProneState() const;// public RVA = 0x5C7690 vtable offset = 0x368
    ProneState _NV_getProneState() const;// public RVA = 0x5C7690 vtable offset = 0x368
    virtual void setProneState(ProneState p);// public RVA = 0x5C76A0 vtable offset = 0x370
    void _NV_setProneState(ProneState p);// public RVA = 0x5C76A0 vtable offset = 0x370
    void _killRagdoll(bool doItNow);// public RVA = 0x5D25A0
    bool isCurrentlyGettingUp; // 0x278 Member
    unsigned char isGettingEaten; // 0x279 Member
    virtual bool giveBirth(GameDataCopyStandalone * appearance, const Ogre::Vector3 & position, const Ogre::Quaternion & rotation, GameSaveState * state, ActivePlatoon * tempplatoonptr, Faction * _faction);// public RVA = 0x62AA90 vtable offset = 0x378
    bool _NV_giveBirth(GameDataCopyStandalone * appearance, const Ogre::Vector3 & position, const Ogre::Quaternion & rotation, GameSaveState * state, ActivePlatoon * tempplatoonptr, Faction * _faction);// public RVA = 0x62AA90 vtable offset = 0x378
    void setupAI();// public RVA = 0x6213F0
    void clearAllAIGoals();// public RVA = 0x621800
    void setupPlatoonAI();// public RVA = 0x620C60
    void setAppearanceData(GameDataCopyStandalone * data);// public RVA = 0x5B9710
    GameDataCopyStandalone * getAppearanceData();// public RVA = 0xCD330
    void setDestination(const Ogre::Vector3 & pos, bool shift);// public RVA = 0x5C8E30
    bool sendDialogEventOverride(Character * target, EventTriggerEnum what, bool forceRepeat);// public RVA = 0x684FB0
    bool sendDialogEvent(Character * target, EventTriggerEnum what);// public RVA = 0x6848F0
    void sayALine(const std::string & line, bool force);// public RVA = 0x67FDC0
    Dialogue * dialogue; // 0x280 Member
    bool hasDialogue() const;// public RVA = 0x67A480
    bool willTalkToEnemies();// public RVA = 0x67A4A0
    void relocationTeleport(const Ogre::Vector3 & moveBy);// public RVA = 0x5C7CE0
    void teleport(const Ogre::Vector3 & moveBy, const Ogre::Quaternion & rot);// public RVA = 0x5C7D60
    void teleport(const Ogre::Vector3 & moveBy);// public RVA = 0x5C9F00
    void teleportVisuallyOnly(const Ogre::Vector3 & to, const Ogre::Quaternion & rot);// public RVA = 0x5C7DC0
    void teleportFromAnimation();// public RVA = 0x5C7E10
    void debugIndicateCharacters(lektor<Character *> list);// public RVA = 0x5CB040
    void attackTarget(Character * who);// public RVA = 0x5CA920
    void notifyTheCampaignOfAnAttack(Character * attacker);// public RVA = 0x998480
    bool iShouldntAggravateThisTarget(Character * target);// public RVA = 0x855410
    void sendMessage(CharacterMessage message, RootObject * sender, RootObject * subject);// public RVA = 0x5C8AD0
    void attackingYou(Character * attacker, bool so, bool doAwarenessCheck);// public RVA = 0x5C8B10
    bool iShotYou(Character * attacker, Harpoon * poon, bool onPurpose);// public RVA = 0x439510
    virtual HitMaterialType hitByMeleeAttack(CutDirection dir, Damages & damage, Character * who, CombatTechniqueData * attack, int comboID);// public RVA = 0x438D70 vtable offset = 0x0
    HitMaterialType _NV_hitByMeleeAttack(CutDirection dir, Damages & damage, Character * who, CombatTechniqueData * attack, int comboID);// public RVA = 0x438D70 vtable offset = 0x0
    virtual bool gettingEaten(float amount, Character * eater);// public RVA = 0x434F70 vtable offset = 0x380
    bool _NV_gettingEaten(float amount, Character * eater);// public RVA = 0x434F70 vtable offset = 0x380
    void _startStumble(CutDirection dir, Damages & damage, GameData * bodyPart, Character * attacker);// public RVA = 0x438A70
    CutOrigination getAttackOriginationDirection(Character * attacker);// public RVA = 0x434E80
    CutDirection convertCutDirection(CutDirection dir, CutOrigination from);// public RVA = 0x434F40
    CutDirection convertCutDirection(CutDirection cut, Character * attacker);// public RVA = 0x435DA0
    bool stumbleState();// public RVA = 0x434DF0
    virtual void setAge(float f);// public RVA = 0x5E51F0 vtable offset = 0x388
    void _NV_setAge(float f);// public RVA = 0x5E51F0 vtable offset = 0x388
    std::string currentStumblePainAnimation; // 0x288 Member
    virtual void setFaction(Faction * p, ActivePlatoon * a);// public RVA = 0x5CB340 vtable offset = 0x0
    void _NV_setFaction(Faction * p, ActivePlatoon * a);// public RVA = 0x5CB340 vtable offset = 0x0
    virtual float getAge() const;// public RVA = 0x5E5200 vtable offset = 0x390
    float _NV_getAge() const;// public RVA = 0x5E5200 vtable offset = 0x390
    virtual float getAge0to1() const;// public RVA = 0x5E5210 vtable offset = 0x398
    float _NV_getAge0to1() const;// public RVA = 0x5E5210 vtable offset = 0x398
    virtual std::string getAgeString() const;// public RVA = 0x886B00 vtable offset = 0x3A0
    std::string _NV_getAgeString() const;// public RVA = 0x886B00 vtable offset = 0x3A0
    virtual float getAgeInverse() const;// public RVA = 0x5E5220 vtable offset = 0x3A8
    float _NV_getAgeInverse() const;// public RVA = 0x5E5220 vtable offset = 0x3A8
    void reThinkCurrentAIAction();// public RVA = 0x5C7BB0
    CharBody * getBody();// public RVA = 0x286260
    CombatClass * getCombatClass() const;// public RVA = 0x5C8B30
    CharStats * getStats();// public RVA = 0xDEE40
    MedicalSystem * getMedical();// public RVA = 0xCD340
    Ownerships * getOwnerships() const;// public RVA = 0x794440
    AI * getAI();// public RVA = 0x268220
    void getSquadMissionTarget(hand & h);// public RVA = 0x791BA0
    hand getAttackTarget() const;// public RVA = 0x435020
    bool isInCombatMode(bool melee, bool ranged) const;// public RVA = 0x435E90
    bool isInRangedCombatMode() const;// public RVA = 0x435F30
    bool isLiterallyUnderMeleeAttackRightNowForSure() const;// public RVA = 0x333820
    bool _isLiterallyUnderMeleeAttackRightNowForSure; // 0x2B0 Member
    void _isLiterallyUnderMeleeAttackRightNowForSure_update();// private RVA = 0x437170
    CharacterMemory * _myMemory; // 0x2B8 Member
    unsigned int conglomerateTagsFor(Character * who);// private RVA = 0x6710B0
    bool isPrisonerFreeToGo();// public RVA = 0x5C9780
    void clearTempEnemyStatus(Character * theEnemy);// public RVA = 0x67A520
    void clearAllTempEnemyStatuses(CharacterPerceptionTags_ShortTerm tag);// public RVA = 0x6716F0
    void rememberCharacter(Character * who, CharacterPerceptionTags_ShortTerm mem);// public RVA = 0x673D20
    void rememberCharacter(Character * who, CharacterPerceptionTags_LongTerm mem);// public RVA = 0x6732A0
    bool getCharacterMemoryTag(Character * who, CharacterPerceptionTags_LongTerm mem);// public RVA = 0x6745F0
    bool getCharacterMemoryTag(Character * who, CharacterPerceptionTags_ShortTerm mem);// public RVA = 0x6781E0
    float lastSeenInHoursAgo(Character * c);// public RVA = 0x6732E0
    bool haveMetBefore(Character * h);// public RVA = 0x674640
    hand getIDForMemoryTagging();// public RVA = 0x671300
    hand lastGuyWhoDefeatedMe; // 0x2C0 Member
    CharMovement * getMovement();// public RVA = 0x645B0
    virtual void lookatPosition(const Ogre::Vector3 & v, bool fullbodyFacing);// public RVA = 0x5C96F0 vtable offset = 0x3B0
    void _NV_lookatPosition(const Ogre::Vector3 & v, bool fullbodyFacing);// public RVA = 0x5C96F0 vtable offset = 0x3B0
    bool areYouGonnaGetMe(Character * who);// public RVA = 0x5C9F70
    lektor<hand> & getAllAttackers(lektor<hand> & out);// public RVA = 0x5CA9D0
    int getAllAttackersCount();// public RVA = 0x5C9F90
    virtual RaceData * getRace() const;// public RVA = 0x5E1780 vtable offset = 0x0
    RaceData * _NV_getRace() const;// public RVA = 0x5E1780 vtable offset = 0x0
    virtual void setRace(GameData * r);// public RVA = 0x5C8C50 vtable offset = 0x3B8
    void _NV_setRace(GameData * r);// public RVA = 0x5C8C50 vtable offset = 0x3B8
    RaceData * myRace; // 0x2E0 Member
    float getRadius();// public RVA = 0x5C7C30
    bool isPlayerCharacter() const;// public RVA = 0x790470
    bool checkPlayerOrderForProblems(TaskType t, RootObject * subject);// public RVA = 0x5D11C0
    bool breakFollowOrderLoop(const hand & start);// public RVA = 0x5C8490
    Inventory * inventory; // 0x2E8 Member
    float getTotalCarryWeight();// public RVA = 0x5C8250
    virtual Weapon * getCurrentWeapon() = 0;// public vtable offset = 0x3C0
    virtual Weapon * getThePreferredWeapon() = 0;// public vtable offset = 0x3C8
    virtual Crossbow * getRangedWeapon();// public RVA = 0x5E1790 vtable offset = 0x3D0
    Crossbow * _NV_getRangedWeapon();// public RVA = 0x5E1790 vtable offset = 0x3D0
    virtual bool drawWeapon(Item * _a1, std::string _a2) = 0;// public vtable offset = 0x3D8 missing arg names
    Item * getUpperBodyArmour();// public RVA = 0x5CC1C0
    Item * getLowerBodyArmour();// public RVA = 0x5CC2F0
    bool isInjured(bool robot) const;// public RVA = 0x7BF340
    bool shouldUseRangedWeapons();// public RVA = 0x7F15E0
    RangedCombatClass * rangedCombat; // 0x2F0 Member
    Ogre::Vector3 getBoneWorldPosition(const std::string & name);// public RVA = 0x43FBE0
    AppearanceBase * getAppearance();// public RVA = 0x645C0
    // no_addr void getCopyOfStatsForModifying(class GameData * _a1);// public missing arg names
    // no_addr void updateModifiedStats(class GameData * _a1);// public missing arg names
    void _setPlatoon(ActivePlatoon * p, int idnum);// public RVA = 0x620C70
    ActivePlatoon * getPlatoon() const;// public RVA = 0x7908B0
    bool hasPlatoon() const;// public RVA = 0x5C5E20
    bool isInAPersistentPlatoon() const;// public RVA = 0x620CC0
    Blackboard * getBlackboard();// public RVA = 0x790940
    Character * getSquadLeader();// public RVA = 0x791FB0
    OrdersReceiver * getOrdersReciever() const;// public RVA = 0x620E10
    bool preventRagdollMode() const;// public RVA = 0x5C7070
    UseStuffState inSomething; // 0x2F8 Member
    hand inWhat; // 0x300 Member
    void setPrisonMode(bool on, UseableStuff * h);// public RVA = 0x330150
    void setBedMode(bool on, UseableStuff * h);// public RVA = 0x32DE40
    bool isChained; // 0x320 Member
    hand slaveOwner; // 0x328 Member
    void setSlaveAIJob(bool on);// public RVA = 0x32DC20
    void setChainedMode(bool on, const hand & owner);// public RVA = 0x32E0E0
    bool isChainedMode() const;// public RVA = 0x32DAB0
    LockedArmour * getChainedModeShackles();// public RVA = 0x5C8290
    hand getMySlaveOwner() const;// public RVA = 0x339D60
    SlaveStateEnum isSlave();// public RVA = 0x5C8320
    void changeSlaveOwner(const hand & newOwner);// public RVA = 0x32DF80
    bool isMySlave(Character * slave);// public RVA = 0x32DD30
    bool isMyFactionsSlave(Character * slave);// public RVA = 0x32DDF0
    virtual bool isHeadShaven() const;// public RVA = 0x5E17A0 vtable offset = 0x3E0
    bool _NV_isHeadShaven() const;// public RVA = 0x5E17A0 vtable offset = 0x3E0
    // no_addr void playSlaveAnim(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > & _a1, float _a2, float _a3);// public missing arg names
    void runSlaveAnim(const std::string & anim, float speed, float sync);// public RVA = 0x5B0930
    void endSlaveAnim(const std::string & anim);// public RVA = 0x334880
    void updatePortraitGUIState();// public RVA = 0x5C8180
    void pickupObject(Character * who);// public RVA = 0x5CF810
    void getPickedUp(Character * byWhom);// public RVA = 0x5CE610
    void slaveAttachToBoneMode(const std::string & bone);// public RVA = 0x5E7600
    bool isDead() const;// public RVA = 0x620E30
    bool isCarryingSomething; // 0x348 Member
    bool isBeingCarried() const;// public RVA = 0x14A980
    hand getCarryingObject() const;// public RVA = 0x339DB0
    std::string carringObjectLeftOrRight; // 0x350 Member
    bool isCarryingLeftSide; // 0x378 Member
    void chooseCarryObjectLeftOrRight();// public RVA = 0x621950
    void dropCarriedObject(bool ragdollHim, bool removeOnly);// public RVA = 0x5CDA60
    void getDropped(bool ragdollHim, bool hull);// public RVA = 0x5CC420
    float getDiplomacyMultiplier();// public RVA = 0x794DC0
    virtual bool isEnemy(Character * who, bool factorInDisguises);// public RVA = 0x79B6F0 vtable offset = 0x3E8
    bool _NV_isEnemy(Character * who, bool factorInDisguises);// public RVA = 0x79B6F0 vtable offset = 0x3E8
    virtual bool isAlly(Character * who, bool factorInDisguises);// public RVA = 0x791170 vtable offset = 0x3F0
    bool _NV_isAlly(Character * who, bool factorInDisguises);// public RVA = 0x791170 vtable offset = 0x3F0
    virtual unsigned int getDefaultTaskRepertoireEnum() const;// public RVA = 0x5E5230 vtable offset = 0x3F8
    unsigned int _NV_getDefaultTaskRepertoireEnum() const;// public RVA = 0x5E5230 vtable offset = 0x3F8
    AnimationClass * getAnimationClass();// public RVA = 0x645E0
    Ogre::Vector3 getPredictedPosition(float secondsInFuture);// public RVA = 0x434D50
    hand carryingObject; // 0x380 Member
    void carryModeT(bool on, bool makeRagdoll, bool makeHull);// public RVA = 0x5C81A0
    void _carryMode(bool on, bool makeRagdoll, bool makeHull);// public RVA = 0x5CE240
    void recalculateTotalEquipmentSkillBonus();// public RVA = 0x885880
    virtual void setupAudio();// public RVA = 0x6291C0 vtable offset = 0x400
    void _NV_setupAudio();// public RVA = 0x6291C0 vtable offset = 0x400
    unsigned __int64 getAudioObject() const;// public RVA = 0x43FCA0
    bool audioEvent(const char * name, SoundRange range);// public RVA = 0x5C92F0
    void audioValue(const char * name, float value) const;// public RVA = 0x5C9220
    void audioValue(const char * name, const char * value) const;// public RVA = 0x5C9200
    void setGroundType(GroundType t);// public RVA = 0x5CA840
    GroundType getGroundType();// public RVA = 0x5C91F0
    void calculateMainArmourType();// public RVA = 0x5D2130
    ArmourType getMainArmourType() const;// public RVA = 0x645F0
    virtual bool wearingUniformOf(Faction * f);// public RVA = 0x5E17B0 vtable offset = 0x408
    bool _NV_wearingUniformOf(Faction * f);// public RVA = 0x5E17B0 vtable offset = 0x408
    GameData * getUniformColorScheme();// public RVA = 0x52CED0
    bool canTakePlayerOrdersAtThisTime();// public RVA = 0x7F16E0
    bool startEffect(GameData * effect);// public RVA = 0x5CAEC0
    bool stopEffect(GameData * effect);// public RVA = 0x5CA0D0
    void stopAllEffects();// public RVA = 0x5CA1A0
    virtual void notifyEffect(EffectType::Enum type, WeatherAffecting what, float strength);// public RVA = 0x5CB540 vtable offset = 0x0
    void _NV_notifyEffect(EffectType::Enum type, WeatherAffecting what, float strength);// public RVA = 0x5CB540 vtable offset = 0x0
    virtual void equipItem(const std::string & sectionName, Item * item);// public RVA = 0x5DB600 vtable offset = 0x0
    void _NV_equipItem(const std::string & sectionName, Item * item);// public RVA = 0x5DB600 vtable offset = 0x0
    virtual void unequipItem(const std::string & sectionName, Item * item);// public RVA = 0x5DBB90 vtable offset = 0x0
    void _NV_unequipItem(const std::string & sectionName, Item * item);// public RVA = 0x5DBB90 vtable offset = 0x0
    virtual void validateInventorySections();// public RVA = 0x5E17C0 vtable offset = 0x410
    void _NV_validateInventorySections();// public RVA = 0x5E17C0 vtable offset = 0x410
    enum CharMessage
    {
        CHARMESSAGE_NONE,
        CHARMESSAGE_CARRY,
        CHARMESSAGE_CAGE    
    };

    Character::CharMessage messages; // 0x3A0 Member
    hand messageSubject; // 0x3A8 Member
    void processCharacterLoadTimeMessages();// protected RVA = 0x796C60
    Ogre::Vector3 ragdollNavmeshPosition; // 0x3C8 Member
    bool wantsPathfinderActive();// protected RVA = 0x6209D0
    virtual void createAnimationClass() = 0;// protected vtable offset = 0x418
    bool _isBeingCarried; // 0x3D4 Member
    WeaponCategory lastUsedWeaponCategory; // 0x3D8 Member
    struct RagdollMsg
    {
        RagdollMsg(bool on, RagdollPart::Enum part);// public RVA = 0x5C7080
        void _CONSTRUCTOR(bool on, RagdollPart::Enum part);// public RVA = 0x5C7080
        bool operator==(const Character::RagdollMsg & m) const;// public RVA = 0x5C7090
        bool on; // 0x0 Member
        RagdollPart::Enum part; // 0x4 Member
    };
    std::deque<Character::RagdollMsg,std::allocator<Character::RagdollMsg> > ragdollMessages; // 0x3E0 Member
    bool _ragdollMode(const Character::RagdollMsg & message);// protected RVA = 0x5D0630
    struct CarryMsg
    {
        bool on; // 0x0 Member
        bool rag; // 0x1 Member
        bool hull; // 0x2 Member
    };
    Character::CarryMsg * msgCarryMode; // 0x410 Member
    int squadMemberID; // 0x418 Member
    float diplomacyMultiplier; // 0x41C Member
    void calculateDestinationState(Building * dest, RootObject * subject, const Ogre::Vector3 & v);// protected RVA = 0x790B90
    hand _destinationInsideBuilding; // 0x420 Member
    int _destinationInsideWalls; // 0x440 Member
    Item * generateWeapon(GameData * weapon, GameData * manufacturer);// protected RVA = 0x621830
    virtual bool createPhysical();// protected RVA = 0x5CBB90 vtable offset = 0x0
    bool _NV_createPhysical();// protected RVA = 0x5CBB90 vtable offset = 0x0
    virtual void destroyPhysical();// protected RVA = 0x5C8D10 vtable offset = 0x0
    void _NV_destroyPhysical();// protected RVA = 0x5C8D10 vtable offset = 0x0
    bool createComponents(GameDataCopyStandalone * appearance);// protected RVA = 0x62A7D0
    AnimationClass * animation; // 0x448 Member
    CharStats * stats; // 0x450 Member
    MedicalSystem medical; // 0x458 Member
    virtual void loadUnloadCheck();// protected RVA = 0x5C8C90 vtable offset = 0x0
    void _NV_loadUnloadCheck();// protected RVA = 0x5C8C90 vtable offset = 0x0
    bool isPhysicalMode; // 0x608 Member
    std::string sex; // 0x610 Member
    CharacterNameTag * nameTag; // 0x638 Member
    void updateStateBroadcast(float time);// protected RVA = 0x8514A0
    CharMovement * movement; // 0x640 Member
    CharBody * body; // 0x648 Member
    AI * ai; // 0x650 Member
    ActivePlatoon * platoon; // 0x658 Member
    short portraitIndex; // 0x660 Member
    unsigned int portraitSerial; // 0x664 Member
    unsigned __int64 audioObject; // 0x668 Member
    AkSoundPosition audioData; // 0x670 Member
    GroundType groundType; // 0x688 Member
    ArmourType armourType; // 0x68C Member
    SoundEmitter * audioEmitter; // 0x690 Member
    float terrainHeightPosition; // 0x698 Member
    char inDoorsSetCooldown; // 0x69C Member
    lektor<std::pair<WeatherAffecting,float> > activeEffects; // 0x6A0 Member
    lektor<Effect *> particleEffects; // 0x6B8 Member
    void setEffectBT(GameData * effect, bool active);// protected RVA = 0x5CD120
    virtual void postRagdollCallback(bool on, RagdollPart::Enum part);// protected RVA = 0x5CB810 vtable offset = 0x420
    void _NV_postRagdollCallback(bool on, RagdollPart::Enum part);// protected RVA = 0x5CB810 vtable offset = 0x420
    Sword * naturalWeapon; // 0x6D0 Member
    virtual void reCalculateNaturalWeapon();// protected RVA = 0x62A2E0 vtable offset = 0x428
    void _NV_reCalculateNaturalWeapon();// protected RVA = 0x62A2E0 vtable offset = 0x428
    // no_addr class Character & operator=(const class Character & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};
