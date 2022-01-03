#pragma once

#include <string>
#include <stdint.h>

namespace Kenshi 
{
	class GameData;
	// LockedArmour extends Armour
	// Armour extends Gear
	// Sword extends Weapon
	// Crossbow extends Weapon
	// Weapon extends Gear
	// RobotItem extends Gear
	// Gear extends Item
	// NestItem extends Item
	// BlueprintItem extends Item
	// MapItem extends Item - size might be 208?
	// MoneyItem extends Item - size is probably 1E8
	// ContainerItem extends Item, RaceLimiter (incomplete?)
	// ContainerItem_1 extends Item, RaceLimiter
	// Item extends InventoryItemBase
	// InventoryItemBase extends RootObject, Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0>>
	// RootObject extends RootObjectBase
	// RootObjectBase is base class
	// RootObject is probably 0xC0 bytes long
	class Item // not sure on size yet - somewhere between 0x198 and 0x1F0 (probably 1E8)
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
		char unk_0138[0xB8]; // 0x138
		// Item struct ends somewhere before/at 1E8
		int32_t value; // 0x1F0 - this appears to be from Gear, not Item
		char unk_01F4[0x34]; // 0x1F4
		float bloodLossMult;// 0x228
		int32_t attackBonus;// 0x22C
		char unk_0230[0x10]; //0x230
		float cutDamage; // 0x240
		float bluntDamage; // 0x244
		char unk_0248[4]; // 0x248
		int32_t defenceBonus; // 0x24C
		int32_t indoorsBonus; // 0x250
	};
}