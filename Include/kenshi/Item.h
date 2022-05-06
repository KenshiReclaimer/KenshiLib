#pragma once

#include <string>
#include <stdint.h>
#include <boost/unordered_map.hpp>

namespace Kenshi 
{
	class GameData;
	// LockedArmour extends Armour (possibly 0x2F8 long)
	// Armour extends Gear (possibly 0x2F0 long)
	// Sword extends Weapon (possibly 0x258 long)
	// Crossbow extends Weapon (possibly 0x248 long)
	// Weapon extends Gear (possibly 0x23C (???) long)
	// RobotLimbItem extends Gear (possibly 0x280 long)
	// Gear extends Item (possibly 0x228 (???) long)
	// SeveredLimbItem extends Item (probably 0x228 long)
	// NestItem extends Item (possibly 0x1E8 long)
	// BlueprintItem extends Item (possibly 0x1F0 long)
	// MapItem extends Item - (probably 0x208 long)
	// MoneyItem extends Item - (probably 0x1E8 long) (interesting virtuals: 632, 648)
	// ContainerItem extends Item, RaceLimiter (probably 0x298 long) (RaceLimiter vtable @ 1E8 implies Item is 1E8 long)
	// Item extends InventoryItemBase (probably 0x1E8 long)
	// InventoryItemBase extends RootObject, Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0>> (at least 0x190 long)
	// RootObject extends RootObjectBase (probably 0xC0 long?)
	// RootObjectBase is base class (possibly approximately 0x74 long?)
	class Item // size = 1E8
	{
		virtual ~Item();
	public:
		char unk_0008[0x10]; // 0x08
		std::string name; // 0x18
		GameData* itemTemplate; // 0x40
		char unk_0048[0x10]; // 0x48
		char unk_0058[0x18]; // 0x58 - hand?
		char unk_0070[0x8]; // 0x70 - Ogre::TransformKeyFrame*?
		char unk_0078[0x8]; // 0x78
		char unk_0080[0x40]; // 0x80 - hand?
		GameData* manufacturer; // 0xC0
		GameData* modelNumber; // 0xC8
		char unk_00D0[0x18]; // 0xD0
		std::string inventorySlotName; // 0x0E8
		char unk_0110[0x4]; // 0x110
		// negative values seem sort of invalid
		int32_t maxCharges; // 0x114
		int32_t charges; // 0x118
		int32_t quality; // 0x11C 
		float weight; // 0x120
		char unk_0124[0x8]; // 0x124
		// negative numbers seem to be invalid
		int count; // 0x12C
		int blockWidth; // 0x130
		int blockHeight; // 0x134
		char unk_0138[0xB0]; // 0x138
		// ends 0x1E8
	};

	class Gear : public Item
	{
		virtual ~Gear();

	public:
		// possibly 0x228 long?
		char unk_01E8[0x8]; // 0x1E8
		int32_t value; // 0x1F0 - this appears to be from Gear, not Item
		char unk_01F4[0x34]; // 0x1F4
		// ends 0x228
	};

	class Weapon : public Gear
	{
		virtual ~Weapon();

	public:
		float bloodLossMult;// 0x228
		int32_t attackBonus;// 0x22C
		char unk_0230[0x10]; //0x230
		float cutDamage; // 0x240
		float bluntDamage; // 0x244
		char unk_0248[4]; // 0x248
		int32_t defenceBonus; // 0x24C
		int32_t indoorsBonus; // 0x250
	};

	class Armour : public Gear
	{
		virtual ~Armour();

	public:
		// Gear ends 0x228
		float cutResistance; // 0x228
		float bluntResistance; // 0x22C
		float unk1; // 0x230
		char unk_0234[0x4]; // 0x234
		float cutEfficiency; // 0x238
		char unk_023C[0x7C];// 0x23C
		boost::unordered_map<GameData*, float> limbCoverage;// 0x2B8
	};
}