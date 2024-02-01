#pragma once

// for global enums 
enum itemType {};// TODO
enum CutDirection {};// TODO
enum HitMaterialType {};// TODO
enum WeatherAffecting {};// TODO
enum AttachSlot {};// TODO
enum ItemFunction {};//TODO
enum ArmourType {};// TODO
enum CharacterTypeEnum {}; // TODO
enum TaskType {}; // TODO


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