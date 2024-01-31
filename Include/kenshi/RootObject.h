#pragma once

#include <ogre/OgreString.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>
#include "util/hand.h"
#include "util/lektor.h"
#include "GameData.h"

namespace Kenshi
{
    class SensoryData;
    class StateBroadcastData;
    class Faction;
    class RootObjectContainer;
    class Ownerships;
    class DatapanelGUI;
    class Damages;
    class CombatTechniqueData;
    class InventoryLayout;
    class PlatoonAI;
    class InstanceID;

    // TODO move?
    class EffectType
    { 
    public:
        enum Enum
        {
            NONE = 0x0,
            CAMERA = 0x1,
            POINT = 0x2,
            WANDERING = 0x3,
            GLOBAL = 0x4,
            CAMERA_RAIN = 0x5,
            CAMERA_ACID_RAIN = 0x6,
            POINT_LIGHTING = 0x7,
            WANDERING_STORM = 0x8,
            WANDERING_GAS = 0x9,
            GLOBAL_POINT = 0xA
        };
    };
    // TODO move?
    class StringPair
    {
        // no_addr public void StringPair(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, float);
        // no_addr public void StringPair(const class std::basic_string<char,std::char_traits<char>,std::allocator<char> > &, float);
    public:
        StringPair(const std::string& a, const std::string& b);// RVA = 0xAC0A0
        StringPair(const StringPair& a);// RVA = 0x229790
        StringPair(const std::string& a);// RVA = 0xAC790
        StringPair();// RVA = 0xAC710
        virtual ~StringPair();// RVA = 0xAA880// vtable offset = 0x0
        std::string s1; // 0x8 Member
        std::string s2; // 0x30 Member
        float val1; // 0x58 Member
        virtual const StringPair& operator=(const StringPair&);// RVA = 0xAC810// vtable offset = 0x8
        // no_addr public void __local_vftable_ctor_closure();
        // no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };
    // TODO move?
    class MessageForB
    {
    public:
        enum MessageType
        {
            M_UNSELECT_ALL = 0x0,
            M_GIVE_TASK = 0x1
        };

        enum StandingOrder
        {
            M_SET_ORDER_RUN = 0x0,
            M_SET_ORDER_JOG = 0x1,
            M_SET_ORDER_WALK = 0x2,
            M_SET_ORDER_STEALTH_ON = 0x3,
            M_SET_ORDER_STEALTH_OFF = 0x4,
            M_SET_ORDER_AGG = 0x5,
            M_SET_ORDER_DEF = 0x6,
            M_SET_ORDER_EVADE = 0x7,
            M_SET_ORDER_FAR = 0x8,
            M_SET_ORDER_NEAR = 0x9,
            M__TOGGLEORDERS__AFTER__THIS_ = 0xA,
            M_SET_ORDER_DEFENSIVE_COMBAT = 0xB,
            M_SET_ORDER_HOLD = 0xC,
            M_SET_ORDER_PASSIVE = 0xD,
            M_SET_ORDER_TAUNT = 0xE,
            M_SET_ORDER_CHASE = 0xF,
            M_SET_ORDER_GROUP_SPEED = 0x10,
            M_SET_ORDER_RANGED = 0x11
        };

        // no_addr public void MessageForB(enum MessageForB::MessageType, int);
        // no_addr public void MessageForB(enum MessageForB::StandingOrder);
        MessageForB::MessageType messageType; // 0x0 Member
        int messageInt; // 0x4 Member
    };

