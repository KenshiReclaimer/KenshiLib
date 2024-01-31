#pragma once

#include "util/lektor.h"
#include "util/hand.h"
#include "util/PerfTimer.h"
#include "RootObject.h"
#include "TimeOfDay.h"
#include "GameDataManager.h"

#include <ogre/OgreMemoryAllocatedObject.h>
#include <boost/unordered_set.hpp>

#include <list>

namespace Kenshi
{
    class Renderer;
    class PhysicsActual;
    class ModInfo;
    class Character;
    class Building;
    class ZoneManager;
    class AudioSystemGlobal;
    class Alarm;
    class PlayerInterface;
    class RenderTimeBackthread;
    class RendererT;
    class PhysicsInterface;
    class RootObjectFactory;
    class FactionManager;
    class NavMesh;
    class NodeList;
    class MessageRoller;
    class AttachedEntity;
    class TownBuildingsManager;
    class NestBatcher;
    class RendererT;
    class ThreadWannabe;
    enum NxShapesType {}; // TODO

    // TODO move?
    class SimpleTimeStamper
    {
    public:
        CPerfTimer timer; // 0x0 Member
        // no_addr public void SimpleTimeStamper(const class SimpleTimeStamper &);
        SimpleTimeStamper();// RVA = 0x685F10
        double getTime(double);// RVA = 0x2BD4A0
        double stampTime();// RVA = 0x1CEFE0
        ~SimpleTimeStamper();// RVA = 0x685EA0
        // no_addr public class SimpleTimeStamper & operator=(const class SimpleTimeStamper &);
        // no_addr public void * __vecDelDtor(unsigned int);
    };

