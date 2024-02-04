#pragma once

// for global enums 
enum itemType
{
    BUILDING = 0x0,
    CHARACTER = 0x1,
    WEAPON = 0x2,
    ARMOUR = 0x3,
    ITEM = 0x4,
    ANIMAL_ANIMATION = 0x5,
    ATTACHMENT = 0x6,
    RACE = 0x7,
    LOCATION = 0x8,
    WAR_SAVESTATE = 0x9,
    FACTION = 0xA,
    NULL_ITEM = 0xB,
    ZONE_MAP = 0xC,
    TOWN = 0xD,
    WORLDMAP_CHARACTER = 0xE,
    CHARACTER_APPEARANCE_OLD = 0xF,
    LOCATIONAL_DAMAGE = 0x10,
    COMBAT_TECHNIQUE = 0x11,
    DIALOGUE = 0x12,
    DIALOGUE_LINE = 0x13,
    TECHTREE = 0x14,
    RESEARCH = 0x15,
    AI_TASK = 0x16,
    AI_STATE = 0x17,
    ANIMATION = 0x18,
    STATS = 0x19,
    PERSONALITY = 0x1A,
    CONSTANTS = 0x1B,
    BIOMES = 0x1C,
    BUILDING_PART = 0x1D,
    INSTANCE_COLLECTION = 0x1E,
    DIALOG_ACTION = 0x1F,
    TEMPORARY_INFO = 0x20,
    MOD_FILENAME = 0x21,
    PLATOON = 0x22,
    GAMESTATE_BUILDING = 0x23,
    GAMESTATE_CHARACTER = 0x24,
    GAMESTATE_FACTION = 0x25,
    GAMESTATE_TOWN_INSTANCE_LIST = 0x26,
    STATE = 0x27,
    SAVED_STATE = 0x28,
    INVENTORY_STATE = 0x29,
    INVENTORY_ITEM_STATE = 0x2A,
    REPEATABLE_BUILDING_PART_SLOT = 0x2B,
    MATERIAL_SPEC = 0x2C,
    MATERIAL_SPECS_COLLECTION = 0x2D,
    CONTAINER = 0x2E,
    MATERIAL_SPECS_CLOTHING = 0x2F,
    GAMESTATE_BUILDING_INTERIOR = 0x30,
    VENDOR_LIST = 0x31,
    MATERIAL_SPECS_WEAPON = 0x32,
    WEAPON_MANUFACTURER = 0x33,
    SQUAD_TEMPLATE = 0x34,
    ROAD = 0x35,
    LOCATION_NODE = 0x36,
    COLOR_DATA = 0x37,
    CAMERA = 0x38,
    MEDICAL_STATE = 0x39,
    MEDICAL_PART_STATE = 0x3A,
    FOLIAGE_LAYER = 0x3B,
    FOLIAGE_MESH = 0x3C,
    GRASS = 0x3D,
    BUILDING_FUNCTIONALITY = 0x3E,
    DAY_SCHEDULE = 0x3F,
    NEW_GAME_STARTOFF = 0x40,
    GAMESTATE_CRAFTING = 0x41,
    CHARACTER_APPEARANCE = 0x42,
    GAMESTATE_AI = 0x43,
    WILDLIFE_BIRDS = 0x44,
    MAP_FEATURES = 0x45,
    DIPLOMATIC_ASSAULTS = 0x46,
    SINGLE_DIPLOMATIC_ASSAULT = 0x47,
    AI_PACKAGE = 0x48,
    DIALOGUE_PACKAGE = 0x49,
    GUN_DATA = 0x4A,
    HUMAN_CHARACTER = 0x4B,
    ANIMAL_CHARACTER = 0x4C,
    UNIQUE_SQUAD_TEMPLATE = 0x4D,
    FACTION_TEMPLATE = 0x4E,
    AI_SCHEDULE = 0x4F,
    WEATHER = 0x50,
    SEASON = 0x51,
    EFFECT = 0x52,
    ITEM_PLACEMENT_GROUP = 0x53,
    WORD_SWAPS = 0x54,
    NEST = 0x55,
    NEST_ITEM = 0x56,
    CHARACTER_PHYSICS_ATTACHMENT = 0x57,
    LIGHT = 0x58,
    HEAD = 0x59,
    BLUEPRINT = 0x5A,
    SHOP_TRADER_CLASS = 0x5B,
    FOLIAGE_BUILDING = 0x5C,
    FACTION_CAMPAIGN = 0x5D,
    GAMESTATE_TOWN = 0x5E,
    BIOME_GROUP = 0x5F,
    EFFECT_FOG_VOLUME = 0x60,
    FARM_DATA = 0x61,
    FARM_PART = 0x62,
    ENVIRONMENT_RESOURCES = 0x63,
    RACE_GROUP = 0x64,
    ARTIFACTS = 0x65,
    MAP_ITEM = 0x66,
    BUILDINGS_SWAP = 0x67,
    ITEMS_CULTURE = 0x68,
    ANIMATION_EVENT = 0x69,
    TUTORIAL = 0x6A,
    CROSSBOW = 0x6B,
    TERRAIN_DECALS = 0x6C,
    AMBIENT_SOUND = 0x6D,
    WORLD_EVENT_STATE = 0x6E,
    LIMB_REPLACEMENT = 0x6F,
    ANIMATION_FILE = 0x70,
    ____XXX___ = 0x71,
    OBJECT_TYPE_MAX = 0x72
};

