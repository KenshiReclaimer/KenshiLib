#pragma once

#include "util/lektor.h"
#include "util/hand.h"
#include "Enums.h"

#include <ogre/OgreVector2.h>
#include <ogre/OgrePlaneBoundedVolume.h>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>

namespace MyGUI
{
    class Widget;
};

class FactoryCallbackInterface
{
public:
    // VTable         : (none)
    virtual void factoryObjectCreatedCallback(RootObject*) = 0;// public vtable offset = 0x0
    // no_addr void FactoryCallbackInterface(const class FactoryCallbackInterface &);// public
    FactoryCallbackInterface();// public RVA = 0x3E4C40
    // no_addr class FactoryCallbackInterface & operator=(const class FactoryCallbackInterface &);// public
};

class ContextMenuGUI;
class RootObject;

// TODO move?
class ContextMenu : public Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    // no_addr void ContextMenu(const class ContextMenu &);// public
    ContextMenu();// public RVA = 0x60CFB0
    ~ContextMenu();// public RVA = 0x60D060
    void showContextMenu(bool on, RootObject* what);// public RVA = 0x61F1C0
    bool isVisible();// public RVA = 0x60A3C0
    void update();// public RVA = 0x668830
    bool rightMouseActivated; // 0x0 Member
    lektor<int> orders; // 0x8 Member
    std::string contextMenuName; // 0x20 Member
    ContextMenuGUI* menuGUI; // 0x48 Member
    ContextMenuGUI* menuGUI2; // 0x50 Member
    void _destroyMenuGUICheck();// private RVA = 0x624EC0
    bool delayedDestroyFlag; // 0x58 Member
    // no_addr class ContextMenu & operator=(const class ContextMenu &);// public
    // no_addr void * __vecDelDtor(unsigned int);// public
};

// TODO move?
class SelectionBox : public Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    Ogre::Vector2 startPos; // 0x0 Member
    Ogre::PlaneBoundedVolume volume; // 0x8 Member
    MyGUI::Widget* widget; // 0x30 Member
    bool active; // 0x38 Member
    void start(const Ogre::Vector2& m);// public RVA = 0x658660
    void update(const Ogre::Vector2& m);// public RVA = 0x658D30
    void cancel();// public RVA = 0x658610
    bool isActive();// public RVA = 0x658630
    bool contains(const Ogre::Vector3& a, const Ogre::Vector3& b, float radius);// public RVA = 0x6586D0
    bool contains(const Ogre::AxisAlignedBox& box);// public RVA = 0x6586B0
    bool contains(const Ogre::Vector3& point, float r);// public RVA = 0x658680
    // no_addr void SelectionBox(const class SelectionBox &);// public
    SelectionBox();// public RVA = 0x659DA0
    ~SelectionBox();// public RVA = 0x6585C0
    // no_addr class SelectionBox & operator=(const class SelectionBox &);// public
    // no_addr void * __vecDelDtor(unsigned int);// public
};

class CameraClass;
class LevelEditor;
class Research;
class MoveMarker;
class PlacementObject;
class Character;
class ZoneMap;
class TownBase;
class Faction;
class Platoon;
class GameData;
class InputHandler;
class Building;
class Item;
class RootObjectContainer;

