#include "Mobs.h"
#include "Player.h"
#include "StateManager.h"

bool Mobs::ControlDistance()
{
    if (GetDistance() < detection)
        return true;
    else
        return false;
}
