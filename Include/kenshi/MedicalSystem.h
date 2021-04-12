#pragma once

#include <stdafx.h>
namespace Kenshi
{
    struct GameData;
    struct Character;
    struct Effect;

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
            class std::string title; //0x0008
            char pad_0028[8]; //0x0028
            class std::string description; //0x0030
            char pad_0050[8]; //0x0050
        }; //Size: 0x0058

        struct HealthPartStatus // total 0x88 bytes
        /*
            A limb, blood, oil, hunger arent here, just head/arms/legs/other appendages.
        */
        {
            GameData* data;
            uint64_t type; // ? unsure, different for different limbs, but not unique
            MedicalSystem* medical;
            Character* character;
            uint64_t unknown[3]; // theres some boolean flags in the last int in this group
            float unknown1; // currently 80, some hidden stat for limb health?
            float unknown2; // currently 1, some regeneration stat?
            float health; // the current health of the limb.
            float unknown3;
        };

        char pad_0008[64]; //0x0008
        class lektor<void*> N00000F07; //0x0048
        float hunger; //0x0060
        char pad_0064[12]; //0x0064
        float blood; //0x0070
        char pad_0074[116]; //0x0074
        class StringPair environmentStatus; //0x00E8 The state above the healthbars
        char pad_0140[80]; //0x0140
        class lektor<HealthPartStatus> healthParts; //0x0190 HealthPartStatus
        char pad_01A8[16]; //0x01A8
        std::string gender; //0x01B8
        char pad_01D8[64]; //0x01D8
        Vector3 position; //0x0218
        Vector3 rotation; //0x0224
        char pad_0230[48]; //0x0230
        class lektor<Effect*> healthEffects; //0x0260 Effect*
        char pad_0278[96]; //0x0278
        
        virtual void Function0();
        virtual void Function1();
        virtual void Function2();
    };
}
