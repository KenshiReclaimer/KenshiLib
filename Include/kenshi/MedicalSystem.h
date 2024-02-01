#pragma once

#include "util/lektor.h"
#include "Enums.h"
#include "TimeOfDay.h"
#include "util/StringPair.h"

#include <ogre/OgreVector3.h>
#include <boost/unordered_map.hpp>

// 1.0.59 GOG MedicalSystem TakeDamage possibly @ kenshi_GOG_x64.exe+5056D0 
// MedicalSystem::TakeDamage(HealthPartStatus* part, struct damage, uint64_t unk)
namespace Kenshi
{
    /*
    class GameData;
    class Character;
    class Armour;
    class CharStats;
    class AnimationClass;
    class Character;


    // Not 100% sure this is correct
    struct Damage
    {
        float cutDamage; // 0x00
        float bluntDamage; // 0x04
        float unk1; // 0x08
        float finalBlunt; //0x0C not really sure about what this does
        float bleedMult;
        float armourPenetration;
    };

    // possibly 0x1B0 long? 
    // ^ based on highest byte written by constructor + next byte written to in Character constructor

    struct MedicalSystem
    {

        class StringPair
        {
        public:
            char pad_0000[8]; //0x0000
            std::string title; //0x0008
            std::string description; //0x0030
        }; //Size: 0x0058

        struct HealthPartStatus // total 0x88 bytes
        {
            GameData* data; // 0x00
            uint64_t type; // 0x08 // ? unsure, different for different limbs, but not unique
            MedicalSystem* medical; // 0x10
            Character* character; // 0x18
            uint8_t unknown[0x18]; // 0x20 maybe theres some boolean flags in the last int in this group
            float unknown1; // 0x38 currently 80, some hidden stat for limb health?
            float unknown2; // 0x3C currently 1, some regeneration stat?
            float health; // 0x40 the current health of the limb.
            float bluntDamage; // 0x44
            char unk_0048[0xC]; // 0x48
            float maxHealth; // 0x54
            float unknown4; // 0x58 -> 1.0
            float unknown5; // 0x5C -> 1.0
            float unknown6; // 0x60 -> 1.0
        };

        // boost::unordered hashmap around beginning
        char pad_0008[64]; //0x0008
        // this is looped through to calculate armour damage reduction when damaged
        class lektor<Armour*> equippedArmour; //0x0048
        float hunger; //0x0060
        char pad_0064[12]; //0x0064
        float blood; //0x0070
        char pad_0074[100]; //0x0074
        AnimationClass* animationClass; // 0xD8
        Character* character; // 0xE0
        class StringPair environmentStatus; //0x00E8 The state above the healthbars
        char pad_0140[80]; //0x0140
        class lektor<HealthPartStatus> healthParts; //0x0190 HealthPartStatus
        CharStats* charStats;
        // is this actually a part of MedicalSystem? the constructor/destructor only deals with up to 0x190
        
        
        virtual void Function0();
        virtual void Function1();
        virtual void Function2();
    };
    */


    enum LimbState {};// TODO
    class Character;
    class GameData;
    class Item;
    class RootObject;

    // TODO move?
    class RobotLimbs
    {
    public:
        enum Limb
        {
            LEFT_ARM = 0x0,
            RIGHT_ARM = 0x1,
            LEFT_LEG = 0x2,
            RIGHT_LEG = 0x3,
            NULL_LIMB = 0x4
        };

        RobotLimbs(Character*);// RVA = 0x8D570
        ~RobotLimbs();// RVA = 0x8D5A0
        void load(GameData*);// RVA = 0x90310
        void save(GameData*);// RVA = 0x8FCD0
        LimbState getState(Limb);// RVA = 0x8D5D0
        Item* getLimb(Limb);// RVA = 0x8D5E0
        int getMask();// RVA = 0x8D5F0
        void setLimb(Limb, LimbState, Item*);// RVA = 0x8FF50
        RootObject* getInventoryInterface(bool);// RVA = 0x90650
        void destroyInventoryInterface();// RVA = 0x8D640
        Item* getLimbItem(Limb);// RVA = 0x4FC120
        Character* character; // 0x0 Member
        RootObject* inventory; // 0x8 Member
        LimbState states[0x4]; // 0x10 Member
        Item* items[0x4]; // 0x20 Member
        // no_addr public void * __vecDelDtor(unsigned int);
    };

