#pragma once


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

    GameWorld& GetGameWorld();
    // GameWorld looks to be an object of all game state, whether its loaded or not.
    // Has things like a list of loaded mods and all the GameData loaded in, probably saves too.

}