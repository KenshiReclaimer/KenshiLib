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

namespace Kenshi
{
    class FactoryCallbackInterface
    {
    public:
        // VTable         : (none)
        // no_addr public virtual void factoryObjectCreatedCallback(class RootObject *);// vtable offset = 0x0
        // no_addr public void FactoryCallbackInterface(const class FactoryCallbackInterface &);
        FactoryCallbackInterface();// RVA = 0x3E4C40
        // no_addr public class FactoryCallbackInterface & operator=(const class FactoryCallbackInterface &);
    };

    class ContextMenuGUI;
    class RootObject;

    // TODO move?
    class ContextMenu : Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
    {
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
        // no_addr public void ContextMenu(const class ContextMenu &);
        ContextMenu();// RVA = 0x60CFB0
        ~ContextMenu();// RVA = 0x60D060
        void showContextMenu(bool, RootObject*);// RVA = 0x61F1C0
        bool isVisible();// RVA = 0x60A3C0
        void update();// RVA = 0x668830
        bool rightMouseActivated; // 0x0 Member
        lektor<int> orders; // 0x8 Member
        std::string contextMenuName; // 0x20 Member
        ContextMenuGUI* menuGUI; // 0x48 Member
        ContextMenuGUI* menuGUI2; // 0x50 Member
        void _destroyMenuGUICheck();// RVA = 0x624EC0
        bool delayedDestroyFlag; // 0x58 Member
        // no_addr public class ContextMenu & operator=(const class ContextMenu &);
        // no_addr public void * __vecDelDtor(unsigned int);
    };

    // TODO move?
    class SelectionBox : Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
    {
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
        Ogre::Vector2 startPos; // 0x0 Member
        Ogre::PlaneBoundedVolume volume; // 0x8 Member
        MyGUI::Widget* widget; // 0x30 Member
        bool active; // 0x38 Member
        void start(const Ogre::Vector2&);// RVA = 0x658660
        void update(const Ogre::Vector2&);// RVA = 0x658D30
        void cancel();// RVA = 0x658610
        bool isActive();// RVA = 0x658630
        bool contains(const Ogre::Vector3&, const Ogre::Vector3&, float);// RVA = 0x6586D0
        bool contains(const Ogre::AxisAlignedBox&);// RVA = 0x6586B0
        bool contains(const Ogre::Vector3&, float);// RVA = 0x658680
        // no_addr public void SelectionBox(const class SelectionBox &);
        SelectionBox();// RVA = 0x659DA0
        ~SelectionBox();// RVA = 0x6585C0
        // no_addr public class SelectionBox & operator=(const class SelectionBox &);
        // no_addr public void * __vecDelDtor(unsigned int);
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

