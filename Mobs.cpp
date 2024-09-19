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

int Mobs::CalculDistance(Vector2 pos)
{
	return  (pos.GetVector()[0] - player->GetPosition().GetVector()[0]) + (pos.GetVector()[1] - player->GetPosition().GetVector()[1]);
}

Player* Mobs::GetPlayer()
{
	return player;
}

void Mobs::SetPlayer(Player* pl)
{
	player = pl;
}

