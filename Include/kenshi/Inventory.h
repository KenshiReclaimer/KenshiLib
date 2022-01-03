#pragma once

#include <string>
#include <stdint.h>
#include <vector>
#include "kenshi/util/lektor.h"

namespace Kenshi
{
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
        char unk_00A8[0x18]; // 0xA8
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
        // Not sure where the struct ends, but should be close to here?
    };
}