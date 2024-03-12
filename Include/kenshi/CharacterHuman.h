#pragma once

#include <kenshi/Character.h>
#include <string>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>

class CharacterHuman : public Character
{
public:
    // Character offset = 0x0, length = 0x6D8
    // no_addr void CharacterHuman(class CharacterHuman & _a1);// public missing arg names
    CharacterHuman(GameData * d, Faction * f, hand _handle);// protected RVA = 0x5CB290
    void _CONSTRUCTOR(GameData * d, Faction * f, hand _handle);// protected RVA = 0x5CB290
    virtual ~CharacterHuman();// protected RVA = 0x5CB2E0 vtable offset = 0x0
    void _DESTRUCTOR();// protected RVA = 0x5CB2E0 vtable offset = 0x0
    virtual CharacterHuman * isHuman();// public RVA = 0x5E5240 vtable offset = 0x0
    CharacterHuman * _NV_isHuman();// public RVA = 0x5E5240 vtable offset = 0x0
    virtual bool drawWeapon(Item * item, std::string lastSection);// public RVA = 0x5DB800 vtable offset = 0x0
    bool _NV_drawWeapon(Item * item, std::string lastSection);// public RVA = 0x5DB800 vtable offset = 0x0
    virtual void sheatheWeapon();// public RVA = 0x5CC0A0 vtable offset = 0x0
    void _NV_sheatheWeapon();// public RVA = 0x5CC0A0 vtable offset = 0x0
    virtual Weapon * getCurrentWeapon();// public RVA = 0x5C9010 vtable offset = 0x0
    Weapon * _NV_getCurrentWeapon();// public RVA = 0x5C9010 vtable offset = 0x0
    virtual Weapon * getThePreferredWeapon();// public RVA = 0x5C9020 vtable offset = 0x0
    Weapon * _NV_getThePreferredWeapon();// public RVA = 0x5C9020 vtable offset = 0x0
    virtual Crossbow * getRangedWeapon();// public RVA = 0x5C83A0 vtable offset = 0x0
    Crossbow * _NV_getRangedWeapon();// public RVA = 0x5C83A0 vtable offset = 0x0
    virtual GameSaveState serialise(GameDataContainer * container, GameData * refList, PosRotPair * offsetPosToSubtract);// public RVA = 0x628E20 vtable offset = 0x0
    GameSaveState _NV_serialise(GameDataContainer * container, GameData * refList, PosRotPair * offsetPosToSubtract);// public RVA = 0x628E20 vtable offset = 0x0
    virtual void loadFromSerialise(GameSaveState * state);// public RVA = 0x6289D0 vtable offset = 0x0
    void _NV_loadFromSerialise(GameSaveState * state);// public RVA = 0x6289D0 vtable offset = 0x0
    virtual bool giveBirth(GameDataCopyStandalone * _appearance, const Ogre::Vector3 & _pos, const Ogre::Quaternion & _rot, GameSaveState * state, ActivePlatoon * tempplatoonptr, Faction * _faction);// public RVA = 0x62E7F0 vtable offset = 0x0
    bool _NV_giveBirth(GameDataCopyStandalone * _appearance, const Ogre::Vector3 & _pos, const Ogre::Quaternion & _rot, GameSaveState * state, ActivePlatoon * tempplatoonptr, Faction * _faction);// public RVA = 0x62E7F0 vtable offset = 0x0
    virtual bool setupInventorySections(GameSaveState * state);// public RVA = 0x62BD60 vtable offset = 0x0
    bool _NV_setupInventorySections(GameSaveState * state);// public RVA = 0x62BD60 vtable offset = 0x0
    virtual void validateInventorySections();// public RVA = 0x621170 vtable offset = 0x0
    void _NV_validateInventorySections();// public RVA = 0x621170 vtable offset = 0x0
    virtual void setupAudio();// public RVA = 0x6296D0 vtable offset = 0x0
    void _NV_setupAudio();// public RVA = 0x6296D0 vtable offset = 0x0
    void shaveHead(bool on);// public RVA = 0x5B1D20
    virtual bool isHeadShaven() const;// public RVA = 0x5B1D40 vtable offset = 0x0
    bool _NV_isHeadShaven() const;// public RVA = 0x5B1D40 vtable offset = 0x0
    virtual void createAnimationClass();// protected RVA = 0x5C8EF0 vtable offset = 0x0
    void _NV_createAnimationClass();// protected RVA = 0x5C8EF0 vtable offset = 0x0
    virtual void dropItem(RootObject * itembase);// protected RVA = 0x5C9FC0 vtable offset = 0x0
    void _NV_dropItem(RootObject * itembase);// protected RVA = 0x5C9FC0 vtable offset = 0x0
    void dropWeaponInHands();// protected RVA = 0x5CBFE0
    void dropWeaponInHandsFake();// protected RVA = 0x5C8EE0
    virtual void unequipItem(const std::string & section, Item * item);// protected RVA = 0x5DBDE0 vtable offset = 0x0
    void _NV_unequipItem(const std::string & section, Item * item);// protected RVA = 0x5DBDE0 vtable offset = 0x0
    virtual void weatherUpdate(float time);// protected RVA = 0x5CF010 vtable offset = 0x0
    void _NV_weatherUpdate(float time);// protected RVA = 0x5CF010 vtable offset = 0x0
    void leaveSheathEquipped(std::string section, int ypos);// protected RVA = 0x5D1D30
    Weapon * weaponInHands; // 0x6D8 Member
    std::string weaponInHandsSheathLocation; // 0x6E0 Member
    virtual void postRagdollCallback(bool on, RagdollPart::Enum part);// protected RVA = 0x5CBAB0 vtable offset = 0x0
    void _NV_postRagdollCallback(bool on, RagdollPart::Enum part);// protected RVA = 0x5CBAB0 vtable offset = 0x0
    virtual void reCalculateNaturalWeapon();// protected RVA = 0x62A570 vtable offset = 0x0
    void _NV_reCalculateNaturalWeapon();// protected RVA = 0x62A570 vtable offset = 0x0
    // no_addr class CharacterHuman & operator=(const class CharacterHuman & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};