    // TODO move?
    class GameSaveState
    {
    public:
        GameSaveState(const GameSaveState&);// RVA = 0xAE220
        GameSaveState(GameDataContainer*, GameData*, GameData*, const PosRotPair&, PosRotPair*, InstanceID*);// RVA = 0x2C2460
        GameSaveState();// RVA = 0x94530
        void generateNewInstanceID();// RVA = 0x2C1FD0
        void createFromSerialisedInstanceData(GameDataContainer*, GameData::ObjectInstance*, const std::string&);// RVA = 0x2AD340
        std::string generateStateID(itemType);// RVA = 0x2121A0
        GameData* createState(itemType);// RVA = 0x2C2BA0
        void addState(GameData*);// RVA = 0x212270
        bool hasState(itemType);// RVA = 0xAC860
        GameData* getState(itemType);// RVA = 0xADB00
        int numStates();// RVA = 0x2BC2B0
        // no_addr public void clearStates();
        // no_addr public enum itemType getObjectType();
        Ogre::Vector3 getPos();// RVA = 0x2BA9E0
        Ogre::Quaternion getRot();// RVA = 0x2BAA00
        InstanceID getInstanceID();// RVA = 0x454D80
        const boost::unordered::unordered_map<itemType, GameData*, boost::hash<itemType>, std::equal_to<itemType>, Ogre::STLAllocator<std::pair<itemType const, GameData*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > >& getAllStates();// RVA = 0x565150
        GameData* baseData; // 0x0 Member
        GameDataContainer* dataSource; // 0x8 Member
        bool firstTime; // 0x10 Member
        operator bool();// RVA = 0x2BAA20
        // no_addr public const class GameSaveState & operator=(const class GameSaveState &);
        GameData::ObjectInstance* instance; // 0x18 Member
        GameData* getTheInstancesData();// RVA = 0x2BAA40
        Ogre::Vector3 pos; // 0x20 Member
        Ogre::Quaternion rot; // 0x2C Member
        std::string instanceID; // 0x40 Member
        boost::unordered::unordered_map<itemType, GameData*, boost::hash<itemType>, std::equal_to<itemType>, Ogre::STLAllocator<std::pair<itemType const, GameData*>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > states; // 0x68 Member
        ~GameSaveState();// RVA = 0x945E0
        // no_addr public void * __vecDelDtor(unsigned int);
    };