    class GameWorld : Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
    {
    public:
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
        // VTable         : (none)
        // Typedef        : HandCharacterMap
        float tempSpawnsDisableTimer; // 0x8 Member
        void justLoadFactionRelations(GameDataManager*);// RVA = 0x7F5620
        bool startUpThreads();// RVA = 0x6BC970
        // no_addr public void GameWorld(const class GameWorld &);
        GameWorld();// RVA = 0x6C4330
        ~GameWorld();// RVA = 0x6BCB10
        bool start(RendererT*);// RVA = 0x6B9E20
        void resetGame();// RVA = 0x2AD5B0
        void _clearAndDestroyGameWorldStuff();// RVA = 0x2AC4B0
        bool initialisation();// RVA = 0x6BD040
        bool initialisationGameData();// RVA = 0x6BFFA0
        void dailyUpdates();// RVA = 0x600FB0
        void initialiseNewGameWorld(GameDataManager*);// RVA = 0x7F5370
        void errorToLogReleaseMode(const std::string&);// RVA = 0x600580
        void errorD(const std::string&);// RVA = 0x6005A0
        void logToSave(const std::string&);// RVA = 0x6005B0
        void log(const std::string&);// RVA = 0x6005C0
        void logDebug(const std::string&, const std::string&);// RVA = 0x6005F0
        void logDebug(const std::string&);// RVA = 0x6005E0
        void destroy(Ogre::MovableObject*);// RVA = 0x612D80
        void destroy(AttachedEntity*);// RVA = 0x612D40
        void destroy(TownBuildingsManager*);// RVA = 0x612E50
        void destroy(NestBatcher*);// RVA = 0x60DAF0
        bool destroy(RootObject*, bool, const char*);// RVA = 0x6120F0
        void destroy(GameData*);// RVA = 0x6530D0
        bool getIsInKillList(RootObject*);// RVA = 0x60D740
        void flushKillList();// RVA = 0x621460
        void dynamicDestroyBuilding(const hand&);// RVA = 0x2111B0
        bool allThreadQueuesAreClear();// RVA = 0x626710
        bool initialized; // 0xC Member
        RendererT* render; // 0x10 Member
        PhysicsInterface* physics; // 0x18 Member
        GameDataManager gamedata; // 0x20 Member
        GameDataManager leveldata; // 0x1A0 Member
        GameDataManager savedata; // 0x320 Member
        RootObjectFactory* theFactory; // 0x4A0 Member
        FactionManager* factionMgr; // 0x4A8 Member
        NavMesh* navmesh; // 0x4B0 Member
        NodeList* nodeList; // 0x4B8 Member
        hand guiDisplayObject; // 0x4C0 Member
        MessageRoller* messageRoller; // 0x4E0 Member
        Ogre::Log* ogreLogger; // 0x4E8 Member
        bool steamEnabled; // 0x4F0 Member
        lektor<ModInfo> baseMods; // 0x4F8 Member
        lektor<std::string > baseModsNames; // 0x510 Member
        lektor<ModInfo*> activeMods; // 0x528 Member
        std::map<std::string, ModInfo, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, ModInfo>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > availableModsByName; // 0x540 Member
        lektor<ModInfo*> availabelModsOrderedList; // 0x568 Member
        void initBaseMods();// RVA = 0x6B9FE0
        void initModsList();// RVA = 0x6BEC60
        lektor<ModInfo*> getModsListFromConfig();// RVA = 0x6B8860
        const lektor<ModInfo*>& getAllModsList();// RVA = 0x6B7DE0
        int getModIndex(const std::string&);// RVA = 0x6B7E60
        const std::string& getModLeveldataFolder(const std::string&);// RVA = 0x6B7F30
        void getObjectsWithinSphere(lektor<RootObject*>&, const Ogre::Vector3&, float, itemType, int, RootObject*);// RVA = 0x600850
        void getCharactersWithinSphere(lektor<RootObject*>&, const Ogre::Vector3&, float, float, float, int, int, RootObject*);// RVA = 0x600D80
        void getObjectsWithinBox(lektor<RootObject*>&, const Ogre::Vector3&, const Ogre::Vector3&, const Ogre::Quaternion&, itemType, int, RootObject*);// RVA = 0x600990
        bool buildingIntersectionTestCapsule(const Ogre::Vector3&, float, float, RootObject*);// RVA = 0x600920
        float getLightLevel(const Ogre::Vector3&, int, bool);// RVA = 0x80BFB0
        void populateMapArea_nonPermanent(ZoneMap*, int, bool);// RVA = 0x7F49C0
        bool findValidSpawnPos(Ogre::Vector3&, const Ogre::Vector3&);// RVA = 0x7F4CC0
        void togglePause(bool);// RVA = 0x6023F0
        float getFrameSpeedMultiplier();// RVA = 0x51D0C0
        void setFrameSpeedMultiplier(float);// RVA = 0x602360
        void setGameSpeed(float, bool);// RVA = 0x6024F0
        void userPause(bool);// RVA = 0x602660
        bool isPaused();// RVA = 0x9BA90
        const Ogre::Vector3 getCameraCenter();// RVA = 0x600640
        const Ogre::Vector3 getCameraPos();// RVA = 0x600670
        bool fixNaNPosition(Ogre::Vector3&);// RVA = 0x6006E0
        float getWindSpeed(const Ogre::Vector3&);// RVA = 0x600600
        bool isLoadingFromASaveGame();// RVA = 0x600500
        PlayerInterface* player; // 0x580 Member
        void addToUpdateListMain(Character*);// RVA = 0x602320
        void removeFromUpdateListMain(Character*);// RVA = 0x601B90
        const boost::unordered::unordered_set<Character*, boost::hash<Character*>, std::equal_to<Character*>, Ogre::STLAllocator<Character*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >& getCharacterUpdateList();// RVA = 0x516680
        void addToDeathParade(Character*);// RVA = 0x60F240
        bool removeFromDeathParade(Character*);// RVA = 0x60F2A0
        void removeFromDeathParadeByPlatoon(Platoon*);// RVA = 0x60F410
        Character* getFromDeathParade(const hand&);// RVA = 0x63A330
        void hideContextMenu();// RVA = 0x6204F0
        // no_addr public void lockBackgroundThreadsForSave();
        // no_addr public void unlockBackgroundThreads();
        void showPlayerAMessage_withLog(const std::string&, bool);// RVA = 0x5B23F0
        void showPlayerAMessage(const std::string&, bool);// RVA = 0x5B23D0
        void showPlayerAMessageD(const std::string&, bool);// RVA = 0x5AEC90
        void playNotification(const char*);// RVA = 0x1CC290
        // no_addr public int getNumCharactersLoaded();
        boost::unordered::unordered_set<Character*, boost::hash<Character*>, std::equal_to<Character*>, Ogre::STLAllocator<Character*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > charactersWithLights; // 0x588 Member
        enum SysMessageEnum
        {
            SYS_NONE = 0x0,
            SYS_RESIDENT_CHANGE = 0x1,
            SYS_SHOW_PROSPECTING_WINDOW = 0x2,
            SYS_CREATE_PHYSICAL = 0x3,
            SYS_DESTROY_PHYSICAL = 0x4,
            SYS_SET_CHAINED_MODE = 0x5,
            SYS_UPDATE_ORDERS_PANEL = 0x6,
            SYS_UPDATE_PORTRAIT = 0x7,
            SYS_RESEARCH_PROGRESS = 0x8,
            SYS_CLOSE_ALL_INVENTORIES = 0x9,
            SYS_CLOSE_INVENTORY = 0xA,
            SYS_BUILDING_PROGRESS = 0xB,
            SYS_DROP_ALL_GEAR = 0xC,
            SYS_CHARACTER_PARTICLES = 0xD,
            SYS_RESTORE_SQUAD = 0xE,
            SYS_DESTROY_PLATOON = 0xF,
            SYS_BREAK_BUILDING = 0x10
        };