enum CutDirection
{
    CUT_DEFAULT = 0x0,
    CUT_DOWNWARD = 0x1,
    CUT_LEFT = 0x2,
    CUT_RIGHT = 0x3,
    CUT_THRUST = 0x4,
    CUT_UPWARDS = 0x5,
    CUT_PIERCED = 0x6,
    CUT_REAR_DOWNWARD = 0x7,
    CUT_REAR_LEFT = 0x8,
    CUT_REAR_RIGHT = 0x9
};

enum CutOrigination
{
    FRONT = 0x0,
    REAR = 0x1,
    LEFTSIDE = 0x2,
    RIGHTSIDE = 0x3
};

enum HitMaterialType
{
    HIT_MISSED = 0x0,
    HIT_METAL = 0x1,
    HIT_FLESH = 0x2,
    HIT_SAND = 0x3,
    HIT_WOOD = 0x4,
    HIT_SWORD = 0x5,
    HIT_CHAIN = 0x6
};

enum WeatherAffecting
{
    WA_NONE = 0x0,
    WA_DUSTSTORM = 0x1,
    WA_ACID = 0x2,
    WA_BURNING = 0x3,
    WA_GAS = 0x4,
    WA_RAIN = 0x5
};

enum AttachSlot
{
    ATTACH_WEAPON = 0x0,
    ATTACH_BACK = 0x1,
    ATTACH_HAIR = 0x2,
    ATTACH_HAT = 0x3,
    ATTACH_EYES = 0x4,
    ATTACH_BODY = 0x5,
    ATTACH_LEGS = 0x6,
    ATTACH_NONE = 0x7,
    ATTACH_SHIRT = 0x8,
    ATTACH_BOOTS = 0x9,
    ATTACH_GLOVES = 0xA,
    ATTACH_NECK = 0xB,
    ATTACH_BACKPACK = 0xC,
    ATTACH_BEARD = 0xD,
    ATTACH_BELT = 0xE,
    ATTACH_LEFT_ARM = 0x32,
    ATTACH_RIGHT_ARM = 0x33,
    ATTACH_LEFT_LEG = 0x34,
    ATTACH_RIGHT_LEG = 0x35
};

enum ItemFunction
{
    ITEM_NO_FUNCTION = 0x0,
    ITEM_FIRSTAID = 0x1,
    ITEM_MEDRIGGING = 0x2,
    ITEM_FOOD = 0x3,
    ITEM_CONTAINER = 0x4,
    ITEM_WEAPON = 0x5,
    ITEM_CLOTHING = 0x6,
    ITEM____ = 0x7,
    ITEM_NARCOTIC = 0x8,
    ITEM_TOOL = 0x9,
    ITEM_ANYTHING = 0xA,
    ITEM_BLUEPRINT = 0xB,
    ITEM_ROBOTREPAIR = 0xC,
    ITEM_BOOK = 0xD,
    ITEM_MONEY = 0xE,
    ITEM_FOOD_RESTRICTED = 0xF,
    ITEM_AMMO = 0x10,
    ITEM_SEVERED_LIMB = 0x11
};

