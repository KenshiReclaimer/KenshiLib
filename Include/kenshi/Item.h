#pragma once

#include "RootObject.h"
#include "util/YesNoMaybe.h"
#include "TimeOfDay.h"

// TODO RobotLimbItem SeveredLimbItem NestItem BlueprintItem MapItem MoneyItem

// TODO move?
class iVector2
{
public:
	iVector2(int, int);// RVA = 0x2BB630
	iVector2();// RVA = 0xFEB00
	int x; // 0x0 Member
	int y; // 0x4 Member
	bool operator==(const iVector2&);// RVA = 0x2D53B0
	bool operator!=(const iVector2&);// RVA = 0x2D53D0
	int getLinearValue();// RVA = 0x2E6520
	bool operator<(const iVector2&);// RVA = 0x2E6530
	std::string getAsString();// RVA = 0x93300
	iVector2 operator+(const iVector2&);// RVA = 0x300150
};

class BuildingItemGroup;
class InventorySection;

class InventoryItemBase : public RootObject, Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
{
public:
	// RootObject offset = 0x0, length = 0xC0
	// Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0xC0, length = 0x1
	// no_addr public virtual void activate(bool, const class Ogre::Vector3 &, const class Ogre::Quaternion &, bool, class YesNoMaybe, bool);// vtable offset = 0x228
	// no_addr public virtual void activate(bool, class YesNoMaybe);// vtable offset = 0x230
	// no_addr public virtual void deactivate();// vtable offset = 0x238
	// no_addr public virtual void resetAfterCopy();// vtable offset = 0x240
	void resetCharges(bool);// RVA = 0x5DFAE0
	void getStolenItemGUIInfo(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x6194A0
	void getBuyBackGUIInfo(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x6199A0
	itemType getItemType();// RVA = 0x1FFBD0
	virtual float getItemWeightSingle();// RVA = 0x91420// vtable offset = 0x248
	virtual float getItemWeight();// RVA = 0x91430// vtable offset = 0x250
	// no_addr public virtual class GameData * _serialise(class GameDataContainer *, enum itemType);// vtable offset = 0x258
	// no_addr public virtual void _loadFromSerialise(class GameDataContainer *, class GameData *);// vtable offset = 0x260
	// no_addr public virtual class GameSaveState serialise(class GameDataContainer *, class GameData *, class PosRotPair *);// vtable offset = 0x0
	// no_addr public virtual void loadFromSerialise(class GameSaveState *);// vtable offset = 0x0
	// no_addr public virtual class GameData * serialiseInInventory(class GameDataContainer *, class GameData *);// vtable offset = 0x268
	// no_addr public virtual void loadFromSerialiseInInventory(class GameDataContainer *, class GameData *);// vtable offset = 0x270
	virtual void getTooltipData1(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x626730// vtable offset = 0x278
	virtual void getTooltipData2(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x617AD0// vtable offset = 0x280
	virtual void getGUIData(DatapanelGUI*, int);// RVA = 0x60D8C0// vtable offset = 0x0
	int getAvgPrice();// RVA = 0x609B70
	virtual int getValueSingle(bool);// RVA = 0x621590// vtable offset = 0x288
	virtual int getValueAll(bool);// RVA = 0x609BB0// vtable offset = 0x290
	virtual int getMaxAffordableNum(int, bool);// RVA = 0x5DFB30// vtable offset = 0x298
	int isStackable(InventorySection*);// RVA = 0x5E0600
	bool canStackWith(InventoryItemBase*);// RVA = 0x5DF9E0
	virtual Inventory* getInventory();// RVA = 0x5E8DB0// vtable offset = 0x0
	virtual bool isSameAs(InventoryItemBase*);// RVA = 0x5DFA80// vtable offset = 0x2A0
	bool onGround();// RVA = 0x2BAB10
	void addQuantity(int&, Item*, InventorySection*);// RVA = 0x5E0790
	virtual const hand& getProperOwner();// RVA = 0x91450// vtable offset = 0x2A8
	virtual void setProperOwner(const hand&);// RVA = 0x91460// vtable offset = 0x2B0
	bool isResearchArtifact();// RVA = 0x108A70
	virtual int getLevel();// RVA = 0x5E8DC0// vtable offset = 0x2B8
	GameData* manufacturerData; // 0xC0 Member
	GameData* materialData; // 0xC8 Member
	GameData* coloriseData; // 0xD0 Member
	bool isInInventory; // 0xD8 Member
	iVector2 inventoryPos; // 0xDC Member
	std::string inventorySection; // 0xE8 Member
	AttachSlot slotType; // 0x110 Member
	float originalFullChargeAmount; // 0x114 Member
	float chargesLeft; // 0x118 Member
	float quality; // 0x11C Member
	float weight; // 0x120 Member
	ItemFunction itemFunction; // 0x124 Member
	bool isTradeItem; // 0x128 Member
	bool isEquipped; // 0x129 Member
	bool isUnique; // 0x12A Member
	int quantity; // 0x12C Member
	int itemWidth; // 0x130 Member
	int itemHeight; // 0x134 Member
	bool deathItem; // 0x138 Member
	const char* getItemSound();// RVA = 0x5E08D0
	bool isStolen(bool);// RVA = 0x616B50
	// no_addr public void InventoryItemBase(const class InventoryItemBase &);
	InventoryItemBase(GameData*, hand, GameData*, GameData*);// RVA = 0x5E2060
	virtual ~InventoryItemBase();// RVA = 0x5E0010// vtable offset = 0x0
	void getTooltipTradeValue(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x616DA0
	float merchantPriceMod();// RVA = 0x616CD0
	itemType objectType; // 0x13C Member
	hand properOwner; // 0x140 Member
	hand _whosInventoryWeAreIn; // 0x160 Member
	bool _isResearchArtifact; // 0x180 Member
	BuildingItemGroup* itemGroup; // 0x188 Member
	// no_addr public class InventoryItemBase & operator=(const class InventoryItemBase &);
	// no_addr protected virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
};

class Gear;
class Crossbow;
class Armour;
class Weapon;
class LockedArmour;
class SimplePhysXEntity;

class Item : public InventoryItemBase
{
public:
	// InventoryItemBase offset = 0x0, length = 0x190
	static bool isFood(GameData*);// RVA = 0x29A330
	virtual Gear* isGear();// RVA = 0x91490// vtable offset = 0x2C0
	virtual itemType getClassType();// RVA = 0x914A0// vtable offset = 0x2C8
	virtual void resetAfterCopy();// RVA = 0x5DFC20// vtable offset = 0x0
	virtual void activate(bool, const Ogre::Vector3&, const Ogre::Quaternion&, bool, YesNoMaybe, bool);// RVA = 0x5DFF20// vtable offset = 0x0
	virtual void activate(bool, YesNoMaybe);// RVA = 0x5E0090// vtable offset = 0x0
	virtual void deactivate();// RVA = 0x5DFB90// vtable offset = 0x0
	virtual void setPositionRotation(const Ogre::Vector3&, const Ogre::Quaternion&, bool);// RVA = 0x5DFBD0// vtable offset = 0x2D0
	virtual Crossbow* isCrossbow();// RVA = 0x914B0// vtable offset = 0x2D8
	virtual Armour* isArmour();// RVA = 0x914C0// vtable offset = 0x2E0
	virtual Weapon* isWeapon();// RVA = 0x914D0// vtable offset = 0x2E8
	virtual LockedArmour* isLockedArmour();// RVA = 0x914E0// vtable offset = 0x2F0
	virtual Faction* isAFactionUniform();// RVA = 0x914F0// vtable offset = 0x2F8
	virtual bool isPhysical();// RVA = 0x91500// vtable offset = 0x0
	virtual void setVisible(bool);// RVA = 0x91520// vtable offset = 0x0
	virtual bool getVisible();// RVA = 0x91560// vtable offset = 0x0
	virtual std::string getModelName();// RVA = 0x5E2870// vtable offset = 0x300
	virtual Inventory* getInventory();// RVA = 0x91570// vtable offset = 0x0
	virtual bool hasIngredients();// RVA = 0x934B0// vtable offset = 0x308
	virtual bool isGoodFood();// RVA = 0x91580// vtable offset = 0x310
	virtual Ogre::Entity* getEntity();// RVA = 0x915B0// vtable offset = 0x318
	virtual TimeOfDay getTimeout();// RVA = 0x92200// vtable offset = 0x320
	virtual GameData* _serialise(GameDataContainer*, itemType);// RVA = 0x5E2F50// vtable offset = 0x0
	virtual void _loadFromSerialise(GameDataContainer*, GameData*);// RVA = 0x5E3AC0// vtable offset = 0x0
	virtual GameSaveState serialise(GameDataContainer*, GameData*, PosRotPair*);// RVA = 0x5E04A0// vtable offset = 0x0
	virtual void loadFromSerialise(GameSaveState*);// RVA = 0x5E0320// vtable offset = 0x0
	virtual GameData* serialiseInInventory(GameDataContainer*, GameData*);// RVA = 0x5DFC50// vtable offset = 0x0
	virtual void loadFromSerialiseInInventory(GameDataContainer*, GameData*);// RVA = 0x5DFC70// vtable offset = 0x0
	// no_addr public class Ogre::Entity * createPhysicalForInventoryIconPicture();
	virtual float getCraftTime();// RVA = 0x937B0// vtable offset = 0x328
	virtual float getCraftMaterialMult();// RVA = 0x915D0// vtable offset = 0x330
	virtual int getLevel();// RVA = 0x915E0// vtable offset = 0x0
	virtual void createItemEntityCallback_Equipping(Ogre::Entity*, Ogre::SceneNode*);// RVA = 0x915F0// vtable offset = 0x338
	virtual void destroyItemEntityCallback_Equipping();// RVA = 0x91600// vtable offset = 0x340
	virtual void notifyTheftFrom(RootObject*);// RVA = 0x60AD80// vtable offset = 0x348
	virtual void notifyTheftFrom(const hand&);// RVA = 0x60AE00// vtable offset = 0x350
	static const hand& findProperOwner(RootObject*);// RVA = 0x60AD10
	static const hand& findProperOwner(const hand&);// RVA = 0x60AC80
	virtual void setInventoryWeAreIn(const hand&);// RVA = 0x91610// vtable offset = 0x358
	const hand& getInventoryWeAreIn();// RVA = 0x46F940
	bool isPersistant();// RVA = 0x2BAB40
	void setPersistant(const hand&);// RVA = 0x752630
	void setPersistant(bool);// RVA = 0x2815A0
	bool persistantOwnerExists();// RVA = 0x2C2A80
	// no_addr public void Item(const class Item &);
	Item(GameData*, GameData*, GameData*, hand);// RVA = 0x5E25C0
	virtual ~Item();// RVA = 0x5E0280// vtable offset = 0x0
	virtual bool createPhysical();// RVA = 0x5E6510// vtable offset = 0x0
	virtual void destroyPhysical();// RVA = 0x5E0160// vtable offset = 0x0
	virtual void loadUnloadCheck();// RVA = 0x5E0B40// vtable offset = 0x0
	void createItemEntityCallback(Ogre::SharedPtr<Ogre::Resource>, void*);// RVA = 0x5E4C50
	virtual void itemEntityCreated(Ogre::Entity*);// RVA = 0x92210// vtable offset = 0x360
	bool physicalShouldExist; // 0x190 Member
	bool existAsBareWeapon; // 0x191 Member
	hand persistant; // 0x198 Member
	bool visible; // 0x1B8 Member
	SimplePhysXEntity* physical; // 0x1C0 Member
	bool _isPhysical; // 0x1C8 Member
	Ogre::Entity* physicalEntity; // 0x1D0 Member
	bool creatingPhysical; // 0x1D8 Member
	bool fixedPhysicalPosition; // 0x1D9 Member
	bool useDynamicPhysics; // 0x1DA Member
	Ogre::Entity* loadingEntity; // 0x1E0 Member
	// no_addr public class Item & operator=(const class Item &);
	// no_addr protected virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
};

class Gear : public Item
{
public:
	// Item offset = 0x0, length = 0x1E8
	// no_addr public void Gear(const class Gear &);
	Gear(GameData*, GameData*, GameData*, hand, int, Faction*);// RVA = 0x92140
	virtual Gear* isGear();// RVA = 0x92220// vtable offset = 0x0
	virtual float getLevel01();// RVA = 0x92230// vtable offset = 0x368
	virtual int getLevel();// RVA = 0x92240// vtable offset = 0x0
	virtual Faction* isAFactionUniform();// RVA = 0x92250// vtable offset = 0x0
	Faction* isUniform; // 0x1E8 Member
	int value; // 0x1F0 Member
	virtual GameData* _serialise(GameDataContainer*, itemType);// RVA = 0x5E4170// vtable offset = 0x0
	virtual void _loadFromSerialise(GameDataContainer*, GameData*);// RVA = 0x5E42F0// vtable offset = 0x0
	virtual void setInventoryWeAreIn(const hand&);// RVA = 0x92260// vtable offset = 0x0
	bool isPlayerCrafted();// RVA = 0x6E8C20
	std::string crafter; // 0x1F8 Member
	float level; // 0x220 Member
	int level_0_100; // 0x224 Member
	virtual ~Gear();// RVA = 0x92290// vtable offset = 0x0
	// no_addr public class Gear & operator=(const class Gear &);
	// no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
};

class Sword;
class Crossbow;

class Weapon : public Gear
{
public:
	// Gear offset = 0x0, length = 0x228
	virtual float getItemWeight();// RVA = 0x6E8BD0// vtable offset = 0x0
	virtual int getValueSingle(bool);// RVA = 0x6E8C30// vtable offset = 0x0
	WeaponCategory getCategory();// RVA = 0x4976D0
	WeaponCategory getCategory_animationOverride();// RVA = 0x40CAE0
	bool is2HandedOnly();// RVA = 0x46F950
	float getCombatWeight();// RVA = 0x6CD900
	virtual float getCraftTime();// RVA = 0x21AAC0// vtable offset = 0x0
	virtual float getCraftMaterialMult();// RVA = 0x6ECA30// vtable offset = 0x0
	// no_addr public virtual void getTooltipData1(class std::vector<StringPair,Ogre::STLAllocator<StringPair,Ogre::CategorisedAllocPolicy<0> > > &);// vtable offset = 0x0
	virtual Weapon* isWeapon();// RVA = 0x6E8BE0// vtable offset = 0x0
	virtual Sword* isSword();// RVA = 0x6E8BF0// vtable offset = 0x370
	virtual Crossbow* isCrossbow();// RVA = 0x6E8C00// vtable offset = 0x0
	float bleedDamage; // 0x228 Member
	int modAttack; // 0x22C Member
	virtual int getSkillModIndoors();// RVA = 0x6E8C10// vtable offset = 0x378
	// no_addr public void Weapon(const class Weapon &);
	Weapon(GameData*, GameData*, GameData*, hand, int);// RVA = 0x6E29D0
	virtual ~Weapon();// RVA = 0x6E8B70// vtable offset = 0x0
	float combatWeight; // 0x230 Member
	WeaponCategory category; // 0x234 Member
	WeaponCategory category_animationOverride; // 0x238 Member
	// no_addr public class Weapon & operator=(const class Weapon &);
	// no_addr protected virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
};

class Sword : Weapon
{
public:
	// Weapon offset = 0x0, length = 0x240
	// no_addr public void Sword(const class Sword &);
	Sword(GameData*, GameData*, GameData*, hand, int);// RVA = 0x6E2C80
	virtual itemType getClassType();// RVA = 0x6ECB40// vtable offset = 0x0
	virtual Sword* isSword();// RVA = 0x6ECB50// vtable offset = 0x0
	void setupStats(int, GameData*, GameData*, GameData*);// RVA = 0x6D3E70
	virtual void getTooltipData1(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x62B020// vtable offset = 0x0
	virtual void getTooltipData2(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x618480// vtable offset = 0x0
	float cutDamage; // 0x240 Member
	float bluntDamage; // 0x244 Member
	float minCutDamage; // 0x248 Member
	int modDefence; // 0x24C Member
	int modIndoors; // 0x250 Member
	virtual int getSkillModIndoors();// RVA = 0x6ECB60// vtable offset = 0x0
	virtual ~Sword();// RVA = 0x6ECB70// vtable offset = 0x0
	// no_addr public class Sword & operator=(const class Sword &);
	// no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
};

class GunClass;

class Crossbow : Weapon
{
public:
	// Weapon offset = 0x0, length = 0x240
	// no_addr public void Crossbow(const class Crossbow &);
	Crossbow(GameData*, hand, int);// RVA = 0x6E2E30
	virtual Crossbow* isCrossbow();// RVA = 0x6ECC50// vtable offset = 0x0
	virtual itemType getClassType();// RVA = 0x6ECC60// vtable offset = 0x0
	// no_addr public enum WeaponCategory getCategory();
	// no_addr public bool is2HandedOnly();
	virtual float getCraftMaterialMult();// RVA = 0x6ECC70// vtable offset = 0x0
	virtual float getCraftTime();// RVA = 0x21C4F0// vtable offset = 0x0
	float getRangeInUnits();// RVA = 0x34FDB0
	float getEquipPositionOffset();// RVA = 0x42D550
	virtual void getTooltipData1(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x628D50// vtable offset = 0x0
	virtual void getTooltipData2(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x618180// vtable offset = 0x0
	virtual void createItemEntityCallback_Equipping(Ogre::Entity*, Ogre::SceneNode*);// RVA = 0x357740// vtable offset = 0x0
	virtual void destroyItemEntityCallback_Equipping();// RVA = 0x350220// vtable offset = 0x0
	GunClass* gunClass; // 0x240 Member
	virtual void setVisible(bool);// RVA = 0x34FD60// vtable offset = 0x0
	virtual ~Crossbow();// RVA = 0x6ECC80// vtable offset = 0x0
	// no_addr public class Crossbow & operator=(const class Crossbow &);
	// no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
};

enum ArmourClass
{
	GEAR_CLOTH,
	GEAR_LIGHT,
	GEAR_MEDIUM,
	GEAR_HEAVY,
	GEAR_MAX
};

class Armour : Gear
{
public:
	// Gear offset = 0x0, length = 0x228
	virtual itemType getClassType();// RVA = 0x6EC7A0// vtable offset = 0x0
	virtual Armour* isArmour();// RVA = 0x6EC7B0// vtable offset = 0x0
	virtual float getItemWeight();// RVA = 0x6EC7C0// vtable offset = 0x0
	virtual int getValueSingle(bool);// RVA = 0x6EC7E0// vtable offset = 0x0
	virtual void getTooltipData1(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x619C50// vtable offset = 0x0
	virtual void getTooltipData2(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x61B9A0// vtable offset = 0x0
	bool didIHitFlesh(GameData*);// RVA = 0x510F00
	bool hasArmourCoverage();// RVA = 0x284420
	virtual float getCraftTime();// RVA = 0x6EC7D0// vtable offset = 0x0
	static float getArmourCraftingMaterialConsumptionRate(GameData*);// RVA = 0x21ABD0
	float cutResistance; // 0x228 Member
	float bluntResistance; // 0x22C Member
	float pierceResistance; // 0x230 Member
	float minCutResistance; // 0x234 Member
	float cutToStun; // 0x238 Member
	ArmourType materialType; // 0x23C Member
	ArmourClass armourClassEnum; // 0x240 Member
	CharacterTypeEnum stigma; // 0x244 Member
	float athleticsMult; // 0x248 Member
	int combatSkillBonusAttk; // 0x24C Member
	int combatSkillBonusDef; // 0x250 Member
	int perceptionBonus; // 0x254 Member
	float combatSpeedMult; // 0x258 Member
	float stealthMult; // 0x25C Member
	float assassinMult; // 0x260 Member
	float dexterityMult; // 0x264 Member
	float damageMult; // 0x268 Member
	float dodgeMult; // 0x26C Member
	int unarmedBonus; // 0x270 Member
	float fistInjuryMult; // 0x274 Member
	float weatherProtectionAmount; // 0x278 Member
	float rangedSkillMult; // 0x27C Member
	std::set<WeatherAffecting, std::less<WeatherAffecting>, Ogre::STLAllocator<WeatherAffecting, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > weatherProtections; // 0x280 Member
	// no_addr public float getWeatherProtection(enum WeatherAffecting, class GameData *);
	float getWeatherProtection_simple(WeatherAffecting);// RVA = 0x50F7E0
	// no_addr public void Armour(const class Armour &);
	Armour(GameData*, GameData*, hand, Faction*, int);// RVA = 0x6E3030
	virtual ~Armour();// RVA = 0x6EC6E0// vtable offset = 0x0
	boost::unordered::unordered_map<GameData*, float, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<std::pair<GameData* const, float>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > bodypartCoverage; // 0x2A8 Member
	float craftTime; // 0x2E8 Member
	// no_addr public class Armour & operator=(const class Armour &);
	// no_addr protected virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
};

class DoorLock;

class LockedArmour : Armour
{
public:
	// Armour offset = 0x0, length = 0x2F0
	// no_addr public void LockedArmour(const class LockedArmour &);
	LockedArmour(GameData*, GameData*, hand, Faction*, int);// RVA = 0x6E45E0
	virtual ~LockedArmour();// RVA = 0x6D1580// vtable offset = 0x0
	virtual Armour* isArmour();// RVA = 0x6EC8C0// vtable offset = 0x0
	virtual LockedArmour* isLockedArmour();// RVA = 0x6EC8D0// vtable offset = 0x0
	DoorLock* lock; // 0x2F0 Member
	virtual GameData* _serialise(GameDataContainer*, itemType);// RVA = 0x5E4410// vtable offset = 0x0
	virtual void _loadFromSerialise(GameDataContainer*, GameData*);// RVA = 0x5E44C0// vtable offset = 0x0
	virtual void getTooltipData1(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x61D4C0// vtable offset = 0x0
	virtual void getTooltipData2(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x6EC8E0// vtable offset = 0x0
	// no_addr public class LockedArmour & operator=(const class LockedArmour &);
	// no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
};

// TODO move?
class RaceLimiter
{
public:
	// VTable         : (none)
	class Limiter
	{
	public:
		// VTable         : (none)
		std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > racesExclude; // 0x8 Member
		std::set<RaceData*, std::less<RaceData*>, Ogre::STLAllocator<RaceData*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > racesInclude; // 0x30 Member
		virtual bool canEquip(RaceData*, bool);// RVA = 0x46D2B0// vtable offset = 0x0
		// no_addr public void Limiter(const class RaceLimiter::Limiter &);
		Limiter();// RVA = 0x46D150
		~Limiter();// RVA = 0x46C370
		// no_addr public class RaceLimiter::Limiter & operator=(const class RaceLimiter::Limiter &);
		// no_addr public void * __vecDelDtor(unsigned int);
	};
	boost::unordered::unordered_map<GameData*, RaceLimiter::Limiter, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<std::pair<GameData* const, RaceLimiter::Limiter>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > limits; // 0x8 Member
	static RaceLimiter* getSingleton();// RVA = 0x46DA80
	void addLimit(GameData*);// RVA = 0x5E56C0
	virtual bool canEquip(GameData*, RootObject*);// RVA = 0x5DFC90// vtable offset = 0x0
	virtual bool canEquip(GameData*, RaceData*, bool);// RVA = 0x46D970// vtable offset = 0x8
	// no_addr public void RaceLimiter(const class RaceLimiter &);
	RaceLimiter();// RVA = 0x46C960
	~RaceLimiter();// RVA = 0x5EB710
	// no_addr public class RaceLimiter & operator=(const class RaceLimiter &);
	// no_addr public void * __vecDelDtor(unsigned int);
};

class ContainerItem : Item, RaceLimiter
{
public:
	// Item offset = 0x0, length = 0x1E8
	// RaceLimiter offset = 0x1E8, length = 0x48
	virtual ~ContainerItem();// RVA = 0x5E5620// vtable offset = 0x0
	virtual itemType getClassType();// RVA = 0x5EB720// vtable offset = 0x0
	virtual bool canEquip(GameData*);// RVA = 0x5EB890// vtable offset = 0x368
	virtual void equipItem(const std::string&, Item*);// RVA = 0x5DFD20// vtable offset = 0x0
	virtual void unequipItem(const std::string&, Item*);// RVA = 0x5DFD50// vtable offset = 0x0
	virtual void dropItem(RootObject*);// RVA = 0x5DFD80// vtable offset = 0x0
	virtual bool takeMoney(int);// RVA = 0x5DFDB0// vtable offset = 0x0
	virtual int getMoney();// RVA = 0x5DFDE0// vtable offset = 0x0
	void doubleCheckHandle();// RVA = 0x5E0400
	virtual Ogre::Vector3 getPosition();// RVA = 0x5DFE10// vtable offset = 0x0
	virtual Inventory* getInventory();// RVA = 0x5EB730// vtable offset = 0x0
	virtual InventoryLayout* createInventoryLayout();// RVA = 0x5DFE60// vtable offset = 0x0
	virtual void getTooltipData1(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x622690// vtable offset = 0x0
	virtual void getTooltipData2(std::vector<StringPair, Ogre::STLAllocator<StringPair, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >&);// RVA = 0x6191D0// vtable offset = 0x0
	virtual GameData* _serialise(GameDataContainer*, itemType);// RVA = 0x5E4930// vtable offset = 0x0
	virtual void _loadFromSerialise(GameDataContainer*, GameData*);// RVA = 0x5E4990// vtable offset = 0x0
	virtual GameSaveState serialise(GameDataContainer*, GameData*, PosRotPair*);// RVA = 0x5E0580// vtable offset = 0x0
	virtual void loadFromSerialise(GameSaveState*);// RVA = 0x5E03C0// vtable offset = 0x0
	virtual void setProperOwner(const hand&);// RVA = 0x5EB750// vtable offset = 0x0
	RootObject* callbackOwner; // 0x230 Member
	float athleticsMult; // 0x238 Member
	float weightMult; // 0x23C Member
	float combatSpeedMult; // 0x240 Member
	int combatSkillBonus; // 0x244 Member
	float stealthMult; // 0x248 Member
	boost::unordered::unordered_set<GameData*, boost::hash<GameData*>, std::equal_to<GameData*>, Ogre::STLAllocator<GameData*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > racesExclude; // 0x250 Member
	// no_addr public void ContainerItem(const class ContainerItem &);
	ContainerItem(GameData*, GameData*, hand);// RVA = 0x5E5D80
	Inventory* inventory; // 0x290 Member
	// no_addr public class ContainerItem & operator=(const class ContainerItem &);
	// no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
};
