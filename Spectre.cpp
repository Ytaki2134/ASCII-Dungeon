#include "Spectre.h"
#include "GameManager.h"
#include "Player.h"


void Spectre::Move()
{
	std::tuple<int, int> actualpos = GetPosition();
	std::tuple<int, int> betterpos = std::tuple<int, int>(std::get<0>(GetPlayer()->GetPosition()), std::get<1>(GetPlayer()->GetPosition()));

	std::tuple<int, int> up = std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) + 1);
	std::tuple<int, int> down = std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) - 1);
	std::tuple<int, int> right = std::tuple<int, int>(std::get<0>(actualpos) + 1, std::get<1>(actualpos));
	std::tuple<int, int> left = std::tuple<int, int>(std::get<0>(actualpos) - 1, std::get<1>(actualpos));

	int bestdist = CalculDistance(betterpos);
	if (int a = CalculDistance(up) > bestdist && gameManager->TestPosition(up)) {
		bestdist = a;
		betterpos = up;
	}
	if (int a = CalculDistance(down) > bestdist && gameManager->TestPosition(down)) {

		bestdist = a;
		betterpos = down;
	}
	if (int a = CalculDistance(left) > bestdist && gameManager->TestPosition(left)) {

		bestdist = a;
		betterpos = left;
	}
	if (int a = CalculDistance(right) > bestdist && gameManager->TestPosition(right)) {

		bestdist = a;
		betterpos = right;
	}

	SetPosition(betterpos);
}

void Spectre::Chase()
{
	std::tuple<int, int> actualpos = GetPosition();
	std::tuple<int, int> betterpos = std::tuple<int, int>(std::get<0>(actualpos) + 1, std::get<1>(actualpos));
	int bestdist = CalculDistance(betterpos);
	if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos) - 1, std::get<1>(actualpos))) > bestdist && gameManager->TestPosition(a)) {
		std::cout << "1 dist" << a << std::endl;
		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos) - 1, std::get<1>(actualpos));
	}
	if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) + 1)) > bestdist && gameManager->TestPosition(a)) {
		std::cout << "2 dist" << a << std::endl;
		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) + 1);
	}
	if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) - 1)) > bestdist && gameManager->TestPosition(a)) {
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
	gameManager->DeleteEntity(GetID());
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