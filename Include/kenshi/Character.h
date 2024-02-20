#pragma once


#include "RootObject.h"
#include "MedicalSystem.h"
#include "TimeOfDay.h"
#include "util/YesNoMaybe.h"

#include <ogre/OgreVector3.h>

#include "util/OgreUnordered.h"

enum ProneState
{
    PS_NORMAL,
    PS_STAYING_LOW,
    PS_CRIPPLED,
    PS_PLAYING_DEAD,
    PS_KO
};

enum SquadMemberType
{
    SQUAD_1,
    SQUAD_2,
    SQUAD_LEADER,
    SQUAD_SIGNALS_PLAN,
    SQUAD_SLAVE
};

enum CrimeEnum
{
    CRIME_NONE,
    CRIME_ENSLAVING,
    CRIME_LOCKPICKING,
    CRIME_STEALING,
    CRIME_MURDER,
    CRIME_ASSAULT,
    CRIME_ASSAULT_VIP,
    CRIME_SLAVE_FREEING,
    CRIME_SMUGGLING,
    CRIME_TERRORISM,
    CRIME_LOOTING,
    CRIME_TRESSPASSING,
    CRIME_ESCAPE_PRISON,
    CRIME_FENCING,
    CRIME_FARM_EATING,
    CRIME_KIDNAPPING,
    CRIME_UNIFORM_THEFT,
    CRIME_END
};

class Bounty
{
public:
    Bounty();// public RVA = 0x6A59D0
    int amount; // 0x0 Member
    unsigned int crimes; // 0x4 Member
    bool bountyHasBeenClaimedOnce; // 0x8 Member
    TimeOfDay bountyAssignmentStartedTime; // 0x10 Member
    void addCrime(CrimeEnum what);// public RVA = 0x6A54D0
    bool hasCrime(CrimeEnum t);// public RVA = 0x497570
    // no_addr class Bounty & operator=(const class Bounty &);// public
};

class Character;

// TODO move?
class BountyManager
{
public:
    ogre_unordered_map<Faction*, Bounty>::type bounties; // 0x0 Member
    Character* me; // 0x40 Member
    Faction* _getBountyFaction(Faction* f);// private RVA = 0x6A5A10
    Faction* _getHighestBountyFaction();// private RVA = 0x6A70E0
    Faction* _hasAccessPass; // 0x48 Member
    TimeOfDay accessPassExpirationTime; // 0x50 Member
    // no_addr void BountyManager(const class BountyManager &);// public
    BountyManager(Character* c);// public RVA = 0x4F9DD0
    int getPercievedBounty(Character* whosLooking);// public RVA = 0x6A79D0
    int getActualBounty(Faction* whosLooking);// public RVA = 0x6A7A80
    void notifyPlayerClaimBounty(Faction* whosLooking);// public RVA = 0x6A7B70
    bool bountyAlreadyBeenClaimedByPlayer(Faction* whosLooking);// public RVA = 0x6A7C70
    void assignBountyForCrimes(Faction* enforcer);// public RVA = 0x6A78C0
    void unfairAddToBounty(Faction* enforcer, int amount);// public RVA = 0x6A7820
    int getBountyRecognitionThreshold();// public RVA = 0x6A5AC0
    void clearBounty(Faction* enforcer);// public RVA = 0x6A73F0
    int getTotalBounty() const;// public RVA = 0x6A7140
    void update(float frameTime);// public RVA = 0x49B900
    StringPair getGUIData(lektor<StringPair>& outs);// public RVA = 0x4A2B20
    void getGUIDataForAppend(lektor<StringPair>& outs);// public RVA = 0x4A1180
    std::string getBountyExpiryStringForGUI();// public RVA = 0x4A0E90
    void load(GameData* state);// public RVA = 0x4E4EB0
    void save(GameData* state);// public RVA = 0x4E5300
    bool setCrime(CrimeEnum crime, Faction* against, const hand& agnst);// public RVA = 0x6A6680
    void notifyCrimeWitnessed(Faction* against, const hand& againstWho, int expirytime, CrimeEnum what);// public RVA = 0x6A6810
    void notifyPossibleCrimeWitnessed(float time);// public RVA = 0x6A5940
    CrimeEnum committingCrime; // 0x58 Member
    Faction* crimeAgainstFaction; // 0x60 Member
    Faction* usingTrainingEquipmentOf; // 0x68 Member
    hand crimeAgainst; // 0x70 Member
    float crimeExpiry; // 0x90 Member
    TimeOfDay prisonSentenceBeganTime; // 0x98 Member
    float prisonSentenceToServe; // 0xA0 Member
    bool _hadABountyAssignedForCurrentCrime; // 0xA4 Member
    bool isCommittingCrime() const;// public RVA = 0x6A54F0
    void notifyStartPrisonSentence(Faction* law);// public RVA = 0x6A8350
    bool hasAccessPass(Faction* forFac) const;// public RVA = 0x6A5500
    void giveAccessPass(Faction* who, float minutes);// public RVA = 0x282220
    static std::string crimeToStr(CrimeEnum c);// public RVA = 0x6A9F30
    static int getBountyForCrime(CrimeEnum c);// public RVA = 0x6A5840
    static int getPrisonSentenceInHours(int bounty);// public RVA = 0x6A58D0
    static float getBountyExpirationTime(int bounty);// public RVA = 0x6A5910
    ~BountyManager();// public RVA = 0x4F9EB0
    // no_addr class BountyManager & operator=(const class BountyManager &);// public
    // no_addr void * __vecDelDtor(unsigned int);// public
};

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

enum MoveSpeed
{
    WALK,
    JOG,
    RUN,
    GROUPED,
    NO_SPEED_CHANGE
};

class RagdollPart // TODO this isn't in the symbols
{
public:
    enum Enum {};
};

