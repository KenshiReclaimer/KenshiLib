#pragma once
#include <stdafx.h>

#include <ogre/OgreVector3.h>

#include <kenshi/Root.h>
#include <kenshi/MedicalSystem.h>

namespace Kenshi
{

    struct GameData;
    struct Faction;
    struct Inventory;
    struct Sword;
    struct Effect;
    enum WeatherAffecting;

    class CharStats
    {
        virtual ~CharStats();

    public:
        MedicalSystem* medicalSystem; // 0x08
        Character* character; // 0x10
        char unk_0018[0x68]; // 0x18
        float strength; // 0x80
        float unk_0084; // 0x84
        float dexterity; // 0x88
        float perception; // 0x8C
        float toughness; // 0x90
        float athletics; // 0x94
        float fieldMedic; // 0x98
        float unk_009C; // 0x9C
        float unk_00A0; // 0xA0
        float stealth; // 0xA4
        float swimming; // 0xA8
        float thievery; // 0xAC
        float lockpicking; // 0xB0
        float unk_00B4; // 0xB4
        float assassination; // 0xB8
        char unk_00BC[0x10]; // 0xBC
        float engineer; // 0xCC
        float weaponSmith; // 0xD0
        float armourSmith; // 0xD4
        float crossbowSmith; // 0xD8
        float robotics; // 0xDC
        float science; // 0xE0
        float labouring; // 0xE4
        float farming; // 0xE8
        float cooking; // 0xEC
        float dodge; // 0xF0
        float precisionShooting; // 0xF4
        float katanas; // 0xF8
        float sabres; // 0xFC
        float hackers; // 0x100
        float heavyWeapons; // 0x104
        float blunt; // 0x108
        float martialArts; // 0x10C
        float crossbows; // 0x110
        float turrets; // 0x114
        float polearms; // 0x118
        float unk_011C; // 0x11C
        float meleeAttack; // 0x120
        float meleeDefense; // 0x124
    };

    // CharacterHuman extends Character (length 0x708)
    // CharacterAnimal extends Character (length 0x718)
    // Character (at least 0x6D0 long - probably 0x6D8)

    class Character : public RootObject
    {
        virtual ~Character(); // func 0
        // [vtable + 000001F0] (function 62) seems to be take damage
        virtual void func1();
        virtual void func2();
        virtual void func3();
        virtual void func4();
        virtual void func5();
        virtual void func6();
        virtual void func7();
        virtual void func8();
        virtual void func9();
        virtual void func10();
        virtual void func11();
        virtual void func12();
        virtual void func13();
        virtual void func14();
        virtual void func15();
        virtual void func16();
        virtual void func17();
        virtual void func18();
        virtual void func19();
        virtual void func20();
        virtual void func21();
        virtual void func22();
        virtual void func23();
        virtual void func24();
        virtual void func25();
        virtual void func26();
        virtual void func27();
        virtual void func28();
        virtual void func29();
        virtual void func30();
        virtual void func31();
        virtual void func32();
        virtual void func33();
        virtual void func34();
        virtual void func35();
        virtual void func36();
        virtual void func37();
        virtual void func38();
        virtual void func39();
        virtual void func40();
        virtual void func41();
        virtual void func42();
        virtual void func43();
        virtual void func44();
        virtual void func45();
        virtual void func46();
        virtual void func47();
        virtual void func48();
        virtual void func49();
        virtual void func50();
        virtual void func51();
        virtual void func52();
        virtual void func53();
        virtual void func54();
        virtual void func55();
        virtual void func56();
        virtual void func57();
        virtual void func58();
        virtual void func59();
        virtual void func60();
        virtual void func61();
        virtual void takeDamage(int unk1);
        virtual void func63();
        virtual void func64();
        virtual void func65();
        virtual void func66();
        virtual void func67();
        virtual void func68();
        virtual void func69();

    public:
    	uint64_t id; //0x0008
        Faction *faction; //0x0010
        std::string name; //0x0018
        GameData *dataNode; //0x0040
        Ogre::Vector3 position; //0x0048
        char pad_0054[92]; //0x0054
        Ogre::Vector3 rotation; //0x00B0
        char pad_00BC[0x8]; //0x00BC
        Ogre::Vector3 N00000E8C; //0x00C4
        char pad_00D0[0x218]; //0x00D0
        Inventory* inventory; // 0x02E8
        char pad_02F0[0x58]; // 0x02F0
        bool isCarryingChar; // 0x0348 - adds 30 to weight if set to true
        char pad_0349[0x107]; // 0x0349
        CharStats* charStats; // 0x450
        MedicalSystem medicalSystem; //0x0458 MedicalSystem
        char pad_01B0[0x8]; // 0x0608
        std::string gender; //0x0610
        char pad_01E0[0x38]; //0x0638
        Ogre::Vector3 position2; //0x0670
        Ogre::Vector3 rotation2; //0x067C
        char pad_0688[0x18]; // 0x688
        // haven't reversed this
        lektor<std::pair<WeatherAffecting, float>> weatherAffecting; //0x06A0
        // haven't reversed this
        lektor<Effect*> healthEffects; //0x6C8
        Sword* sword; // 0x06D0
        // probably ends at 0x6D8
    };


    class CharacterHuman : public Character
    {
        virtual ~CharacterHuman();

    public:

    };

    class CharacterAnimal : public Character
    {
        virtual ~CharacterAnimal();

    public:

    };
}