    namespace AttackDirection // this doesn't appear to have type info so I think it's a namespace?
    {
        enum Enum {};// TODO
    }

    enum LeftRight {};// TODO
    enum StatsEnumerated {}; // TODO

    class Wound;
    class CharStats;
    class RobotLimbItem;
    class AnimationClass;
    class Armour;
    class Harpoon;
    class Faction;
    class Damages;
    class CombatTechniqueData;
    class DatapanelGUI;

    class MedicalSystem
    {
    public:
        // VTable         : (none)
        void precalculateFirstAidNeedScore();// RVA = 0x4FD640
        // no_addr public void MedicalSystem(const class MedicalSystem &);
        MedicalSystem();// RVA = 0x4F9B10
        virtual ~MedicalSystem();// RVA = 0x4FF190// vtable offset = 0x0
        void init(AnimationClass*, Character*, GameData*, CharStats*);// RVA = 0x506BF0
        virtual void updateStats();// RVA = 0x4FDAB0// vtable offset = 0x8
        void notifyRaceChange(GameData*);// RVA = 0x5064F0
        void medicalUpdate(float);// RVA = 0x50A7E0
        virtual void periodicUpdate();// RVA = 0x506250// vtable offset = 0x10
        float scoreFirstAidNeed(bool);// RVA = 0x4FC480
        float scoreJuryRigNeed(float);// RVA = 0x4FEBE0
        bool isFullyRested();// RVA = 0x4FC4B0
        void _setHealth(const std::string&, float);// RVA = 0x4FE6D0
        void validateHealthValues();// RVA = 0x4FDD80
        LimbState getLimbState(RobotLimbs::Limb);// RVA = 0x4FC310
        void amputate(RobotLimbs::Limb, bool, const Ogre::Vector3&);// RVA = 0x5075A0
        void crushLimb(RobotLimbs::Limb);// RVA = 0x4FC330
        bool isUselessNoLimbGuy();// RVA = 0x4FC950
        float recalculateStealthHinderance();// RVA = 0x4FD580
        class HealthPartStatus
        {
        public:
            GameData* data; // 0x0 Member
            void serialise(GameData*, int);// RVA = 0x505B70
            void load(GameData*, int);// RVA = 0x505DE0
            enum PartType
            {
                PART_TORSO = 0x0,
                PART_LEG = 0x1,
                PART_ARM = 0x2,
                PART_HEAD = 0x3
            };

