#include "Spectre.h"
#include "GameManager.h"
#include "Player.h"


void Spectre::Move()
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

void Spectre::Chase()
{
	std::tuple<int, int> actualpos = GetPosition();
	std::tuple<int, int> betterpos = std::tuple<int, int>(std::get<0>(actualpos) + 1, std::get<1>(actualpos));
	int bestdist = CalculDistance(betterpos);
	if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos) - 1, std::get<1>(actualpos))) > bestdist) {
		std::cout << "1 dist" << a << std::endl;
		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos) - 1, std::get<1>(actualpos));
	}
	if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) + 1)) > bestdist) {
		std::cout << "2 dist" << a << std::endl;
		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) + 1);
	}
	if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) - 1)) > bestdist) {
		std::cout << "3 dist" << a << std::endl << "pleaye: " << std::get<0>(GetPlayer()->GetPosition()) << " , " << std::get<0>(GetPlayer()->GetPosition());
		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) - 1);
	}
	std::cout << "position:" << std::get<0>(betterpos) << " , " << std::get<1>(betterpos) << std::endl;
	SetPosition(betterpos);
}

void Spectre::Attack()
{
	GetPlayer()->Attacked(getDamage());
}
void Spectre::Death()
{
	gameManager->DeadEntity(GetID());
}

void Spectre::ConfigureMonster(GameManager* gamemanager)
{
	setLife(100);
	setDammage(10);
	SetDetection(5);
	gameManager = gamemanager;
}
void Spectre::GetDamage(int damage)
{
		TakeDamage(damage);
}