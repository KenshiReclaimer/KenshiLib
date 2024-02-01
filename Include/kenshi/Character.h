#pragma once


#include "RootObject.h"
#include "MedicalSystem.h"
#include "TimeOfDay.h"
#include "util/YesNoMaybe.h"

#include <ogre/OgreVector3.h>

namespace Kenshi
{
    enum ProneState {};// TODO
    enum SquadMemberType {};// TODO
    enum CrimeEnum {};// TODO

    class Bounty
    {
    public:
        Bounty();// RVA = 0x6A59D0
        int amount; // 0x0 Member
        unsigned int crimes; // 0x4 Member
        bool bountyHasBeenClaimedOnce; // 0x8 Member
        TimeOfDay bountyAssignmentStartedTime; // 0x10 Member
        void addCrime(CrimeEnum);// RVA = 0x6A54D0
        bool hasCrime(CrimeEnum);// RVA = 0x497570
        // no_addr public class Bounty & operator=(const class Bounty &);
    };

    class Character;

    // TODO move?
    class BountyManager
    {
    public:
        boost::unordered::unordered_map<Faction*, Bounty, boost::hash<Faction*>, std::equal_to<Faction*>, Ogre::STLAllocator<std::pair<Faction* const, Bounty>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > bounties; // 0x0 Member
        Character* me; // 0x40 Member
        Faction* _getBountyFaction(Faction*);// RVA = 0x6A5A10
        Faction* _getHighestBountyFaction();// RVA = 0x6A70E0
        Faction* _hasAccessPass; // 0x48 Member
        TimeOfDay accessPassExpirationTime; // 0x50 Member
        // no_addr public void BountyManager(const class BountyManager &);
        BountyManager(Character*);// RVA = 0x4F9DD0
        int getPercievedBounty(Character*);// RVA = 0x6A79D0
        int getActualBounty(Faction*);// RVA = 0x6A7A80
        void notifyPlayerClaimBounty(Faction*);// RVA = 0x6A7B70
        bool bountyAlreadyBeenClaimedByPlayer(Faction*);// RVA = 0x6A7C70
        void assignBountyForCrimes(Faction*);// RVA = 0x6A78C0
        void unfairAddToBounty(Faction*, int);// RVA = 0x6A7820
        int getBountyRecognitionThreshold();// RVA = 0x6A5AC0
        void clearBounty(Faction*);// RVA = 0x6A73F0
        int getTotalBounty();// RVA = 0x6A7140
        void update(float);// RVA = 0x49B900
        StringPair getGUIData(lektor<StringPair>&);// RVA = 0x4A2B20
        void getGUIDataForAppend(lektor<StringPair>&);// RVA = 0x4A1180
        std::string getBountyExpiryStringForGUI();// RVA = 0x4A0E90
        void load(GameData*);// RVA = 0x4E4EB0
        void save(GameData*);// RVA = 0x4E5300
        bool setCrime(CrimeEnum, Faction*, const hand&);// RVA = 0x6A6680
        void notifyCrimeWitnessed(Faction*, const hand&, int, CrimeEnum);// RVA = 0x6A6810
        void notifyPossibleCrimeWitnessed(float);// RVA = 0x6A5940
        CrimeEnum committingCrime; // 0x58 Member
        Faction* crimeAgainstFaction; // 0x60 Member
        Faction* usingTrainingEquipmentOf; // 0x68 Member
        hand crimeAgainst; // 0x70 Member
        float crimeExpiry; // 0x90 Member
        TimeOfDay prisonSentenceBeganTime; // 0x98 Member
        float prisonSentenceToServe; // 0xA0 Member
        bool _hadABountyAssignedForCurrentCrime; // 0xA4 Member
        bool isCommittingCrime();// RVA = 0x6A54F0
        void notifyStartPrisonSentence(Faction*);// RVA = 0x6A8350
        bool hasAccessPass(Faction*);// RVA = 0x6A5500
        void giveAccessPass(Faction*, float);// RVA = 0x282220
        static std::string crimeToStr(CrimeEnum);// RVA = 0x6A9F30
        static int getBountyForCrime(CrimeEnum);// RVA = 0x6A5840
        static int getPrisonSentenceInHours(int);// RVA = 0x6A58D0
        static float getBountyExpirationTime(int);// RVA = 0x6A5910
        ~BountyManager();// RVA = 0x4F9EB0
        // no_addr public class BountyManager & operator=(const class BountyManager &);
        // no_addr public void * __vecDelDtor(unsigned int);
    };

    class WaterState
    {
    public:
        enum Enum
        {
            NO_WATER = 0x0,
            VERY_SHALLOW_WATER = 0x1,
            THIGH_DEEP_WATER = 0x2,
            DEEP_WATER = 0x3
        };

    };

    enum MoveSpeed {};// TODO
    class RagdollPart // TODO this isn't in the symbols
    {
    public:
        enum Enum {};
    };
    enum EventTriggerEnum {};// TODO 
    enum CharacterMessage {};// TODO
    enum CharacterPerceptionTags_ShortTerm {};// TODO
    enum CharacterPerceptionTags_LongTerm {};// TODO
    enum UseStuffState {};// TODO
    enum SlaveStateEnum {};// TODO
    enum SoundRange {};// TODO
    enum GroundType {};// TODO
    enum WeaponCategory {};// TODO
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
        struct AkVector Position; // 0x0 Member
        struct AkVector Orientation; // 0xC Member
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