enum ArmourType
{
    CLOTH = 0x0,
    LEATHER = 0x1,
    CHAIN = 0x2,
    METAL_PLATE = 0x3
};

enum CharacterTypeEnum
{
    OT_NONE = 0x0,
    OT_LAW_ENFORCEMENT = 0x1,
    OT_MILITARY = 0x2,
    OT_TRADER = 0x3,
    OT_CIVILIAN = 0x4,
    OT_DIPLOMAT = 0x5,
    OT_SLAVE = 0x6,
    OT_SLAVER = 0x7,
    OT_BANDIT = 0x8,
    OT_ADVENTURER = 0x9,
    OT_END = 0xA
};

enum TaskType
{
    NULL_TASK = 0x0,
    MOVE_ON_FREE_WILL = 0x1,
    BUILD = 0x2,
    PICKUP = 0x3,
    MELEE_ATTACK = 0x4,
    FOCUSED_MELEE_ATTACK = 0x5,
    EQUIP_WEAPON = 0x6,
    UNEQUIP_WEAPON = 0x7,
    FIND_WEAPON = 0x8,
    CHOOSE_ENEMY_AND_ATTACK = 0x9,
    CHOOSE_ATTACKER_OF_ALLY = 0xA,
    ATTACK_CHARACTERS_ATTACKER = 0xB,
    PLAYER_TALK_TO = 0xC,
    ATTACK_ATTACKERS_OF = 0xD,
    IDLE = 0xE,
    PROTECT_ALLIES = 0xF,
    ATTACK_ENEMIES = 0x10,
    PROTECTION = 0x11,
    RAID_TOWN = 0x12,
    GO_HOMEBUILDING = 0x13,
    STAND_AT_SHOPKEEPER_NODE = 0x14,
    ATTACK_ENEMIES_AND_NEUTRALS = 0x15,
    PATROL = 0x16,
    ATTACK_TOWN = 0x17,
    WANDERER = 0x18,
    FIRST_AID_ORDER = 0x19,
    LOOT_TARGET = 0x1A,
    CROUCH = 0x1B,
    STAND_UP = 0x1C,
    MOVE_CUS_ORDERED = 0x1D,
    HOLD_POSITION = 0x1E,
    STAY_CLOSE_TO_TARGET = 0x1F,
    SELF_PRESERVATION = 0x20,
    QUELL_AGGRESSION = 0x21,
    ATTACK_TROUBLE_MAKERS = 0x22,
    RUN_AWAY = 0x23,
    PATROL_TOWN = 0x24,
    WANDER_TOWN = 0x25,
    STAND_AT_GUARD_NODE_HOMEBUILDING_IN_OUT = 0x26,
    WANDERING_TRADER = 0x27,
    GET_NEAR_TO = 0x28,
    ATTACK_ENEMIES_OF_MY_SLAVEMASTER = 0x29,
    NOT_BE_UNARMED = 0x2A,
    STAY_IN_HOME = 0x2B,
    FOLLOW_PLAYER_ORDER = 0x2C,
    BODYGUARD = 0x2D,
    CHASE = 0x2E,
    STAND_AT_GENERAL_NODE = 0x2F,
    STAND_AT_DEFENSIVE_NODE = 0x30,
    STAND_AT_BUILDING_GUARD_NODE = 0x31,
    STAND_AT_BUILDING_DEFENSIVE_NODE = 0x32,
    STAND_AT_NODE = 0x33,
    GET_UP_STAY_DOWN_THOUGH = 0x34,
    TRAVEL_TO_TARGET_TOWN = 0x35,
    REST = 0x36,
    RECRUIT_AT_JOBCENTER = 0x37,
    SWITCH_FOLLOW_ME_MODE_ON = 0x38,
    JOB_REPAIR_ROBOT = 0x39,
    JOB_MEDIC = 0x3A,
    GET_READY_FOR_ACTION = 0x3B,
    FIRST_AID_ROBOT = 0x3C,
    UNPROVOKED_FOCUSED_MELEE_ATTACK = 0x3D,
    STAND_STILL = 0x3E,
    SQUAD_WAIT_FOR_ME = 0x3F,
    MAKE_TARGET_STAND_STILL = 0x40,
    GET_UP_STAND_UP = 0x41,
    FORCE_GET_UP = 0x42,
    MOVE_ON_FREE_WILL_FAST = 0x43,
    LIFT_PERSON = 0x44,
    PUT_DOWN_OBJECT = 0x45,
    PUT_DOWN_CHARACTER_IN_BED = 0x46,
    ADD_MATERIALS_TO_BUILDING = 0x47,
    OPEN_DOOR = 0x48,
    CLOSE_DOOR = 0x49,
    OPEN_DOOR_HERE = 0x4A,
    CLOSE_DOOR_HERE = 0x4B,
    PICK_LOCK = 0x4C,
    LOCK_DOOR = 0x4D,
    UNLOCK_DOOR = 0x4E,
    LOCK_DOOR_HERE = 0x4F,
    UNLOCK_DOOR_HERE = 0x50,
    BASH_DOOR = 0x51,
    MOVE_TO_BUILDING_DOOR = 0x52,
    MOVE_TO_CURRENT_LOCATION_BUILDING_DOOR = 0x53,
    OPEN_DOOR_FOR_CURRENT_LOCATION = 0x54,
    OPEN_DOOR_FOR_DESTINATION = 0x55,
    OPEN_UP_SHOP_DOORS = 0x56,
    OPERATE_MACHINERY = 0x57,
    DELIVER_RESOURCES = 0x58,
    JOB_KEEP_EVERYTHING_RUNNING = 0x59,
    UNJAM_ALL_MACHINES = 0x5A,
    UNJAM_MACHINE = 0x5B,
    COLLECT_OUTPUT_RESOURCE = 0x5C,
    FILL_MACHINE = 0x5D,
    WANT_TO_FILL_MACHINE = 0x5E,
    REPAIR = 0x5F,
    DISMANTLE = 0x60,
    USE_TRAINING_DUMMY = 0x61,
    USE_BED = 0x62,
    PUT_SOMEONE_IN_BED = 0x63,
    GET_PUT_IN_BED = 0x64,
    DEFEAT_SQUAD = 0x65,
    SEEK_AND_TALK_AND_SEND_SIGNAL = 0x66,
    MAKE_ANNOUNCEMENT = 0x67,
    ALWAYS_IMPOSSIBLE_TASK = 0x68,
    FIND_AND_RESCUE = 0x69,
    FIND_BED_AND_PUT_IN = 0x6A,
    USE_CAGE = 0x6B,
    PUT_IN_CAGE = 0x6C,
    KNOCKOUT_PRISONER = 0x6D,
    RELEASE_PRISONER = 0x6E,
    BREAKOUT_PRISONER = 0x6F,
    FIND_CAGE_AND_PUT_IN = 0x70,
    EMPTY_MACHINE_OUTPUTS = 0x71,
    GET_RID_OF_RESOURCES_IN_MY_INVENTORY = 0x72,
    FIND_SOME_BUILDING_MATERIALS = 0x73,
    GET_OUT_OF_BED = 0x74,
    FIND_A_SHOP = 0x75,
    SHOPPING = 0x76,
    BUY_SHIT = 0x77,
    MOVE_INSIDE_BUILDING = 0x78,
    MOVE_TO_FORTIFICATION_GATE = 0x79,
    OPEN_FORTIFICATION_GATE = 0x7A,
    BASH_GATE = 0x7B,
    OPERATE_STORAGE = 0x7C,
    JOB_BUILDER = 0x7D,
    TALKTO_NEAREST_PLAYER_CHARACTER = 0x7E,
    RUN_AWAY_HOMETOWN = 0x7F,
    RETREAT_HOMETOWN = 0x80,
    MAKE_ANNOUNCEMENT_FAST = 0x81,
    TRAVEL_TO_TARGET_TOWN_FAST = 0x82,
    LOOT_FOOD_AND_STUFF = 0x83,
    FIND_AND_KIDNAP = 0x84,
    GET_OUT_OF_CAGE_LEGIT = 0x85,
    KILL_CAGE_OCCUPANT = 0x86,
    KILL_A_RANDOM_CAGE_OCCUPANT = 0x87,
    FEED_CORPSE_INTO_MACHINE = 0x88,
    DEAD_GUYS_GO_IN_THE_POT = 0x89,
    FIND_A_DEAD_GUY = 0x8A,
    EAT_A_RANDOM_CAGE_OCCUPANT = 0x8B,
    UNLOCK_DOOR_PLAYER_ORDER = 0x8C,
    FOLLOW_SQUADLEADER = 0x8D,
    FIND_AND_RESCUE_LEADER = 0x8E,
    PROTECT_OWN_SQUAD = 0x8F,
    TERRITORIAL_AGGRESSION_BUT_DONT_LEAVE_HOME = 0x90,
    GET_RE_EQUIPPED = 0x91,
    USE_TURRET = 0x92,
    STUMBLE_TASK_FORCED = 0x93,
    FIND_AND_RESCUE_IF_THERES_BEDS = 0x94,
    MAN_A_TURRET = 0x95,
    PROSPECTING = 0x96,
    EMPTYING_MACHINE = 0x97,
    OPERATE_AUTOMATIC_MACHINERY = 0x98,
    GO_HOME_AND_GO_TO_BED = 0x99,
    GO_TO_THE_BAR_AND_DRINK = 0x9A,
    LOCK_ALL_MY_DOORS = 0x9B,
    ENTER_BUILDING = 0x9C,
    STAND_AT_GUARD_NODE_HOMETOWN_OUTSIDE = 0x9D,
    SHOO_STRANGERS_OUT_OF_MY_BUILDING = 0x9E,
    SEND_DIALOGUE_SIGNAL = 0x9F,
    SEND_DIALOGUE_SIGNAL_REPEAT = 0xA0,
    SEND_DIALOGUE_SIGNAL_WITHOUT_MOVING = 0xA1,
    LOCK_DOOR_FROM_INSIDE = 0xA2,
    MOVE_TO_BUILDING_DOOR_INSIDEPOS = 0xA3,
    FOLLOW_WHILE_TALKING = 0xA4,
    TOWN_STALKER = 0xA5,
    CHAIN_TARGET = 0xA6,
    CAPTURE_NEW_SLAVES = 0xA7,
    CARRY_WOUNDED_SLAVES = 0xA8,
    PUT_DOWN_CARRIED_DUDE_IF_THEY_CAN_WALK = 0xA9,
    LIFT_OBJECT_BUT_HEAL_FIRST = 0xAA,
    FOLLOW_SLAVEMASTER = 0xAB,
    SLAVE_GET_IN_MY_MASTERS_CAGE = 0xAC,
    GATHER_SLAVES_FROM_CAGES = 0xAD,
    GET_SLAVE = 0xAE,
    SLEEP_ON_FLOOR = 0xAF,
    HUNTING_BLOODSMELL = 0xB0,
    LOOT_THE_DEAD = 0xB1,
    LOOT_TO_REPLACE_MISSING_WEAPON = 0xB2,
    HUNT_MY_THIEF = 0xB3,
    MAN_THE_GATE = 0xB4,
    STRIP_TARGETS_WEAPONS = 0xB5,
    PROCESS_AND_STRIP_NEW_SLAVE = 0xB6,
    SLAVE_WATCHING = 0xB7,
    PUT_LOOT_IN_STORAGE = 0xB8,
    CUT_SHACKLES = 0xB9,
    BRUTE_FORCE_SHACKLES = 0xBA,
    _SLAVE_OBEDIENCE = 0xBB,
    WORK_THE_SLAVES = 0xBC,
    AUTO_LABOURING_MINES = 0xBD,
    AUTO_LABOURING_MINES_PRETEND = 0xBE,
    GO_TO_NEAREST_HQ = 0xBF,
    GO_TO_SOMEWHERE_FOR_DELIVERING_SLAVES = 0xC0,
    CAPTURE_ESCAPING_SLAVES = 0xC1,
    GIVE_ALL_MY_SLAVES_TO = 0xC2,
    LOCK_ALL_THE_CAGES = 0xC3,
    BEAT_CAGE_OCCUPANT = 0xC4,
    LOCK_ALL_MY_DOORS_FROM_OUTSIDE = 0xC5,
    LOCK_DOOR_FROM_OUTSIDE = 0xC6,
    MOVE_TO_BUILDING_DOOR_OUTSIDEPOS = 0xC7,
    LEAVE_BUILDING = 0xC8,
    PICK_LOCK_ON_SHACKLES = 0xC9,
    TOTAL_ESCAPE = 0xCA,
    ARREST_TARGET = 0xCB,
    HUNT_BOUNTIES = 0xCC,
    ARREST_TARGETS_CARRIED_PERSON = 0xCD,
    FIND_CAGE_AND_PUT_IN_IF_BOUNTY = 0xCE,
    GET_OUT_OF_CAGE_ESCAPE = 0xCF,
    GET_OUT_OF_BED_IF_ITS_EMERGENCY = 0xD0,
    INVESTIGATE_ALARMS = 0xD1,
    INVESTIGATE_ALARMS_ALLIES_ONLY = 0xD2,
    POLICE_FREE_PRISONERS_WHEN_DONE = 0xD3,
    LOOT_STOLEN_GOODS = 0xD4,
    LIFT_PERSON_SNATCHING_ALLOWED = 0xD5,
    RELAX_IN_TOWN_PACKAGE = 0xD6,
    TRAVEL_TO_TARGET_PACKAGE = 0xD7,
    RUN_AROUND_TOWN_LOOKING_FOR_PEOPLE = 0xD8,
    GATHER_SLAVES_FROM_CAGES_IF_ITS_AN_EXPORT_TOWN = 0xD9,
    GIVE_ALL_MY_SLAVES_TO_IF_ITS_AN_IMPORT_TOWN = 0xDA,
    TAKE_OFF_MY_SHACKLES = 0xDB,
    EAT_TARGET_ALIVE = 0xDC,
    PRETEND_TO_OPERATE_MACHINERY = 0xDD,
    MAN_A_TURRET_ON_BUILDING = 0xDE,
    PICKUP_INTRUDERS_BUILDING = 0xDF,
    TAKE_INTRUDER_OUTSIDE = 0xE0,
    LIFT_PERSON_PLAYER_ORDER = 0xE1,
    BASH_DOOR_PLAYER_ORDER = 0xE2,
    MELEE_ATTACK_ANIMAL = 0xE3,
    STEALTH_KNOCKOUT = 0xE4,
    STEALTH_KILL = 0xE5,
    EAT_A_RANDOM_DEAD_BODY = 0xE6,
    EAT_CROPS = 0xE7,
    FIND_CROPS_TO_EAT = 0xE8,
    EAT_A_RANDOM_KO_BODY = 0xE9,
    MAN_A_TURRET_PLAYER_JOB = 0xEA,
    SHOOT_AT_TARGET = 0xEB,
    WORSHIP_TARGET = 0xEC,
    FOGMAN_WORSHIP_VICTIM = 0xED,
    LOOT_ANIMALS_JOB = 0xEE,
    GO_HOME_AND_GO_TO_BED_SECURE = 0xEF,
    LIFT_PERSON_SNATCHING_ALLOWED_IN_TOWN_ONLY = 0xF0,
    LOOT_RESOURCE_ITEMS_WE_HAVE_STORAGE_FOR = 0xF1,
    DITCH_ALL_RESOURCES = 0xF2,
    AQUIRE_FOOD_AT_HOMEBASE = 0xF3,
    GRAB_ONE_FOOD = 0xF4,
    GATHER_PRISONERS_FROM_CAGES_IF_FEMALE_OR_BEAST = 0xF5,
    KIDNAP_ORDER = 0xF6,
    COLLECT_OUTPUT_RESOURCE_BUILD_MATS = 0xF7,
    DEFEAT_SQUAD_LIMIT_CHASE_RANGE = 0xF8,
    SPLINT_ORDER = 0xF9,
    SPLINT_JOB = 0xFA,
    ESCAPE_KIDNAP = 0xFB,
    ESCAPE_KIDNAP_STR = 0xFC,
    FOLLOW_URGENT_ESCAPE = 0xFD,
    FINAL_KIDNAPPER_CAGE_JOB = 0xFE,
    SIT_ON_THRONE = 0xFF,
    GET_OUT_OF_CAGE_OPPORTUNISTIC = 0x100,
    GET_OUT_OF_BED_ONCE_HEALED = 0x101,
    USE_BED_ORDER = 0x102,
    EAT_FOOD_ON_GROUND = 0x103,
    NEW_SLAVE_PROCESSING = 0x104,
    SLEEP_ON_FLOOR_FAKE_AMBUSH = 0x105,
    RANGED_ATTACK = 0x106,
    RANGED_ATTACK_FOCUSED = 0x107,
    EQUIP_CROSSBOW = 0x108,
    UNEQUIP_CROSSBOW = 0x109,
    RANGED_ATTACK_FOCUSED_UNPROVOKED = 0x10A,
    MOVE_IN_BOW_RANGE = 0x10B,
    STAND_AT_GUARD_NODE_HOMEBUILDING_INDOORS_ONLY = 0x10C,
    HEAL_MY_LEGS = 0x10D,
    ASSAULT_FORTIFICATIONS_PREFER_GATES = 0x10E,
    ASSAULT_FORTIFICATIONS_PREFER_WALLS = 0x10F,
    SMASH_BUILDING = 0x110,
    PICKUP_INTRUDERS_TOWN = 0x111,
    TAKE_INTRUDER_OUTSIDE_TOWN = 0x112,
    SIT_AROUND = 0x113,
    LIBERATE_ALL_THE_PRISONERS = 0x114,
    ANIMAL_FETCH_A_LIMB = 0x115,
    PLAY_BECAUSE_I_HAVE_A_LIMB_IN_MOUTH = 0x116,
    CHASE_ALLY_DOGS_WITH_MOUTH_LIMBS = 0x117,
    RUN_AWAY_FORCED = 0x118,
    FIND_CAGE_AND_PUT_DEADGUY_IN = 0x119,
    EAT_A_RANDOM_CAGE_OCCUPANT_MEASURED_RATE = 0x11A,
    SHOO_STRANGERS_OUT_OF_MY_BUILDING_IF_PRIVATE = 0x11B,
    LOOT_CONTAINER = 0x11C,
    CUT_LOCK = 0x11D,
    BRUTE_FORCE_LOCK = 0x11E,
    BASH_DOOR_HERE = 0x11F,
    PROTECT_ALLIES_STAY_IN_TOWN = 0x120,
    STAY_CLOSE_TO_TARGET_ANIMAL = 0x121,
    BASH_GATE_PLAYER_ORDER = 0x122
};

