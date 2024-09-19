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
		mob.SetPosition(GetPosition().GetVector()[0] + 1, GetPosition().GetVector()[1]);
		break;
	case 1:
		mob.SetPosition(GetPosition().GetVector()[0] - 1, GetPosition().GetVector()[1]);
		break;
	case 2:
		mob.SetPosition(GetPosition().GetVector()[0], GetPosition().GetVector()[1] + 1);
		break;
	case 3:
		mob.SetPosition(GetPosition().GetVector()[0], GetPosition().GetVector()[1] - 1);
		break;

	default:
		break;
	}
}

void Golem::Chase()
{
	Vector2 actualpos = GetPosition();
	Vector2 betterpos;
	betterpos.SetVector(actualpos[0] + 1, actualpos[1]);

	int bestdist = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos) + 1, std::get<1>(actualpos)));
	if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos) - 1, std::get<1>(actualpos))) < bestdist) {
		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos) - 1, std::get<1>(actualpos));
	}
	else if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) + 1)) < bestdist) {
		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) + 1);
	}
	else if (int a = CalculDistance(std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) - 1)) < bestdist) {
		bestdist = a;
		betterpos = std::tuple<int, int>(std::get<0>(actualpos), std::get<1>(actualpos) - 1);
	}
	//std::find(gameManager->listMobs.begin(), gameManager->listMobs.end(), dynamic_cast<Entity*>(this))[0]->SetPosition(betterpos);
	std::cout<<"position:" << std::get<0>(betterpos) << " , " << std::get<1>(betterpos) << std::endl;
}

void Golem::Attack()
{
	GetPlayer()->Attacked(getDamage());
}

void Golem::Death()
{
	gameManager->DeleteEntity(GetID());
}