enum CharacterMessage
{
    ATTACKING_MELEE
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

enum SoundRange
{
    SOUNDRANGE_SHORT = 0xFFFF9C40,
    SOUNDRANGE_LONG = 0xF4240,
    SOUNDRANGE_ALWAYS = 0x0
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

class DoorLock;

// TODO move?
struct AkVector
{
    float X; // 0x0 Member
    float Y; // 0x4 Member
    float Z; // 0x8 Member
};
struct AkSoundPosition
{
    AkVector Position; // 0x0 Member
    AkVector Orientation; // 0xC Member
};

class Effect;
class CampaignInstance;
class Formation;
class ContainerItem; 
class Tasker;
class Dialogue;
class Harpoon;
class CharBody;
class CombatClass;
class AI;
class CharacterMemory;
class CharMovement;
class RangedCombatClass;
class AppearanceBase;
class Blackboard;
class OrdersReceiver;
class UseableStuff;
class LockedArmour;
class CharacterNameTag;
class CharMovement;
class SoundEmitter;
class Sword;
class Crossbow;
class StorageBuilding;
class GameDataCopyStandalone;
class CharacterAnimal;
class CharacterHuman;
class Weapon;

class Character : public RootObject, public Ogre::GeneralAllocatedObject
{
public:
    // RootObject offset = 0x0, length = 0xC0
    // Ogre::GeneralAllocatedObject offset = 0xC0, length = 0x1
    // no_addr void Character(class Character &);// public
    Character(GameData* dat, Faction* own, const hand& _handle);// protected RVA = 0x4E1440
    bool isImmuneToOffscreenMode();// protected RVA = 0x497740
    virtual void init();// protected RVA = 0x4E01E0 vtable offset = 0x228
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
    virtual ~Character();// public RVA = 0x4E1AD0 vtable offset = 0x0
    bool isVisibleUpdateMode; // 0xE4 Member
    bool setVisibleMsg; // 0xE5 Member
    YesNoMaybe stealthUnseen; // 0xE8 Member
    virtual bool isOnARoof();// public RVA = 0x4AC7C0 vtable offset = 0x0
    virtual bool isOnAWall();// public RVA = 0x498840 vtable offset = 0x230
    float getLightLevel();// public RVA = 0x4FC1B0
    virtual float getHPMultiplier() const;// public RVA = 0x4AFAF0 vtable offset = 0x238
    void healCompletely();// public RVA = 0x4FECA0
    void resetRagdollNavmeshSafePos();// public RVA = 0x63D610
    void setRagdollNavmeshSafePos();// public RVA = 0x511EB0
    float getFrameTime() const;// public RVA = 0x27A190
    void frameSkip();// public RVA = 0x6036F0
    float getCurrentNoiseRange();// public RVA = 0x6A5710
    virtual bool isDestroyed() const;// public RVA = 0x4AC800 vtable offset = 0x240
    bool isLawEnforcement();// public RVA = 0x4729F0
    bool canAssignBounties();// public RVA = 0x47D860
    virtual itemType getDataType() const;// public RVA = 0x4AC810 vtable offset = 0x0
    bool isDiplomaticStatus(bool factorInBiome);// public RVA = 0x60E840
    bool isLeadingAWarCampaign();// public RVA = 0x7D2D50
    CampaignInstance* isInAWarCampaign();// public RVA = 0x7D2DD0
    bool playerWantsMeToGetUp; // 0xEC Member
    bool wantsToTriggerCampaigns();// public RVA = 0x7D2FB0
    bool isUnique();// public RVA = 0x3FAB50
    bool canSpeakNormally();// public RVA = 0x4B2250
    virtual CharacterAnimal* isAnimal();// public RVA = 0x4AFB00 vtable offset = 0x248
    virtual CharacterHuman* isHuman();// public RVA = 0x4AC820 vtable offset = 0x250
    virtual bool takeMoney(int n);// public RVA = 0x60EBF0 vtable offset = 0x0
    virtual int getMoney() const;// public RVA = 0x609C60 vtable offset = 0x0
    void setSquadMemberType(SquadMemberType memType);// public RVA = 0x4E0610
    TownBase* isResident() const;// public RVA = 0x49E370
    BountyManager crimes; // 0xF0 Member
    StatsEnumerated currentSkillUsing; // 0x198 Member
    void dailyUpdate();// public RVA = 0x4A2510
    StateBroadcastData* stateBroadcast; // 0x1A0 Member
    bool isVisibleAndNear; // 0x1A8 Member
    bool isOnScreen; // 0x1A9 Member
    bool updateOnScreenCheck();// public RVA = 0x499CE0
    void offscreenUpdate();// public RVA = 0x497820
    void updateTimes();// public RVA = 0x497860
    virtual SensoryData* getSensoryData();// public RVA = 0x498480 vtable offset = 0x0
    virtual StateBroadcastData* getStateBroadcast();// public RVA = 0x4AC830 vtable offset = 0x0
    virtual Formation* getFormation() const;// public RVA = 0x499660 vtable offset = 0x258
    virtual Formation* getEnemyFormation() const;// public RVA = 0x499680 vtable offset = 0x260
    void formationUpdateCallback(const Ogre::Vector3& pos, const hand& target, const Ogre::Vector3& heading, Formation* from);// public RVA = 0x4996A0
    bool AIDestinationIndoorOutdoorCheck(RootObject* who);// public RVA = 0x3FFA00
    virtual void setHandle(const hand& h);// public RVA = 0x4E2970 vtable offset = 0x0
    virtual void update();// public RVA = 0x49EEB0 vtable offset = 0x0
    virtual void postUpdate();// public RVA = 0x49D7A0 vtable offset = 0x268
    void ragdollUpdatesUT();// public RVA = 0x4A29B0
    void fourFrameUpdate();// public RVA = 0x49FB10
    virtual void periodicUpdate();// public RVA = 0x49CB10 vtable offset = 0x0
    virtual void pausedUpdate();// public RVA = 0x4978A0 vtable offset = 0x270
    void updateUT();// public RVA = 0x497970
    virtual void threadedUpdate();// public RVA = 0x4979B0 vtable offset = 0x0
    virtual void threadedUpdate4();// public RVA = 0x497AC0 vtable offset = 0x278
    virtual void threadedUpdatePeriodic();// public RVA = 0x49FE30 vtable offset = 0x280
    bool pathExists(const Ogre::Vector3& v);// public RVA = 0x511350
    virtual void weatherUpdate(float);// public RVA = 0x497CE0 vtable offset = 0x288
    void stealthUpdate(float _time);// public RVA = 0x6AC0D0
    float lineOfSightCheck(Character* who);// public RVA = 0x6A7020
    float getPerceptionMult();// public RVA = 0x6A63C0
    bool isWithThePlayer();// public RVA = 0x6AA5C0
    void notifyICanSeeYouSneaking(Character* who, YesNoMaybe* seeing, float maybeProgress01);// public RVA = 0x6A9930
    bool isItSafeToGetUp();// public RVA = 0x49A1D0
    Platoon* separateIntoMyOwnSquad(bool permanent);// public RVA = 0x49E260
    void dropGearOnDeath(bool vampiricDeath);// public RVA = 0x49B590
    virtual bool isItOkForMeToLoot(RootObject* _victim, Item* item);// public RVA = 0x60BF40 vtable offset = 0x290
    virtual bool ImStealingDoYouNotice(RootObject* stealFrom, Item* item);// public RVA = 0x60CE10 vtable offset = 0x298
    float getFencingSuccessChance(Item* item, RootObject* thief);// public RVA = 0x60BA90
    virtual bool stolenGoodsDetectionCheck(Item* item, RootObject* thief);// public RVA = 0x60BD70 vtable offset = 0x0
    virtual bool sellingUniformDetectionCheck(Item* item, Character* thief);// public RVA = 0x60BCC0 vtable offset = 0x2A0
    virtual YesNoMaybe smugglingTradeCheck(Item* item, Character* who);// public RVA = 0x60D480 vtable offset = 0x2A8
    float getStealingSuccessChance(RootObject* stealFrom, Item* item, Character** victimOut);// public RVA = 0x60CAD0
    WeatherAffecting getCurrentWeatherAffectStatus() const;// public RVA = 0x498440
    float getCurrentWeatherAffectStrength() const;// public RVA = 0x498460
    WaterState::Enum getWaterLevel();// public RVA = 0x497D50
    void setTerrainHeightPosition(float height);// public RVA = 0x497580
    float getTerrainHeightPosition();// public RVA = 0x485260
    enum DisguiseGUIFeedback
    {
        DGF_SAME_FACTION,
        DGF_MY_SLAVE,
        DGF_I_HATE_YOU
    };