enum WeaponCategory
{
    SKILL_KATANAS = 0x0,
    SKILL_SABRES = 0x1,
    SKILL_BLUNT = 0x2,
    SKILL_HEAVY = 0x3,
    SKILL_HACKERS = 0x4,
    SKILL_UNARMED = 0x5,
    SKILL_BOW = 0x6,
    SKILL_TURRET = 0x7,
    ATTACK_POLEARMS = 0x8,
    ATTACK_ELEPHANT = 0x9,
    ATTACK_DOG = 0xA,
    ATTACK_BULL = 0xB,
    ATTACK_ROBOTSPIDER = 0xC,
    ATTACK_SPIDER = 0xD,
    ATTACK_CAGEBEAST = 0xE,
    ATTACK_DUCK = 0xF,
    ATTACK_GORILLA = 0x10,
    ATTACK_GAR = 0x11,
    ATTACK_FROG = 0x12,
    ATTACK_GOAT = 0x13,
    ATTACK_GIRAFFE = 0x14,
    ATTACK_NULL = 0x15,
    NUM_SKILL_TYPES = 0x16
};

enum LeftRight
{
    SIDE_NEITHER = 0x0,
    SIDE_LEFT = 0x1,
    SIDE_RIGHT = 0x2,
    SIDE_BOTH = 0x3
};


