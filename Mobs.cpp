#include "Mobs.h"



bool Mobs::ControlDistance()
{
    if (GetDistance() < detection)
        return true;
    else
        return false;
}