    void setDisguiseMessage(Character::DisguiseGUIFeedback msg);// public RVA = 0x6B3A70
    ogre_unordered_map<Character::DisguiseGUIFeedback, float>::type disguiseGUIFeedbacks; // 0x1B0 Member
    class WhoSeesMe
    {
    public:
        // no_addr void WhoSeesMe(class Character::WhoSeesMe &);// public
        WhoSeesMe(double timestamp, YesNoMaybe* what, float prog);// public RVA = 0x6AF060
        WhoSeesMe();// public RVA = 0x6AF050
        double lastUpdated; // 0x0 Member
        YesNoMaybe seeState; // 0x8 Member
        float progressOfMaybe; // 0xC Member
    };
    ogre_unordered_map<hand, Character::WhoSeesMe>::type whoSeesMeSneaking; // 0x1F0 Member
    class AttachedArrowManager
    {
    public:
        ~AttachedArrowManager();// public RVA = 0x49ADD0
        void clearAll();// public RVA = 0x49A330
        void updateStart();// public RVA = 0x4980A0
        void addArrow(Ogre::Vector3& pos, Ogre::Vector3& targ, int color);// public RVA = 0x4AC550
        void updateEnd();// public RVA = 0x49A3A0
        lektor<Ogre::Entity*> ents; // 0x0 Member
        int index; // 0x18 Member
        // no_addr void AttachedArrowManager(const class Character::AttachedArrowManager &);// public
        AttachedArrowManager();// public RVA = 0x4F1DB0
        // no_addr class Character::AttachedArrowManager & operator=(const class Character::AttachedArrowManager &);// public
        // no_addr void * __vecDelDtor(unsigned int);// public
    };
    Character::AttachedArrowManager stealthMarkerArrows; // 0x230 Member
    void uniqueStateUpdate();// protected RVA = 0x49F1F0
    virtual void foodUpdate();// protected RVA = 0x4A2740 vtable offset = 0x2B0
    bool eatItem(Item* food, Inventory* from);// public RVA = 0x4A0500
    virtual GameSaveState serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract);// public RVA = 0x4E70F0 vtable offset = 0x0
    virtual void loadFromSerialise(GameSaveState* state);// public RVA = 0x4E5FA0 vtable offset = 0x0
    virtual void loadFromSerialisePostCreationStage(GameSaveState* gd);// public RVA = 0x4E6B80 vtable offset = 0x2B8
    virtual bool setupInventorySections(GameSaveState* state);// public RVA = 0x4E1ED0 vtable offset = 0x2C0
    virtual Ogre::Vector3 getPosition();// public RVA = 0x49E400 vtable offset = 0x0
    Ogre::Vector3 _getRawPosition() const;// public RVA = 0x5166D0
    Ogre::Vector3 getRawEntityPosition();// public RVA = 0x497E50
    virtual float getMovementSpeed() const;// public RVA = 0x498150 vtable offset = 0x0
    virtual MoveSpeed getMovementSpeedOrders() const;// public RVA = 0x498190 vtable offset = 0x2C8
    virtual Ogre::Vector3 getMovementDirection() const;// public RVA = 0x4981B0 vtable offset = 0x0
    // no_addr int getSquadMemberID();// public
    virtual bool isPhysical() const;// public RVA = 0x498540 vtable offset = 0x0
    virtual void setVisible(bool on);// public RVA = 0x498570 vtable offset = 0x0
    virtual bool getVisible() const;// public RVA = 0x498600 vtable offset = 0x0
    void switchLights(bool on);// public RVA = 0x41A380
    virtual bool isDisabled();// public RVA = 0x498630 vtable offset = 0x0
    virtual void setInsideTownWalls(int s);// public RVA = 0x60A5E0 vtable offset = 0x0
    virtual void sheatheWeapon();// public RVA = 0x4FA3F0 vtable offset = 0x2D0
    virtual void select();// public RVA = 0x499270 vtable offset = 0x0
    virtual void unselect();// public RVA = 0x4992A0 vtable offset = 0x0
    virtual void getGUIData(DatapanelGUI* datapanel, int category);// public RVA = 0x4A3FE0 vtable offset = 0x0
    virtual TownBase* getCurrentTownLocation();// public RVA = 0x498730 vtable offset = 0x0
    virtual void say_WithARepeatLimiter(const std::string& s);// public RVA = 0x49AC90 vtable offset = 0x2D8
    virtual void say(const std::string& s);// public RVA = 0x4996D0 vtable offset = 0x0
    virtual bool isInventoryVisible() const;// public RVA = 0x4992D0 vtable offset = 0x2E0
    virtual bool giveItem(Item* item, bool dropOnFail, bool destroyOnFail);// public RVA = 0x49B180 vtable offset = 0x0
    virtual bool hasRoomForItem(GameData* item);// public RVA = 0x49B2A0 vtable offset = 0x0
    virtual bool hasItem(GameData* item);// public RVA = 0x49B330 vtable offset = 0x0
    virtual bool hasAmmoFor(Crossbow* c);// public RVA = 0x499300 vtable offset = 0x2E8
    virtual int getNumFoodItems();// public RVA = 0x4706C0 vtable offset = 0x2F0
    virtual bool hasSimilarItem(itemType ty);// public RVA = 0x49C2E0 vtable offset = 0x2F8
    bool ifImASmithShouldIDitchMyBackWeapon();// public RVA = 0x49C230
    virtual bool hasItemsFrom(StorageBuilding* from, ogre_unordered_set<GameData*>::type& allTheOnesWeHave);// public RVA = 0x47D900 vtable offset = 0x300
    virtual Inventory* getInventory() const;// public RVA = 0x4AC840 vtable offset = 0x0
    ContainerItem* hasABackpackOn() const;// public RVA = 0x49B0A0
    bool isATrader() const;// public RVA = 0x49FCF0
    bool isFemale();// public RVA = 0x1FEDA0
    bool isFleeing();// public RVA = 0x499910
    virtual InventoryLayout* createInventoryLayout();// public RVA = 0x49B6F0 vtable offset = 0x0
    bool _isEngagedWithAPlayer; // 0x250 Member
    hand isUsingTurret; // 0x258 Member
    float getStealthKOChance(Character* victim, bool factors);// public RVA = 0x6CF490
    float getKidnappingChance(Character* victim);// public RVA = 0x6CF7A0
    float getKidnappingEscapeChance_skill(Character* captor);// public RVA = 0x6CFA60
    float getKidnappingEscapeChance_strength(Character* captor);// public RVA = 0x6CFCB0
    float getLockpickChance(DoorLock* victim);// public RVA = 0x6CFE30
    bool shouldIHelpThisGuy(Character* who);// public RVA = 0x473A60
    bool shouldIScrewThisGuyOver(Character* who);// public RVA = 0x473BA0
    bool ILoveThisGuyBecauseOfStuffThatHappened(Character* who);// public RVA = 0x472980
    bool IHateThisGuyBecauseOfStuffThatHappened(Character* who);// public RVA = 0x4729C0
    int getRoughLevel();// public RVA = 0x473D10
    virtual void setStandingOrder(MessageForB::StandingOrder orderID, bool on);// public RVA = 0x49A7D0 vtable offset = 0x308
    bool getStandingOrder(MessageForB::StandingOrder orderID) const;// public RVA = 0x499440
    void setStealthMode(bool on);// public RVA = 0x49A720
    bool isStealthMode() const;// public RVA = 0x4994D0
    bool isStealthModeOrCrawling() const;// public RVA = 0x5166F0
    void declareDead();// public RVA = 0x61E800
    void updateGUIStatsDetails(DatapanelGUI* datapanel, const std::string& name, int statId, StatsEnumerated);// public RVA = 0x6F3D00
    void _printRaceXPBonusLine(DatapanelGUI* panel, StatsEnumerated s);// public RVA = 0x6EDA30
    void addGoal(TaskType t, RootObjectBase* subject);// public RVA = 0x498DA0
    // no_addr void removeGoal(enum TaskType);// public
    void addJob(TaskType t, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location);// public RVA = 0x498B20
    void removeJob(TaskType t);// public RVA = 0x498C30
    void removePermajob(int t);// public RVA = 0x498D80
    void clearPermajobs();// public RVA = 0x498D60
    void movePermajob(int taskIdx, int targetIdx);// public RVA = 0x498D40
    const std::string& getPermajobName(int slot) const;// public RVA = 0x498C50
    TaskType getPermajob(int slot) const;// public RVA = 0x498C70
    const Tasker* getPermajobData(int slot) const;// public RVA = 0x498C90
    int getPermajobCount() const;// public RVA = 0x498CB0
    virtual const Ogre::Aabb& getAABB() const;// public RVA = 0x498CD0 vtable offset = 0x0
    void addOrder(Building* dest, TaskType t, RootObject* subject, bool shift, bool clear, const Ogre::Vector3& location);// public RVA = 0x4A1E50
    virtual void updateLastTask(Building* dest, TaskType t, RootObject* subject, const Ogre::Vector3& location);// public RVA = 0x498EB0 vtable offset = 0x310
    virtual void playerMoveOrderDefault(Building* dest, RootObject* subject, const Ogre::Vector3& location);// public RVA = 0x4A2030 vtable offset = 0x318
    void endCombatMode();// public RVA = 0x498F40
    virtual float getTotalRelativeStrengthOfAttackers();// public RVA = 0x498FB0 vtable offset = 0x320
    virtual bool canGoIndoors(Building* b) const;// public RVA = 0x4AFB10 vtable offset = 0x328
    virtual const hand& isIndoors() const;// public RVA = 0x49DDA0 vtable offset = 0x0
    virtual const hand& isStandingOnBuilding() const;// public RVA = 0x4984A0 vtable offset = 0x330
    virtual bool isIndoorsRagdoll() const;// public RVA = 0x4984C0 vtable offset = 0x338
    virtual void notifyIndoors(const hand& in);// public RVA = 0x60A910 vtable offset = 0x0
    hand destinationIndoors(RootObject* r) const;// public RVA = 0x60B830
    int destinationInsideWalls(RootObject* r);// public RVA = 0x60A5F0
    void setDestinationIndoors(const hand& h);// public RVA = 0x62F500
    // no_addr void setDestinationInsideWalls(int);// public
    virtual float getIntendedAggression();// public RVA = 0x471F80 vtable offset = 0x0
    Ogre::Vector3 getPositionBip01();// public RVA = 0x212770
    virtual int amInsideTownWalls();// public RVA = 0x60A800 vtable offset = 0x0
    virtual void setName(const std::string& name);// public RVA = 0x49C050 vtable offset = 0x0
    void setNameTagVisible(bool value);// public RVA = 0x498930
    void ragdollMode(bool on, RagdollPart::Enum part);// public RVA = 0x49BAE0
    bool isRagdoll() const;// public RVA = 0x63D740
    bool isDown();// public RVA = 0x1F8800
    Ogre::Vector3 getRagdollPhysicsRootPos();// public RVA = 0x63D9F0
    virtual bool amSomeoneWhoNeedsToEatToLive();// public RVA = 0x499B10 vtable offset = 0x340
    virtual float getMagicHungerSetting();// public RVA = 0x499A20 vtable offset = 0x348
    bool wantsToEatNow();// public RVA = 0x497CF0
    virtual bool isKidnapped();// public RVA = 0x60A350 vtable offset = 0x350
    virtual bool isLiterallyUnconciousNotPretending() const;// public RVA = 0x499B70 vtable offset = 0x358
    virtual bool isUnconcious() const;// public RVA = 0x499B90 vtable offset = 0x0
    virtual bool isCrippled() const;// public RVA = 0x4AC850 vtable offset = 0x360
    virtual ProneState getProneState() const;// public RVA = 0x497B90 vtable offset = 0x368
    virtual void setProneState(ProneState p);// public RVA = 0x497BA0 vtable offset = 0x370
    void _killRagdoll(bool doItNow);// public RVA = 0x4A2AA0
    bool isCurrentlyGettingUp; // 0x278 Member
    unsigned char isGettingEaten; // 0x279 Member
    virtual bool giveBirth(GameDataCopyStandalone* appearance, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, GameSaveState* state, ActivePlatoon* tempplatoonptr, Faction* _faction);// public RVA = 0x4EA260 vtable offset = 0x378
    void setupAI();// public RVA = 0x4E0BC0
    void clearAllAIGoals();// public RVA = 0x4E0FD0
    void setupPlatoonAI();// public RVA = 0x4E0430
    void setAppearanceData(GameDataCopyStandalone* data);// public RVA = 0x48E020
    GameDataCopyStandalone* getAppearanceData();// public RVA = 0x8D4F0
    void setDestination(const Ogre::Vector3& pos, bool shift);// public RVA = 0x499330
    bool sendDialogEventOverride(Character* target, EventTriggerEnum what, bool forceRepeat);// public RVA = 0x5351B0
    bool sendDialogEvent(Character* target, EventTriggerEnum what);// public RVA = 0x534AF0
    void sayALine(const std::string& line, bool force);// public RVA = 0x530000
    Dialogue* dialogue; // 0x280 Member
    bool hasDialogue() const;// public RVA = 0x52A6C0
    bool willTalkToEnemies();// public RVA = 0x52A6E0
    void relocationTeleport(const Ogre::Vector3& moveBy);// public RVA = 0x4981E0
    void teleport(const Ogre::Vector3& moveBy, const Ogre::Quaternion& rot);// public RVA = 0x498260
    void teleport(const Ogre::Vector3& moveBy);// public RVA = 0x49A400
    void teleportVisuallyOnly(const Ogre::Vector3& to, const Ogre::Quaternion& rot);// public RVA = 0x4982C0
    void teleportFromAnimation();// public RVA = 0x498310
    void debugIndicateCharacters(lektor<Character*>* list);// public RVA = 0x49B540
    void attackTarget(Character* who);// public RVA = 0x49AE20
    void notifyTheCampaignOfAnAttack(Character* attacker);// public RVA = 0x7B02B0
    bool iShouldntAggravateThisTarget(Character* target);// public RVA = 0x6AA3A0
    void sendMessage(CharacterMessage message, RootObject* sender, RootObject* subject);// public RVA = 0x498FD0
    void attackingYou(Character* attacker, bool so, bool doAwarenessCheck);// public RVA = 0x499010
    bool iShotYou(Character* attacker, Harpoon* poon, bool onPurpose);// public RVA = 0x354BC0
    virtual HitMaterialType hitByMeleeAttack(CutDirection dir, Damages& damage, Character* who, CombatTechniqueData* attack, int comboID);// public RVA = 0x354420 vtable offset = 0x0
    virtual bool gettingEaten(float amount, Character* eater);// public RVA = 0x350620 vtable offset = 0x380
    void _startStumble(CutDirection dir, Damages& damage, GameData* bodyPart, Character* attacker);// public RVA = 0x354120
    CutOrigination getAttackOriginationDirection(Character* attacker);// public RVA = 0x350530
    CutDirection convertCutDirection(CutDirection dir, CutOrigination from);// public RVA = 0x3505F0
    CutDirection convertCutDirection(CutDirection cut, Character* attacker);// public RVA = 0x351450
    bool stumbleState();// public RVA = 0x3504A0
    virtual void setAge(float f);// public RVA = 0x4AFB20 vtable offset = 0x388
    std::string currentStumblePainAnimation; // 0x288 Member
    virtual void setFaction(Faction* p, ActivePlatoon* a);// public RVA = 0x49B840 vtable offset = 0x0
    virtual float getAge() const;// public RVA = 0x4AFB30 vtable offset = 0x390
    virtual float getAge0to1() const;// public RVA = 0x4AFB40 vtable offset = 0x398
    virtual std::string getAgeString() const;// public RVA = 0x6D2450 vtable offset = 0x3A0
    virtual float getAgeInverse() const;// public RVA = 0x4AFB50 vtable offset = 0x3A8
    void reThinkCurrentAIAction();// public RVA = 0x4980B0
    CharBody* getBody();// public RVA = 0x1F25B0
    CombatClass* getCombatClass() const;// public RVA = 0x499030
    CharStats* getStats();// public RVA = 0x9BB10
    MedicalSystem* getMedical();// public RVA = 0x8D500
    Ownerships* getOwnerships() const;// public RVA = 0x60DCA0
    AI* getAI();// public RVA = 0x1D9AD0
    void getSquadMissionTarget(hand& h);// public RVA = 0x60B400
    hand getAttackTarget() const;// public RVA = 0x3506D0
    bool isInCombatMode(bool melee, bool ranged) const;// public RVA = 0x351540
    bool isInRangedCombatMode() const;// public RVA = 0x3515E0
    bool isLiterallyUnderMeleeAttackRightNowForSure() const;// public RVA = 0x27ED20
    bool _isLiterallyUnderMeleeAttackRightNowForSure; // 0x2B0 Member
    void _isLiterallyUnderMeleeAttackRightNowForSure_update();// private RVA = 0x352820
    CharacterMemory* _myMemory; // 0x2B8 Member
    unsigned int conglomerateTagsFor(Character* who);// private RVA = 0x5212F0
    bool isPrisonerFreeToGo();// public RVA = 0x499C80
    void clearTempEnemyStatus(Character* theEnemy);// public RVA = 0x52A760
    void clearAllTempEnemyStatuses(CharacterPerceptionTags_ShortTerm tag);// public RVA = 0x521930
    void rememberCharacter(Character* who, CharacterPerceptionTags_ShortTerm mem);// public RVA = 0x523F60
    void rememberCharacter(Character* who, CharacterPerceptionTags_LongTerm mem);// public RVA = 0x5234E0
    bool getCharacterMemoryTag(Character* who, CharacterPerceptionTags_LongTerm mem);// public RVA = 0x524830
    bool getCharacterMemoryTag(Character* who, CharacterPerceptionTags_ShortTerm mem);// public RVA = 0x528420
    float lastSeenInHoursAgo(Character* c);// public RVA = 0x523520
    bool haveMetBefore(Character* h);// public RVA = 0x524880
    hand getIDForMemoryTagging();// public RVA = 0x521540
    hand lastGuyWhoDefeatedMe; // 0x2C0 Member
    CharMovement* getMovement();// public RVA = 0x3BE50
    virtual void lookatPosition(const Ogre::Vector3& v, bool fullbodyFacing);// public RVA = 0x499BF0 vtable offset = 0x3B0
    bool areYouGonnaGetMe(Character* who);// public RVA = 0x49A470
    lektor<hand>& getAllAttackers(lektor<hand>& out);// public RVA = 0x49AED0
    int getAllAttackersCount();// public RVA = 0x49A490
    virtual RaceData* getRace() const;// public RVA = 0x4AC860 vtable offset = 0x0
    virtual void setRace(GameData* r);// public RVA = 0x499150 vtable offset = 0x3B8
    RaceData* myRace; // 0x2E0 Member
    float getRadius();// public RVA = 0x498130
    bool isPlayerCharacter() const;// public RVA = 0x609CD0
    bool checkPlayerOrderForProblems(TaskType t, RootObject* subject);// public RVA = 0x4A16C0
    bool breakFollowOrderLoop(const hand& start);// public RVA = 0x498990
    Inventory* inventory; // 0x2E8 Member
    float getTotalCarryWeight();// public RVA = 0x498750
    virtual Weapon* getCurrentWeapon() = 0;// public vtable offset = 0x3C0
    virtual Weapon* getThePreferredWeapon() = 0;// public vtable offset = 0x3C8
    virtual Crossbow* getRangedWeapon();// public RVA = 0x4AC870 vtable offset = 0x3D0
    virtual bool drawWeapon(Item*, std::string) = 0;// public vtable offset = 0x3D8
    Item* getUpperBodyArmour();// public RVA = 0x49C6C0
    Item* getLowerBodyArmour();// public RVA = 0x49C7F0
    bool isInjured(bool robot) const;// public RVA = 0x62F530
    bool shouldUseRangedWeapons();// public RVA = 0x658940
    RangedCombatClass* rangedCombat; // 0x2F0 Member
    Ogre::Vector3 getBoneWorldPosition(const std::string& name);// public RVA = 0x358C90
    AppearanceBase* getAppearance();// public RVA = 0x3BE60
    // no_addr void getCopyOfStatsForModifying(class GameData *);// public
    // no_addr void updateModifiedStats(class GameData *);// public
    void _setPlatoon(ActivePlatoon* p, int idnum);// public RVA = 0x4E0440
    ActivePlatoon* getPlatoon() const;// public RVA = 0x60A110
    bool hasPlatoon() const;// public RVA = 0x4966D0
    bool isInAPersistentPlatoon() const;// public RVA = 0x4E0490
    Blackboard* getBlackboard();// public RVA = 0x60A1A0
    Character* getSquadLeader();// public RVA = 0x60B810
    OrdersReceiver* getOrdersReciever() const;// public RVA = 0x4E05E0
    bool preventRagdollMode() const;// public RVA = 0x4975A0
    UseStuffState inSomething; // 0x2F8 Member
    hand inWhat; // 0x300 Member
    void setPrisonMode(bool on, UseableStuff* h);// public RVA = 0x27C830
    void setBedMode(bool on, UseableStuff* h);// public RVA = 0x27A520
    bool isChained; // 0x320 Member
    hand slaveOwner; // 0x328 Member
    void setSlaveAIJob(bool on);// public RVA = 0x27A300
    void setChainedMode(bool on, const hand& owner);// public RVA = 0x27A7C0
    bool isChainedMode() const;// public RVA = 0x27A1A0
    LockedArmour* getChainedModeShackles();// public RVA = 0x498790
    hand getMySlaveOwner() const;// public RVA = 0x284330
    SlaveStateEnum isSlave();// public RVA = 0x498820
    void changeSlaveOwner(const hand& newOwner);// public RVA = 0x27A660
    bool isMySlave(Character* slave);// public RVA = 0x27A410
    bool isMyFactionsSlave(Character* slave);// public RVA = 0x27A4D0
    virtual bool isHeadShaven() const;// public RVA = 0x4AC880 vtable offset = 0x3E0
    // no_addr void playSlaveAnim(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, float, float);// public
    void runSlaveAnim(const std::string& anim, float speed, float sync);// public RVA = 0x485270
    void endSlaveAnim(const std::string& anim);// public RVA = 0x27FB10
    void updatePortraitGUIState();// public RVA = 0x498680
    void pickupObject(Character* who);// public RVA = 0x49FD10
    void getPickedUp(Character* byWhom);// public RVA = 0x49EB10
    void slaveAttachToBoneMode(const std::string& bone);// public RVA = 0x4B1860
    bool isDead() const;// public RVA = 0x4E0600
    bool isCarryingSomething; // 0x348 Member
    bool isBeingCarried() const;// public RVA = 0xF1DF0
    hand getCarryingObject() const;// public RVA = 0x284370
    std::string carringObjectLeftOrRight; // 0x350 Member
    bool isCarryingLeftSide; // 0x378 Member
    void chooseCarryObjectLeftOrRight();// public RVA = 0x4E1120
    void dropCarriedObject(bool ragdollHim, bool removeOnly);// public RVA = 0x49DF60
    void getDropped(bool ragdollHim, bool hull);// public RVA = 0x49C920
    float getDiplomacyMultiplier();// public RVA = 0x60E620
    virtual bool isEnemy(Character* who, bool factorInDisguises);// public RVA = 0x614F50 vtable offset = 0x3E8
    virtual bool isAlly(Character* who, bool factorInDisguises);// public RVA = 0x60A9D0 vtable offset = 0x3F0
    virtual unsigned int getDefaultTaskRepertoireEnum() const;// public RVA = 0x4AFB60 vtable offset = 0x3F8
    AnimationClass* getAnimationClass();// public RVA = 0x3BE70
    Ogre::Vector3 getPredictedPosition(float secondsInFuture);// public RVA = 0x350400
    hand carryingObject; // 0x380 Member
    void carryModeT(bool on, bool makeRagdoll, bool makeHull);// public RVA = 0x4986A0
    void _carryMode(bool on, bool makeRagdoll, bool makeHull);// public RVA = 0x49E740
    void recalculateTotalEquipmentSkillBonus();// public RVA = 0x6D11D0
    virtual void setupAudio();// public RVA = 0x4E8990 vtable offset = 0x400
    unsigned __int64 getAudioObject() const;// public RVA = 0x358D30
    bool audioEvent(const char* name, SoundRange range);// public RVA = 0x4997F0
    void audioValue(const char* name, float value) const;// public RVA = 0x499720
    void audioValue(const char* name, const char* value) const;// public RVA = 0x499700
    void setGroundType(GroundType t);// public RVA = 0x49AD40
    GroundType getGroundType();// public RVA = 0x4996F0
    void calculateMainArmourType();// public RVA = 0x4A2630
    ArmourType getMainArmourType() const;// public RVA = 0x3BE80
    virtual bool wearingUniformOf(Faction* f);// public RVA = 0x4AC890 vtable offset = 0x408
    GameData* getUniformColorScheme();// public RVA = 0x41ACD0
    bool canTakePlayerOrdersAtThisTime();// public RVA = 0x658A40
    bool startEffect(GameData* effect);// public RVA = 0x49B3C0
    bool stopEffect(GameData* effect);// public RVA = 0x49A5D0
    void stopAllEffects();// public RVA = 0x49A6A0
    virtual void notifyEffect(EffectType::Enum type, WeatherAffecting what, float strength);// public RVA = 0x49BA40 vtable offset = 0x0
    virtual void equipItem(const std::string& sectionName, Item* item);// public RVA = 0x4ABB00 vtable offset = 0x0
    virtual void unequipItem(const std::string& sectionName, Item* item);// public RVA = 0x4AC090 vtable offset = 0x0
    virtual void validateInventorySections();// public RVA = 0x4AC8A0 vtable offset = 0x410
    enum CharMessage
    {
        CHARMESSAGE_NONE,
        CHARMESSAGE_CARRY,
        CHARMESSAGE_CAGE
    };

