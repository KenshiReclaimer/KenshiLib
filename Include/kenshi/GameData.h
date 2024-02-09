#pragma once

#include <string>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>
#include <map>
#include "util/lektor.h"
#include "util/hand.h"

namespace Kenshi
{
    // TODO pretty sure Ogre had typedefs for these somewhere?
    template <typename T1, typename T2>
    struct unordered_map_ogre
    {
        // size = 0x20 which is correct!
        typedef boost::unordered::unordered_map<T1, T2, boost::hash<T1>, std::equal_to<T2>, Ogre::STLAllocator<std::pair<T1 const, T2>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > type;
    };

    template <typename T1, typename T2>
    struct  map_ogre
    {
        typedef std::map<T1, T2, std::less<T1>, Ogre::STLAllocator<std::pair<T1 const, T2>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > type;
    };

    class GameDataContainer;
    class GameDataReference;
    class GameSaveState;
    class PosRotPair;
    class TripleInt;

    class GameData : Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
    {
    public:
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
        // VTable         : (none)
        int validity; // 0x8 Member
        GameDataContainer* sourceContainer; // 0x10 Member
        virtual ~GameData();// RVA = 0x7A290// vtable offset = 0x0
        // no_addr public void GameData(const class GameData &);
        GameData();// RVA = 0x51C560
        bool isStandalone; // 0x18 Member
        bool isValid();// RVA = 0x42EF10
        GameDataContainer* getSourceContainer();// RVA = 0x8D330
        void destroy();// RVA = 0x6530B0
        enum DataType
        {
            NONE,
            INT,
            FLOAT,
            BOOL,
            FILE,
            STRING
        };

