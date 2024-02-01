#pragma once

#include "Enums.h"
#include "util/lektor.h"
#include "util/Array2d.h"

#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>

namespace Kenshi
{
    /*
    * old code
    class Item;
    class GameData;
    class Character;
    class Inventory;

    class InventorySection
    {
        virtual ~InventorySection();
    public:
        // Class SectionItem derived from vector allocator type, 
        // hopefully I did it right, first time I've tried that
        class SectionItem
        {
        public:
            Item* item; // 0x00
            char unk_8[8]; // 0x08
        };

        // useful constants for sectionName
        // set in .cpp file
        static const std::string Hip;
        static const std::string Back;
        static const std::string Boots;
        static const std::string Head;
        static const std::string Backpack_Attach;
        static const std::string Shirt;
        static const std::string Armour;
        static const std::string Legs;
        static const std::string Belt;
        static const std::string Main;

        // member variables
        std::string sectionName; // 0x08
        uint32_t width; // 0x30
        uint32_t height; // 0x34
        char unk_0038[0x8]; //0x38
        // Ogre::STLAllocator<InventorySection::SectionItem,Ogre::CategorisedAllocPolicy<0> >
        // One pointer for each item in inventory
        std::vector<SectionItem> sectionItems; // 0x40
        uint32_t _width_slave; // 0x60 - this doesn't seem to be used
        uint32_t _height_slave; // 0x64 - this doesn't seem to be used
        // Ogre::STLAllocator<Item * __ptr64,Ogre::CategorisedAllocPolicy<0> >
        // one pointer for each cell in inventory block
        // e.g. a 4x4 item will have 4 pointers in this vector
        std::vector<Item*> inventoryBlocks; // 0x68
        // looks like a double?
        char unk_0070[8]; // 0x88
        // lektor<GameData * __ptr64>
        // Don't know what this is for, seems to be empty for human player characters?
        lektor<GameData*> gameDataLektor; // 0x90
        char unk_00A8[0x8]; // 0xA8
        float weight;// 0xB0
        char unk_00B4[0xC]; // 0xB4
        // Sometimes null
        Character* parentCharacter; // 0xC0
        // Not null
        Inventory* parentInventory; // 0xC8
        // possibly a bool with padding?
        // not sure I trust the size...
        uint32_t enabled; // 0xD0
        // pretty sure this is the end of the class
        char unk_00D4[0xC]; // 0xD4
        //
    };

    struct Inventory
    {
        virtual ~Inventory();
    public:
        // helper functions
        // returns null if inventory section doesn't exist
        InventorySection* GetInventorySection(std::string sectionName);

        char unk_0008[0x08]; // 0x08
        // lektor<Item * __ptr64>
        // List of items in "main" inventory section
        lektor<Item*> mainSectionItems; // 0x10
        char unk_0028[0x8]; // 0x28
        // Hashmap?
        // vtable Ogre::STLAllocator<boost::unordered::detail::ptr_bucket,Ogre::CategorisedAllocPolicy<0> >
        char unk_0030[0x8]; // 0x30
        //Ogre::STLAllocator<boost::unordered::detail::ptr_node<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,InventorySection * __ptr64> >,Ogre::CategorisedAllocPolicy<0> >
        // boost::unordered_map<std::string, InventorySection*>
        char unk_0038[0x8]; // 0x38
        char unk_0040[0x20]; // 0x40
        // Pointer to sparse array of inventory sections
        // Hashmap contents?
        void* unk_0060; // 0x60
        // lektor<InventorySection * __ptr64>
        lektor<InventorySection*> inventorySections; // 0x68
        Character* patentCharacter; // 0x80
        // Not sure why there are two
        Character* patentCharacter2; // 0x88
        float weight; // 0x90
        // Not sure where the struct ends, but should be close to here?
    };
    */

    class Item;
    class hand;
    class Faction;
    class Inventory;
    class RootObject;
    class GameData;