    Character::CharMessage messages; // 0x3A0 Member
    hand messageSubject; // 0x3A8 Member
    void processCharacterLoadTimeMessages();// protected RVA = 0x6104C0
    Ogre::Vector3 ragdollNavmeshPosition; // 0x3C8 Member
    bool wantsPathfinderActive();// protected RVA = 0x4E01A0
    virtual void createAnimationClass() = 0;// protected vtable offset = 0x418
    bool _isBeingCarried; // 0x3D4 Member
    WeaponCategory lastUsedWeaponCategory; // 0x3D8 Member
    struct RagdollMsg
    {
        RagdollMsg(bool on, RagdollPart::Enum part);// public RVA = 0x4975B0
        bool operator==(const Character::RagdollMsg& m) const;// public RVA = 0x4975C0
        bool on; // 0x0 Member
        RagdollPart::Enum part; // 0x4 Member
    };
    std::deque<Character::RagdollMsg, std::allocator<Character::RagdollMsg> > ragdollMessages; // 0x3E0 Member
    bool _ragdollMode(const Character::RagdollMsg& message);// protected RVA = 0x4A0B30
    struct CarryMsg
    {
        bool on; // 0x0 Member
        bool rag; // 0x1 Member
        bool hull; // 0x2 Member
    };
    Character::CarryMsg* msgCarryMode; // 0x410 Member
    int squadMemberID; // 0x418 Member
    float diplomacyMultiplier; // 0x41C Member
    void calculateDestinationState(Building* dest, RootObject* subject, const Ogre::Vector3& v);// protected RVA = 0x60A3F0
    hand _destinationInsideBuilding; // 0x420 Member
    int _destinationInsideWalls; // 0x440 Member
    Item* generateWeapon(GameData* weapon, GameData* manufacturer);// protected RVA = 0x4E1000
    virtual bool createPhysical();// protected RVA = 0x49C090 vtable offset = 0x0
    virtual void destroyPhysical();// protected RVA = 0x499210 vtable offset = 0x0
    bool createComponents(GameDataCopyStandalone* appearance);// protected RVA = 0x4E9FA0
    AnimationClass* animation; // 0x448 Member
    CharStats* stats; // 0x450 Member
    MedicalSystem medical; // 0x458 Member
    virtual void loadUnloadCheck();// protected RVA = 0x499190 vtable offset = 0x0
    bool isPhysicalMode; // 0x608 Member
    std::string sex; // 0x610 Member
    CharacterNameTag* nameTag; // 0x638 Member
    void updateStateBroadcast(float time);// protected RVA = 0x6A6430
    CharMovement* movement; // 0x640 Member
    CharBody* body; // 0x648 Member
    AI* ai; // 0x650 Member
    ActivePlatoon* platoon; // 0x658 Member
    short portraitIndex; // 0x660 Member
    unsigned int portraitSerial; // 0x664 Member
    unsigned __int64 audioObject; // 0x668 Member
    AkSoundPosition audioData; // 0x670 Member
    GroundType groundType; // 0x688 Member
    ArmourType armourType; // 0x68C Member
    SoundEmitter* audioEmitter; // 0x690 Member
    float terrainHeightPosition; // 0x698 Member
    char inDoorsSetCooldown; // 0x69C Member
    lektor<std::pair<WeatherAffecting, float> > activeEffects; // 0x6A0 Member
    lektor<Effect*> particleEffects; // 0x6B8 Member
    void setEffectBT(GameData* effect, bool active);// protected RVA = 0x49D620
    virtual void postRagdollCallback(bool on, RagdollPart::Enum part);// protected RVA = 0x49BD10 vtable offset = 0x420
    Sword* naturalWeapon; // 0x6D0 Member
    virtual void reCalculateNaturalWeapon();// protected RVA = 0x4E9AB0 vtable offset = 0x428
    // no_addr class Character & operator=(const class Character &);// public
    //virtual void * __vecDelDtor(unsigned int) = 0;// public vtable offset = 0x0
};

class Weapon;

class CharacterHuman : public Character
{
public:
    // Character offset = 0x0, length = 0x6D8
    // no_addr void CharacterHuman(class CharacterHuman &);// public
    CharacterHuman(GameData* d, Faction* f, hand _handle);// protected RVA = 0x49B790
    void _CONSTRUCTOR(GameData* d, Faction* f, hand _handle);// protected RVA = 0x49B790
    virtual ~CharacterHuman();// protected RVA = 0x49B7E0 vtable offset = 0x0
    void _DESTRUCTOR();// protected RVA = 0x49B7E0 vtable offset = 0x0
    virtual CharacterHuman* isHuman();// public RVA = 0x4AFB70 vtable offset = 0x0
    virtual bool drawWeapon(Item* item, std::string* lastSection);// public RVA = 0x4ABD00 vtable offset = 0x0
    virtual void sheatheWeapon();// public RVA = 0x49C5A0 vtable offset = 0x0
    virtual Weapon* getCurrentWeapon();// public RVA = 0x499510 vtable offset = 0x0
    virtual Weapon* getThePreferredWeapon();// public RVA = 0x499520 vtable offset = 0x0
    virtual Crossbow* getRangedWeapon();// public RVA = 0x4988A0 vtable offset = 0x0
    virtual GameSaveState serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract);// public RVA = 0x4E85F0 vtable offset = 0x0
    virtual void loadFromSerialise(GameSaveState* state);// public RVA = 0x4E81A0 vtable offset = 0x0
    virtual bool giveBirth(GameDataCopyStandalone* _appearance, const Ogre::Vector3& _pos, const Ogre::Quaternion& _rot, GameSaveState* state, ActivePlatoon* tempplatoonptr, Faction* _faction);// public RVA = 0x4EDFC0 vtable offset = 0x0
    virtual bool setupInventorySections(GameSaveState* state);// public RVA = 0x4EB530 vtable offset = 0x0
    virtual void validateInventorySections();// public RVA = 0x4E0940 vtable offset = 0x0
    virtual void setupAudio();// public RVA = 0x4E8EA0 vtable offset = 0x0
    void shaveHead(bool on);// public RVA = 0x486630
    virtual bool isHeadShaven() const;// public RVA = 0x486650 vtable offset = 0x0
    virtual void createAnimationClass();// protected RVA = 0x4993F0 vtable offset = 0x0
    virtual void dropItem(RootObject* itembase);// protected RVA = 0x49A4C0 vtable offset = 0x0
    void dropWeaponInHands();// protected RVA = 0x49C4E0
    void dropWeaponInHandsFake();// protected RVA = 0x4993E0
    virtual void unequipItem(const std::string& section, Item* item);// protected RVA = 0x4AC2E0 vtable offset = 0x0
    virtual void weatherUpdate(float time);// protected RVA = 0x49F510 vtable offset = 0x0
    void leaveSheathEquipped(std::string* section, int ypos);// protected RVA = 0x4A2230
    Weapon* weaponInHands; // 0x6D8 Member
    std::string weaponInHandsSheathLocation; // 0x6E0 Member
    virtual void postRagdollCallback(bool on, RagdollPart::Enum part);// protected RVA = 0x49BFB0 vtable offset = 0x0
    virtual void reCalculateNaturalWeapon();// protected RVA = 0x4E9D40 vtable offset = 0x0
    // no_addr class CharacterHuman & operator=(const class CharacterHuman &);// public
    //virtual void * __vecDelDtor(unsigned int) = 0;// protected vtable offset = 0x0
};

