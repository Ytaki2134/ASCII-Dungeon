#include "Golem.h"
#include "GameManager.h"
#include "Player.h"
#include <random>


void Golem::Move()
{
	srand(time(NULL));
	int direction = (rand() % 4) + 1;
	auto mob = gameManager->GetEntity(GetID());

	switch (direction)
	{
	case 0:
		if (gameManager->TestPosition(std::tuple<int, int>(std::get<0>(GetPosition()) + 1, std::get<1>(GetPosition()))))
			mob.SetPosition(std::tuple<int, int>(std::get<0>(GetPosition()) + 1, std::get<1>(GetPosition())));
		break;
	case 1:
		if (gameManager->TestPosition(std::tuple<int, int>(std::get<0>(GetPosition()) - 1, std::get<1>(GetPosition()))))
			mob.SetPosition(std::tuple<int, int>(std::get<0>(GetPosition()) - 1, std::get<1>(GetPosition())));
		break;
	case 2:
		if (gameManager->TestPosition(std::tuple<int, int>(std::get<0>(GetPosition()), std::get<1>(GetPosition()) + 1)))
			mob.SetPosition(std::tuple<int, int>(std::get<0>(GetPosition()), std::get<1>(GetPosition()) + 1));
		break;
	case 3:
		if (gameManager->TestPosition(std::tuple<int, int>(std::get<0>(GetPosition()), std::get<1>(GetPosition()) - 1)))
			mob.SetPosition(std::tuple<int, int>(std::get<0>(GetPosition()), std::get<1>(GetPosition()) - 1));
		break;

	default:
		break;
	}
}

void Golem::Chase()
{
	std::tuple<int, int> actualpos = GetPosition();
	std::tuple<int, int> betterpos = std::tuple<int, int>(100, 100);

	std::tuple<int, int> up = std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) + 1);
	std::tuple<int, int> down = std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) - 1);
	std::tuple<int, int> right = std::tuple<int, int>(std::get<0>(actualpos) + 1, std::get<1>(actualpos));
	std::tuple<int, int> left = std::tuple<int, int>(std::get<0>(actualpos) - 1, std::get<1>(actualpos));
	
		
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

void Golem::Attack()
{
	GetPlayer()->Attacked(getDamage());
}

void Golem::Death()
{
	gameManager->DeleteEntity(GetID());
}

void Golem::ConfigureMonster(GameManager* gamemanager)
{
	setLife(100);
	setDammage(10);
	gameManager = gamemanager;
}

void Golem::GetDamage(int damage) 
{
	srand(time(NULL));
	int deniedattack = (rand() % 100) + 1;
	if (deniedattack > 20)
		TakeDamage(damage);
}