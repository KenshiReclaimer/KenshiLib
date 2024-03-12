#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>
#include <string>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>
#include <kenshi/GameDataManager.h>
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/util/PerfTimer.h>
#include <kenshi/util/TimeOfDay.h>
#include <kenshi/util/hand.h>

class GameDataManager;
class RendererT;
class AttachedEntity;
class TownBuildingsManager;
class NestBatcher;
class PhysicsInterface;
class RootObjectFactory;
class FactionManager;
class NavMesh;
class NodeList;
class MessageRoller;
class ZoneMap;
class RenderTimeBackthread;
class ThreadWannabe;
class RootObject;
class ModInfo;
class PlayerInterface;
class ZoneManager;
class AudioSystemGlobal;

// TODO move?
enum NxShapesType
{
    NX_STATIC_SHAPES = 0x1,
    NX_DYNAMIC_SHAPES = 0x2,
    NX_ALL_SHAPES = 0x3
};

// TODO move?
class SimpleTimeStamper
{
public:
    CPerfTimer timer; // 0x0 Member
    // no_addr void SimpleTimeStamper(const class SimpleTimeStamper & _a1);// public missing arg names
    SimpleTimeStamper();// public RVA = 0x685F10
    void _CONSTRUCTOR();// public RVA = 0x685F10
    double getTime(double _lastStamp);// public RVA = 0x2BD4A0
    double stampTime();// public RVA = 0x1CEFE0
    ~SimpleTimeStamper();// public RVA = 0x685EA0
    void _DESTRUCTOR();// public RVA = 0x685EA0
    // no_addr class SimpleTimeStamper & operator=(const class SimpleTimeStamper & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class GameWorld : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    // Typedef        : HandCharacterMap
    float tempSpawnsDisableTimer; // 0x8 Member
    void justLoadFactionRelations(GameDataManager * datasrc);// private RVA = 0x9EDD30
    bool startUpThreads();// private RVA = 0x86BF20
    // no_addr void GameWorld(const class GameWorld & _a1);// public missing arg names
    GameWorld();// public RVA = 0x873780
    void _CONSTRUCTOR();// public RVA = 0x873780
    ~GameWorld();// public RVA = 0x86C0C0
    void _DESTRUCTOR();// public RVA = 0x86C0C0
    bool start(RendererT * _rend);// public RVA = 0x8693D0
    void resetGame();// public RVA = 0x36C660
    void _clearAndDestroyGameWorldStuff();// public RVA = 0x36B560
    bool initialisation();// public RVA = 0x86C5F0
    bool initialisationGameData();// public RVA = 0x86F3F0
    void dailyUpdates();// public RVA = 0x7856F0
    void initialiseNewGameWorld(GameDataManager * datasrc);// public RVA = 0x9EDA80
    void errorToLogReleaseMode(const std::string & msg);// public RVA = 0x784CC0
    void errorD(const std::string & msg);// public RVA = 0x784CE0
    void logToSave(const std::string & msg);// public RVA = 0x784CF0
    void log(const std::string & line);// public RVA = 0x784D00
    void logDebug(const std::string & msg, const std::string & logname);// public RVA = 0x784D30
    void logDebug(const std::string & line);// public RVA = 0x784D20
    void destroy(Ogre::MovableObject * e);// public RVA = 0x799520
    void destroy(AttachedEntity * e);// public RVA = 0x7994E0
    void destroy(TownBuildingsManager * b);// public RVA = 0x7995F0
    void destroy(NestBatcher * n);// public RVA = 0x794290
    bool destroy(RootObject * obj, bool justUnloaded, const char * debugInfo);// public RVA = 0x798890
    void destroy(GameData * d);// public RVA = 0x7EA990
    bool getIsInKillList(RootObject * obj);// public RVA = 0x793EE0
    void flushKillList();// public RVA = 0x7A7C00
    void dynamicDestroyBuilding(const hand & h);// public RVA = 0x2AC0D0
    bool allThreadQueuesAreClear();// public RVA = 0x7ACEB0
    bool initialized; // 0xC Member
    RendererT * render; // 0x10 Member
    PhysicsInterface * physics; // 0x18 Member
    GameDataManager gamedata; // 0x20 Member
    GameDataManager leveldata; // 0x1A0 Member
    GameDataManager savedata; // 0x320 Member
    RootObjectFactory * theFactory; // 0x4A0 Member
    FactionManager * factionMgr; // 0x4A8 Member
    NavMesh * navmesh; // 0x4B0 Member
    NodeList * nodeList; // 0x4B8 Member
    hand guiDisplayObject; // 0x4C0 Member
    MessageRoller * messageRoller; // 0x4E0 Member
    Ogre::Log * ogreLogger; // 0x4E8 Member
    bool steamEnabled; // 0x4F0 Member
    lektor<ModInfo> baseMods; // 0x4F8 Member
    lektor<std::string > baseModsNames; // 0x510 Member
    lektor<ModInfo *> activeMods; // 0x528 Member
    std::map<std::string,ModInfo,std::less<std::string >,Ogre::STLAllocator<std::pair<std::string const ,ModInfo>,Ogre::GeneralAllocPolicy > > availableModsByName; // 0x540 Member
    lektor<ModInfo *> availabelModsOrderedList; // 0x568 Member
    void initBaseMods();// public RVA = 0x869590
    void initModsList();// public RVA = 0x86E210
    lektor<ModInfo *> getModsListFromConfig();// public RVA = 0x867E10
    const lektor<ModInfo *> & getAllModsList() const;// public RVA = 0x867390
    int getModIndex(const std::string & modName) const;// public RVA = 0x867410
    const std::string & getModLeveldataFolder(const std::string & modName);// public RVA = 0x8674E0
    void getObjectsWithinSphere(lektor<RootObject *> & results, const Ogre::Vector3 & spherePos, float radius, itemType type, int maxNumber, RootObject * skip);// public RVA = 0x784F90
    void getCharactersWithinSphere(lektor<RootObject *> & results, const Ogre::Vector3 & spherePos, float farRadius, float nearRadius, float always, int maxFar, int maxNear, RootObject * skip);// public RVA = 0x7854C0
    void getObjectsWithinBox(lektor<RootObject *> & results, const Ogre::Vector3 & pos, const Ogre::Vector3 & size, const Ogre::Quaternion & rot, itemType type, int maxNumber, RootObject * skip);// public RVA = 0x7850D0
    bool buildingIntersectionTestCapsule(const Ogre::Vector3 & pos, float radius, float length, RootObject * skip);// public RVA = 0x785060
    float getLightLevel(const Ogre::Vector3 & position, int floor, bool inside) const;// public RVA = 0xA09760
    void populateMapArea_nonPermanent(ZoneMap * map, int howMany, bool rePopulationMode);// public RVA = 0x9ED0D0
    bool findValidSpawnPos(Ogre::Vector3 & pos, const Ogre::Vector3 & centerArea);// public RVA = 0x9ED3D0
    void togglePause(bool on);// public RVA = 0x786B30
    float getFrameSpeedMultiplier() const;// public RVA = 0x66BFE0
    void setFrameSpeedMultiplier(float m);// public RVA = 0x786AA0
    void setGameSpeed(float speed, bool click);// public RVA = 0x786C30
    void userPause(bool p);// public RVA = 0x786DA0
    bool isPaused() const;// public RVA = 0xDEDC0
    const Ogre::Vector3 getCameraCenter() const;// public RVA = 0x784D80
    const Ogre::Vector3 getCameraPos() const;// public RVA = 0x784DB0
    bool fixNaNPosition(Ogre::Vector3 & pos) const;// public RVA = 0x784E20
    float getWindSpeed(const Ogre::Vector3 & pos) const;// public RVA = 0x784D40
    bool isLoadingFromASaveGame();// public RVA = 0x784C40
    PlayerInterface * player; // 0x580 Member
    void addToUpdateListMain(Character * character);// public RVA = 0x786A60
    void removeFromUpdateListMain(Character * character);// public RVA = 0x7862D0
    const ogre_unordered_set<Character *>::type & getCharacterUpdateList() const;// public RVA = 0x663BE0
    void addToDeathParade(Character * who);// public RVA = 0x7959E0
    bool removeFromDeathParade(Character * who);// public RVA = 0x795A40
    void removeFromDeathParadeByPlatoon(Platoon * p);// public RVA = 0x795BB0
    Character * getFromDeathParade(const hand & h);// public RVA = 0x7CC1E0
    void hideContextMenu();// public RVA = 0x7A6C90
    // no_addr void lockBackgroundThreadsForSave();// public
    // no_addr void unlockBackgroundThreads();// public
    void showPlayerAMessage_withLog(const std::string & message, bool queued);// public RVA = 0x723850
    void showPlayerAMessage(const std::string & message, bool queued);// public RVA = 0x723830
    void showPlayerAMessageD(const std::string & message, bool queued);// public RVA = 0x7200F0
    void playNotification(const char * sound) const;// public RVA = 0x257850
    // no_addr int getNumCharactersLoaded();// public
    ogre_unordered_set<Character *>::type charactersWithLights; // 0x588 Member
    enum SysMessageEnum
    {
        SYS_NONE,
        SYS_RESIDENT_CHANGE,
        SYS_SHOW_PROSPECTING_WINDOW,
        SYS_CREATE_PHYSICAL,
        SYS_DESTROY_PHYSICAL,
        SYS_SET_CHAINED_MODE,
        SYS_UPDATE_ORDERS_PANEL,
        SYS_UPDATE_PORTRAIT,
        SYS_RESEARCH_PROGRESS,
        SYS_CLOSE_ALL_INVENTORIES,
        SYS_CLOSE_INVENTORY,
        SYS_BUILDING_PROGRESS,
        SYS_DROP_ALL_GEAR,
        SYS_CHARACTER_PARTICLES,
        SYS_RESTORE_SQUAD,
        SYS_DESTROY_PLATOON,
        SYS_BREAK_BUILDING    
    };

