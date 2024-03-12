#pragma once

#include <string>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/InstanceID.h>
#include <kenshi/Enums.h>

class GameSaveState
{
public:
    GameSaveState(const GameSaveState& __that);// public RVA = 0xAE220
    void _CONSTRUCTOR(const GameSaveState& __that);// public RVA = 0xAE220
    GameSaveState(GameDataContainer* source, GameData* _baseData, GameData* instanceCollectionSavingTo, const PosRotPair& _pos, PosRotPair* _offset, InstanceID* _instanceID);// public RVA = 0x2C2460
    void _CONSTRUCTOR(GameDataContainer* source, GameData* _baseData, GameData* instanceCollectionSavingTo, const PosRotPair& _pos, PosRotPair* _offset, InstanceID* _instanceID);// public RVA = 0x2C2460
    GameSaveState();// public RVA = 0x94530
    void _CONSTRUCTOR();// public RVA = 0x94530
    void generateNewInstanceID();// public RVA = 0x2C1FD0
    void createFromSerialisedInstanceData(GameDataContainer* _container, GameData::ObjectInstance* _instance, const std::string& id);// public RVA = 0x2AD340
    std::string generateStateID(itemType type);// public RVA = 0x2121A0
    GameData* createState(itemType type);// public RVA = 0x2C2BA0
    void addState(GameData* state);// public RVA = 0x212270
    bool hasState(itemType type) const;// public RVA = 0xAC860
    GameData* getState(itemType type);// public RVA = 0xADB00
    int numStates() const;// public RVA = 0x2BC2B0
    // no_addr void clearStates();// public
    // no_addr enum itemType getObjectType();// public
    Ogre::Vector3 getPos() const;// public RVA = 0x2BA9E0
    Ogre::Quaternion getRot() const;// public RVA = 0x2BAA00
    InstanceID getInstanceID() const;// public RVA = 0x454D80
    const ogre_unordered_map<itemType, GameData*>::type& getAllStates() const;// public RVA = 0x565150
    GameData* baseData; // 0x0 Member
    GameDataContainer* dataSource; // 0x8 Member
    bool firstTime; // 0x10 Member
    operator bool() const;// public RVA = 0x2BAA20
    // no_addr const class GameSaveState & operator=(const class GameSaveState & _a1);// public missing arg names
    GameData::ObjectInstance* instance; // 0x18 Member
    GameData* getTheInstancesData();// public RVA = 0x2BAA40
    Ogre::Vector3 pos; // 0x20 Member
    Ogre::Quaternion rot; // 0x2C Member
    std::string instanceID; // 0x40 Member
    ogre_unordered_map<itemType, GameData*>::type states; // 0x68 Member
    ~GameSaveState();// public RVA = 0x945E0
    void _DESTRUCTOR();// public RVA = 0x945E0
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};