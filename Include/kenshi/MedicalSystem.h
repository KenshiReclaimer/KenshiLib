#pragma once

#include <kenshi/util/lektor.h>

// 1.0.59 GOG MedicalSystem TakeDamage possibly @ kenshi_GOG_x64.exe+5056D0 
// MedicalSystem::TakeDamage(HealthPartStatus* part, struct damage, uint64_t unk)
namespace Kenshi
{
    struct GameData;
    struct Character;
    struct Armour;
    struct CharStats;
    struct AnimationClass;
    struct Character;


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
    /*
        Houses health, bodypart, armor, etc data. Anything that hurts or heals is tracked here.
        In Character class (might be CharacterHuman).
    */
    {

        class StringPair
        {
        public:
            char pad_0000[8]; //0x0000
            std::string title; //0x0008
            std::string description; //0x0030
        }; //Size: 0x0058

        struct HealthPartStatus // total 0x88 bytes
        /*
            A limb, blood, oil, hunger arent here, just head/arms/legs/other appendages.
        */
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
}
