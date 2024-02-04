#pragma once

class GameData;
namespace Kenshi
{
    class GlobalConstants
    {
    public:
        void setup(class GameData*);// RVA = 0x6BA770
        float EXTRA_BLEED_FROM_BODYPARTS_MULTIPLIER; // 0x0 Member
        float BLEED_RATE_MULTIPLIER; // 0x4 Member
        float INITIAL_BLEED_LOSS_MULTIPLIER; // 0x8 Member
        float BLEED_CLOT_RATE; // 0xC Member
        float BLUNT_DAMAGE_1; // 0x10 Member
        float BLUNT_DAMAGE_99; // 0x14 Member
        float CUT_DAMAGE_1; // 0x18 Member
        float CUT_DAMAGE_99; // 0x1C Member
        float BOW_DAMAGE_0; // 0x20 Member
        float BOW_DAMAGE_99; // 0x24 Member
        float PIERCE_MULTIPLIER; // 0x28 Member
        float MIN_STUMBLE_DAMAGE_MAX; // 0x2C Member
        float DAMAGE_RESISTANCE_MIN; // 0x30 Member
        float DAMAGE_RESISTANCE_MAX; // 0x34 Member
        float STUN_RECOVERY_RATE; // 0x38 Member
        float BLOOD_RECOVERY_RATE; // 0x3C Member
        float ATTACK_CHANCE_SKILL_DIFFERENCE_FACTOR; // 0x40 Member
        float BASE_BLOCK_CHANCE; // 0x44 Member
        float BLOCK_CHANCE_REDUCTION; // 0x48 Member
        float BLOCK_CHANCE_INCREASE; // 0x4C Member
        float DEGENERATION_MULT_1; // 0x50 Member
        float DEGENERATION_MULT_99; // 0x54 Member
        float MEDIC_SPEED_MULT; // 0x58 Member
        float KNOCKOUT_MULT_1; // 0x5C Member
        float KNOCKOUT_MULT_99; // 0x60 Member
        float KNOCKOUT_BASE_TIME; // 0x64 Member
        float BODYPART_DEGENERATE_RATE_MULT; // 0x68 Member
        float BODYPART_HEAL_RATE_MULT; // 0x6C Member
        float BODYPART_HEAL_RATE_MULT_RESTING; // 0x70 Member
        float XP_MEDIC_1; // 0x74 Member
        float XP_MEDIC_99; // 0x78 Member
        float MEDKIT_DRAIN_1; // 0x7C Member
        float MEDKIT_DRAIN_99; // 0x80 Member
        float ROBOT_WEAR_RATE; // 0x84 Member
        float ROBOT_FIRST_AID_SPEED; // 0x88 Member
        float STARVATION_TIME_HRS; // 0x8C Member
        float FED_RECOVERY_RATE_MULT; // 0x90 Member
        float BED_HUNGER_RATE; // 0x94 Member
        float ENCUMBRANCE_HUNGER_RATE; // 0x98 Member
        float FOOD_QUALITY_MULT; // 0x9C Member
        float FOOD_PRICE_MULT; // 0xA0 Member
        float SKILL_DIFFERENCE_XP_RATIO_MULT_BONUS; // 0xA4 Member
        float SKILL_DIFFERENCE_XP_RATIO_MULT_PENALTY; // 0xA8 Member
        float XP_HIT_THEM; // 0xAC Member
        float XP_HIT_ME; // 0xB0 Member
        float XP_BLOCKED_THEM; // 0xB4 Member
        float XP_BLOCKED_ME; // 0xB8 Member
        float XP_FIRSTAID; // 0xBC Member
        float XP_FITNESS; // 0xC0 Member
        float XP_TOUGHNESS; // 0xC4 Member
        float PRICE_ROBOTICS; // 0xC8 Member
        float PRICE_CROSSBOWS; // 0xCC Member
        float PRICE_ARMOUR; // 0xD0 Member
        float PRICE_SWORDS; // 0xD4 Member
        float PRICE_TRADE; // 0xD8 Member
        float PRICE_GLOBAL_MULT; // 0xDC Member
        float PRICE_CLOTHING; // 0xE0 Member
        float TRADE_PROFIT_MARGINS; // 0xE4 Member
        float PRICE_LOOT_GEAR; // 0xE8 Member
        float PRICE_LOOT_ITEMS; // 0xEC Member
        float PRICE_LOOT_PLAYER_CRAFTED_ARMOUR; // 0xF0 Member
        float PRICE_LOOT_PLAYER_CRAFTED_WEAPONS; // 0xF4 Member
        float BLUEPRINT_COST_MULT; // 0xF8 Member
        float UNIFORM_PRICE_MULT; // 0xFC Member
        float BLUNT_PERMANENT_DAMAGE_RATIO; // 0x100 Member
        float UNARMED_DAMAGE_MULT; // 0x104 Member
        int MAX_NUM_ATTACK_SLOTS; // 0x108 Member
        float MINIMUM_STRENGTH_XP_MULT; // 0x10C Member
        float WEIGHT_STR_DIFF_1X; // 0x110 Member
        float WEIGHT_STR_DIFF_MAX; // 0x114 Member
        float WEAPON_INVENTORY_WEIGHT_MULT; // 0x118 Member
        float STRENGTH_XP_RATE_FROM_WALKING; // 0x11C Member
        float STRENGTH_XP_RATE; // 0x120 Member
        float ATHLETICS_XP_RATE; // 0x124 Member
        float ENCUMBRANCE_BASE; // 0x128 Member
        float CARRY_WEIGHT_MULT; // 0x12C Member
        float CARRY_PERSON_WEIGHT; // 0x130 Member
        float MIN_MATS_FROM_DISMANTLE_01; // 0x134 Member
        double EXPERIENCE_GAIN; // 0x138 Member
        double EXPERIENCE_GAIN_1; // 0x140 Member
        double EXPERIENCE_GAIN_99; // 0x148 Member
        float RESEARCH_LEVEL_INCREASE; // 0x150 Member
        float RESEARCH_RATE; // 0x154 Member
        float LOCKPICK_CHANCE_MINIMUM; // 0x158 Member
        float EXPERIENCE_CURVE; // 0x15C Member
        float ANIMATION_BLEND_RATE; // 0x160 Member
        float PRODUCTION_MULTIPLIER; // 0x164 Member
        float BUILD_SPEED_MULTIPLIER; // 0x168 Member
        float PRISON_TIME_MULT; // 0x16C Member
        float TOUGHNESS_KO_POINT_MIN; // 0x170 Member
        float TOUGHNESS_KO_POINT_MAX; // 0x174 Member
        int MAX_SQUAD_SIZE; // 0x178 Member
        int MAX_SQUADS; // 0x17C Member
        int MAX_FACTION_SIZE; // 0x180 Member
        bool attackDiplomats; // 0x184 Member
        GameData* settings; // 0x188 Member
        float APPEARANCE_RANDOM_DEVIATION; // 0x190 Member
        float fogDistMax; // 0x194 Member
        float fogDistMin; // 0x198 Member
    };
}