    class Character : public RootObject, Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
    {
    public:
        // RootObject offset = 0x0, length = 0xC0
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0xC0, length = 0x1
        // no_addr public void Character(class Character &);
        Character(GameData*, Faction*, const hand&);// RVA = 0x4E1440
        bool isImmuneToOffscreenMode();// RVA = 0x497740
        virtual void init();// RVA = 0x4E01E0// vtable offset = 0x228
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
        virtual ~Character();// RVA = 0x4E1AD0// vtable offset = 0x0
        bool isVisibleUpdateMode; // 0xE4 Member
        bool setVisibleMsg; // 0xE5 Member
        YesNoMaybe stealthUnseen; // 0xE8 Member
        virtual bool isOnARoof();// RVA = 0x4AC7C0// vtable offset = 0x0
        virtual bool isOnAWall();// RVA = 0x498840// vtable offset = 0x230
        float getLightLevel();// RVA = 0x4FC1B0
        virtual float getHPMultiplier();// RVA = 0x4AFAF0// vtable offset = 0x238
        void healCompletely();// RVA = 0x4FECA0
        void resetRagdollNavmeshSafePos();// RVA = 0x63D610
        void setRagdollNavmeshSafePos();// RVA = 0x511EB0
        float getFrameTime();// RVA = 0x27A190
        void frameSkip();// RVA = 0x6036F0
        float getCurrentNoiseRange();// RVA = 0x6A5710
        virtual bool isDestroyed();// RVA = 0x4AC800// vtable offset = 0x240
        bool isLawEnforcement();// RVA = 0x4729F0
        bool canAssignBounties();// RVA = 0x47D860
        virtual itemType getDataType();// RVA = 0x4AC810// vtable offset = 0x0
        bool isDiplomaticStatus(bool);// RVA = 0x60E840
        bool isLeadingAWarCampaign();// RVA = 0x7D2D50
        CampaignInstance* isInAWarCampaign();// RVA = 0x7D2DD0
        bool playerWantsMeToGetUp; // 0xEC Member
        bool wantsToTriggerCampaigns();// RVA = 0x7D2FB0
        bool isUnique();// RVA = 0x3FAB50
        bool canSpeakNormally();// RVA = 0x4B2250
        virtual CharacterAnimal* isAnimal();// RVA = 0x4AFB00// vtable offset = 0x248
        virtual CharacterHuman* isHuman();// RVA = 0x4AC820// vtable offset = 0x250
        virtual bool takeMoney(int);// RVA = 0x60EBF0// vtable offset = 0x0
        virtual int getMoney();// RVA = 0x609C60// vtable offset = 0x0
        void setSquadMemberType(SquadMemberType);// RVA = 0x4E0610
        TownBase* isResident();// RVA = 0x49E370
        BountyManager crimes; // 0xF0 Member
        StatsEnumerated currentSkillUsing; // 0x198 Member
        void dailyUpdate();// RVA = 0x4A2510
        StateBroadcastData* stateBroadcast; // 0x1A0 Member
        bool isVisibleAndNear; // 0x1A8 Member
        bool isOnScreen; // 0x1A9 Member
        bool updateOnScreenCheck();// RVA = 0x499CE0
        void offscreenUpdate();// RVA = 0x497820
        void updateTimes();// RVA = 0x497860
        virtual SensoryData* getSensoryData();// RVA = 0x498480// vtable offset = 0x0
        virtual StateBroadcastData* getStateBroadcast();// RVA = 0x4AC830// vtable offset = 0x0
        virtual Formation* getFormation();// RVA = 0x499660// vtable offset = 0x258
        virtual Formation* getEnemyFormation();// RVA = 0x499680// vtable offset = 0x260
        void formationUpdateCallback(const Ogre::Vector3&, const hand&, const Ogre::Vector3&, Formation*);// RVA = 0x4996A0
        bool AIDestinationIndoorOutdoorCheck(RootObject*);// RVA = 0x3FFA00
        virtual void setHandle(const hand&);// RVA = 0x4E2970// vtable offset = 0x0
        virtual void update();// RVA = 0x49EEB0// vtable offset = 0x0
        virtual void postUpdate();// RVA = 0x49D7A0// vtable offset = 0x268
        void ragdollUpdatesUT();// RVA = 0x4A29B0
        void fourFrameUpdate();// RVA = 0x49FB10
        virtual void periodicUpdate();// RVA = 0x49CB10// vtable offset = 0x0
        virtual void pausedUpdate();// RVA = 0x4978A0// vtable offset = 0x270
        void updateUT();// RVA = 0x497970
        virtual void threadedUpdate();// RVA = 0x4979B0// vtable offset = 0x0
        virtual void threadedUpdate4();// RVA = 0x497AC0// vtable offset = 0x278
        virtual void threadedUpdatePeriodic();// RVA = 0x49FE30// vtable offset = 0x280
        bool pathExists(const Ogre::Vector3&);// RVA = 0x511350
        virtual void weatherUpdate(float);// RVA = 0x497CE0// vtable offset = 0x288
        void stealthUpdate(float);// RVA = 0x6AC0D0
        float lineOfSightCheck(Character*);// RVA = 0x6A7020
        float getPerceptionMult();// RVA = 0x6A63C0
        bool isWithThePlayer();// RVA = 0x6AA5C0
        void notifyICanSeeYouSneaking(Character*, YesNoMaybe, float);// RVA = 0x6A9930
        bool isItSafeToGetUp();// RVA = 0x49A1D0
        Platoon* separateIntoMyOwnSquad(bool);// RVA = 0x49E260
        void dropGearOnDeath(bool);// RVA = 0x49B590
        virtual bool isItOkForMeToLoot(RootObject*, Item*);// RVA = 0x60BF40// vtable offset = 0x290
        virtual bool ImStealingDoYouNotice(RootObject*, Item*);// RVA = 0x60CE10// vtable offset = 0x298
        float getFencingSuccessChance(Item*, RootObject*);// RVA = 0x60BA90
        virtual bool stolenGoodsDetectionCheck(Item*, RootObject*);// RVA = 0x60BD70// vtable offset = 0x0
        virtual bool sellingUniformDetectionCheck(Item*, Character*);// RVA = 0x60BCC0// vtable offset = 0x2A0
        virtual YesNoMaybe smugglingTradeCheck(Item*, Character*);// RVA = 0x60D480// vtable offset = 0x2A8
        float getStealingSuccessChance(RootObject*, Item*, Character**);// RVA = 0x60CAD0
        WeatherAffecting getCurrentWeatherAffectStatus();// RVA = 0x498440
        float getCurrentWeatherAffectStrength();// RVA = 0x498460
        WaterState::Enum getWaterLevel();// RVA = 0x497D50
        void setTerrainHeightPosition(float);// RVA = 0x497580
        float getTerrainHeightPosition();// RVA = 0x485260
        enum DisguiseGUIFeedback
        {
            DGF_SAME_FACTION = 0x0,
            DGF_MY_SLAVE = 0x1,
            DGF_I_HATE_YOU = 0x2
        };