    class RootObjectBase
    {
    public:
        int validKey; // 0x8 Member
        // no_addr public void RootObjectBase(const class RootObjectBase &);
        // void __fastcall RootObjectBase::RootObjectBase(RootObjectBase *this, GameData *d, Faction *ownr, hand h)
        RootObjectBase(GameData* d, Faction* ownr, hand h);// RVA = 0x46DF80
        virtual ~RootObjectBase();// RVA = 0x46EDB0// vtable offset = 0x0
        bool isValid();// RVA = 0x27A000
        virtual std::string getName();// RVA = 0x92B60// vtable offset = 0x8
        virtual void setName(const std::string&);// RVA = 0x92D80// vtable offset = 0x10
        virtual GameData* getGameData();// RVA = 0x910B0// vtable offset = 0x18
        virtual enum itemType getDataType();// RVA = 0x46DD00// vtable offset = 0x20
        virtual bool typeIsAnItem();// RVA = 0x910C0// vtable offset = 0x28
        virtual bool isUnconcious();// RVA = 0x91100// vtable offset = 0x30
        virtual Ogre::Vector3 getPositionForWaypoint(const Ogre::Vector3&);// RVA = 0x91110// vtable offset = 0x38
        virtual Ogre::Vector3 getPosition();// RVA = 0x91130// vtable offset = 0x40
        virtual float getMovementSpeed();// RVA = 0x91150// vtable offset = 0x48
        virtual Ogre::Vector3 getMovementDirection();// RVA = 0x91160// vtable offset = 0x50
        virtual Faction* getFaction();// RVA = 0x46E040// vtable offset = 0x58
        bool hasFaction();// RVA = 0x46E0F0
        virtual int getFloor();// RVA = 0x46EE00// vtable offset = 0x60
        virtual SensoryData* getSensoryData();// RVA = 0x91180// vtable offset = 0x68
        virtual StateBroadcastData* getStateBroadcast();// RVA = 0x91190// vtable offset = 0x70
        virtual TownBase* getCurrentTownLocation();// RVA = 0x911A0// vtable offset = 0x78
        const hand& getHandle();// RVA = 0x7C290
        virtual void setHandle(const hand&);// RVA = 0x911B0// vtable offset = 0x80
        // these two don't have implementations
        virtual GameSaveState serialise(GameDataContainer*, GameData*, PosRotPair*);// vtable offset = 0x88
        virtual void loadFromSerialise(GameSaveState*);// vtable offset = 0x90
        virtual Ownerships* getOwnerships();// RVA = 0x911D0// vtable offset = 0x98
        // no_addr public bool operator==(const class hand &);
        // no_addr public bool operator!=(const class hand &);
        Faction* owner; // 0x10 Member
        virtual void setFaction(Faction*, ActivePlatoon*);// RVA = 0x46EE10// vtable offset = 0xA0
        std::string displayName; // 0x18 Member
        GameData* data; // 0x40 Member
        Ogre::Vector3 pos; // 0x48 Member
        hand handle; // 0x58 Member
        // no_addr public class RootObjectBase & operator=(const class RootObjectBase &);
        // no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };
    // TODO
    enum CutDirection {};
    enum WeatherDirection {};
    enum HitMaterialType {};
    enum WeatherAffecting {};
    class InstanceID;
    class ZoneMap;
    class RaceData;
    class Inventory;
    class RootObject : RootObjectBase
    {
        // RootObjectBase offset = 0x0, length = 0x78
        // no_addr public void RootObject(const class RootObject &);
    public:
        // void __fastcall RootObject::RootObject(RootObject *this, GameData *d, Faction *ownr, hand _h)
        RootObject(GameData* d, Faction* ownr, hand _h);// RVA = 0x46E200
        virtual ~RootObject();// RVA = 0x46E340// vtable offset = 0x0
        virtual bool needsSaving(const std::string&);// RVA = 0x911E0// vtable offset = 0xA8
        virtual InstanceID* getInstanceID();// RVA = 0x911F0// vtable offset = 0xB0
        virtual const std::string& getLayoutInstanceID();// RVA = 0x91200// vtable offset = 0xB8
        virtual Ogre::Quaternion getOrientation();// RVA = 0x91210// vtable offset = 0xC0
        virtual ZoneMap* getZoneMapLocation();// RVA = 0x46DD10// vtable offset = 0xC8
        virtual RaceData* getRace();// RVA = 0x91240// vtable offset = 0xD0
        // no_addr public class Ogre::Matrix3 getMatrix();
        virtual void threadedUpdate();// RVA = 0x91250// vtable offset = 0xD8
        virtual void update();// RVA = 0x46DC80// vtable offset = 0xE0
        virtual void periodicUpdate();// RVA = 0x46DCF0// vtable offset = 0xE8
        virtual const struct Ogre::Aabb& getAABB();// RVA = 0x91260// vtable offset = 0xF0
        // no_addr
        virtual bool isPhysical();// vtable offset = 0xF8
        virtual void setVisible(bool);// vtable offset = 0x100
        virtual bool getVisible();// RVA = 0x93BD0// vtable offset = 0x108
        virtual bool isDisabled();// RVA = 0x91270// vtable offset = 0x110
        virtual void setFaction(Faction*, ActivePlatoon*);// RVA = 0x46DDE0// vtable offset = 0x0
        virtual int amInsideTownWalls();// RVA = 0x46E1B0// vtable offset = 0x118
        virtual void setInsideTownWalls(int);// RVA = 0x91280// vtable offset = 0x120
        virtual int getFloor();// RVA = 0x91290// vtable offset = 0x0
        virtual void setFloor(int);// RVA = 0x912A0// vtable offset = 0x128
        virtual void select();// RVA = 0x912B0// vtable offset = 0x130
        virtual void unselect();// RVA = 0x912C0// vtable offset = 0x138
        virtual void getGUIData(DatapanelGUI*, int);// RVA = 0x93BE0// vtable offset = 0x140
        virtual void getGUIDataCategories(lektor<StringPair>&);// RVA = 0x912D0// vtable offset = 0x148
        virtual void setStandingOrder(MessageForB::StandingOrder);// RVA = 0x912E0// vtable offset = 0x150
        virtual void getOrders(lektor<std::string >&);// RVA = 0x912F0// vtable offset = 0x158
        virtual Inventory* getInventory();// RVA = 0x2C9AF0// vtable offset = 0x160
        virtual bool giveItem(Item*, bool, bool);// RVA = 0x46DB40// vtable offset = 0x168
        virtual bool hasRoomForItem(GameData*);// RVA = 0x46DBC0// vtable offset = 0x170
        virtual bool hasItem(GameData*);// RVA = 0x46DC20// vtable offset = 0x178
        virtual InventoryLayout* createInventoryLayout();// RVA = 0x91300// vtable offset = 0x180
        virtual bool ImStealingDoYouNotice(RootObject*);// RVA = 0x91310// vtable offset = 0x188
        virtual bool stolenGoodsDetectionCheck(Item*, RootObject*);// RVA = 0x91320// vtable offset = 0x190
        virtual void equipItem(const std::string&, Item*);// RVA = 0x91330// vtable offset = 0x198
        virtual void unequipItem(const std::string&, Item*);// RVA = 0x91340// vtable offset = 0x1A0
        virtual void dropItem(RootObject*);// RVA = 0x91350// vtable offset = 0x1A8
        virtual bool takeMoney(int);// RVA = 0x91360// vtable offset = 0x1B0
        virtual int getMoney();// RVA = 0x91370// vtable offset = 0x1B8
        virtual void say(const std::string&);// RVA = 0x91380// vtable offset = 0x1C0
        virtual void notifyIndoors(const hand&);// RVA = 0x46DC90// vtable offset = 0x1C8
        virtual void notifyOutdoors();// RVA = 0x46DCD0// vtable offset = 0x1D0
        virtual const hand& isIndoors();// RVA = 0x91390// vtable offset = 0x1D8
        virtual bool isOnARoof();// RVA = 0x913A0// vtable offset = 0x1E0
        virtual float getIntendedAggression();// RVA = 0x913B0// vtable offset = 0x1E8
        virtual HitMaterialType hitByMeleeAttack(CutDirection, Damages&, Character*, CombatTechniqueData*, int);// RVA = 0x913C0// vtable offset = 0x1F0
        virtual PlatoonAI* getPlatoonAI();// RVA = 0x913D0// vtable offset = 0x1F8
        // no_addr
        virtual bool createPhysical();// vtable offset = 0x200
        virtual void destroyPhysical();// vtable offset = 0x208
        virtual void setIsInsideBuilding(const hand&);// RVA = 0x913E0// vtable offset = 0x210
        virtual void notifyEffect(EffectType::Enum, WeatherAffecting, float);// RVA = 0x91410// vtable offset = 0x218
        RootObjectContainer* container; // 0x78 Member
        hand isInsideBuilding; // 0x80 Member
        int isInsideTownWalls; // 0xA0 Member
        int floorNum; // 0xA4 Member
        unsigned int spacialKey; // 0xA8 Member
        int outdoorDelayNotification_timer; // 0xAC Member
        Ogre::Quaternion rot; // 0xB0 Member
        /* protected */ virtual void loadUnloadCheck();// RVA = 0x46DD50// vtable offset = 0x220
        // no_addr public class RootObject & operator=(const class RootObject &);
        // no_addr public virtual void * __vecDelDtor(unsigned int);// vtable offset = 0x0
    };

