#pragma once

#include "Enums.h"
#include "util/lektor.h"
#include "util/YesNoMaybe.h"
#include "util/StringPair.h"
#include "util/hand.h"
#include "FitnessSelector.h"

#include <ogre/OgreVector3.h>

class MedicalSystem;
class Character;
class CombatTechniqueData;
class GameData;
class DatapanelGUI;
class Item;
class Weapon;
class Building;
class Damages;

class CharStats : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::GeneralAllocatedObject offset = 0x8, length = 0x1
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
    std::map<WeatherAffecting, float, std::less<WeatherAffecting>, Ogre::STLAllocator<std::pair<WeatherAffecting const, float>, Ogre::GeneralAllocPolicy > > _weatherProtections; // 0x58 Member
    float getWeatherProtection(WeatherAffecting w) const;// public RVA = 0x6D0EB0
    // no_addr void CharStats(const class CharStats &);// public
    CharStats();// public RVA = 0x6D0FC0
    int unarmedEncumbrancePenalty() const;// public RVA = 0x6CE7E0
    int skillBonusUnarmed_forGUI(bool factorEnvironment) const;// public RVA = 0x6CE820
    int skillBonusAttack_melee(bool factorEnvironment) const;// public RVA = 0x6CE660
    int skillBonusAttack_unarmed(bool factorEnvironment) const;// public RVA = 0x6CE720
    int skillBonusDefence(bool factorEnvironment) const;// public RVA = 0x6CE8B0
    void serialise(GameData* data);// public RVA = 0x5030D0
    void updateStats(GameData* statData);// public RVA = 0x503E80
    virtual void init(GameData* data, MedicalSystem* _med, Character* charact);// public RVA = 0x505310 vtable offset = 0x0
    void _randomiseStats(float amount);// public RVA = 0x4FC4D0
    void getGUIData(DatapanelGUI* panel, int category);// public RVA = 0x6DF4F0
    void printStealthStats(std::string& out);// public RVA = 0x6D9AA0
    void getStealthTooltip(lektor<StringPair>* dats);// public RVA = 0x6D9B40
    void printRunSpeedStatMax(std::string& out);// public RVA = 0x6D3150
    void getAthleticsTooltip(lektor<StringPair>* dats);// public RVA = 0x6D8920
    void getGUIDataForMainInfo(DatapanelGUI* datapanel, int category, bool combatMode);// public RVA = 0x6DC2C0
    std::string formatWholeStatStringWithBonuses(int base, int current) const;// public RVA = 0x6D38B0
    std::string formatWholeStatStringWithBonuses(StatsEnumerated stat) const;// public RVA = 0x6ECAD0
    enum GUIStatsDisplayMode
    {
        GUI_STATS_NORMAL,
        GUI_STATS_MARTIALARTIST,
        GUI_STATS_RANGED
    };

    CharStats::GUIStatsDisplayMode getGUIStatsDisplayMode();// public RVA = 0x6CE270
    virtual void periodicUpdate();// public RVA = 0x6CDD10 vtable offset = 0x8
    float calculateStumbleThresholdDamageAmount();// public RVA = 0x6CE1C0
    void setEquipmentStatBonuses(float athlet, float combatSpd, int attack, int def, float _stealth, int _unarmed, float _dodge, float fistdamage, int perception, float ranged, float dexmult, float assmult, float damagemult);// public RVA = 0x6CE510
    float getOverallSkillLevel_0_100() const;// public RVA = 0x6CF1F0
    float& getStatRef(StatsEnumerated what);// public RVA = 0x6CE330
    float getStat(StatsEnumerated what, bool unmodified) const;// public RVA = 0x6CEC60
    static std::string getStatName(StatsEnumerated what);// public RVA = 0x6D25E0
    float getStatMultiplier(StatsEnumerated st) const;// public RVA = 0x6CF440
    std::string getStatMultiplierForGUI(StatsEnumerated st);// public RVA = 0x6D3B30
    bool getStatPenaltiesForGUI(const std::string& statName, StatsEnumerated stat, lektor<StringPair>& dats);// public RVA = 0x6DACA0
    int getStatPenaltiesTotalForGUI(const std::string& statName, StatsEnumerated stat);// public RVA = 0x6CE200
    void xpStat_timeBased(StatsEnumerated st);// public RVA = 0x704800
    void xpStat_eventBased(StatsEnumerated st, float amount);// public RVA = 0x7048C0
    void xpDodgeEvent(float enemySkill, bool successful);// public RVA = 0x703910
    float strengthActual() const;// public RVA = 0x2825B0
    float _strength; // 0x80 Member
    virtual float strengthBase() const;// public RVA = 0x4FA3A0 vtable offset = 0x10
    float fitness; // 0x84 Member
    float _dexterity; // 0x88 Member
    float dexterityBase() const;// public RVA = 0x4285E0
    float dexterityActual() const;// public RVA = 0x6CD8A0
    float perception; // 0x8C Member
    float _toughness; // 0x90 Member
    float toughness() const;// public RVA = 0x46F8B0
    float getToughnessMult();// public RVA = 0x4FC190
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
    float getRangedFriendlyFireAvoidanceChance();// public RVA = 0x358C40
    float getRangedAccuracyMult(StatsEnumerated stat);// public RVA = 0x350090
    float getReloadSkill(StatsEnumerated stat);// public RVA = 0x6CFE80
    float currentItemMaximumJuryRig; // 0x11C Member
    void animalRecruitReduceStats();// public RVA = 0x54F870
    float __meleeAttack; // 0x120 Member
    float _meleeDefence; // 0x124 Member
    float& getMeleeAttackRef();// protected RVA = 0x703380
    void _chooseAttacks(FitnessSelector<CombatTechniqueData*>& possibleAttacks, float range, float weaponReach, CombatTechniqueData* lastAttack, bool opponentIsStationary, bool skipMedicals, WeaponCategory _weaponType, float _weaponSkill);// protected RVA = 0x6D1870
    float getMeleeDefence(bool includeDefensiveMode) const;// public RVA = 0x6D0430
    float getDodge(bool bonuses) const;// public RVA = 0x6CF330
    float getDodgePenalty_encumbrance() const;// public RVA = 0x6CF260
    float getDodgePenalty_injuries() const;// public RVA = 0x6CF2C0
    float getDodgePenalty_gear() const;// public RVA = 0x6CE890
    float getMeleeDefence_melee(bool includeDefensiveMode) const;// public RVA = 0x6CF0F0
    float getMeleeAttack() const;// public RVA = 0x6CF080
    float getMeleeAttack_unarmed(bool bonuses) const;// public RVA = 0x6CEFA0
    float getMeleeAttack_melee() const;// public RVA = 0x6CF020
    float _getMeleeAttackBase() const;// public RVA = 0x520C80
    float getMaxHealAmount(Item* equipment, Building* bed, bool isRobot);// public RVA = 0x4FCAF0
    bool isDefensiveMode() const;// public RVA = 0x216510
    bool _defensiveMode; // 0x128 Member
    bool rangedMode; // 0x129 Member
    bool tauntMode; // 0x12A Member
    bool holdPositionMode() const;// public RVA = 0x216550
    bool _holdPositionMode; // 0x12B Member
    bool passiveCombatMode; // 0x12C Member
    Ogre::Vector3 holdLocation; // 0x130 Member
    void setHoldLocation(const Ogre::Vector3& v);// public RVA = 0x27D620
    void clearHoldLocation();// public RVA = 0x27D630
    // no_addr bool hasHoldLocation();// public
    float warriorSpirit; // 0x13C Member
    float derivedSpirit; // 0x140 Member
    float aggression; // 0x144 Member
    float goodness; // 0x148 Member
    float evilness; // 0x14C Member
    CombatTechniqueData* getBashAnimation(float range);// public RVA = 0x6D15C0
    CombatTechniqueData* chooseAttack(float range, float weaponReach, CombatTechniqueData* lastAttack, bool opponentIsStationary);// public RVA = 0x6D21D0
    float longestReachingAttack; // 0x150 Member
    CombatTechniqueData* chooseBlock(CutDirection dir, float opponentAttackSkill, CutOrigination from, Character* opponent);// public RVA = 0x6D1B10
    float calculateStumbleBlockTimer(float stumbleForce);// public RVA = 0x6D0450
    const std::string& getPainAnim(GameData* anatomyHit) const;// public RVA = 0x4FF390
    float calculateTechniqueInegrityCheckTimer();// public RVA = 0x6D0460
    float calculateToughnessDamageResistanceMult();// public RVA = 0x4FCF50
    float calculateToughnessWoundDegenerationRate();// public RVA = 0x4FC450
    float getAttackChance();// public RVA = 0x6CFFE0
    float getAttackCuttingDamage();// public RVA = 0x6CDD40
    float getAttackBluntPower();// public RVA = 0x6CDE00
    float getAttackBleedDamageMult();// public RVA = 0x6CDDF0
    float getAttackPierceDamage();// public RVA = 0x6CDEB0
    Damages getTotalAttackDamageFor(Character* target);// public RVA = 0x6D0A50
    virtual float getEquippedWeaponSkill() const;// public RVA = 0x6EBA90 vtable offset = 0x18
    float getSkillDifferenceRatio(float mine, float his);// public RVA = 0x703550
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

    float calculateDeadTime(CharStats::DeadTimeState state);// public RVA = 0x6CE190
    float STUBBOURNESS; // 0x154 Member
    float PROFESSIONALNESS; // 0x158 Member
    float HOLDING_POSITION; // 0x15C Member
    float IMMEDIACY; // 0x160 Member
    float IMMEDIACY_MAX_RANGE; // 0x164 Member
    float MANLINESS; // 0x168 Member
    float MURDEROUS; // 0x16C Member
    void xpMelee(CharStats::DeadTimeState what, Character* target, const Damages& damage);// public RVA = 0x703F30
    void xpToughness_RagdollEvent();// public RVA = 0x703CD0
    void xpToughness_GetUpEvent();// public RVA = 0x703D30
    void xpToughness_PunchSomething(HitMaterialType mat);// public RVA = 0x703E90
    void xpFirstAid(Character* patient, float time, StatsEnumerated medicStat);// public RVA = 0x7036E0
    void xpRunning(float time, float speed);// public RVA = 0x703C10
    void xpStealth(float time, bool enemiesAbout, YesNoMaybe* seen, bool isMoving);// public RVA = 0x703B50
    void xpStealthHearCheckEvent(bool enemiesAbout, bool trespassing, bool seen);// public RVA = 0x7048E0
    StringPair stealthXPMultForGUI();// public RVA = 0x704990
    float _stealthXPMultForGUI; // 0x170 Member
    float stealthXPTooManyCooksPenalty; // 0x174 Member
    void xpMassCombat();// public RVA = 0x703430
    void xpEngineering(float time);// public RVA = 0x703800
    void xpLockpicking(int lockLevel, bool success);// public RVA = 0x703890
    void xpTraining(float time, float mult, float& stat, float upperLimit, StatsEnumerated whatStatIsIt);// public RVA = 0x703AA0
    void xpGeneral(float time, float mult, StatsEnumerated what);// public RVA = 0x7039E0
    float calculateAthleticsXPMult(float speed);// public RVA = 0x703470
    float calculateStrengthXPMultFromWalking();// public RVA = 0x703670
    void setWeapon(Weapon* _weapon);// public RVA = 0x6E20D0
    bool isUnarmed() const;// public RVA = 0x27F170
    // no_addr float getWeaponWeightBonus();// public
    float getWeaponWeightXPBonus();// public RVA = 0x6CD8F0
    float getAttackSpeed();// public RVA = 0x212700
    float getBlockSpeed();// public RVA = 0x4CBDD0
    float getMaxRunSpeed();// public RVA = 0x212710
    float getCurrentWeaponLength() const;// public RVA = 0x4CBDE0
    float getStealthSkill01(bool modded) const;// public RVA = 0x6CE9F0
    float getAttackSuccessChanceSkill();// public RVA = 0x4CBDF0
    static float _convertWeaponWeightToBluntMultiplier(float weaponWeight);// public RVA = 0x6CDA40
    static float _convertBluntMultiplierToWeaponWeight(float blunt);// public RVA = 0x6CDA50
    float getEncumbranceMult() const;// public RVA = 0x212720
    float calculateHungerMult();// public RVA = 0x6CD940
    void printExertionHungerMultTooltip(lektor<StringPair>* dats);// public RVA = 0x6D4450
    float calculateTheoreticalIdealMaxRunSpeed();// public RVA = 0x6CDF50
    float calculateWeaponWeightXPMult(float weaponWeight);// public RVA = 0x6CDA80
    bool hasWeapon() const;// public RVA = 0x46F8C0
    // no_addr enum WeaponCategory getCurrentWeaponType();// public
    float calculateMaxStealthSpeed();// public RVA = 0x6CEAC0
    float _calculateMaxSwimSpeed();// public RVA = 0x6CDFD0
    float calculateSwimSpeed();// public RVA = 0x6D0050
    float currentOperatingMachineHungerRate; // 0x178 Member
    float calculateDodgeChance(float versus, bool stumbling);// public RVA = 0x6CFF20
    void calculateMaxRunSpeed();// protected RVA = 0x6D0600
    float moveSpeed; // 0x17C Member
    float _calculateEncumberanceMult();// protected RVA = 0x6CE920
    void _calculateWeaponWeightSpeedMultiplier(float weaponWeight);// protected RVA = 0x6CDB40
    LeftRight currentWeaponHand();// protected RVA = 0x6CDA60
    float calculateAttackOrBlockSpeed(float weaponWeightSpeedMult, float attackOrBlockSkill, bool isBlock);// protected RVA = 0x6CDC20
    float weaponWeightSpeedMult; // 0x180 Member
    float weaponWeightXPMult; // 0x184 Member
    float attackSpeed; // 0x188 Member
    float blockSpeed; // 0x18C Member
    float encumbranceMult; // 0x190 Member
    float _calculateBlockChance(float versus);// protected RVA = 0x6D0470
    virtual void _recalculateStats();// protected RVA = 0x6D0850 vtable offset = 0x20
    static void setupCombatTechniques();// protected RVA = 0x6D2E40
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
    // this is weird - I think the template might actually take a policy as an arg?
    std::map<GameData*, float, std::less<GameData*>, Ogre::STLAllocator<std::pair<GameData* const, float>, Ogre::GeneralAllocPolicy > > bonusRaces; // 0x1C8 Member
    WeaponCategory currentWeaponType; // 0x1F0 Member
    float* pCurrentWeaponSkill; // 0x1F8 Member
    float currentWeaponLength; // 0x200 Member
    virtual void setEquippedWeaponSkill(float v);// protected RVA = 0x6EBAA0 vtable offset = 0x28
    hand weapon; // 0x208 Member
    float weaponWeight; // 0x228 Member
    ~CharStats();// public RVA = 0x4F9D10
    // no_addr class CharStats & operator=(const class CharStats &);// public
    // no_addr void * __vecDelDtor(unsigned int);// public
};