class PlayerInterface : public FactoryCallbackInterface, public Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
{
public:
    // FactoryCallbackInterface offset = 0x0, length = 0x8
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // no_addr void PlayerInterface(const class PlayerInterface &);// public
    PlayerInterface();// public RVA = 0x65CC30
    ~PlayerInterface();// public RVA = 0x6612E0
    CameraClass* getCamera();// public RVA = 0x310790
    void playerSetup(CameraClass* cam);// public RVA = 0x6587C0
    void clearAndReset();// public RVA = 0x6605E0
    virtual void factoryObjectCreatedCallback(RootObject* building);// public RVA = 0x3D1D10 vtable offset = 0x0
    void setFaction(Faction* f);// public RVA = 0x668610
    Faction* getFaction();// public RVA = 0x1F4B80
    bool setCurrentPlatoon(Platoon* platoon);// public RVA = 0x658900
    Platoon* getCurrentPlatoon();// public RVA = 0x65B620
    RootObjectContainer* getCurrentActivePlatoon();// public RVA = 0x65B810
    bool recruit(const lektor<Character*>& characters, bool editor);// public RVA = 0x6659B0
    bool recruit(Character* character, bool editor);// public RVA = 0x53C050
    ActivePlatoon* createSquad();// public RVA = 0x65AA10
    ActivePlatoon* getDeadSquad();// public RVA = 0x65AA60
    const hand& getDeadSquadHandle();// public RVA = 0x3331F0
    void update();// public RVA = 0x667720
    void updateUT();// public RVA = 0x65DFE0
    bool isBuildMode();// public RVA = 0x3D3250
    void activateObjectPlacementMode(GameData* data);// public RVA = 0x3DF840
    // no_addr void setTaskClickMode(enum TaskType, enum itemType);// public
    void activateCharacterEditMode(Character* character);// public RVA = 0x659770
    bool triggerAreaArrivalDialogue(GameData* area);// public RVA = 0x665F40
    void setCharacterEditMode(bool on);// public RVA = 0x65A840
    bool getCharacterEditMode();// public RVA = 0x485360
    void unselectAll();// public RVA = 0x65EEA0
    void selectAll();// public RVA = 0x65EE00
    void selectObject(RootObject* obj, bool modifier);// public RVA = 0x65F100
    void selectPlayerCharacter(int index, bool modifier, bool track);// public RVA = 0x65F1B0
    void _selectPlayerCharacter(RootObject* obj, bool modifier, bool track);// public RVA = 0x65F060
    void activateSelection(RootObject* obj);// public RVA = 0x65AED0
    const Ogre::Vector3 getCameraCenter();// public RVA = 0x658A60
    float getDistanceFromCamera(const Ogre::Vector3& v);// public RVA = 0x658A90
    float getSquaredDistanceFromCamera(const Ogre::Vector3& v);// public RVA = 0x658B20
    void startTrackCharacter(RootObject* target);// public RVA = 0x65B500
    void stopTrackCharacter();// public RVA = 0x658880
    bool isTrackingCharacter();// public RVA = 0x6588E0
    void focusCamera(const Ogre::Vector3& pos);// public RVA = 0x658BB0
    void manuallyOrientCamera(const Ogre::Quaternion& rot, float zoom);// public RVA = 0x658BC0
    void focusCameraSelectedCharacter();// public RVA = 0x6598F0
    void toggleLevelEditorOnSelectedTown();// public RVA = 0x659820
    bool isLevelEditMode();// public RVA = 0x9BAF0
    bool isObjectPlacementMode();// public RVA = 0x5FCE80
    void setOrderSelectedCharacters(MessageForB::StandingOrder order);// public RVA = 0x659980
    LevelEditor* getLevelEditor();// public RVA = 0x3E4CE0
    void objectSelected(RootObject* obj, bool select);// public RVA = 0x65E020
    void toggleObjectSelected(RootObject* obj);// public RVA = 0x65E510
    bool isObjectSelected(RootObject* obj);// public RVA = 0x65AE20
    void unselectPlayerCharacter(RootObject* obj);// public RVA = 0x65E550
    void updatePlayerSelection(const hand& oldHandle, const hand& newHandle);// public RVA = 0x65D210
    int getCurrentFloor();// public RVA = 0x108A50
    void setCurrentFloor(int floor);// public RVA = 0x659630
    void getAllSelectedObjects(lektor<RootObject*>& out, itemType type);// public RVA = 0x65C8C0
    Character* getNearestSelectedCharacterTo(const Ogre::Vector3& pos);// public RVA = 0x65ACA0
    Character* getNearestCharacterTo(const Ogre::Vector3& pos);// public RVA = 0x659070
    void newPlayerTaskSelectedCharacters(TaskType t, const hand& targetH, Building* destinationIndoors, const Ogre::Vector3& clickpos, bool addDontClear);// public RVA = 0x660750
    bool getPlayerTaskProbability(TaskType task, RootObject* target, float& probability);// public RVA = 0x65C6E0
    void addOrderSelectedCharacters(Building* destinationIndoors, TaskType task, RootObject* subject, bool shift, bool addDontClear, const Ogre::Vector3& location);// public RVA = 0x65FF20
    void addJobSelectedCharacters(TaskType task, RootObject* subject, bool shift, bool add, const Ogre::Vector3& location);// public RVA = 0x65BB90
    void removeJobSelectedCharacters(TaskType t);// public RVA = 0x65BD80
    void removePermaJobSelectedCharacters(int id);// public RVA = 0x65BEF0
    bool selectedCharactersUnconcious(bool displayMessage);// public RVA = 0x65D050
    bool selectedCharactersLayingLow();// public RVA = 0x659B20
    void useSpeedGroup(bool use);// public RVA = 0x660B70
    void assignSpeedGroup(bool create);// public RVA = 0x65F8C0
    bool isEnemy(Character* who);// public RVA = 0x6151E0
    bool isFactionKnown(Faction* f);// public RVA = 0x65ABC0
    void encounterFaction(Faction* faction);// public RVA = 0x65DF90
    void pickupItem(Item* item);// public RVA = 0x6614A0
    void cycleSquad();// public RVA = 0x65C480
    void cycleCharacter(int d);// public RVA = 0x65F230
    void stopCharactersMovement();// public RVA = 0x65C570
    Character* getAnyPlayerCharacter();// public RVA = 0x658D10
    void getAllPlayerCharacters(lektor<RootObject*>& list);// public RVA = 0x6585A0
    const lektor<Character*>& getAllPlayerCharacters();// public RVA = 0x658590
    bool isOrderValidForSelection(TaskType task);// public RVA = 0x6584B0
    void serialise(GameData* data);// public RVA = 0x659F60
    void loadFromSerialise(GameData* data);// public RVA = 0x65A0B0
    bool getInteriorsVisible(Building* building);// public RVA = 0x658500
    std::string factionName; // 0x8 Member
    CameraClass* camera; // 0x30 Member
    Research* technology; // 0x38 Member
    bool selectedObjectsChangedThisFrame; // 0x40 Member
    ContextMenu contextMenu; // 0x48 Member
    SelectionBox selectBox; // 0xA8 Member
    MoveMarker* moveMarker; // 0xE8 Member
    hand selectedCharacter; // 0xF0 Member
    void setVisibilityForReflections(bool set);// public RVA = 0x65C1D0
    class AIOptions
    {
    public:
        AIOptions();// public RVA = 0x668840
        void load(GameData* data);// public RVA = 0x315680
        void save(GameData* data);// public RVA = 0x314E40
        bool healAllies; // 0x0 Member
        bool helpAllies; // 0x1 Member
        bool rescueAllies; // 0x2 Member
        bool stayInBase; // 0x3 Member
        bool feedAnimals; // 0x4 Member
        bool shareFood; // 0x5 Member
        bool autoSleep; // 0x6 Member
        bool autoDitchItems; // 0x7 Member
        bool autoSit; // 0x8 Member
        bool ejectEnemies; // 0x9 Member
        bool shootFirst; // 0xA Member
    };
    PlayerInterface::AIOptions aiOptions; // 0x110 Member
    // Typedef        : ZoneMapFloorMap
    // Typedef        : BuildingInteriorSet
    // Typedef        : TownsSet
    void updateFloorVisibility(const lektor<Character*>& characters);// private RVA = 0x65D330
    void resetFloorsVisibility();// private RVA = 0x659AC0
    void setFloorsVisibility(int floor);// private RVA = 0x659A40
    void addTaskNearestSelectedCharacter(Building* dest, TaskType t, RootObject* subject, bool shift, const Ogre::Vector3& location, bool noAnimals);// private RVA = 0x660F70
    void updateLastMoveWaypointSelectedCharacters(const Ogre::Vector3& location, Building* dest);// private RVA = 0x65C050
    void clearSelection();// private RVA = 0x659C50
    void playerControl(InputHandler& key);// private RVA = 0x667000
    void mouseScan();// private RVA = 0x666350
    // no_addr void itemInsideScan(class RootObject * &, class Building *, const class Ogre::Ray &);// private
    // no_addr void characterInsideScan(class RootObject * &, class Building *, const class Ogre::Ray &);// private
    void characterSelected(Character* target);// private RVA = 0x661510
    void itemSelected(Item* item);// private RVA = 0x662540
    bool buildingSelected(Building* building, const Ogre::Vector3& position, bool interiorsVisible);// private RVA = 0x6627E0
    void playerMove(const Ogre::Vector3& pos, Building* destBuilding);// private RVA = 0x660950
    bool _isPlayerCharacter(RootObject* obj);// private RVA = 0x658540
    boost::unordered::unordered_map<ZoneMap*, unsigned char, boost::hash<ZoneMap*>, std::equal_to<ZoneMap*>, Ogre::STLAllocator<std::pair<ZoneMap* const, unsigned char>, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > zonesVisibilities; // 0x120 Member
    boost::unordered::unordered_set<TownBase*, boost::hash<TownBase*>, std::equal_to<TownBase*>, Ogre::STLAllocator<TownBase*, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > townsActive; // 0x160 Member
    boost::unordered::unordered_set<hand, boost::hash<hand>, std::equal_to<hand>, Ogre::STLAllocator<hand, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > interiorsVisible; // 0x1A0 Member
    unsigned int interiorsVisibleHash; // 0x1E0 Member
    int currentFloor; // 0x1E4 Member
    TaskType currentMouseTask; // 0x1E8 Member
    itemType mouseTaskTypeRestriction; // 0x1EC Member
    bool mouseRightTargetSet; // 0x1F0 Member
    RootObject* mouseRightTarget; // 0x1F8 Member
    float rmouseTimer; // 0x200 Member
    boost::unordered::unordered_set<hand, boost::hash<hand>, std::equal_to<hand>, Ogre::STLAllocator<hand, Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> > > selectedCharacters; // 0x208 Member
    hand selectedObject; // 0x248 Member
    bool onlyAnimalsSelected; // 0x268 Member
    int selectedLoadedLeft; // 0x26C Member
    hand trackedCharacterHandle; // 0x270 Member
    int trackedCharacterFloor; // 0x290 Member
    LevelEditor* levelEditor; // 0x298 Member
    Faction* participant; // 0x2A0 Member
    Platoon* currentPlatoon; // 0x2A8 Member
    lektor<Character*> playerCharacters; // 0x2B0 Member
    hand deadPlayerSquad; // 0x2C8 Member
    PlacementObject* placementObject; // 0x2E8 Member
    bool characterEditorMode; // 0x2F0 Member
    bool mLeftUp; // 0x2F1 Member
    bool mLeftDown; // 0x2F2 Member
    bool mRightUp; // 0x2F3 Member
    bool mRightDown; // 0x2F4 Member
    // no_addr class PlayerInterface & operator=(const class PlayerInterface &);// public
    // no_addr void * __vecDelDtor(unsigned int);// public
};
