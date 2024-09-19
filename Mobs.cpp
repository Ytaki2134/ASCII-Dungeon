#include "Mobs.h"
#include "Player.h"
#include "StateManager.h"
#include "GameManager.h"




void Mobs::Initialize()
{
	stateManager = new StateManager();
	stateManager->SetMonster(this);
	stateManager->Initialize();
}

void Mobs::Move()
{
	srand(time(NULL));
	int direction = (rand() % 4) + 1;
	GameManager* gameManager = GameManager::get();

	switch (direction)
	{
	case 0:
		if (gameManager->TestPosition(Vector2(GetPosition().GetVector()[0] + 1, GetPosition().GetVector()[1])))
			SetPosition(GetPosition().GetVector()[0] + 1, GetPosition().GetVector()[1]);

	case 1:
		if (gameManager->TestPosition(Vector2(GetPosition().GetVector()[0] - 1, GetPosition().GetVector()[1])))
			SetPosition(GetPosition().GetVector()[0] - 1, GetPosition().GetVector()[1]);
		break;
	case 2:
		if (gameManager->TestPosition(Vector2(GetPosition().GetVector()[0], GetPosition().GetVector()[1] + 1)))
			SetPosition(GetPosition().GetVector()[0], GetPosition().GetVector()[1] + 1);
		break;
	case 3:
		if (gameManager->TestPosition(Vector2(GetPosition().GetVector()[0], GetPosition().GetVector()[1] - 1)))
			SetPosition(GetPosition().GetVector()[0], GetPosition().GetVector()[1] - 1);
		break;

	default:
		break;
	}
}

void Mobs::Chase()
{

	GameManager* gameManager = GameManager::get();
	Vector2 actualpos = GetPosition();
	Vector2 betterpos = Vector2(100, 100);

	Vector2 up = Vector2(GetPosition().GetVector()[0], GetPosition().GetVector()[1] + 1);
	Vector2 down = Vector2(GetPosition().GetVector()[0], GetPosition().GetVector()[1] - 1);
	Vector2 right = Vector2(GetPosition().GetVector()[0] + 1, GetPosition().GetVector()[1]);
	Vector2 left = Vector2(GetPosition().GetVector()[0] - 1, GetPosition().GetVector()[1]);


	int bestdist = CalculDistance(betterpos);
	if (int a = CalculDistance(up) < bestdist && gameManager->TestPosition(up)) {
		bestdist = a;
		betterpos = up;
	}
	if (int a = CalculDistance(down) < bestdist && gameManager->TestPosition(down)) {

		bestdist = a;
		betterpos = down;
	}
	if (int a = CalculDistance(left) < bestdist && gameManager->TestPosition(left)) {

		bestdist = a;
		betterpos = left;
	}
	if (int a = CalculDistance(right) < bestdist && gameManager->TestPosition(right)) {

		bestdist = a;
		betterpos = right;
	}
	SetPosition(betterpos);
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