    class SysMessage
    {
    public:
        GameWorld::SysMessageEnum msg; // 0x0 Member
        hand target; // 0x8 Member
        hand from; // 0x28 Member
        bool on; // 0x48 Member
        float number; // 0x4C Member
        void * data; // 0x50 Member
        SysMessage(const GameWorld::SysMessage & __that);// public RVA = 0x2AADF0
        void _CONSTRUCTOR(const GameWorld::SysMessage & __that);// public RVA = 0x2AADF0
        SysMessage(GameWorld::SysMessageEnum _msg, const hand & _target, const hand & _from, bool _on, float _number, void * _data);// public RVA = 0x2AA040
        void _CONSTRUCTOR(GameWorld::SysMessageEnum _msg, const hand & _target, const hand & _from, bool _on, float _number, void * _data);// public RVA = 0x2AA040
        // no_addr void SysMessage();// public
        bool operator==(const GameWorld::SysMessage & m) const;// public RVA = 0x338050
        // no_addr class GameWorld::SysMessage & operator=(const class GameWorld::SysMessage & _a1);// public missing arg names
    };
    void sysMessage(const GameWorld::SysMessage & m);// public RVA = 0x2ACA90
    void sysMessageUrgent(const GameWorld::SysMessage & m);// public RVA = 0x65C810
    void sysMessage_noDuplicates(const GameWorld::SysMessage & m);// public RVA = 0x349730
    virtual void mainLoop_GPUSensitiveStuff(float time);// public RVA = 0x7877A0 vtable offset = 0x0
    void _NV_mainLoop_GPUSensitiveStuff(float time);// public RVA = 0x7877A0 vtable offset = 0x0
    void clearPortaitsUpdate();// public RVA = 0x7860A0
    void addPortraitUpdate(const hand & characterHandle);// public RVA = 0x786340
    void removePortaitUpdate(const hand & characterHandle);// public RVA = 0x786390
    std::list<GameWorld::SysMessage,Ogre::STLAllocator<GameWorld::SysMessage,Ogre::GeneralAllocPolicy > > sysMessageList; // 0x5C8 Member
    void processSysMessages();// protected RVA = 0x7B5350
    void getCollisionGroupType(itemType type, NxShapesType & shapeType, unsigned int & group);// protected RVA = 0x784E80
    ogre_unordered_map<hand,float>::type updatePortraitsMap; // 0x5E8 Member
    lektor<hand> dynamicDestroyBuildingsList; // 0x628 Member
    ogre_unordered_set<AttachedEntity *>::type destroyListAE; // 0x640 Member
    ogre_unordered_set<Ogre::MovableObject *>::type destroyListOE; // 0x680 Member
    ogre_unordered_set<TownBuildingsManager *>::type destroyListTBM; // 0x6C0 Member
    float frameSpeedMult; // 0x700 Member
    void destroyDeathParade();// private RVA = 0x7860C0
    ogre_unordered_map<hand,Character *>::type deathParade; // 0x708 Member
    bool deathParadeWasMeddledWith; // 0x748 Member
    void processKeys();// private RVA = 0x786EF0
    void processThreadMessages();// private RVA = 0x784B90
    bool charUpdateListMain_inUse; // 0x749 Member
    ogre_unordered_set<Character *>::type charUpdateListMain; // 0x750 Member
    void charsUpdate();// private RVA = 0x785C20
    void charsUpdateUT();// private RVA = 0x7857D0
    void charsUpdatePaused();// private RVA = 0x786020
    void charsUpdateDeathParade();// private RVA = 0x785830
    void threadSafeRagdollUpdates();// private RVA = 0x7D1120
    RenderTimeBackthread * _AINonRenderThread; // 0x790 Member
    ThreadWannabe * AINonRenderThread();// public RVA = 0x2963B0
    void processAttachmentsKillList();// public RVA = 0x794340
    void processKillList(bool forceImmediate);// protected RVA = 0x79C640
    void processUpdateRemovalList();// protected RVA = 0x7942C0
    std::deque<NestBatcher *,Ogre::STLAllocator<NestBatcher *,Ogre::GeneralAllocPolicy > > nestBatcherKillList; // 0x798 Member
    ogre_unordered_set<RootObject *>::type killListPhase0; // 0x7D0 Member
    ogre_unordered_map<RootObject *,float>::type killListPhase1; // 0x810 Member
    std::deque<RootObject *,Ogre::STLAllocator<RootObject *,Ogre::GeneralAllocPolicy > > killListPhase2; // 0x850 Member
    lektor<Character *> mainUpdateListRemovalQueue; // 0x888 Member
    void loadAllPlatoons();// protected RVA = 0x9ED6C0
    void reCalculateFortificationInsideOutsideStateForAllCharacters();// public RVA = 0x785700
    SimpleTimeStamper timeStamper; // 0x8A0 Member
    double getTimeStamp();// public RVA = 0x25B040
    TimeOfDay getTimeFromStamp(const TimeOfDay & stamp);// public RVA = 0x66C4B0
    float getTimeFromStamp(double stamp);// public RVA = 0x514C10
    float getTimeFromStamp_inGameHours(double stamp);// public RVA = 0x66A070
    TimeOfDay getTimeStamp_inGameHours();// public RVA = 0x66C490
    float getLengthOfHourInRealSeconds();// public RVA = 0x66CC70
    ZoneManager * zoneMgr; // 0x8B0 Member
    bool debugFlag; // 0x8B8 Member
    bool paused; // 0x8B9 Member
    bool gameResetting; // 0x8BA Member
    AudioSystemGlobal * audioThread; // 0x8C0 Member
    // no_addr class GameWorld & operator=(const class GameWorld & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};
