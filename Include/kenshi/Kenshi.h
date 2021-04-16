#pragma once
#include "mygui/MyGUI_Gui.h"


namespace Kenshi 
{


    struct GameWorld;
    struct PlayerInterface;
    struct Character;
    struct Building;
    struct Renderer;
    struct PhysicsActual;
    struct ModInfo;
    struct Character;
    struct Building;
    struct ZoneManager;
    struct AudioSystemGlobal;
    struct Alarm;
    struct PlayerInterface;
    struct ResearchManager;
    struct ResearchItem;

    MyGUI::WidgetPtr FindWidget(MyGUI::EnumeratorWidgetPtr enumerator, std::string name);

    GameWorld& GetGameWorld();
    // GameWorld looks to be an object of all game state, whether its loaded or not.
    // Has things like a list of loaded mods and all the GameData loaded in, probably saves too.

}