    class InventorySection
    {
    public:
        // VTable         : (none)
        class SectionItem
        {
        public:
            Item* item; // 0x0 Member
            unsigned short x; // 0x8 Member
            unsigned short y; // 0xA Member
            unsigned short w; // 0xC Member
            unsigned short h; // 0xE Member
        };
        // no_addr public void InventorySection(const class InventorySection &);
        InventorySection(const std::string&, int, int, AttachSlot, Inventory*, bool, bool, bool);// RVA = 0x5D0000
        virtual ~InventorySection();// RVA = 0x5CE090// vtable offset = 0x0
        virtual bool hasRoomForItem(GameData*, int);// RVA = 0x5D1BC0// vtable offset = 0x8
        void notifyModified();// RVA = 0x5CE220
        virtual bool addItem(Item*, int);// RVA = 0x5D3310// vtable offset = 0x10
        virtual void _addItem(Item*, int, int);// RVA = 0x5D0180// vtable offset = 0x18
        Item* getItemAt(int, int);// RVA = 0x5CD760
        // no_addr public float getTotalWeight();
        bool hasItem(GameData*);// RVA = 0x5CD810
        bool hasItem(Item*);// RVA = 0x5CD7B0
        bool hasItemType(itemType);// RVA = 0x5CD210
        virtual void autoArrange();// RVA = 0x5D0790// vtable offset = 0x20
        void getAllItemsOfType(lektor<Item*>&, Item*);// RVA = 0x5CD980
        void getAllItemsOfType(lektor<Item*>&, itemType);// RVA = 0x5CD8C0
        void getAllItemsOfName(lektor<Item*>&, const std::string&);// RVA = 0x5CDC80
        unsigned int getNumItems();// RVA = 0x5CD2A0
        bool isEmpty();// RVA = 0x5CD2E0
        bool removeItem(Item*);// RVA = 0x5D0480
        void clearAllItems(bool, bool);// RVA = 0x5D0680
        bool canItemGoHere(Item*, int, int);// RVA = 0x5D28A0
        bool getValidInventoryPosition(Item*, int&, int&);// RVA = 0x5D2920
        bool findNearestPlaceForItem(Item*, int&, int&);// RVA = 0x5D2A50
        int getItemsInFootprint(lektor<Item*>&, int, int, int, int);// RVA = 0x5CD670
        int getItemsInFootprint(lektor<Item*>&, Item*, int, int);// RVA = 0x5CDB40
        bool existsItemInFootprint(Item*, int, int);// RVA = 0x5CD150
        AttachSlot getLimitedSlot();// RVA = 0x497670
        void setupContainerData(GameData*);// RVA = 0x5D2580
        int applyStackingBonuses(int);// RVA = 0x5CD110
        void recalculateTotalWeight();// RVA = 0x5CFBC0
        void setWeightMultiplier(float);// RVA = 0x5CC8F0
        void setStackingBonus(int, float);// RVA = 0x1FFB70
        int getMaxStack();// RVA = 0x2233E0
        // no_addr public class RootObject * getCallbackObject();
        void addVeryLimitedSlot(GameData*);// RVA = 0x5D1EA0
        void clearVeryLimitedSlot();// RVA = 0x5CE5E0
        const lektor<GameData*>& getVeryLimitedSlot();// RVA = 0xF4490
        bool isLimitedSlotCompatible(GameData*);// RVA = 0x5D17E0
        bool isLimitedSlotCompatible(Item*);// RVA = 0x5D2690
        // no_addr public bool getIsAnEquippedItemSection();
        bool getEnabled();// RVA = 0xF44A0
        void setEnabled(bool);// RVA = 0x5CC900
        void setItemsLimitCount(int);// RVA = 0x5CC610
        // no_addr public int getItemsLimitCount();
        bool getItemsLimitReached();// RVA = 0x5A92D0
        Inventory* getInventory();// RVA = 0x5CC620
        float getFillPercentage();// RVA = 0x5CDA40
        const std::vector<InventorySection::SectionItem, Ogre::STLAllocator<InventorySection::SectionItem, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >& getItems();// RVA = 0x1FFB80
        Item* getItem();// RVA = 0x211230
        std::string name; // 0x8 Member
        int width; // 0x30 Member
        int height; // 0x34 Member
        bool armourOnly; // 0x38 Member
        void setupEquipCallbacks(RootObject*);// RVA = 0x5CC630
        int numItemsInFootprint(Item*, int, int);// RVA = 0x5CDBB0
        void resize(int, int, bool);// RVA = 0x5D1E60
        std::vector<InventorySection::SectionItem, Ogre::STLAllocator<InventorySection::SectionItem, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > items; // 0x40 Member
        Array2d<Item> content; // 0x60 Member
        int stackingBonusMin; // 0x88 Member
        float stackingBonusMult; // 0x8C Member
        lektor<GameData*> veryLimitedSlot; // 0x90 Member
        int itemsLimit; // 0xA8 Member
        float weightMultiplier; // 0xAC Member
        float totalWeight; // 0xB0 Member
        bool isAnEquippedItemSection; // 0xB4 Member
        AttachSlot limitedSlot; // 0xB8 Member
        bool containerSlot; // 0xBC Member
        RootObject* callbackObject; // 0xC0 Member
        Inventory* parentInventory; // 0xC8 Member
        bool enabled; // 0xD0 Member
        // no_addr public class InventorySection & operator=(const class InventorySection &);
        // no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };

