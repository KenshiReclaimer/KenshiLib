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
        char pad_02F0[0x168]; // 0x02F0
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
