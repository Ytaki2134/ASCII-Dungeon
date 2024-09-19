#include "Faucheur.h"
#include "GameManager.h"
#include "Player.h"


void Faucheur::Move()
{
	srand(time(NULL));
	int direction = (rand() % 4) + 1;
	auto mob = gameManager->GetEntity(GetID());

	switch (direction)
	{
	case 0:
		mob.SetPosition(std::tuple<int, int>(std::get<0>(GetPosition()) + 1, std::get<1>(GetPosition())));
		break;
	case 1:
		mob.SetPosition(std::tuple<int, int>(std::get<0>(GetPosition()) - 1, std::get<1>(GetPosition())));
		break;
	case 2:
		mob.SetPosition(std::tuple<int, int>(std::get<0>(GetPosition()), std::get<1>(GetPosition()) + 1));
		break;
	case 3:
		mob.SetPosition(std::tuple<int, int>(std::get<0>(GetPosition()), std::get<1>(GetPosition()) - 1));
		break;

	default:
		break;
	}
}

void Faucheur::Chase()
{
	std::tuple<int, int> actualpos = GetPosition();
	std::tuple<int, int> betterpos = std::tuple<int, int>(std::get<0>(actualpos) + 1, std::get<1>(actualpos));
	int bestdist = CalculDistance(betterpos);
	if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos) - 1, std::get<1>(actualpos))) < bestdist) {

		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos) - 1, std::get<1>(actualpos));
	}
	if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) + 1)) < bestdist) {

		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) + 1);
	}
	if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) - 1)) < bestdist) {

		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) - 1);
	}

	SetPosition(betterpos);
}

void Faucheur::Attack()
{
	GetPlayer()->Attacked(getDamage());
}

void Faucheur::Death()
{
	gameManager->DeleteEntity(GetID());
}

void Faucheur::ConfigureMonster(GameManager* gamemanager)
{
	setLife(70);
	setDammage(20);
	SetDetection(15);
	gameManager = gamemanager;
}

void Faucheur::GetDamage(int damage)
{
	TakeDamage(damage);
}