    class GameDataContainer;
    class GameSaveState;
    class Item;
    class Character;
    class Weapon;
    class InventoryGUI;

    class Inventory : Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
    {
    public:
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
        // VTable         : (none)
        // no_addr public void Inventory(const class Inventory &);
        Inventory(RootObject*);// RVA = 0x5D1F70
        virtual ~Inventory();// RVA = 0x5D20C0// vtable offset = 0x0
        const hand& getHandle();// RVA = 0x5CC650
        void clearAll(bool, bool);// RVA = 0x5D1010
        GameData* serialise(GameDataContainer*, GameData*);// RVA = 0x5CE250
        void loadFrom(GameDataContainer*, GameData*);// RVA = 0x5D2B40
        void loadFrom(GameSaveState*);// RVA = 0x5D3800
        void notifyModified();// RVA = 0x5CDFF0
        void fillFromVendorList(GameData*, Faction*);// RVA = 0x5D0E30
        void fillFromVendorList(lektor<GameData*>&, Faction*);// RVA = 0x5D18E0
        virtual InventorySection* initialiseNewSection(const std::string&, int, int, AttachSlot, bool, bool, bool, int);// RVA = 0x5D23A0// vtable offset = 0x8
        void resizeSection(InventorySection*, int, int, bool);// RVA = 0x5D2530
        void removeAllSections();// RVA = 0x5D1940
        InventorySection* getSection(const std::string&);// RVA = 0x5CE610
        InventorySection* getSectionOfType(AttachSlot);// RVA = 0x5CC950
        void getAllSectionsOfType(lektor<InventorySection*>&, AttachSlot);// RVA = 0x5CD380
        lektor<InventorySection*>& getAllSections();// RVA = 0x93C20
        bool getExcessLoot(const hand&, lektor<Item*>&, bool);// RVA = 0x5CF7A0
        void getResourceItems(boost::unordered::unordered_set<GameData*, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<GameData*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&, bool);// RVA = 0x5CFEF0
        int getNumItems(GameData*);// RVA = 0x5CCCA0
        int getNumItems();// RVA = 0x5CDF00
        Character* getCallbackCharacter();// RVA = 0x59E4C0
        virtual bool addItem(Item*, int, bool, bool);// RVA = 0x5CC6E0// vtable offset = 0x10
        virtual bool tryAddItem(Item*, int);// RVA = 0x5D2780// vtable offset = 0x18
        class HasRoomCache
        {
        public:
            std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData* const, bool> > > itemStates; // 0x0 Member
            void modified();// RVA = 0x5DCB90
            bool knowsAbout(GameData*);// RVA = 0x5DB120
            bool hasRoomFor(GameData*);// RVA = 0x5DB180
            void remember(GameData*, bool);// RVA = 0x5DE7A0
            // no_addr public void HasRoomCache(const class Inventory::HasRoomCache &);
            HasRoomCache();// RVA = 0x5DE800
            ~HasRoomCache();// RVA = 0x5DDE50
            // no_addr public class Inventory::HasRoomCache & operator=(const class Inventory::HasRoomCache &);
            // no_addr public void * __vecDelDtor(unsigned int);
        };
        HasRoomCache* hasRoomCache; // 0x8 Member
        virtual bool hasRoomForItem(GameData*);// RVA = 0x5D1A00// vtable offset = 0x20
        virtual Item* removeItemDontDestroy_returnsItem(Item*, int, bool);// RVA = 0x5D13B0// vtable offset = 0x28
        virtual bool removeItemAutoDestroy(Item*, int);// RVA = 0x5CC840// vtable offset = 0x30
        virtual void dropItem(Item*);// RVA = 0x5CC7F0// vtable offset = 0x38
        bool transferMouseItem(Item*);// RVA = 0x5CC7D0
        bool hasItem(GameData*, int);// RVA = 0x5CC9D0
        bool hasItem(Item*);// RVA = 0x5CC990
        int countItems(GameData*);// RVA = 0x5CCA70
        Item* getItem(GameData*);// RVA = 0x5CCB00
        bool hasItemType(itemType, bool);// RVA = 0x5CCB90
        void getAllStolenItems(lektor<Item*>&, bool);// RVA = 0x5CF620
        bool hasStolenItems();// RVA = 0x5CCBE0
        void getAllItemsOfType(lektor<Item*>&, itemType, bool);// RVA = 0x5CD420
        void getEquippedWeapons(lektor<Item*>&);// RVA = 0x5CEA50
        Weapon* getSecondaryWeapon();// RVA = 0x5CE690
        Weapon* getPrimaryWeapon();// RVA = 0x5CE860
        void getEquippedArmour(lektor<Item*>&);// RVA = 0x5CEDE0
        Item* takeOneItemOnly(GameData*);// RVA = 0x5D1590
        bool deathCheck(Item*);// RVA = 0x5E0D50
        bool takeItem_EntireStack(Item*);// RVA = 0x5D1780
        Item* takeItem_EntireStack(GameData*);// RVA = 0x5D16B0
        bool hasItemFunction(ItemFunction);// RVA = 0x5CCC60
        void getAllItemsWithFunction(lektor<Item*>&, ItemFunction);// RVA = 0x5CD4E0
        Item* getBestItemWithFunction(ItemFunction);// RVA = 0x5CCDB0
        Item* getBestItemWithLowestCharges(GameData*);// RVA = 0x5D1B00
        Item* getBestItemWithLowestCharges(ItemFunction);// RVA = 0x5CCEE0
        Item* getBestFoodItem(Character*);// RVA = 0x497680
        int getNumFoodItems(Character*);// RVA = 0x27F410
        Item* _getBestFoodItem(ItemFunction, Character*);// RVA = 0x5CF7D0
        int _getNumFoodItems(ItemFunction, Character*);// RVA = 0x5CD030
        bool hasWeaponEquipped();// RVA = 0x5CDDD0
        bool equipItem(Item*);// RVA = 0x5D30B0
        bool isAContainer();// RVA = 0x5CC670
        // no_addr public class RootObject * getOwner();
        RootObject* getOwner();// RVA = 0xF44B0
        bool isEmpty();// RVA = 0x5CD410
        void recalculateTotalWeight();// RVA = 0x5CDEA0
        float getTotalWeight();// RVA = 0x5CDE30
        int getMoney();// RVA = 0x5CC8C0
        void takeMoney(int);// RVA = 0x5CC890
        Item* buyItem(Item*, RootObject*);// RVA = 0x5D1090
        InventoryGUI* getInventoryGUI();// RVA = 0xF44F0
        bool isVisible();// RVA = 0xF4520
        virtual void _sectionAddItemCallback(Item*);// RVA = 0x5CE010// vtable offset = 0x40
        virtual void _sectionUpdateItemCallback(Item*, int);// RVA = 0x5CE040// vtable offset = 0x48
        virtual void _sectionRemoveItemCallback(Item*);// RVA = 0x5CE060// vtable offset = 0x50
        virtual void refreshGui();// RVA = 0x5CC6B0// vtable offset = 0x58
        void autoArrange();// RVA = 0x5CDF80
        RootObject* getCallbackObject();// RVA = 0xF44C0
        const lektor<Item*>& getAllItems();// RVA = 0x1FFB90
        virtual void _addToList(Item*);// RVA = 0x5CD620// vtable offset = 0x60
        virtual void _removeFromList(Item*, bool);// RVA = 0x5CCD20// vtable offset = 0x68
        lektor<Item*> _allItems; // 0x10 Member
        boost::unordered::unordered_map<std::string, InventorySection*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, InventorySection*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > sections; // 0x28 Member
        lektor<InventorySection*> sectionsInSearchOrder; // 0x68 Member
        RootObject* callbackObject; // 0x80 Member
        RootObject* owner; // 0x88 Member
        float totalWeight; // 0x90 Member
        // no_addr public class Inventory & operator=(const class Inventory &);
        // no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    }; 
};
