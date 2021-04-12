#include <kenshi/Kenshi.h>

#include <kenshi/GameWorld.h>
#include <kenshi/PlayerInterface.h>

#include <core/RVA.h>
#include <cassert>

/**
 * Kenshi.cpp
 * 
 * This file will house the majority if not all memory-related actions to act as one centralized file that needs to be updated for new versions as they come out.
 * 
 * Kenshi v1.0.51
 * 
 */


Kenshi::GameWorld& Kenshi::GetGameWorld()
{
    static RVAPtr<GameWorld> c_inst(0x001AAE060);
    return *c_inst.GetPtr();
}

#if 0
Kenshi::PlayerInterface& Kenshi::GetPlayerInterface()
{
   return *Kenshi::GetGameWorld().player_interface;
}
#endif