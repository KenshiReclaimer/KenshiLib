#pragma once

#include <kenshi/Character.h>
#include <string>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>

class CharacterAnimal : public Character
{
public:
    // Character offset = 0x0, length = 0x6D8
    virtual CharacterAnimal * isAnimal();// public RVA = 0x5E17D0 vtable offset = 0x0
    CharacterAnimal * _NV_isAnimal();// public RVA = 0x5E17D0 vtable offset = 0x0
    virtual void createAnimationClass();// public RVA = 0x5E84B0 vtable offset = 0x0
    void _NV_createAnimationClass();// public RVA = 0x5E84B0 vtable offset = 0x0
    // no_addr bool preventRagdollMode();// public
    virtual bool drawWeapon(Item * _a1, std::string lastSlot);// public RVA = 0x5E5150 vtable offset = 0x0
    bool _NV_drawWeapon(Item * _a1, std::string lastSlot);// public RVA = 0x5E5150 vtable offset = 0x0
    virtual void sheatheWeapon();// public RVA = 0x5E17E0 vtable offset = 0x0
    void _NV_sheatheWeapon();// public RVA = 0x5E17E0 vtable offset = 0x0
    virtual Weapon * getCurrentWeapon();// public RVA = 0x5E17F0 vtable offset = 0x0
    Weapon * _NV_getCurrentWeapon();// public RVA = 0x5E17F0 vtable offset = 0x0
    virtual Weapon * getThePreferredWeapon();// public RVA = 0x5E1800 vtable offset = 0x0
    Weapon * _NV_getThePreferredWeapon();// public RVA = 0x5E1800 vtable offset = 0x0
    virtual InventoryLayout * createInventoryLayout();// public RVA = 0x5CBEB0 vtable offset = 0x0
    InventoryLayout * _NV_createInventoryLayout();// public RVA = 0x5CBEB0 vtable offset = 0x0
    virtual bool giveBirth(GameDataCopyStandalone * appearance, const Ogre::Vector3 & position, const Ogre::Quaternion & rotation, GameSaveState * state, ActivePlatoon * tempplatoonptr, Faction * _faction);// public RVA = 0x62E880 vtable offset = 0x0
    bool _NV_giveBirth(GameDataCopyStandalone * appearance, const Ogre::Vector3 & position, const Ogre::Quaternion & rotation, GameSaveState * state, ActivePlatoon * tempplatoonptr, Faction * _faction);// public RVA = 0x62E880 vtable offset = 0x0
    virtual bool setupInventorySections(GameSaveState * state);// public RVA = 0x6299B0 vtable offset = 0x0
    bool _NV_setupInventorySections(GameSaveState * state);// public RVA = 0x6299B0 vtable offset = 0x0
    virtual void setupAudio();// public RVA = 0x629870 vtable offset = 0x0
    void _NV_setupAudio();// public RVA = 0x629870 vtable offset = 0x0
    virtual void periodicUpdate();// public RVA = 0x5CD780 vtable offset = 0x0
    void _NV_periodicUpdate();// public RVA = 0x5CD780 vtable offset = 0x0
    virtual void setAge(float zeroToOne);// public RVA = 0x5E1810 vtable offset = 0x0
    void _NV_setAge(float zeroToOne);// public RVA = 0x5E1810 vtable offset = 0x0
    virtual float getAge() const;// public RVA = 0x5E1820 vtable offset = 0x0
    float _NV_getAge() const;// public RVA = 0x5E1820 vtable offset = 0x0
    virtual float getAgeInverse() const;// public RVA = 0x5E1850 vtable offset = 0x0
    float _NV_getAgeInverse() const;// public RVA = 0x5E1850 vtable offset = 0x0
    virtual float getAge0to1() const;// public RVA = 0x5E1890 vtable offset = 0x0
    float _NV_getAge0to1() const;// public RVA = 0x5E1890 vtable offset = 0x0
    virtual unsigned int getDefaultTaskRepertoireEnum() const;// public RVA = 0x5E18A0 vtable offset = 0x0
    unsigned int _NV_getDefaultTaskRepertoireEnum() const;// public RVA = 0x5E18A0 vtable offset = 0x0
    virtual bool canGoIndoors(Building * b) const;// public RVA = 0x5C7A50 vtable offset = 0x0
    bool _NV_canGoIndoors(Building * b) const;// public RVA = 0x5C7A50 vtable offset = 0x0
    virtual float getSmellHuntingThresholdBlood() const;// public RVA = 0x5E18B0 vtable offset = 0x430
    float _NV_getSmellHuntingThresholdBlood() const;// public RVA = 0x5E18B0 vtable offset = 0x430
    virtual float getSmellHuntingThresholdEggs() const;// public RVA = 0x5E18C0 vtable offset = 0x438
    float _NV_getSmellHuntingThresholdEggs() const;// public RVA = 0x5E18C0 vtable offset = 0x438
    bool weaponIsTechnicallyEquipped; // 0x6D8 Member
    virtual float getHPMultiplier() const;// public RVA = 0x5E18D0 vtable offset = 0x0
    float _NV_getHPMultiplier() const;// public RVA = 0x5E18D0 vtable offset = 0x0
    float HPMultiplier; // 0x6DC Member
    TimeOfDay itemInMouthTimeStamp; // 0x6E0 Member
    virtual void foodUpdate();// public RVA = 0x5DBED0 vtable offset = 0x0
    void _NV_foodUpdate();// public RVA = 0x5DBED0 vtable offset = 0x0
    bool pickupItemInMouth(Item * item);// public RVA = 0x5D03D0
    bool dropItemInMouth();// public RVA = 0x5C7AC0
    Item * getItemInMouth();// public RVA = 0x5C7B50
    void eatItemInMouth();// public RVA = 0x5D05A0
    // no_addr void CharacterAnimal(class CharacterAnimal & _a1);// public missing arg names
    CharacterAnimal(GameData * d, Faction * f, hand _handle, float _age);// protected RVA = 0x5C79D0
    void _CONSTRUCTOR(GameData * d, Faction * f, hand _handle, float _age);// protected RVA = 0x5C79D0
    virtual ~CharacterAnimal();// protected RVA = 0x5C7A30 vtable offset = 0x0
    void _DESTRUCTOR();// protected RVA = 0x5C7A30 vtable offset = 0x0
    virtual void init();// protected RVA = 0x622EE0 vtable offset = 0x0
    void _NV_init();// protected RVA = 0x622EE0 vtable offset = 0x0
    virtual void dropItem(RootObject * itembase);// protected RVA = 0x5C9D20 vtable offset = 0x0
    void _NV_dropItem(RootObject * itembase);// protected RVA = 0x5C9D20 vtable offset = 0x0
    float smellThresholdBlood; // 0x6E8 Member
    float smellThresholdEggs; // 0x6EC Member
    float ageSizeMin; // 0x6F0 Member
    float ageSizeMax; // 0x6F4 Member
    float lifespanInDays; // 0x6F8 Member
    float lastUpdatedAge; // 0x6FC Member
    float age; // 0x700 Member
    Weapon * weaponInHands; // 0x708 Member
    float audioTimeStamp; // 0x710 Member
    // no_addr class CharacterAnimal & operator=(const class CharacterAnimal & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};