        void setDisguiseMessage(Character::DisguiseGUIFeedback);// RVA = 0x6B3A70
        boost::unordered::unordered_map<Character::DisguiseGUIFeedback, float, boost::hash<Character::DisguiseGUIFeedback>, std::equal_to<Character::DisguiseGUIFeedback>, Ogre::STLAllocator<std::pair<Character::DisguiseGUIFeedback const, float>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > disguiseGUIFeedbacks; // 0x1B0 Member
        class WhoSeesMe
        {
            // no_addr public void WhoSeesMe(class Character::WhoSeesMe &);
            WhoSeesMe(double, YesNoMaybe, float);// RVA = 0x6AF060
            WhoSeesMe();// RVA = 0x6AF050
            double lastUpdated; // 0x0 Member
            YesNoMaybe seeState; // 0x8 Member
            float progressOfMaybe; // 0xC Member
        };
        boost::unordered::unordered_map<hand, Character::WhoSeesMe, boost::hash<hand>, std::equal_to<hand>, Ogre::STLAllocator<std::pair<hand const, Character::WhoSeesMe>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > whoSeesMeSneaking; // 0x1F0 Member
        class AttachedArrowManager
        {
            ~AttachedArrowManager();// RVA = 0x49ADD0
            void clearAll();// RVA = 0x49A330
            void updateStart();// RVA = 0x4980A0
            void addArrow(Ogre::Vector3&, Ogre::Vector3&, int);// RVA = 0x4AC550
            void updateEnd();// RVA = 0x49A3A0
            lektor<Ogre::Entity*> ents; // 0x0 Member
            int index; // 0x18 Member
            // no_addr public void AttachedArrowManager(const class Character::AttachedArrowManager &);
            AttachedArrowManager();// RVA = 0x4F1DB0
            // no_addr public class Character::AttachedArrowManager & operator=(const class Character::AttachedArrowManager &);
            // no_addr public void * __vecDelDtor(unsigned int);
        };
        AttachedArrowManager stealthMarkerArrows; // 0x230 Member
        void uniqueStateUpdate();// RVA = 0x49F1F0
        virtual void foodUpdate();// RVA = 0x4A2740// vtable offset = 0x2B0
        bool eatItem(Item*, Inventory*);// RVA = 0x4A0500
        virtual GameSaveState serialise(GameDataContainer*, GameData*, PosRotPair*);// RVA = 0x4E70F0// vtable offset = 0x0
        virtual void loadFromSerialise(GameSaveState*);// RVA = 0x4E5FA0// vtable offset = 0x0
        virtual void loadFromSerialisePostCreationStage(GameSaveState*);// RVA = 0x4E6B80// vtable offset = 0x2B8
        virtual bool setupInventorySections(GameSaveState*);// RVA = 0x4E1ED0// vtable offset = 0x2C0
        virtual Ogre::Vector3 getPosition();// RVA = 0x49E400// vtable offset = 0x0
        Ogre::Vector3 _getRawPosition();// RVA = 0x5166D0
        Ogre::Vector3 getRawEntityPosition();// RVA = 0x497E50
        virtual float getMovementSpeed();// RVA = 0x498150// vtable offset = 0x0
        virtual MoveSpeed getMovementSpeedOrders();// RVA = 0x498190// vtable offset = 0x2C8
        virtual Ogre::Vector3 getMovementDirection();// RVA = 0x4981B0// vtable offset = 0x0
        // no_addr public int getSquadMemberID();
        virtual bool isPhysical();// RVA = 0x498540// vtable offset = 0x0
        virtual void setVisible(bool);// RVA = 0x498570// vtable offset = 0x0
        virtual bool getVisible();// RVA = 0x498600// vtable offset = 0x0
        void switchLights(bool);// RVA = 0x41A380
        virtual bool isDisabled();// RVA = 0x498630// vtable offset = 0x0
        virtual void setInsideTownWalls(int);// RVA = 0x60A5E0// vtable offset = 0x0
        virtual void sheatheWeapon();// RVA = 0x4FA3F0// vtable offset = 0x2D0
        virtual void select();// RVA = 0x499270// vtable offset = 0x0
        virtual void unselect();// RVA = 0x4992A0// vtable offset = 0x0
        virtual void getGUIData(DatapanelGUI*, int);// RVA = 0x4A3FE0// vtable offset = 0x0
        virtual TownBase* getCurrentTownLocation();// RVA = 0x498730// vtable offset = 0x0
        virtual void say_WithARepeatLimiter(const std::string&);// RVA = 0x49AC90// vtable offset = 0x2D8
        virtual void say(const std::string&);// RVA = 0x4996D0// vtable offset = 0x0
        virtual bool isInventoryVisible();// RVA = 0x4992D0// vtable offset = 0x2E0
        virtual bool giveItem(Item*, bool, bool);// RVA = 0x49B180// vtable offset = 0x0
        virtual bool hasRoomForItem(GameData*);// RVA = 0x49B2A0// vtable offset = 0x0
        virtual bool hasItem(GameData*);// RVA = 0x49B330// vtable offset = 0x0
        virtual bool hasAmmoFor(Crossbow*);// RVA = 0x499300// vtable offset = 0x2E8
        virtual int getNumFoodItems();// RVA = 0x4706C0// vtable offset = 0x2F0
        virtual bool hasSimilarItem(itemType);// RVA = 0x49C2E0// vtable offset = 0x2F8
        bool ifImASmithShouldIDitchMyBackWeapon();// RVA = 0x49C230
        virtual bool hasItemsFrom(StorageBuilding*, boost::unordered::unordered_set<GameData*, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<GameData*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x47D900// vtable offset = 0x300
        virtual Inventory* getInventory();// RVA = 0x4AC840// vtable offset = 0x0
        ContainerItem* hasABackpackOn();// RVA = 0x49B0A0
        bool isATrader();// RVA = 0x49FCF0
        bool isFemale();// RVA = 0x1FEDA0
        bool isFleeing();// RVA = 0x499910
        virtual InventoryLayout* createInventoryLayout();// RVA = 0x49B6F0// vtable offset = 0x0
        bool _isEngagedWithAPlayer; // 0x250 Member
        hand isUsingTurret; // 0x258 Member
        float getStealthKOChance(Character*, bool);// RVA = 0x6CF490
        float getKidnappingChance(Character*);// RVA = 0x6CF7A0
        float getKidnappingEscapeChance_skill(Character*);// RVA = 0x6CFA60
        float getKidnappingEscapeChance_strength(Character*);// RVA = 0x6CFCB0
        float getLockpickChance(DoorLock*);// RVA = 0x6CFE30
        bool shouldIHelpThisGuy(Character*);// RVA = 0x473A60
        bool shouldIScrewThisGuyOver(Character*);// RVA = 0x473BA0
        bool ILoveThisGuyBecauseOfStuffThatHappened(Character*);// RVA = 0x472980
        bool IHateThisGuyBecauseOfStuffThatHappened(Character*);// RVA = 0x4729C0
        int getRoughLevel();// RVA = 0x473D10
        virtual void setStandingOrder(MessageForB::StandingOrder, bool);// RVA = 0x49A7D0// vtable offset = 0x308
        bool getStandingOrder(MessageForB::StandingOrder);// RVA = 0x499440
        void setStealthMode(bool);// RVA = 0x49A720
        bool isStealthMode();// RVA = 0x4994D0
        bool isStealthModeOrCrawling();// RVA = 0x5166F0
        void declareDead();// RVA = 0x61E800
        void updateGUIStatsDetails(DatapanelGUI*, const std::string&, int);// RVA = 0x6F3D00
        void _printRaceXPBonusLine(DatapanelGUI*, StatsEnumerated);// RVA = 0x6EDA30
        void addGoal(TaskType, Kenshi::RootObjectBase*);// RVA = 0x498DA0
        // no_addr public void removeGoal(enum TaskType);
        void addJob(TaskType, RootObject*, bool, bool, const Ogre::Vector3&);// RVA = 0x498B20
        void removeJob(TaskType);// RVA = 0x498C30
        void removePermajob(int);// RVA = 0x498D80
        void clearPermajobs();// RVA = 0x498D60
        void movePermajob(int, int);// RVA = 0x498D40
        const std::string& getPermajobName(int);// RVA = 0x498C50
        TaskType getPermajob(int);// RVA = 0x498C70
        const Tasker* getPermajobData(int);// RVA = 0x498C90
        int getPermajobCount();// RVA = 0x498CB0
        virtual const struct Ogre::Aabb& getAABB();// RVA = 0x498CD0// vtable offset = 0x0
        void addOrder(Building*, TaskType, RootObject*, bool, bool, const Ogre::Vector3&);// RVA = 0x4A1E50
        virtual void updateLastTask(Building*, TaskType, RootObject*, const Ogre::Vector3&);// RVA = 0x498EB0// vtable offset = 0x310
        virtual void playerMoveOrderDefault(Building*, RootObject*, const Ogre::Vector3&);// RVA = 0x4A2030// vtable offset = 0x318
        void endCombatMode();// RVA = 0x498F40
        virtual float getTotalRelativeStrengthOfAttackers();// RVA = 0x498FB0// vtable offset = 0x320
        virtual bool canGoIndoors(Building*);// RVA = 0x4AFB10// vtable offset = 0x328
        virtual const hand& isIndoors();// RVA = 0x49DDA0// vtable offset = 0x0
        virtual const hand& isStandingOnBuilding();// RVA = 0x4984A0// vtable offset = 0x330
        virtual bool isIndoorsRagdoll();// RVA = 0x4984C0// vtable offset = 0x338
        virtual void notifyIndoors(const hand&);// RVA = 0x60A910// vtable offset = 0x0
        hand destinationIndoors(RootObject*);// RVA = 0x60B830
        int destinationInsideWalls(RootObject*);// RVA = 0x60A5F0
        void setDestinationIndoors(const hand&);// RVA = 0x62F500
        // no_addr public void setDestinationInsideWalls(int);
        virtual float getIntendedAggression();// RVA = 0x471F80// vtable offset = 0x0
        Ogre::Vector3 getPositionBip01();// RVA = 0x212770
        virtual int amInsideTownWalls();// RVA = 0x60A800// vtable offset = 0x0
        virtual void setName(const std::string&);// RVA = 0x49C050// vtable offset = 0x0
        void setNameTagVisible(bool);// RVA = 0x498930
        void ragdollMode(bool, RagdollPart::Enum);// RVA = 0x49BAE0
        bool isRagdoll();// RVA = 0x63D740
        bool isDown();// RVA = 0x1F8800
        Ogre::Vector3 getRagdollPhysicsRootPos();// RVA = 0x63D9F0
        virtual bool amSomeoneWhoNeedsToEatToLive();// RVA = 0x499B10// vtable offset = 0x340
        virtual float getMagicHungerSetting();// RVA = 0x499A20// vtable offset = 0x348
        bool wantsToEatNow();// RVA = 0x497CF0
        virtual bool isKidnapped();// RVA = 0x60A350// vtable offset = 0x350
        virtual bool isLiterallyUnconciousNotPretending();// RVA = 0x499B70// vtable offset = 0x358
        virtual bool isUnconcious();// RVA = 0x499B90// vtable offset = 0x0
        virtual bool isCrippled();// RVA = 0x4AC850// vtable offset = 0x360
        virtual ProneState getProneState();// RVA = 0x497B90// vtable offset = 0x368
        virtual void setProneState(ProneState);// RVA = 0x497BA0// vtable offset = 0x370
        void _killRagdoll(bool);// RVA = 0x4A2AA0
        bool isCurrentlyGettingUp; // 0x278 Member
        unsigned char isGettingEaten; // 0x279 Member
        virtual bool giveBirth(GameDataCopyStandalone*, const Ogre::Vector3&, const Ogre::Quaternion&, GameSaveState*, ActivePlatoon*, Faction*);// RVA = 0x4EA260// vtable offset = 0x378
        void setupAI();// RVA = 0x4E0BC0
        void clearAllAIGoals();// RVA = 0x4E0FD0
        void setupPlatoonAI();// RVA = 0x4E0430
        void setAppearanceData(GameDataCopyStandalone*);// RVA = 0x48E020
        GameDataCopyStandalone* getAppearanceData();// RVA = 0x8D4F0
        void setDestination(const Ogre::Vector3&, bool);// RVA = 0x499330
        bool sendDialogEventOverride(Character*, EventTriggerEnum, bool);// RVA = 0x5351B0
        bool sendDialogEvent(Character*, EventTriggerEnum);// RVA = 0x534AF0
        void sayALine(const std::string&, bool);// RVA = 0x530000
        Dialogue* dialogue; // 0x280 Member
        bool hasDialogue();// RVA = 0x52A6C0
        bool willTalkToEnemies();// RVA = 0x52A6E0
        void relocationTeleport(const Ogre::Vector3&);// RVA = 0x4981E0
        void teleport(const Ogre::Vector3&, const Ogre::Quaternion&);// RVA = 0x498260
        void teleport(const Ogre::Vector3&);// RVA = 0x49A400
        void teleportVisuallyOnly(const Ogre::Vector3&, const Ogre::Quaternion&);// RVA = 0x4982C0
        void teleportFromAnimation();// RVA = 0x498310
        void debugIndicateCharacters(lektor<Character*>);// RVA = 0x49B540
        void attackTarget(Character*);// RVA = 0x49AE20
        void notifyTheCampaignOfAnAttack(Character*);// RVA = 0x7B02B0
        bool iShouldntAggravateThisTarget(Character*);// RVA = 0x6AA3A0
        void sendMessage(CharacterMessage, RootObject*, RootObject*);// RVA = 0x498FD0
        void attackingYou(Character*, bool, bool);// RVA = 0x499010
        bool iShotYou(Character*, Harpoon*, bool);// RVA = 0x354BC0
        virtual HitMaterialType hitByMeleeAttack(CutDirection, Damages&, Character*, CombatTechniqueData*, int);// RVA = 0x354420// vtable offset = 0x0
        virtual bool gettingEaten(float, Character*);// RVA = 0x350620// vtable offset = 0x380
        void _startStumble(CutDirection, Damages&, GameData*, Character*);// RVA = 0x354120
        CutOrigination getAttackOriginationDirection(Character*);// RVA = 0x350530
        CutDirection convertCutDirection(CutDirection, CutOrigination);// RVA = 0x3505F0
        CutDirection convertCutDirection(CutDirection, Character*);// RVA = 0x351450
        bool stumbleState();// RVA = 0x3504A0
        virtual void setAge(float);// RVA = 0x4AFB20// vtable offset = 0x388
        std::string currentStumblePainAnimation; // 0x288 Member
        virtual void setFaction(Faction*, ActivePlatoon*);// RVA = 0x49B840// vtable offset = 0x0
        virtual float getAge();// RVA = 0x4AFB30// vtable offset = 0x390
        virtual float getAge0to1();// RVA = 0x4AFB40// vtable offset = 0x398
        virtual std::string getAgeString();// RVA = 0x6D2450// vtable offset = 0x3A0
        virtual float getAgeInverse();// RVA = 0x4AFB50// vtable offset = 0x3A8
        void reThinkCurrentAIAction();// RVA = 0x4980B0
        CharBody* getBody();// RVA = 0x1F25B0
        CombatClass* getCombatClass();// RVA = 0x499030
        CharStats* getStats();// RVA = 0x9BB10
        MedicalSystem* getMedical();// RVA = 0x8D500
        Ownerships* getOwnerships();// RVA = 0x60DCA0
        AI* getAI();// RVA = 0x1D9AD0
        void getSquadMissionTarget(hand&);// RVA = 0x60B400
        hand getAttackTarget();// RVA = 0x3506D0
        bool isInCombatMode(bool, bool);// RVA = 0x351540
        bool isInRangedCombatMode();// RVA = 0x3515E0
        bool isLiterallyUnderMeleeAttackRightNowForSure();// RVA = 0x27ED20
        bool _isLiterallyUnderMeleeAttackRightNowForSure; // 0x2B0 Member
        void _isLiterallyUnderMeleeAttackRightNowForSure_update();// RVA = 0x352820
        CharacterMemory* _myMemory; // 0x2B8 Member
        unsigned int conglomerateTagsFor(Character*);// RVA = 0x5212F0
        bool isPrisonerFreeToGo();// RVA = 0x499C80
        void clearTempEnemyStatus(Character*);// RVA = 0x52A760
        void clearAllTempEnemyStatuses(CharacterPerceptionTags_ShortTerm);// RVA = 0x521930
        void rememberCharacter(Character*, CharacterPerceptionTags_ShortTerm);// RVA = 0x523F60
        void rememberCharacter(Character*, CharacterPerceptionTags_LongTerm);// RVA = 0x5234E0
        bool getCharacterMemoryTag(Character*, CharacterPerceptionTags_LongTerm);// RVA = 0x524830
        bool getCharacterMemoryTag(Character*, CharacterPerceptionTags_ShortTerm);// RVA = 0x528420
        float lastSeenInHoursAgo(Character*);// RVA = 0x523520
        bool haveMetBefore(Character*);// RVA = 0x524880
        hand getIDForMemoryTagging();// RVA = 0x521540
        hand lastGuyWhoDefeatedMe; // 0x2C0 Member
        CharMovement* getMovement();// RVA = 0x3BE50
        virtual void lookatPosition(const Ogre::Vector3&, bool);// RVA = 0x499BF0// vtable offset = 0x3B0
        bool areYouGonnaGetMe(Character*);// RVA = 0x49A470
        lektor<hand>& getAllAttackers(lektor<hand>&);// RVA = 0x49AED0
        int getAllAttackersCount();// RVA = 0x49A490
        virtual RaceData* getRace();// RVA = 0x4AC860// vtable offset = 0x0
        virtual void setRace(GameData*);// RVA = 0x499150// vtable offset = 0x3B8
        RaceData* myRace; // 0x2E0 Member
        float getRadius();// RVA = 0x498130
        bool isPlayerCharacter();// RVA = 0x609CD0
        bool checkPlayerOrderForProblems(TaskType, RootObject*);// RVA = 0x4A16C0
        bool breakFollowOrderLoop(const hand&);// RVA = 0x498990
        Inventory* inventory; // 0x2E8 Member
        float getTotalCarryWeight();// RVA = 0x498750
        // no_addr public virtual class Weapon * getCurrentWeapon();// vtable offset = 0x3C0
        // no_addr public virtual class Weapon * getThePreferredWeapon();// vtable offset = 0x3C8
        virtual Crossbow* getRangedWeapon();// RVA = 0x4AC870// vtable offset = 0x3D0
        // no_addr public virtual bool drawWeapon(class Item *, class std::basic_string<char,std::char_traits<char>,std::allocator<char> >);// vtable offset = 0x3D8
        Item* getUpperBodyArmour();// RVA = 0x49C6C0
        Item* getLowerBodyArmour();// RVA = 0x49C7F0
        bool isInjured(bool);// RVA = 0x62F530
        bool shouldUseRangedWeapons();// RVA = 0x658940
        RangedCombatClass* rangedCombat; // 0x2F0 Member
        Ogre::Vector3 getBoneWorldPosition(const std::string&);// RVA = 0x358C90
        AppearanceBase* getAppearance();// RVA = 0x3BE60
        // no_addr public void getCopyOfStatsForModifying(class GameData *);
        // no_addr public void updateModifiedStats(class GameData *);
        void _setPlatoon(ActivePlatoon*, int);// RVA = 0x4E0440
        ActivePlatoon* getPlatoon();// RVA = 0x60A110
        bool hasPlatoon();// RVA = 0x4966D0
        bool isInAPersistentPlatoon();// RVA = 0x4E0490
        Blackboard* getBlackboard();// RVA = 0x60A1A0
        Character* getSquadLeader();// RVA = 0x60B810
        OrdersReceiver* getOrdersReciever();// RVA = 0x4E05E0
        bool preventRagdollMode();// RVA = 0x4975A0
        UseStuffState inSomething; // 0x2F8 Member
        hand inWhat; // 0x300 Member
        void setPrisonMode(bool, UseableStuff*);// RVA = 0x27C830
        void setBedMode(bool, UseableStuff*);// RVA = 0x27A520
        bool isChained; // 0x320 Member
        hand slaveOwner; // 0x328 Member
        void setSlaveAIJob(bool);// RVA = 0x27A300
        void setChainedMode(bool, const hand&);// RVA = 0x27A7C0
        bool isChainedMode();// RVA = 0x27A1A0
        LockedArmour* getChainedModeShackles();// RVA = 0x498790
        hand getMySlaveOwner();// RVA = 0x284330
        SlaveStateEnum isSlave();// RVA = 0x498820
        void changeSlaveOwner(const hand&);// RVA = 0x27A660
        bool isMySlave(Character*);// RVA = 0x27A410
        bool isMyFactionsSlave(Character*);// RVA = 0x27A4D0
        virtual bool isHeadShaven();// RVA = 0x4AC880// vtable offset = 0x3E0
        // no_addr public void playSlaveAnim(const std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, float, float);
        void runSlaveAnim(const std::string&, float, float);// RVA = 0x485270
        void endSlaveAnim(const std::string&);// RVA = 0x27FB10
        void updatePortraitGUIState();// RVA = 0x498680
        void pickupObject(Character*);// RVA = 0x49FD10
        void getPickedUp(Character*);// RVA = 0x49EB10
        void slaveAttachToBoneMode(const std::string&);// RVA = 0x4B1860
        bool isDead();// RVA = 0x4E0600
        bool isCarryingSomething; // 0x348 Member
        bool isBeingCarried();// RVA = 0xF1DF0
        hand getCarryingObject();// RVA = 0x284370
        std::string carringObjectLeftOrRight; // 0x350 Member
        bool isCarryingLeftSide; // 0x378 Member
        void chooseCarryObjectLeftOrRight();// RVA = 0x4E1120
        void dropCarriedObject(bool, bool);// RVA = 0x49DF60
        void getDropped(bool, bool);// RVA = 0x49C920
        float getDiplomacyMultiplier();// RVA = 0x60E620
        virtual bool isEnemy(Character*, bool);// RVA = 0x614F50// vtable offset = 0x3E8
        virtual bool isAlly(Character*, bool);// RVA = 0x60A9D0// vtable offset = 0x3F0
        virtual unsigned int getDefaultTaskRepertoireEnum();// RVA = 0x4AFB60// vtable offset = 0x3F8
        AnimationClass* getAnimationClass();// RVA = 0x3BE70
        Ogre::Vector3 getPredictedPosition(float);// RVA = 0x350400
        hand carryingObject; // 0x380 Member
        void carryModeT(bool, bool, bool);// RVA = 0x4986A0
        void _carryMode(bool, bool, bool);// RVA = 0x49E740
        void recalculateTotalEquipmentSkillBonus();// RVA = 0x6D11D0
        virtual void setupAudio();// RVA = 0x4E8990// vtable offset = 0x400
        unsigned __int64 getAudioObject();// RVA = 0x358D30
        bool audioEvent(const char*, SoundRange);// RVA = 0x4997F0
        void audioValue(const char*, float);// RVA = 0x499720
        void audioValue(const char*, const char*);// RVA = 0x499700
        void setGroundType(GroundType);// RVA = 0x49AD40
        GroundType getGroundType();// RVA = 0x4996F0
        void calculateMainArmourType();// RVA = 0x4A2630
        ArmourType getMainArmourType();// RVA = 0x3BE80
        virtual bool wearingUniformOf(Faction*);// RVA = 0x4AC890// vtable offset = 0x408
        GameData* getUniformColorScheme();// RVA = 0x41ACD0
        bool canTakePlayerOrdersAtThisTime();// RVA = 0x658A40
        bool startEffect(GameData*);// RVA = 0x49B3C0
        bool stopEffect(GameData*);// RVA = 0x49A5D0
        void stopAllEffects();// RVA = 0x49A6A0
        virtual void notifyEffect(EffectType::Enum, WeatherAffecting, float);// RVA = 0x49BA40// vtable offset = 0x0
        virtual void equipItem(const std::string&, Item*);// RVA = 0x4ABB00// vtable offset = 0x0
        virtual void unequipItem(const std::string&, Item*);// RVA = 0x4AC090// vtable offset = 0x0
        virtual void validateInventorySections();// RVA = 0x4AC8A0// vtable offset = 0x410
        enum CharMessage
        {
            CHARMESSAGE_NONE = 0x0,
            CHARMESSAGE_CARRY = 0x1,
            CHARMESSAGE_CAGE = 0x2
        };

        CharMessage messages; // 0x3A0 Member
        hand messageSubject; // 0x3A8 Member
        void processCharacterLoadTimeMessages();// RVA = 0x6104C0
        Ogre::Vector3 ragdollNavmeshPosition; // 0x3C8 Member
        bool wantsPathfinderActive();// RVA = 0x4E01A0
        // no_addr protected virtual void createAnimationClass();// vtable offset = 0x418
        bool _isBeingCarried; // 0x3D4 Member
        WeaponCategory lastUsedWeaponCategory; // 0x3D8 Member
        struct RagdollMsg
        {
            RagdollMsg(bool, RagdollPart::Enum);// RVA = 0x4975B0
            bool operator==(const struct Character::RagdollMsg&);// RVA = 0x4975C0
            bool on; // 0x0 Member
            RagdollPart::Enum part; // 0x4 Member
        };
        std::deque<Character::RagdollMsg, std::allocator<Character::RagdollMsg> > ragdollMessages; // 0x3E0 Member
        bool _ragdollMode(const struct Character::RagdollMsg&);// RVA = 0x4A0B30
        struct CarryMsg
        {
            bool on; // 0x0 Member
            bool rag; // 0x1 Member
            bool hull; // 0x2 Member
        };
        CarryMsg* msgCarryMode; // 0x410 Member
        int squadMemberID; // 0x418 Member
        float diplomacyMultiplier; // 0x41C Member
        void calculateDestinationState(Building*, RootObject*, const Ogre::Vector3&);// RVA = 0x60A3F0
        hand _destinationInsideBuilding; // 0x420 Member
        int _destinationInsideWalls; // 0x440 Member
        Item* generateWeapon(GameData*, GameData*);// RVA = 0x4E1000
        virtual bool createPhysical();// RVA = 0x49C090// vtable offset = 0x0
        virtual void destroyPhysical();// RVA = 0x499210// vtable offset = 0x0
        bool createComponents(GameDataCopyStandalone*);// RVA = 0x4E9FA0
        AnimationClass* animation; // 0x448 Member
        CharStats* stats; // 0x450 Member
        MedicalSystem medical; // 0x458 Member
        virtual void loadUnloadCheck();// RVA = 0x499190// vtable offset = 0x0
        bool isPhysicalMode; // 0x608 Member
        std::string sex; // 0x610 Member
        CharacterNameTag* nameTag; // 0x638 Member
        void updateStateBroadcast(float);// RVA = 0x6A6430
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
        void setEffectBT(GameData*, bool);// RVA = 0x49D620
        virtual void postRagdollCallback(bool, RagdollPart::Enum);// RVA = 0x49BD10// vtable offset = 0x420
        Sword* naturalWeapon; // 0x6D0 Member
        virtual void reCalculateNaturalWeapon();// RVA = 0x4E9AB0// vtable offset = 0x428
        // no_addr public class Character & operator=(const class Character &);
        // no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };

    class Weapon;

    class CharacterHuman : public Character
    {
        // Character offset = 0x0, length = 0x6D8
        // no_addr public void CharacterHuman(class CharacterHuman &);
        CharacterHuman(GameData*, Faction*, hand);// RVA = 0x49B790
        virtual ~CharacterHuman();// RVA = 0x49B7E0// vtable offset = 0x0
        virtual CharacterHuman* isHuman();// RVA = 0x4AFB70// vtable offset = 0x0
        virtual bool drawWeapon(Item*, std::string);// RVA = 0x4ABD00// vtable offset = 0x0
        virtual void sheatheWeapon();// RVA = 0x49C5A0// vtable offset = 0x0
        virtual Weapon* getCurrentWeapon();// RVA = 0x499510// vtable offset = 0x0
        virtual Weapon* getThePreferredWeapon();// RVA = 0x499520// vtable offset = 0x0
        virtual Crossbow* getRangedWeapon();// RVA = 0x4988A0// vtable offset = 0x0
        virtual GameSaveState serialise(GameDataContainer*, GameData*, PosRotPair*);// RVA = 0x4E85F0// vtable offset = 0x0
        virtual void loadFromSerialise(GameSaveState*);// RVA = 0x4E81A0// vtable offset = 0x0
        virtual bool giveBirth(GameDataCopyStandalone*, const Ogre::Vector3&, const Ogre::Quaternion&, GameSaveState*, ActivePlatoon*, Faction*);// RVA = 0x4EDFC0// vtable offset = 0x0
        virtual bool setupInventorySections(GameSaveState*);// RVA = 0x4EB530// vtable offset = 0x0
        virtual void validateInventorySections();// RVA = 0x4E0940// vtable offset = 0x0
        virtual void setupAudio();// RVA = 0x4E8EA0// vtable offset = 0x0
        void shaveHead(bool);// RVA = 0x486630
        virtual bool isHeadShaven();// RVA = 0x486650// vtable offset = 0x0
        virtual void createAnimationClass();// RVA = 0x4993F0// vtable offset = 0x0
        virtual void dropItem(RootObject*);// RVA = 0x49A4C0// vtable offset = 0x0
        void dropWeaponInHands();// RVA = 0x49C4E0
        void dropWeaponInHandsFake();// RVA = 0x4993E0
        virtual void unequipItem(const std::string&, Item*);// RVA = 0x4AC2E0// vtable offset = 0x0
        virtual void weatherUpdate(float);// RVA = 0x49F510// vtable offset = 0x0
        void leaveSheathEquipped(std::string, int);// RVA = 0x4A2230
        Weapon* weaponInHands; // 0x6D8 Member
        std::string weaponInHandsSheathLocation; // 0x6E0 Member
        virtual void postRagdollCallback(bool, RagdollPart::Enum);// RVA = 0x49BFB0// vtable offset = 0x0
        virtual void reCalculateNaturalWeapon();// RVA = 0x4E9D40// vtable offset = 0x0
        // no_addr public class CharacterHuman & operator=(const class CharacterHuman &);
        // no_addr protected virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };

    class CharacterAnimal : public Character
    {
        // Character offset = 0x0, length = 0x6D8
        virtual CharacterAnimal* isAnimal();// RVA = 0x4AC8B0// vtable offset = 0x0
        virtual void createAnimationClass();// RVA = 0x4B2450// vtable offset = 0x0
        // no_addr public bool preventRagdollMode();
        virtual bool drawWeapon(Item*, std::string);// RVA = 0x4AFA90// vtable offset = 0x0
        virtual void sheatheWeapon();// RVA = 0x4AC8C0// vtable offset = 0x0
        virtual Weapon* getCurrentWeapon();// RVA = 0x4AC8D0// vtable offset = 0x0
        virtual Weapon* getThePreferredWeapon();// RVA = 0x4AC8E0// vtable offset = 0x0
        virtual InventoryLayout* createInventoryLayout();// RVA = 0x49C3B0// vtable offset = 0x0
        virtual bool giveBirth(GameDataCopyStandalone*, const Ogre::Vector3&, const Ogre::Quaternion&, GameSaveState*, ActivePlatoon*, Faction*);// RVA = 0x4EE050// vtable offset = 0x0
        virtual bool setupInventorySections(GameSaveState*);// RVA = 0x4E9180// vtable offset = 0x0
        virtual void setupAudio();// RVA = 0x4E9040// vtable offset = 0x0
        virtual void periodicUpdate();// RVA = 0x49DC80// vtable offset = 0x0
        virtual void setAge(float);// RVA = 0x4AC8F0// vtable offset = 0x0
        virtual float getAge();// RVA = 0x4AC900// vtable offset = 0x0
        virtual float getAgeInverse();// RVA = 0x4AC930// vtable offset = 0x0
        virtual float getAge0to1();// RVA = 0x4AC970// vtable offset = 0x0
        virtual unsigned int getDefaultTaskRepertoireEnum();// RVA = 0x4AC980// vtable offset = 0x0
        virtual bool canGoIndoors(Building*);// RVA = 0x497F50// vtable offset = 0x0
        virtual float getSmellHuntingThresholdBlood();// RVA = 0x4AC990// vtable offset = 0x430
        virtual float getSmellHuntingThresholdEggs();// RVA = 0x4AC9A0// vtable offset = 0x438
        bool weaponIsTechnicallyEquipped; // 0x6D8 Member
        virtual float getHPMultiplier();// RVA = 0x4AC9B0// vtable offset = 0x0
        float HPMultiplier; // 0x6DC Member
        TimeOfDay itemInMouthTimeStamp; // 0x6E0 Member
        virtual void foodUpdate();// RVA = 0x4AC3D0// vtable offset = 0x0
        bool pickupItemInMouth(Item*);// RVA = 0x4A08D0
        bool dropItemInMouth();// RVA = 0x497FC0
        Item* getItemInMouth();// RVA = 0x498050
        void eatItemInMouth();// RVA = 0x4A0AA0
        // no_addr public void CharacterAnimal(class CharacterAnimal &);
        CharacterAnimal(GameData*, Faction*, hand, float);// RVA = 0x497ED0
        virtual ~CharacterAnimal();// RVA = 0x497F30// vtable offset = 0x0
        virtual void init();// RVA = 0x4E26B0// vtable offset = 0x0
        virtual void dropItem(RootObject*);// RVA = 0x49A220// vtable offset = 0x0
        float smellThresholdBlood; // 0x6E8 Member
        float smellThresholdEggs; // 0x6EC Member
        float ageSizeMin; // 0x6F0 Member
        float ageSizeMax; // 0x6F4 Member
        float lifespanInDays; // 0x6F8 Member
        float lastUpdatedAge; // 0x6FC Member
        float age; // 0x700 Member
        Weapon* weaponInHands; // 0x708 Member
        float audioTimeStamp; // 0x710 Member
        // no_addr public class CharacterAnimal & operator=(const class CharacterAnimal &);
        // no_addr protected virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };
}