    class PlayerInterface : FactoryCallbackInterface, Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL> >
    {
    public:
        // FactoryCallbackInterface offset = 0x0, length = 0x8
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
        // no_addr public void PlayerInterface(const class PlayerInterface &);
        PlayerInterface();// RVA = 0x65CC30
        ~PlayerInterface();// RVA = 0x6612E0
        CameraClass* getCamera();// RVA = 0x310790
        void playerSetup(CameraClass*);// RVA = 0x6587C0
        void clearAndReset();// RVA = 0x6605E0
        virtual void factoryObjectCreatedCallback(RootObject*);// RVA = 0x3D1D10// vtable offset = 0x0
        void setFaction(Faction*);// RVA = 0x668610
        Faction* getFaction();// RVA = 0x1F4B80
        bool setCurrentPlatoon(Platoon*);// RVA = 0x658900
        Platoon* getCurrentPlatoon();// RVA = 0x65B620
        RootObjectContainer* getCurrentActivePlatoon();// RVA = 0x65B810
        bool recruit(const lektor<Character*>&, bool);// RVA = 0x6659B0
        bool recruit(Character*, bool);// RVA = 0x53C050
        ActivePlatoon* createSquad();// RVA = 0x65AA10
        ActivePlatoon* getDeadSquad();// RVA = 0x65AA60
        const hand& getDeadSquadHandle();// RVA = 0x3331F0
        void update();// RVA = 0x667720
        void updateUT();// RVA = 0x65DFE0
        bool isBuildMode();// RVA = 0x3D3250
        void activateObjectPlacementMode(GameData*);// RVA = 0x3DF840
        // no_addr public void setTaskClickMode(enum TaskType, enum itemType);
        void activateCharacterEditMode(Character*);// RVA = 0x659770
        bool triggerAreaArrivalDialogue(GameData*);// RVA = 0x665F40
        void setCharacterEditMode(bool);// RVA = 0x65A840
        bool getCharacterEditMode();// RVA = 0x485360
        void unselectAll();// RVA = 0x65EEA0
        void selectAll();// RVA = 0x65EE00
        void selectObject(RootObject*, bool);// RVA = 0x65F100
        void selectPlayerCharacter(int, bool, bool);// RVA = 0x65F1B0
        void _selectPlayerCharacter(RootObject*, bool, bool);// RVA = 0x65F060
        void activateSelection(RootObject*);// RVA = 0x65AED0
        const Ogre::Vector3 getCameraCenter();// RVA = 0x658A60
        float getDistanceFromCamera(const Ogre::Vector3&);// RVA = 0x658A90
        float getSquaredDistanceFromCamera(const Ogre::Vector3&);// RVA = 0x658B20
        void startTrackCharacter(RootObject*);// RVA = 0x65B500
        void stopTrackCharacter();// RVA = 0x658880
        bool isTrackingCharacter();// RVA = 0x6588E0
        void focusCamera(const Ogre::Vector3&);// RVA = 0x658BB0
        void manuallyOrientCamera(const Ogre::Quaternion&, float);// RVA = 0x658BC0
        void focusCameraSelectedCharacter();// RVA = 0x6598F0
        void toggleLevelEditorOnSelectedTown();// RVA = 0x659820
        bool isLevelEditMode();// RVA = 0x9BAF0
        bool isObjectPlacementMode();// RVA = 0x5FCE80
        void setOrderSelectedCharacters(MessageForB::StandingOrder);// RVA = 0x659980
        LevelEditor* getLevelEditor();// RVA = 0x3E4CE0
        void objectSelected(RootObject*, bool);// RVA = 0x65E020
        void toggleObjectSelected(RootObject*);// RVA = 0x65E510
        bool isObjectSelected(RootObject*);// RVA = 0x65AE20
        void unselectPlayerCharacter(RootObject*);// RVA = 0x65E550
        void updatePlayerSelection(const hand&, const hand&);// RVA = 0x65D210
        int getCurrentFloor();// RVA = 0x108A50
        void setCurrentFloor(int);// RVA = 0x659630
        void getAllSelectedObjects(lektor<RootObject*>&, itemType);// RVA = 0x65C8C0
        Character* getNearestSelectedCharacterTo(const Ogre::Vector3&);// RVA = 0x65ACA0
        Character* getNearestCharacterTo(const Ogre::Vector3&);// RVA = 0x659070
        void newPlayerTaskSelectedCharacters(TaskType, const hand&, Building*, const Ogre::Vector3&, bool);// RVA = 0x660750
        bool getPlayerTaskProbability(TaskType, RootObject*, float&);// RVA = 0x65C6E0
        void addOrderSelectedCharacters(Building*, TaskType, RootObject*, bool, bool, const Ogre::Vector3&);// RVA = 0x65FF20
        void addJobSelectedCharacters(TaskType, RootObject*, bool, bool, const Ogre::Vector3&);// RVA = 0x65BB90
        void removeJobSelectedCharacters(TaskType);// RVA = 0x65BD80
        void removePermaJobSelectedCharacters(int);// RVA = 0x65BEF0
        bool selectedCharactersUnconcious(bool);// RVA = 0x65D050
        bool selectedCharactersLayingLow();// RVA = 0x659B20
        void useSpeedGroup(bool);// RVA = 0x660B70
        void assignSpeedGroup(bool);// RVA = 0x65F8C0
        bool isEnemy(Character*);// RVA = 0x6151E0
        bool isFactionKnown(Faction*);// RVA = 0x65ABC0
        void encounterFaction(Faction*);// RVA = 0x65DF90
        void pickupItem(Item*);// RVA = 0x6614A0
        void cycleSquad();// RVA = 0x65C480
        void cycleCharacter(int);// RVA = 0x65F230
        void stopCharactersMovement();// RVA = 0x65C570
        Character* getAnyPlayerCharacter();// RVA = 0x658D10
        void getAllPlayerCharacters(lektor<RootObject*>&);// RVA = 0x6585A0
        const lektor<Character*>& getAllPlayerCharacters();// RVA = 0x658590
        bool isOrderValidForSelection(TaskType);// RVA = 0x6584B0
        void serialise(GameData*);// RVA = 0x659F60
        void loadFromSerialise(GameData*);// RVA = 0x65A0B0
        bool getInteriorsVisible(Building*);// RVA = 0x658500
        std::string factionName; // 0x8 Member
        CameraClass* camera; // 0x30 Member
        Research* technology; // 0x38 Member
        bool selectedObjectsChangedThisFrame; // 0x40 Member
        ContextMenu contextMenu; // 0x48 Member
        SelectionBox selectBox; // 0xA8 Member
        MoveMarker* moveMarker; // 0xE8 Member
        hand selectedCharacter; // 0xF0 Member
        void setVisibilityForReflections(bool);// RVA = 0x65C1D0
        class AIOptions
        {
        public:
            AIOptions();// RVA = 0x668840
            void load(GameData*);// RVA = 0x315680
            void save(GameData*);// RVA = 0x314E40
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
        AIOptions aiOptions; // 0x110 Member
        // Typedef        : ZoneMapFloorMap
        // Typedef        : BuildingInteriorSet
        // Typedef        : TownsSet
        void updateFloorVisibility(const lektor<Character*>&);// RVA = 0x65D330
        void resetFloorsVisibility();// RVA = 0x659AC0
        void setFloorsVisibility(int);// RVA = 0x659A40
        void addTaskNearestSelectedCharacter(Building*, TaskType, RootObject*, bool, const Ogre::Vector3&, bool);// RVA = 0x660F70
        void updateLastMoveWaypointSelectedCharacters(const Ogre::Vector3&, Building*);// RVA = 0x65C050
        void clearSelection();// RVA = 0x659C50
        void playerControl(InputHandler&);// RVA = 0x667000
        void mouseScan();// RVA = 0x666350
        // no_addr private void itemInsideScan(class RootObject * &, class Building *, const class Ogre::Ray &);
        // no_addr private void characterInsideScan(class RootObject * &, class Building *, const class Ogre::Ray &);
        void characterSelected(Character*);// RVA = 0x661510
        void itemSelected(Item*);// RVA = 0x662540
        bool buildingSelected(Building*, const Ogre::Vector3&, bool);// RVA = 0x6627E0
        void playerMove(const Ogre::Vector3&, Building*);// RVA = 0x660950
        bool _isPlayerCharacter(RootObject*);// RVA = 0x658540
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
        // no_addr public class PlayerInterface & operator=(const class PlayerInterface &);
        // no_addr public void * __vecDelDtor(unsigned int);
    };
};
