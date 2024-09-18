#include "Golem.h"
#include "GameManager.h"
#include "Player.h"
#include <random>


void Golem::Move()
{
	srand(time(NULL));
	int direction = (rand() % 4) + 1;

	switch (direction)
	{
	case 0:
		//up
		break;
	case 1:
		//down
		break;
	case 2:
		//left
		break;
	case 3:
		//right
		break;
		
	default:
		break;
	}
	//fonctions random
}

void Golem::Chase()
{
	std::tuple<int, int> actualpos = GetPosition();
	std::tuple<int, int> betterpos = std::tuple<int, int>(std::get<0>(actualpos) + 1, std::get<1>(actualpos));
	int bestdist = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos)+1, std::get<1>(actualpos)));
	if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos) - 1, std::get<1>(actualpos))) < bestdist) {
		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos) - 1, std::get<1>(actualpos));
	}
	else if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos)+1)) < bestdist) {
		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos)+1);
	}
	else if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos)-1)) < bestdist) {
		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos)-1);
	}
	std::find(gameManager->listMobs.begin(), gameManager->listMobs.end(), dynamic_cast<Entity*>(this))[0]->SetPosition(betterpos);
}

void Golem::Attack()
{
	GetPlayer()->Attacked(getDamage());
}

void Golem::Death()
{
	
}