        class ItemData
        {
        public:
            // no_addr public void ItemData(const class GameData::ItemData &);
            // no_addr public void ItemData(class std::basic_string<char,std::char_traits<char>,std::allocator<char> >, bool, class std::basic_string<char,std::char_traits<char>,std::allocator<char> >, float, float, enum itemType, int, bool);
            // no_addr public void ItemData();
            bool visible; // 0x0 Member
            std::string category; // 0x8 Member
            std::string description; // 0x30 Member
            std::string fileTypes; // 0x58 Member
            itemType objectType; // 0x80 Member
            int maxSize; // 0x84 Member
            int maxValue; // 0x88 Member
            int minValue; // 0x8C Member
            bool isSlider; // 0x90 Member
            // no_addr public const class GameData::ItemData & operator=(const class GameData::ItemData &);
            // no_addr public void ~ItemData();
            // no_addr public void * __vecDelDtor(unsigned int);
        };
        int id; // 0x1C Member
        bool readOnly; // 0x20 Member
        std::string name; // 0x28 Member
        itemType type; // 0x50 Member
        std::string stringID; // 0x58 Member
        bool isFromActiveFile; // 0x80 Member
        void initialise(itemType, bool);// RVA = 0x51B8F0
        bool loadFromFile(const std::string&, itemType);// RVA = 0x564D60
        bool saveToFile(const std::string&);// RVA = 0x561C20
        void storeHandleList(const boost::unordered::unordered_set<hand, boost::hash<hand>, std::equal_to<hand>, Ogre::STLAllocator<hand, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&, const std::string&);// RVA = 0x55E1D0
        void storeHandleList(const lektor<hand>&, const std::string&);// RVA = 0x55E0E0
        void getHandleList(boost::unordered::unordered_set<hand, boost::hash<hand>, std::equal_to<hand>, Ogre::STLAllocator<hand, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&, const std::string&);// RVA = 0x55E680
        void getHandleList(lektor<hand>&, const std::string&);// RVA = 0x55E500
        void storeHandle(const hand&, const std::string&, bool);// RVA = 0x55DD70
        bool getHandle(hand&, const std::string&);// RVA = 0x55E2F0
        bool updateFrom(const GameData*, bool);// RVA = 0x240380
        bool isValueActive(const std::string&);// RVA = 0x23FF10
        // no_addr public bool isRefDeleted(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
        bool isRefActive(const std::string&);// RVA = 0x23FC30
        void addFileName(const std::string&, const std::string&, std::string, std::string, bool);// RVA = 0x2C2F20
        void addString(const std::string&, const std::string&, std::string, bool);// RVA = 0x77B20
        // no_addr public void add(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, class Ogre::Quaternion);
        void add(const std::string&, Ogre::Vector3);// RVA = 0x77C20
        void add(const std::string&, bool, std::string, bool);// RVA = 0x76D50
        void add(const std::string&, float, std::string, bool, bool);// RVA = 0x77BA0
        void add(const std::string&, unsigned int, std::string, bool);// RVA = 0x4FA6A0
        void add(const std::string&, int, std::string, bool);// RVA = 0x76CD0
        GameDataReference* getGameDataReferenceObject(const std::string&, const std::string&);// RVA = 0x7A3D0
        void addToList(const std::string&, const std::string&, int, int, int);// RVA = 0x7A4B0
        void removeFromList(const std::string&, int);// RVA = 0x697090
        void removeFromList(const std::string&, const std::string&);// RVA = 0x569600
        bool findInList(const std::string&, const std::string&);// RVA = 0x232B80
        void clearList(const std::string&);// RVA = 0x7A5C0
        // no_addr public void clearAllLists();
        void clearEverything();// RVA = 0x459890
        void clearInstances();// RVA = 0x457720
        const std::string& getFromList(const std::string&, int);// RVA = 0x70490
        const std::string& getFromList_random(const std::string&);// RVA = 0x55DB40
        int getListSize(const std::string&);// RVA = 0x93420
        bool listExists(const std::string&);// RVA = 0x46C0B0
        bool listExistsAndNotEmpty(const std::string&);// RVA = 0x70550
        void getAllFromList(const std::string&, lektor<std::string >&);// RVA = 0x4FBFC0
        const std::vector<GameDataReference, Ogre::STLAllocator<GameDataReference, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >* getReferenceList(const std::string&);// RVA = 0x43340
        const std::vector<GameDataReference, Ogre::STLAllocator<GameDataReference, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >* getReferenceListIfExists(const std::string&);// RVA = 0x22ECC0
        std::vector<GameDataReference, Ogre::STLAllocator<GameDataReference, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >* _getReferenceList_nonConst(const std::string&);// RVA = 0x939D0
        void getAllFromListAsDatas(const std::string&, lektor<GameData*>&, GameDataContainer*, itemType);// RVA = 0x7A5E0
        GameData* getFromListAsData(const std::string&, int, GameDataContainer*, itemType);// RVA = 0x7A710
        const TripleInt& getValueFromList(const std::string&, int);// RVA = 0x8A7C0
        class ObjectInstance
        {
            ObjectInstance(const GameData::ObjectInstance&);// RVA = 0xB6080
            ObjectInstance();// RVA = 0xB5160
            Ogre::Vector3 pos; // 0x0 Member
            Ogre::Quaternion rot; // 0xC Member
            std::string refID; // 0x20 Member
            short created; // 0x48 Member
            short modified; // 0x4A Member
            lektor<std::string > stateIDs; // 0x50 Member
            const GameData::ObjectInstance& operator=(const GameData::ObjectInstance&);// RVA = 0x2C23F0
            void updateInstancedObjectAttachedDatas(const boost::unordered::unordered_map<itemType, GameData*, boost::hash<itemType>, std::equal_to<itemType>, Ogre::STLAllocator<std::pair<itemType const, GameData*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x55D950
            ~ObjectInstance();// RVA = 0x65AD0
            // no_addr public void * __vecDelDtor(unsigned int);
        };
        // Typedef        : StringObjectInstanceMap
        void addSavedInstancedObject(const std::string&, const std::string&, int, const Ogre::Vector3&, const Ogre::Quaternion&, const lektor<std::string >&);// RVA = 0x5693C0
        void deleteInstancedObject(const std::string&, int);// RVA = 0x569500
        // no_addr public void updateInstancedObject(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, class Ogre::Vector3, class Ogre::Quaternion);
        void getInstances(lektor<GameData::ObjectInstance*>&);// RVA = 0x453AE0
        std::map<std::string, GameData::ObjectInstance, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, GameData::ObjectInstance>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > instances; // 0x88 Member
        int currentID; // 0xB0 Member
        int getNewID();// RVA = 0x55D440
        boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > activeValues; // 0xB8 Member
        boost::unordered::unordered_map<std::string, bool, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, bool>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > bdata; // 0xF8 Member
        boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > sdata; // 0x138 Member
        boost::unordered::unordered_map<std::string, int, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > idata; // 0x178 Member
        boost::unordered::unordered_map<std::string, float, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, float>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > fdata; // 0x1B8 Member
        boost::unordered::unordered_map<std::string, std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::string >, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > filesdata; // 0x1F8 Member
        boost::unordered::unordered_map<std::string, Ogre::Vector3, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Vector3>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > vecdata; // 0x238 Member
        boost::unordered::unordered_map<std::string, Ogre::Quaternion, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::Quaternion>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > quatdata; // 0x278 Member
        boost::unordered::unordered_map<std::string, std::vector<GameDataReference, Ogre::STLAllocator<GameDataReference, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, std::vector<GameDataReference, Ogre::STLAllocator<GameDataReference, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > >, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > objectReferences; // 0x2B8 Member
        unsigned short createdIndex; // 0x2F8 Member
        Ogre::ColourValue getColor(const std::string&);// RVA = 0x76DD0
        Ogre::Vector3 getColorVec(const std::string&);// RVA = 0x93660
        void setColor(const std::string&, const Ogre::Vector3&);// RVA = 0x93730
        void setColor(const std::string&, const Ogre::ColourValue&);// RVA = 0x936F0
        // no_addr public enum GameData::DataType getDataType(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &);
        GameData::ObjectInstance* addANewInstancedObject(GameData::ObjectInstance*);// RVA = 0x5602E0
        void addANewInstancedObject(GameData*, const PosRotPair&);// RVA = 0x5601F0
        void addANewInstancedObject(GameData*);// RVA = 0x560140
        GameData::ObjectInstance* addANewInstancedObject(const GameSaveState&, const PosRotPair&, PosRotPair*);// RVA = 0x564130
        void addDeletedInstance(const std::string&);// RVA = 0x560460
        // no_addr public class GameData & operator=(const class GameData &);
        // no_addr public void __local_vftable_ctor_closure();
        // no_addr protected virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };

}