class MessageForB
{
public:
    enum MessageType
    {
        M_UNSELECT_ALL = 0x0,
        M_GIVE_TASK = 0x1
    };

    enum StandingOrder
    {
        M_SET_ORDER_RUN = 0x0,
        M_SET_ORDER_JOG = 0x1,
        M_SET_ORDER_WALK = 0x2,
        M_SET_ORDER_STEALTH_ON = 0x3,
        M_SET_ORDER_STEALTH_OFF = 0x4,
        M_SET_ORDER_AGG = 0x5,
        M_SET_ORDER_DEF = 0x6,
        M_SET_ORDER_EVADE = 0x7,
        M_SET_ORDER_FAR = 0x8,
        M_SET_ORDER_NEAR = 0x9,
        M__TOGGLEORDERS__AFTER__THIS_ = 0xA,
        M_SET_ORDER_DEFENSIVE_COMBAT = 0xB,
        M_SET_ORDER_HOLD = 0xC,
        M_SET_ORDER_PASSIVE = 0xD,
        M_SET_ORDER_TAUNT = 0xE,
        M_SET_ORDER_CHASE = 0xF,
        M_SET_ORDER_GROUP_SPEED = 0x10,
        M_SET_ORDER_RANGED = 0x11
    };

    // no_addr public void MessageForB(enum MessageForB::MessageType, int);
    // no_addr public void MessageForB(enum MessageForB::StandingOrder);
    MessageForB::MessageType messageType; // 0x0 Member
    int messageInt; // 0x4 Member
};