    /*
    struct RootObjectBase
    {

        virtual ~RootObjectBase();

        virtual Ogre::String& GetState();
        virtual void SetState(const Ogre::String& state);
        virtual void GetVirtualProcessorRoot(); // ?GetVirtualProcessorRoot@UMSThreadProxy@details@Concurrency@@QEAAPEAVUMSFreeVirtualProcessorRoot@23@XZ ; Concurrency::details::UMSThreadProxy::GetVirtualProcessorRoot(void)
        virtual void sub_7FF7F0DB6C80();
        virtual void sub_7FF7F09E10C0();
        virtual void sub_7FF7F09E1100();
        virtual void unknown_libname_373(); //; Microsoft VisualC v7/14 64bit runtime
        virtual void sub_7FF7F09E1130();
        virtual void sub_7FF7F09E1150();
        virtual void sub_7FF7F09E1160();
        virtual void sub_7FF7F0DB6FC0(); // ; #STR: "nofac"
        virtual long GetSchedulerId();
        virtual void sub_7FF7F09E1180();
        virtual void sub_7FF7F09E1190();
        virtual void sub_7FF7F09E11A0();
        virtual void sub_7FF7F09E11B0();
        virtual void sub_7FF7F0F15550();
        virtual void sub_7FF7F0F15550_1();
        virtual void sub_7FF7F09E11D0();
        virtual void sub_7FF7F0DB7D90();
    };
    struct RootObject : public RootObjectBase
    {

    };

    struct RootObjectSimple : public RootObject
    {
    public:

        static RootObjectSimple* Instance();
    };
    */
}

