#pragma once

#include "Enums.h"
#include "util/lektor.h"
#include "util/YesNoMaybe.h"
#include "util/StringPair.h"
#include "util/hand.h"

#include <ogre/OgreVector3.h>

class MedicalSystem;
class Character;

// TODO move?
// RVAs from FitnessSelector<CombatTechniqueData*>
template<typename T>
class FitnessSelector
{
    // no_addr public void FitnessSelector<CombatTechniqueData *>(const class FitnessSelector<CombatTechniqueData *> &);
    // no_addr public void FitnessSelector<CombatTechniqueData *>();
    // no_addr public void reset();
    // no_addr public void deleteAll();
    // no_addr public int size();
    // no_addr public bool hasItem(class CombatTechniqueData * const);
    // no_addr public bool empty();
    // no_addr public float getItemScore(class CombatTechniqueData * const);
    // no_addr public void addItem(class CombatTechniqueData *, const float);
    // no_addr public bool removeItem(class CombatTechniqueData * const);
    // no_addr public class CombatTechniqueData * chooseAnItem(class boost::random::mersenne_twister_engine<unsigned int,32,624,397,31,2567483615,11,4294967295,7,2636928640,15,4022730752,18,1812433253> &);
    // no_addr public class CombatTechniqueData * chooseAnItem();
    // no_addr public class CombatTechniqueData * chooseAnItem_absoluteScore();
    // no_addr public class CombatTechniqueData * chooseHighest();
    // no_addr public class CombatTechniqueData * takeHighest();
    // no_addr public class CombatTechniqueData * takeRandom();
    std::map<float, T, std::less<float>, Ogre::STLAllocator<std::pair<float const, T>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > list; // 0x0 Member
    std::map<T, float, std::less<T>, Ogre::STLAllocator<std::pair<T const, float>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > itemsScores; // 0x28 Member
    float totalScore; // 0x50 Member
    float highestScore; // 0x54 Member
    T highestItem; // 0x58 Member
    // no_addr public void ~FitnessSelector<CombatTechniqueData *>();
    // no_addr public class FitnessSelector<CombatTechniqueData *> & operator=(const class FitnessSelector<CombatTechniqueData *> &);
    // no_addr public void * __vecDelDtor(unsigned int);
};

class CombatTechniqueData;
class GameData;
class DatapanelGUI;
class Item;
class Weapon;
class Building;
class Damages;