class CharacterAnimal : public Character
{
public:
    // Character offset = 0x0, length = 0x6D8
    virtual CharacterAnimal* isAnimal();// public RVA = 0x4AC8B0 vtable offset = 0x0
    virtual void createAnimationClass();// public RVA = 0x4B2450 vtable offset = 0x0
    // no_addr bool preventRagdollMode();// public
    virtual bool drawWeapon(Item*, std::string* lastSlot);// public RVA = 0x4AFA90 vtable offset = 0x0
    virtual void sheatheWeapon();// public RVA = 0x4AC8C0 vtable offset = 0x0
    virtual Weapon* getCurrentWeapon();// public RVA = 0x4AC8D0 vtable offset = 0x0
    virtual Weapon* getThePreferredWeapon();// public RVA = 0x4AC8E0 vtable offset = 0x0
    virtual InventoryLayout* createInventoryLayout();// public RVA = 0x49C3B0 vtable offset = 0x0
    virtual bool giveBirth(GameDataCopyStandalone* appearance, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, GameSaveState* state, ActivePlatoon* tempplatoonptr, Faction* _faction);// public RVA = 0x4EE050 vtable offset = 0x0
    virtual bool setupInventorySections(GameSaveState* state);// public RVA = 0x4E9180 vtable offset = 0x0
    virtual void setupAudio();// public RVA = 0x4E9040 vtable offset = 0x0
    virtual void periodicUpdate();// public RVA = 0x49DC80 vtable offset = 0x0
    virtual void setAge(float zeroToOne);// public RVA = 0x4AC8F0 vtable offset = 0x0
    virtual float getAge() const;// public RVA = 0x4AC900 vtable offset = 0x0
    virtual float getAgeInverse() const;// public RVA = 0x4AC930 vtable offset = 0x0
    virtual float getAge0to1() const;// public RVA = 0x4AC970 vtable offset = 0x0
    virtual unsigned int getDefaultTaskRepertoireEnum() const;// public RVA = 0x4AC980 vtable offset = 0x0
    virtual bool canGoIndoors(Building* b) const;// public RVA = 0x497F50 vtable offset = 0x0
    virtual float getSmellHuntingThresholdBlood() const;// public RVA = 0x4AC990 vtable offset = 0x430
    virtual float getSmellHuntingThresholdEggs() const;// public RVA = 0x4AC9A0 vtable offset = 0x438
    bool weaponIsTechnicallyEquipped; // 0x6D8 Member
    virtual float getHPMultiplier() const;// public RVA = 0x4AC9B0 vtable offset = 0x0
    float HPMultiplier; // 0x6DC Member
    TimeOfDay itemInMouthTimeStamp; // 0x6E0 Member
    virtual void foodUpdate();// public RVA = 0x4AC3D0 vtable offset = 0x0
    bool pickupItemInMouth(Item* item);// public RVA = 0x4A08D0
    bool dropItemInMouth();// public RVA = 0x497FC0
    Item* getItemInMouth();// public RVA = 0x498050
    void eatItemInMouth();// public RVA = 0x4A0AA0
    // no_addr void CharacterAnimal(class CharacterAnimal &);// public
    CharacterAnimal(GameData* d, Faction* f, hand* _handle, float _age);// protected RVA = 0x497ED0
    virtual ~CharacterAnimal();// protected RVA = 0x497F30 vtable offset = 0x0
    virtual void init();// protected RVA = 0x4E26B0 vtable offset = 0x0
    virtual void dropItem(RootObject* itembase);// protected RVA = 0x49A220 vtable offset = 0x0
    float smellThresholdBlood; // 0x6E8 Member
    float smellThresholdEggs; // 0x6EC Member
    float ageSizeMin; // 0x6F0 Member
    float ageSizeMax; // 0x6F4 Member
    float lifespanInDays; // 0x6F8 Member
    float lastUpdatedAge; // 0x6FC Member
    float age; // 0x700 Member
    Weapon* weaponInHands; // 0x708 Member
    float audioTimeStamp; // 0x710 Member
    // no_addr class CharacterAnimal & operator=(const class CharacterAnimal &);// public
    //virtual void * __vecDelDtor(unsigned int) = 0;// protected vtable offset = 0x0
};