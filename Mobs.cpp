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
	int player_x = GetPosition().GetVector()[0] - player->GetPosition().GetVector()[0];
	if (player_x < 0)
		player_x *= -1;
	int player_y = GetPosition().GetVector()[1] - player->GetPosition().GetVector()[1];
	if (player_y < 0)
		player_y *= -1;
	std::cout << player_x + player_y;
	return   player_x + player_y;
}

int Mobs::CalculDistance(Vector2 pos)
{
	int distance_x = player->GetPosition().GetVector()[0] - pos.GetVector()[0];
	if (distance_x < 0)
		distance_x *= -1;
	
	int distance_y = player->GetPosition().GetVector()[1] - pos.GetVector()[1];
	if (distance_y < 0)
		distance_y *= -1;
	return  distance_x + distance_y;
}

Player* Mobs::GetPlayer()
{
	return player;
}

void Mobs::SetPlayer(Player* pl)
{
	player = pl;
}

