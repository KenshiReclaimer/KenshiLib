#pragma once

#include "Enums.h"
#include "util/lektor.h"

#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <ogre/OgreMemoryAllocatedObject.h>

namespace Kenshi
{
    class GameData;
    class Serialisable;

    class GameDataContainer : Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
    {
    public:
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
        // VTable         : (none)
        void addNewData(GameData*, const std::string&);// RVA = 0x560A70
        void addNewData(const lektor<GameData*>&);// RVA = 0x560DA0
        // no_addr public void GameDataContainer(const class GameDataContainer &);
        GameDataContainer();// RVA = 0x2C37D0
        virtual ~GameDataContainer();// RVA = 0x561990// vtable offset = 0x0
        GameData* createNewData(itemType, const std::string&, const std::string&);// RVA = 0x561A40
        GameData* getData(const std::string&);// RVA = 0x55E7D0
        GameData* getData(const std::string&, itemType);// RVA = 0x561150
        GameData* getData(int);// RVA = 0x55DA00
        GameData* getDataByName(const std::string&, itemType);// RVA = 0x561090
        void getDataOfType(lektor<GameData*>&, itemType);// RVA = 0x561710
        const boost::unordered::unordered_map<int, GameData*, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, GameData*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >& _getAllData();// RVA = 0x2ABB40
        // no_addr public class lektor<GameData *> getInstancesFrom(class GameData *, enum itemType);
        void renameData(GameData*, const std::string&);// RVA = 0x560E60
        void removeData(GameData*);// RVA = 0x560970
        void removeDuplicatesOf(GameData*);// RVA = 0x5617D0
        void removeAllDataOfType(itemType);// RVA = 0x5618D0
        bool loadGameDataReturn(std::string, bool, bool, Serialisable*);// RVA = 0x563C90
        bool load(const std::string&, const std::string&, int, Serialisable*, bool);// RVA = 0x561E40
        bool save(const std::string&, Serialisable*);// RVA = 0x55E860
        void clearInstances();// RVA = 0x561AF0
        void clearButDontDestroy();// RVA = 0x560490
        void clearButDontDestroyPlatoons();// RVA = 0x5608B0
        void clearAndDestroy();// RVA = 0x560800
        int getNewID();// RVA = 0x55D850
        static void flushKillList();// RVA = 0x55D680
        static void destroyHomelessData(GameData*);// RVA = 0x55DCB0
        void destroyData(GameData*);// RVA = 0x560F90
        void preLoadAllReferencePtrs();// RVA = 0x55F0F0
        void clearAllReferencePtrs();// RVA = 0x55D520
        void setName(const std::string&);// RVA = 0x2C1260
        void findAllDataThatReferencesThis(lektor<GameData*>&, GameData*, itemType, const std::string&);// RVA = 0x561410
        int currentID; // 0x8 Member
        void checkForDuplicates(GameData*);// RVA = 0x55D910
        static boost::unordered::unordered_set<GameData*, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<GameData*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > killList; // Static Member
        static void _addToKillList(GameData*);// RVA = 0x55DC60
        boost::unordered::unordered_map<int, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > >, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > gamedataCatName; // 0x10 Member
        boost::unordered::unordered_map<int, GameData*, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, GameData*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > gamedataID; // 0x50 Member
        boost::unordered::unordered_map<int, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >, boost::hash<int>, std::equal_to<int>, Ogre::STLAllocator<std::pair<int const, boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > >, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > gamedataCatSID; // 0x90 Member
        boost::unordered::unordered_map<std::string, GameData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > gamedataSID; // 0xD0 Member
        boost::unordered::unordered_set<GameData*, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<GameData*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > mainList; // 0x110 Member
        // no_addr protected bool saveGameData(class boost::unordered::unordered_map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,GameData *,boost::hash<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::equal_to<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,Ogre::STLAllocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,GameData *>,Ogre::CategorisedAllocPolicy<0> > > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, bool, class Serialisable *);
        std::string name; // 0x150 Member
        bool isBaseDatafile; // 0x178 Member
        bool readOnly; // 0x179 Member
        // no_addr public class GameDataContainer & operator=(const class GameDataContainer &);
        // no_addr public void __local_vftable_ctor_closure();
        // no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };

    class GameDataManager : GameDataContainer
    {
    public:
        // GameDataContainer offset = 0x0, length = 0x180
        // no_addr public void GameDataManager(const class GameDataManager &);
        GameDataManager();// RVA = 0x396910
        bool reloadGameData(std::string, bool, bool);// RVA = 0x565010
        void postProcessingTheDatas();// RVA = 0x5647E0
        void getBuildings(lektor<GameData*>&, const std::string&);// RVA = 0x561220
        GameData* getMapSector(int, int);// RVA = 0x563D30
        void updateDatasOfType(GameDataContainer*, itemType, bool);// RVA = 0x564C80
        void updateData(GameData*, bool);// RVA = 0x561B30
        virtual ~GameDataManager();// RVA = 0x388B50// vtable offset = 0x0
        // no_addr public class GameDataManager & operator=(const class GameDataManager &);
        // no_addr public void __local_vftable_ctor_closure();
        // no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };
}