            PartType whatAmI; // 0x8 Member
            MedicalSystem* medical; // 0x10 Member
            Character* me; // 0x18 Member
            LeftRight side; // 0x20 Member
            RobotLimbItem* robotLimb; // 0x28 Member
            bool isRobotic();// RVA = 0x4FC250
            GameData* getData();// RVA = 0x4FC130
            RobotLimbs::Limb getRobotLimbEnum();// RVA = 0x4FC380
            void setup(GameData*, float, float, float, MedicalSystem*, bool, Character*);// RVA = 0x5058C0
            bool update(float, float, float, float, float, float);// RVA = 0x507DA0
            void updateDerivedHealths();// RVA = 0x4FC400
            void applyDamage(const Damages&);// RVA = 0x4FD250
            void applyWearDamage(const Damages&);// RVA = 0x4FC3D0
            float getWorstDamage(float);// RVA = 0x4FC870
            LimbState getRobotLimbState();// RVA = 0x4285C0
            void setRobotLimbItem(RobotLimbItem*, bool);// RVA = 0x4FCD90
            float getExtraBleedingAmount();// RVA = 0x4FD2E0
            bool isDead();// RVA = 0x50BF70
            float getBloodynessMult();// RVA = 0x429A80
            bool selfHealing; // 0x30 Member
            bool collapses; // 0x31 Member
            bool fatal; // 0x32 Member
            float KOMult; // 0x34 Member
            float hitChance; // 0x38 Member
            float hitChanceMult; // 0x3C Member
            float flesh; // 0x40 Member
            float fleshStun; // 0x44 Member
            float bandaging; // 0x48 Member
            float juryRigging; // 0x4C Member
            float wearDamage; // 0x50 Member
            float maxHealth();// RVA = 0x1FFC60
            float _maxHealth; // 0x54 Member
            float age; // 0x58 Member
            float HPMult; // 0x5C Member
            float healthAsPercent(float);// RVA = 0x4FC140
            float derivedFleshHealthPercent; // 0x60 Member
        };
        boost::unordered::unordered_map<GameData*, MedicalSystem::HealthPartStatus, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<std::pair<GameData* const, MedicalSystem::HealthPartStatus>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > status; // 0x8 Member
        HealthPartStatus* getPart(RobotLimbs::Limb);// RVA = 0x50BFB0
        HealthPartStatus* getPart(unsigned __int64);// RVA = 0x20F7E0
        HealthPartStatus* getPart(MedicalSystem::HealthPartStatus::PartType, LeftRight);// RVA = 0x50EC70
        // no_addr public class MedicalSystem::HealthPartStatus * getPart(class GameData *);
        int getPartCount();// RVA = 0x20F7D0
        void setRobotLimbItem(RobotLimbs::Limb, Item*, bool);// RVA = 0x4FDE70
        bool hasRobotics();// RVA = 0x6CD850
        lektor<Armour*> armourList; // 0x48 Member
        void addArmour(Armour*);// RVA = 0x4FE510
        void removeArmour(Item*);// RVA = 0x4FE600
        bool wearingUniformOf(Faction*);// RVA = 0x4FDA60
        void serialise(GameData*);// RVA = 0x507230
        void load(GameData*);// RVA = 0x508320
        GameData* addWound(bool, CutDirection, Damages&, int&, RootObject*, AttackDirection::Enum&, Harpoon*);// RVA = 0x5090B0
        float punchSomething(HitMaterialType, Character*, CombatTechniqueData*, int);// RVA = 0x518820
        static const std::string& getBoneNameForBodypart(GameData*);// RVA = 0x5027B0
        float hunger; // 0x60 Member
        float fed; // 0x64 Member
        bool isFed();// RVA = 0x46F860
        TimeOfDay lastPeriodicUpdate; // 0x68 Member
        float blood; // 0x70 Member
        float getMaxBlood();// RVA = 0x4FC880
        float extraBloodLossFromBodyparts; // 0x74 Member
        float currentBleedRate; // 0x78 Member
        HealthPartStatus* leftLeg; // 0x80 Member
        HealthPartStatus* rightLeg; // 0x88 Member
        HealthPartStatus* leftArm; // 0x90 Member
        HealthPartStatus* rightArm; // 0x98 Member
        float knockoutTimer; // 0xA0 Member
        void startKnockoutTimer();// RVA = 0x4FCFB0
        void knockout(float);// RVA = 0x4FD160
        void knockoutForceTimer(float);// RVA = 0x4973D0
        float pointOfCollapseBloodloss();// RVA = 0x4FC170
        float pointOfNoReturn();// RVA = 0x4FC2C0
        float pointOfNoReturn_Hunger01(float);// RVA = 0x50C020
        bool isHungerKO();// RVA = 0x4FCB00
        float getToughnessXpBonus();// RVA = 0x7034F0
        float getHungerSpeedModifier();// RVA = 0x4FD510
        float getHealthStatModifier(StatsEnumerated, bool, bool, bool, bool, bool, bool);// RVA = 0x4FDFC0
        float _getRoboticsStatMult(StatsEnumerated);// RVA = 0x4FD370
        float getMissingArmPenaltyMult();// RVA = 0x50C090
        float getDerivedHeadHealth();// RVA = 0x4FD560
        float worstDamage; // 0xA4 Member
        float needsFirstAidScoreTotal_robot; // 0xA8 Member
        float needsFirstAidScoreTotal_fleshy; // 0xAC Member
        float restedState; // 0xB0 Member
        float stealthHinderance; // 0xB4 Member
        float partBestArm; // 0xB8 Member
        float partHead; // 0xBC Member
        float partWorstTorso; // 0xC0 Member
        bool isCollapse(MedicalSystem::HealthPartStatus*, float);// RVA = 0x4FC290
        enum CollapseStage
        {
            COLLAPSE_NONE = 0x0,
            COLLAPSE_BUT_NO_RAGDOLL = 0x1,
            COLLAPSE_KO = 0x2
        };