class CharStats : Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    MedicalSystem* medical; // 0x8 Member
    Character* me; // 0x10 Member
    float athleticsMultiplier; // 0x18 Member
    float combatSpeedMultiplier; // 0x1C Member
    int _skillBonusAttack; // 0x20 Member
    int _skillBonusDefence; // 0x24 Member
    int skillBonusIndoors; // 0x28 Member
    int skillBonusUnarmed; // 0x2C Member
    int skillBonusPerception; // 0x30 Member
    float ageMult; // 0x34 Member
    float skillMultDodge; // 0x38 Member
    float skillMultStealth; // 0x3C Member
    float skillMultAssassin; // 0x40 Member
    float skillMultDexterity; // 0x44 Member
    float skillMultDamage; // 0x48 Member
    float fistInjuryEquipmentMult; // 0x4C Member
    float skillMultRanged; // 0x50 Member
    std::map<WeatherAffecting, float, std::less<WeatherAffecting>, Ogre::STLAllocator<std::pair<WeatherAffecting const, float>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > _weatherProtections; // 0x58 Member
    float getWeatherProtection(WeatherAffecting);// RVA = 0x6D0EB0
    // no_addr public void CharStats(const class CharStats &);
    CharStats();// RVA = 0x6D0FC0
    int unarmedEncumbrancePenalty();// RVA = 0x6CE7E0
    int skillBonusUnarmed_forGUI(bool);// RVA = 0x6CE820
    int skillBonusAttack_melee(bool);// RVA = 0x6CE660
    int skillBonusAttack_unarmed(bool);// RVA = 0x6CE720
    int skillBonusDefence(bool);// RVA = 0x6CE8B0
    void serialise(GameData*);// RVA = 0x5030D0
    void updateStats(GameData*);// RVA = 0x503E80
    virtual void init(GameData*, MedicalSystem*, Character*);// RVA = 0x505310// vtable offset = 0x0
    void _randomiseStats(float);// RVA = 0x4FC4D0
    void getGUIData(DatapanelGUI*, int);// RVA = 0x6DF4F0
    void printStealthStats(std::string&);// RVA = 0x6D9AA0
    void getStealthTooltip(lektor<StringPair>*);// RVA = 0x6D9B40
    void printRunSpeedStatMax(std::string&);// RVA = 0x6D3150
    void getAthleticsTooltip(lektor<StringPair>*);// RVA = 0x6D8920
    void getGUIDataForMainInfo(DatapanelGUI*, int, bool);// RVA = 0x6DC2C0
    std::string formatWholeStatStringWithBonuses(int, int);// RVA = 0x6D38B0
    std::string formatWholeStatStringWithBonuses(StatsEnumerated);// RVA = 0x6ECAD0
    enum GUIStatsDisplayMode
    {
        GUI_STATS_NORMAL,
        GUI_STATS_MARTIALARTIST,
        GUI_STATS_RANGED
    };

    GUIStatsDisplayMode getGUIStatsDisplayMode();// RVA = 0x6CE270
    virtual void periodicUpdate();// RVA = 0x6CDD10// vtable offset = 0x8
    float calculateStumbleThresholdDamageAmount();// RVA = 0x6CE1C0
    void setEquipmentStatBonuses(float, float, int, int, float, int, float, float, int, float, float, float, float);// RVA = 0x6CE510
    float getOverallSkillLevel_0_100();// RVA = 0x6CF1F0
    float& getStatRef(StatsEnumerated);// RVA = 0x6CE330
    float getStat(StatsEnumerated, bool);// RVA = 0x6CEC60
    static std::string getStatName(StatsEnumerated);// RVA = 0x6D25E0
    float getStatMultiplier(StatsEnumerated);// RVA = 0x6CF440
    std::string getStatMultiplierForGUI(StatsEnumerated);// RVA = 0x6D3B30
    bool getStatPenaltiesForGUI(const std::string&, StatsEnumerated, lektor<StringPair>&);// RVA = 0x6DACA0
    int getStatPenaltiesTotalForGUI(const std::string&, StatsEnumerated);// RVA = 0x6CE200
    void xpStat_timeBased(StatsEnumerated);// RVA = 0x704800
    void xpStat_eventBased(StatsEnumerated, float);// RVA = 0x7048C0
    void xpDodgeEvent(float, bool);// RVA = 0x703910
    float strengthActual();// RVA = 0x2825B0
    float _strength; // 0x80 Member
    virtual float strengthBase();// RVA = 0x4FA3A0// vtable offset = 0x10
    float fitness; // 0x84 Member
    float _dexterity; // 0x88 Member
    float dexterityBase();// RVA = 0x4285E0
    float dexterityActual();// RVA = 0x6CD8A0
    float perception; // 0x8C Member
    float _toughness; // 0x90 Member
    float toughness();// RVA = 0x46F8B0
    float getToughnessMult();// RVA = 0x4FC190
    float _athletics; // 0x94 Member
    float medic; // 0x98 Member
    float massCombat; // 0x9C Member
    float arrowDefence; // 0xA0 Member
    float stealth; // 0xA4 Member
    float swimming; // 0xA8 Member
    float thieving; // 0xAC Member
    float lockpicking; // 0xB0 Member
    float bluff; // 0xB4 Member
    float assassin; // 0xB8 Member
    float survival; // 0xBC Member
    float tracking; // 0xC0 Member
    float climbing; // 0xC4 Member
    float doctor; // 0xC8 Member
    float engineer; // 0xCC Member
    float weaponSmith; // 0xD0 Member
    float armourSmith; // 0xD4 Member
    float bowSmith; // 0xD8 Member
    float robotics; // 0xDC Member
    float science; // 0xE0 Member
    float labouring; // 0xE4 Member
    float farming; // 0xE8 Member
    float cooking; // 0xEC Member
    float dodging; // 0xF0 Member
    float friendlyFire; // 0xF4 Member
    float katanas; // 0xF8 Member
    float sabres; // 0xFC Member
    float hackers; // 0x100 Member
    float blunt; // 0x104 Member
    float heavyWeapons; // 0x108 Member
    float unarmed; // 0x10C Member
    float bows; // 0x110 Member
    float turrets; // 0x114 Member
    float polearms; // 0x118 Member
    float getRangedFriendlyFireAvoidanceChance();// RVA = 0x358C40
    float getRangedAccuracyMult(StatsEnumerated);// RVA = 0x350090
    float getReloadSkill(StatsEnumerated);// RVA = 0x6CFE80
    float currentItemMaximumJuryRig; // 0x11C Member
    void animalRecruitReduceStats();// RVA = 0x54F870
    float __meleeAttack; // 0x120 Member
    float _meleeDefence; // 0x124 Member
    float& getMeleeAttackRef();// RVA = 0x703380
    void _chooseAttacks(FitnessSelector<CombatTechniqueData*>&, float, float, CombatTechniqueData*, bool, bool, WeaponCategory, float);// RVA = 0x6D1870
    float getMeleeDefence(bool);// RVA = 0x6D0430
    float getDodge(bool);// RVA = 0x6CF330
    float getDodgePenalty_encumbrance();// RVA = 0x6CF260
    float getDodgePenalty_injuries();// RVA = 0x6CF2C0
    float getDodgePenalty_gear();// RVA = 0x6CE890
    float getMeleeDefence_melee(bool);// RVA = 0x6CF0F0
    float getMeleeAttack();// RVA = 0x6CF080
    float getMeleeAttack_unarmed(bool);// RVA = 0x6CEFA0
    float getMeleeAttack_melee();// RVA = 0x6CF020
    float _getMeleeAttackBase();// RVA = 0x520C80
    float getMaxHealAmount(Item*, Building*, bool);// RVA = 0x4FCAF0
    bool isDefensiveMode();// RVA = 0x216510
    bool _defensiveMode; // 0x128 Member
    bool rangedMode; // 0x129 Member
    bool tauntMode; // 0x12A Member
    bool holdPositionMode();// RVA = 0x216550
    bool _holdPositionMode; // 0x12B Member
    bool passiveCombatMode; // 0x12C Member
    Ogre::Vector3 holdLocation; // 0x130 Member
    void setHoldLocation(const Ogre::Vector3&);// RVA = 0x27D620
    void clearHoldLocation();// RVA = 0x27D630
    // no_addr public bool hasHoldLocation();
    float warriorSpirit; // 0x13C Member
    float derivedSpirit; // 0x140 Member
    float aggression; // 0x144 Member
    float goodness; // 0x148 Member
    float evilness; // 0x14C Member
    CombatTechniqueData* getBashAnimation(float);// RVA = 0x6D15C0
    CombatTechniqueData* chooseAttack(float, float, CombatTechniqueData*, bool);// RVA = 0x6D21D0
    float longestReachingAttack; // 0x150 Member
    CombatTechniqueData* chooseBlock(CutDirection, float, CutOrigination, Character*);// RVA = 0x6D1B10
    float calculateStumbleBlockTimer(float);// RVA = 0x6D0450
    const std::string& getPainAnim(GameData*);// RVA = 0x4FF390
    float calculateTechniqueInegrityCheckTimer();// RVA = 0x6D0460
    float calculateToughnessDamageResistanceMult();// RVA = 0x4FCF50
    float calculateToughnessWoundDegenerationRate();// RVA = 0x4FC450
    float getAttackChance();// RVA = 0x6CFFE0
    float getAttackCuttingDamage();// RVA = 0x6CDD40
    float getAttackBluntPower();// RVA = 0x6CDE00
    float getAttackBleedDamageMult();// RVA = 0x6CDDF0
    float getAttackPierceDamage();// RVA = 0x6CDEB0
    Damages getTotalAttackDamageFor(Character*);// RVA = 0x6D0A50
    virtual float getEquippedWeaponSkill();// RVA = 0x6EBA90// vtable offset = 0x18
    float getSkillDifferenceRatio(float, float);// RVA = 0x703550
    enum DeadTimeState
    {
        ATTACK_HIT,
        ATTACK_WAS_BLOCKED,
        BLOCKED_IT,
        ATTACK_SLOT_OPEN,
        WAS_HIT,
        ATTACK_INTERRUPTED,
        ATTACK_MISSED
    };

    float calculateDeadTime(DeadTimeState);// RVA = 0x6CE190
    float STUBBOURNESS; // 0x154 Member
    float PROFESSIONALNESS; // 0x158 Member
    float HOLDING_POSITION; // 0x15C Member
    float IMMEDIACY; // 0x160 Member
    float IMMEDIACY_MAX_RANGE; // 0x164 Member
    float MANLINESS; // 0x168 Member
    float MURDEROUS; // 0x16C Member
    void xpMelee(DeadTimeState, Character*, const Damages&);// RVA = 0x703F30
    void xpToughness_RagdollEvent();// RVA = 0x703CD0
    void xpToughness_GetUpEvent();// RVA = 0x703D30
    void xpToughness_PunchSomething(HitMaterialType);// RVA = 0x703E90
    void xpFirstAid(Character*, float, StatsEnumerated);// RVA = 0x7036E0
    void xpRunning(float, float);// RVA = 0x703C10
    void xpStealth(float, bool, YesNoMaybe, bool);// RVA = 0x703B50
    void xpStealthHearCheckEvent(bool, bool, bool);// RVA = 0x7048E0
    StringPair stealthXPMultForGUI();// RVA = 0x704990
    float _stealthXPMultForGUI; // 0x170 Member
    float stealthXPTooManyCooksPenalty; // 0x174 Member
    void xpMassCombat();// RVA = 0x703430
    void xpEngineering(float);// RVA = 0x703800
    void xpLockpicking(int, bool);// RVA = 0x703890
    void xpTraining(float, float, float&, float, StatsEnumerated);// RVA = 0x703AA0
    void xpGeneral(float, float, StatsEnumerated);// RVA = 0x7039E0
    float calculateAthleticsXPMult(float);// RVA = 0x703470
    float calculateStrengthXPMultFromWalking();// RVA = 0x703670
    void setWeapon(Weapon*);// RVA = 0x6E20D0
    bool isUnarmed();// RVA = 0x27F170
    // no_addr public float getWeaponWeightBonus();
    float getWeaponWeightXPBonus();// RVA = 0x6CD8F0
    float getAttackSpeed();// RVA = 0x212700
    float getBlockSpeed();// RVA = 0x4CBDD0
    float getMaxRunSpeed();// RVA = 0x212710
    float getCurrentWeaponLength();// RVA = 0x4CBDE0
    float getStealthSkill01(bool);// RVA = 0x6CE9F0
    float getAttackSuccessChanceSkill();// RVA = 0x4CBDF0
    static float _convertWeaponWeightToBluntMultiplier(float);// RVA = 0x6CDA40
    static float _convertBluntMultiplierToWeaponWeight(float);// RVA = 0x6CDA50
    float getEncumbranceMult();// RVA = 0x212720
    float calculateHungerMult();// RVA = 0x6CD940
    void printExertionHungerMultTooltip(lektor<StringPair>*);// RVA = 0x6D4450
    float calculateTheoreticalIdealMaxRunSpeed();// RVA = 0x6CDF50
    float calculateWeaponWeightXPMult(float);// RVA = 0x6CDA80
    bool hasWeapon();// RVA = 0x46F8C0
    // no_addr public enum WeaponCategory getCurrentWeaponType();
    float calculateMaxStealthSpeed();// RVA = 0x6CEAC0
    float _calculateMaxSwimSpeed();// RVA = 0x6CDFD0
    float calculateSwimSpeed();// RVA = 0x6D0050
    float currentOperatingMachineHungerRate; // 0x178 Member
    float calculateDodgeChance(float, bool);// RVA = 0x6CFF20
    void calculateMaxRunSpeed();// RVA = 0x6D0600
    float moveSpeed; // 0x17C Member
    float _calculateEncumberanceMult();// RVA = 0x6CE920
    void _calculateWeaponWeightSpeedMultiplier(float);// RVA = 0x6CDB40
    LeftRight currentWeaponHand();// RVA = 0x6CDA60
    float calculateAttackOrBlockSpeed(float, float, bool);// RVA = 0x6CDC20
    float weaponWeightSpeedMult; // 0x180 Member
    float weaponWeightXPMult; // 0x184 Member
    float attackSpeed; // 0x188 Member
    float blockSpeed; // 0x18C Member
    float encumbranceMult; // 0x190 Member
    float _calculateBlockChance(float);// RVA = 0x6D0470
    virtual void _recalculateStats();// RVA = 0x6D0850// vtable offset = 0x20
    static void setupCombatTechniques();// RVA = 0x6D2E40
    static lektor<CombatTechniqueData*> attacks; // Static Member
    static lektor<CombatTechniqueData*> blocks; // Static Member
    float xp; // 0x194 Member
    int freeAttributePoints; // 0x198 Member
    float cutDamageMult; // 0x19C Member
    float bluntDamageMult; // 0x1A0 Member
    float bleedDamageMult; // 0x1A4 Member
    float pierceDamageMult; // 0x1A8 Member
    float cutDamageMin; // 0x1AC Member
    float bluntDamageMin; // 0x1B0 Member
    float bonusRobots; // 0x1B4 Member
    float bonusHumans; // 0x1B8 Member
    float bonusAnimals; // 0x1BC Member
    float bonusArmourPenetration; // 0x1C0 Member
    std::map<GameData*, float, std::less<GameData*>, Ogre::STLAllocator<std::pair<GameData* const, float>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > bonusRaces; // 0x1C8 Member
    WeaponCategory currentWeaponType; // 0x1F0 Member
    float* pCurrentWeaponSkill; // 0x1F8 Member
    float currentWeaponLength; // 0x200 Member
    virtual void setEquippedWeaponSkill(float);// RVA = 0x6EBAA0// vtable offset = 0x28
    hand weapon; // 0x208 Member
    float weaponWeight; // 0x228 Member
    ~CharStats();// RVA = 0x4F9D10
    // no_addr public class CharStats & operator=(const class CharStats &);
    // no_addr public void * __vecDelDtor(unsigned int);
};