        class SysMessage
        {
            GameWorld::SysMessageEnum msg; // 0x0 Member
            hand target; // 0x8 Member
            hand from; // 0x28 Member
            bool on; // 0x48 Member
            float number; // 0x4C Member
            void* data; // 0x50 Member
            SysMessage(const GameWorld::SysMessage&);// RVA = 0x210230
            SysMessage(GameWorld::SysMessageEnum, const hand&, const hand&, bool, float, void*);// RVA = 0x20F700
            // no_addr public void SysMessage();
            bool operator==(const GameWorld::SysMessage&);// RVA = 0x282970
            // no_addr public class GameWorld::SysMessage & operator=(const class GameWorld::SysMessage &);
        };
        void sysMessage(const GameWorld::SysMessage&);// RVA = 0x2119A0
        void sysMessageUrgent(const GameWorld::SysMessage&);// RVA = 0x510990
        void sysMessage_noDuplicates(const GameWorld::SysMessage&);// RVA = 0x290D60
        virtual void mainLoop_GPUSensitiveStuff(float);// RVA = 0x603060// vtable offset = 0x0
        void clearPortaitsUpdate();// RVA = 0x601960
        void addPortraitUpdate(const hand&);// RVA = 0x601C00
        void removePortaitUpdate(const hand&);// RVA = 0x601C50
        std::list<GameWorld::SysMessage, Ogre::STLAllocator<GameWorld::SysMessage, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > sysMessageList; // 0x5C8 Member
        void processSysMessages();// RVA = 0x62EBB0
        void getCollisionGroupType(itemType, NxShapesType&, unsigned int&);// RVA = 0x600740
        boost::unordered::unordered_map<hand, float, boost::hash<hand>, std::equal_to<hand>, Ogre::STLAllocator<std::pair<hand const, float>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > updatePortraitsMap; // 0x5E8 Member
        lektor<hand> dynamicDestroyBuildingsList; // 0x628 Member
        boost::unordered::unordered_set<AttachedEntity*, boost::hash<AttachedEntity*>, std::equal_to<AttachedEntity*>, Ogre::STLAllocator<AttachedEntity*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > destroyListAE; // 0x640 Member
        boost::unordered::unordered_set<Ogre::MovableObject*, boost::hash<Ogre::MovableObject*>, std::equal_to<Ogre::MovableObject*>, Ogre::STLAllocator<Ogre::MovableObject*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > destroyListOE; // 0x680 Member
        boost::unordered::unordered_set<TownBuildingsManager*, boost::hash<TownBuildingsManager*>, std::equal_to<TownBuildingsManager*>, Ogre::STLAllocator<TownBuildingsManager*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > destroyListTBM; // 0x6C0 Member
        float frameSpeedMult; // 0x700 Member
        void destroyDeathParade();// RVA = 0x601980
        boost::unordered::unordered_map<hand, Character*, boost::hash<hand>, std::equal_to<hand>, Ogre::STLAllocator<std::pair<hand const, Character*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > deathParade; // 0x708 Member
        bool deathParadeWasMeddledWith; // 0x748 Member
        void processKeys();// RVA = 0x6027B0
        void processThreadMessages();// RVA = 0x600450
        bool charUpdateListMain_inUse; // 0x749 Member
        boost::unordered::unordered_set<Character*, boost::hash<Character*>, std::equal_to<Character*>, Ogre::STLAllocator<Character*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > charUpdateListMain; // 0x750 Member
        void charsUpdate();// RVA = 0x6014E0
        void charsUpdateUT();// RVA = 0x601090
        void charsUpdatePaused();// RVA = 0x6018E0
        void charsUpdateDeathParade();// RVA = 0x6010F0
        void threadSafeRagdollUpdates();// RVA = 0x63E680
        RenderTimeBackthread* _AINonRenderThread; // 0x790 Member
        ThreadWannabe* AINonRenderThread();// RVA = 0x1FF8F0
        void processAttachmentsKillList();// RVA = 0x60DBA0
        void processKillList(bool);// RVA = 0x615EA0
        void processUpdateRemovalList();// RVA = 0x60DB20
        std::deque<NestBatcher*, Ogre::STLAllocator<NestBatcher*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > nestBatcherKillList; // 0x798 Member
        boost::unordered::unordered_set<RootObject*, boost::hash<RootObject*>, std::equal_to<RootObject*>, Ogre::STLAllocator<RootObject*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > killListPhase0; // 0x7D0 Member
        boost::unordered::unordered_map<RootObject*, float, boost::hash<RootObject*>, std::equal_to<RootObject*>, Ogre::STLAllocator<std::pair<RootObject* const, float>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > killListPhase1; // 0x810 Member
        std::deque<RootObject*, Ogre::STLAllocator<RootObject*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > killListPhase2; // 0x850 Member
        lektor<Character*> mainUpdateListRemovalQueue; // 0x888 Member
        void loadAllPlatoons();// RVA = 0x7F4FB0
        void reCalculateFortificationInsideOutsideStateForAllCharacters();// RVA = 0x600FC0
        SimpleTimeStamper timeStamper; // 0x8A0 Member
        double getTimeStamp();// RVA = 0x1CF000
        TimeOfDay getTimeFromStamp(const TimeOfDay&);// RVA = 0x51D510
        float getTimeFromStamp(double);// RVA = 0x406B60
        float getTimeFromStamp_inGameHours(double);// RVA = 0x51B7E0
        TimeOfDay getTimeStamp_inGameHours();// RVA = 0x51D4F0
        float getLengthOfHourInRealSeconds();// RVA = 0x51DCD0
        ZoneManager* zoneMgr; // 0x8B0 Member
        bool debugFlag; // 0x8B8 Member
        bool paused; // 0x8B9 Member
        bool gameResetting; // 0x8BA Member
        AudioSystemGlobal* audioThread; // 0x8C0 Member
        // no_addr public class GameWorld & operator=(const class GameWorld &);
        // no_addr public void * __vecDelDtor(unsigned int);
    };

};