        CollapseStage getCollapseStage(MedicalSystem::HealthPartStatus*, float);// RVA = 0x4FCC30
        void calculateDesiredPainAnimations();// RVA = 0x5028E0
        float getMovementSpeedInjuryMultiplier();// RVA = 0x6CEB10
        float getStatRoboticsMultiplier(StatsEnumerated);// RVA = 0x6CE020
        float getMovementSwimSpeedInjuryMultiplier();// RVA = 0x6CEBD0
        bool gettingEaten(float, bool);// RVA = 0x508B50
        bool gettingAcidRain(float);// RVA = 0x4FFAA0
        bool gettingAcidWater(float);// RVA = 0x4FF460
        bool gettingAcidFeet(float);// RVA = 0x4FF7F0
        bool gettingGassed(float);// RVA = 0x500610
        bool gettingWindyface(float);// RVA = 0x5016D0
        bool gettingBurnt(float);// RVA = 0x500C40
        bool applyFirstAid(float, Item*, float, Character*);// RVA = 0x505FE0
        bool applyDoctoring(float, Item*, float, Character*);// RVA = 0x5021E0
        bool applyRigging(float, Item*, float);// RVA = 0x502530
        void reassessCollapseMode(bool, bool);// RVA = 0x501B00
        bool isUnconcious();// RVA = 0x1F87E0
        bool isCrippled();// RVA = 0x40CA20
        bool isDead();// RVA = 0x27A180
        bool hasAnArmToFightWith();// RVA = 0x4FC930
        bool hasFreshlySeveredALimb();// RVA = 0x4FDB30
        bool isReallyHungry();// RVA = 0x333200
        float scoreTechnique(CombatTechniqueData*);// RVA = 0x6D01D0
        void getMedicalGUIData(DatapanelGUI*);// RVA = 0x6D4A90
        bool isProbablyDying();// RVA = 0x6CEC10
        float dazedOrAlert; // 0xC4 Member
        float getOverallHealthRating();// RVA = 0x6D0D80
        bool canGetUpWakeUp();// RVA = 0x46F880
        void _reassessRagdollPartsAssumingWeJustClearedTheEntireRagdoll();// RVA = 0x502730
        bool isRightArmOk();// RVA = 0x27F150
        bool isLeftArmOk();// RVA = 0x27F160
        bool canIkick();// RVA = 0x6CE140
        bool isInBloodlossTrauma();// RVA = 0x6CD890
        void splatBlood(const Damages&, CutDirection, AttackDirection::Enum);// RVA = 0x60C120
        void clearWeatherEffects();// RVA = 0x4AFA60
        float getWeatherStatPenaltyMult();// RVA = 0x4FC1D0
        int getWeatherStatPenalty(float);// RVA = 0x4FC210
        RobotLimbs* robotLimbs; // 0xC8 Member
        bool bloodynessChanged; // 0xD0 Member
        bool bloodynessCleanedUp; // 0xD1 Member
        float calculateBleedRateForFX();// RVA = 0x4FC440
        AnimationClass* animation; // 0xD8 Member
        Character* me; // 0xE0 Member
        StringPair weatherGUIfeedback; // 0xE8 Member
        WeatherAffecting currentWeatherAffect; // 0x148 Member
        float currentWeatherAffectStrength; // 0x14C Member
        TimeOfDay lastHungerKO; // 0x150 Member
        float nextKOTime; // 0x158 Member
        int _eatenDeathDelay; // 0x15C Member
        bool crippled; // 0x160 Member
        bool unconcious; // 0x161 Member
        bool sub50KO; // 0x162 Member
        bool bloodlossTrauma; // 0x163 Member
        bool dead; // 0x164 Member
        bool rightArmOk; // 0x165 Member
        bool leftArmOk; // 0x166 Member
        Ogre::Vector3 lastBloodPosition; // 0x168 Member
        Ogre::FastArray<Wound*> wounds; // 0x178 Member
        lektor<MedicalSystem::HealthPartStatus*> anatomy; // 0x190 Member
        void bloodlossUpdate(float);// RVA = 0x4FE920
        void drainMedkit(float, Item*, float);// RVA = 0x4FCA30
        void applyDamage(HealthPartStatus*, const Damages&, bool, bool, const Ogre::Vector3&);// RVA = 0x507AE0
        void ragdollPartCollapse(HealthPartStatus*);// RVA = 0x502050
        void updateDamageState();// RVA = 0x4FF040
        CharStats* stats; // 0x1A8 Member
        // no_addr public class MedicalSystem & operator=(const class MedicalSystem &);
        // no_addr public void __local_vftable_ctor_closure();
        // no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };

};
