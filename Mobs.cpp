#include "Mobs.h"
#include "Player.h"
#include "StateManager.h"




void Mobs::Initialize()
{
	stateManager = new StateManager();
	stateManager->SetMonster(this);
	stateManager->Initialize();
}


void Mobs::Play() {
	stateManager->EnterState();
}

bool Mobs::ControlDistance()
{
	if (GetDistance() < detection)
		return true;
	else
		return false;
}

int Mobs::GetDistance()
{
	int player_x = std::get<0>(player->GetPosition());
	int player_y = std::get<1>(player->GetPosition());
	return  std::get<0>(GetPosition()) - player_x + std::get<1>(GetPosition()) - player_y;
}

int Mobs::CalculDistance(std::tuple<int, int> pos)
{
	int distance_x = std::get<0>(player->GetPosition()) - std::get<0>(pos);
	if (distance_x < 0)
		distance_x *= -1;
	
	int distance_y = std::get<1>(player->GetPosition()) - std::get<1>(pos);
	if (distance_y < 0)
		distance_y *= -1;
	int distance = distance_x+distance_y;
	return distance;
}

Player* Mobs::GetPlayer()
{
	return player;
}

void Mobs::SetPlayer(Player* pl)
{
	player = pl;
}

