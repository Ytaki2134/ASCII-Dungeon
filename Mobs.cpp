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

int Mobs::GetDistance()
{ 
    return  (std::get<0>(GetPosition()) - std::get<0>(player->GetPosition())) + (std::get<1>(GetPosition()) - std::get<1>(player->GetPosition())); 
}

int Mobs::CalculDistance(std::tuple<int, int> pos) 
{
    return  (std::get<0>(pos) - std::get<0>(player->GetPosition())) + (std::get<1>(pos) - std::get<1>(player->GetPosition())); 
}

Player* Mobs::GetPlayer()
{
    return player;
}