enum StatsEnumerated
{
    STAT_NONE = 0x0,
    STAT_STRENGTH = 0x1,
    STAT_MELEE_ATTACK = 0x2,
    STAT_LABOURING = 0x3,
    STAT_SCIENCE = 0x4,
    STAT_ENGINEERING = 0x5,
    STAT_ROBOTICS = 0x6,
    STAT_SMITHING_WEAPON = 0x7,
    STAT_SMITHING_ARMOUR = 0x8,
    STAT_MEDIC = 0x9,
    STAT_THIEVING = 0xA,
    STAT_TURRETS = 0xB,
    STAT_FARMING = 0xC,
    STAT_COOKING = 0xD,
    STAT_HIVEMEDIC = 0xE,
    STAT_VET = 0xF,
    STAT_STEALTH = 0x10,
    STAT_ATHLETICS = 0x11,
    STAT_DEXTERITY = 0x12,
    STAT_MELEE_DEFENCE = 0x13,
    STAT_WEAPONS = 0x14,
    STAT_TOUGHNESS = 0x15,
    STAT_ASSASSINATION = 0x16,
    STAT_SWIMMING = 0x17,
    STAT_PERCEPTION = 0x18,
    STAT_KATANAS = 0x19,
    STAT_SABRES = 0x1A,
    STAT_HACKERS = 0x1B,
    STAT_HEAVYWEAPONS = 0x1C,
    STAT_BLUNT = 0x1D,
    STAT_MARTIALARTS = 0x1E,
    STAT_MASSCOMBAT = 0x1F,
    STAT_DODGE = 0x20,
    STAT_SURVIVAL = 0x21,
    STAT_POLEARMS = 0x22,
    STAT_CROSSBOWS = 0x23,
    STAT_FRIENDLY_FIRE = 0x24,
    STAT_LOCKPICKING = 0x25,
    STAT_SMITHING_BOW = 0x26,
    STAT_END = 0x27,
    _PrimaryWeaponDamage = 0x28,
    _PrimaryWeaponSpeed = 0x29,
    _SecondaryWeaponDamage = 0x2A,
    _SecondaryWeaponSpeed = 0x2B,
    _MaxCarryWeight = 0x2C,
    _StrengthXPRateWalk = 0x2D,
    _StrengthXPRateCombat = 0x2E,
    _AttackSpeedHeavyWeapons = 0x2F,
    _DamageResistance = 0x30,
    _ToughnessXPRate = 0x31,
    _KnockoutTime = 0x32,
    _ToughnessKnockoutPoint = 0x33,
    _WoundDeteriorationSpeed = 0x34,
    _MaxRunSpeed = 0x35,
    _CurrentRunSpeed = 0x36,
    _AthleticsXPBonus = 0x37,
    _TurretAccuracy = 0x38,
    _TurretRateOfFire = 0x39,
    _TurretFriendlyFireAvoidance = 0x3A,
    _BuildingRate = 0x3B,
    _RepairingRate = 0x3C,
    _Mining = 0x3D,
    _Farming = 0x3E,
    _UsingMachinery = 0x3F,
    _encumbrance = 0x40,
    _combatSpeed = 0x41
};