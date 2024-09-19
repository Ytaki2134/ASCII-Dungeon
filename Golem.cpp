#include "Golem.h"
#include "GameManager.h"
#include "Player.h"
#include <random>


void Golem::Move()
{

	/*srand(time(NULL));
	int direction = (rand() % 4) + 1;
	auto mob = gameManager->GetEntity(GetID());

	switch (direction)
	{
	case 0:
		if (gameManager->TestPosition(GetPosition().GetVector()[0] + 1, GetPosition().GetVector()[1]))
			mob.SetPosition(GetPosition().GetVector()[0] + 1, GetPosition().GetVector()[1]);
			
	case 1:
		if (gameManager->TestPosition((GetPosition().GetVector()[0] - 1, GetPosition().GetVector()[1])))	
			mob.SetPosition(GetPosition().GetVector()[0] - 1, GetPosition().GetVector()[1]);
		break;
	case 2:
		if (gameManager->TestPosition(GetPosition().GetVector()[0], GetPosition().GetVector()[1] + 1))
			mob.SetPosition(GetPosition().GetVector()[0], GetPosition().GetVector()[1] + 1);
		break;
	case 3:
		if (gameManager->TestPosition(GetPosition().GetVector()[0], GetPosition().GetVector()[1] - 1))
			mob.SetPosition(GetPosition().GetVector()[0], GetPosition().GetVector()[1] - 1);
		break;

	default:
		break;
	}*/
}

void Golem::Chase()
{

	//Vector2 actualpos = GetPosition();
	//Vector2 betterpos = Vector2(100, 100);

	//Vector2 up = Vector2(GetPosition().GetVector()[0] , GetPosition().GetVector()[1]+1);
	//Vector2 down = Vector2(GetPosition().GetVector()[0], GetPosition().GetVector()[1] - 1);
	//Vector2 right = Vector2(GetPosition().GetVector()[0] +1, GetPosition().GetVector()[1]);
	//Vector2 left = Vector2(GetPosition().GetVector()[0] -1, GetPosition().GetVector()[1] );


	//int bestdist = CalculDistance(betterpos);
	//if (int a = CalculDistance(up) < bestdist && gameManager->TestPosition(up)) {
	//	bestdist = a;
	//	betterpos = up;
	//}
	//if (int a = CalculDistance(down) < bestdist && gameManager->TestPosition(down)) {

	//	bestdist = a;
	//	betterpos = down;
	//}
	//if (int a = CalculDistance(left) < bestdist && gameManager->TestPosition(left)) {

	//	bestdist = a;
	//	betterpos = left;
	//}
	//if (int a = CalculDistance(right) < bestdist && gameManager->TestPosition(right)) {

	//	bestdist = a;
	//	betterpos = right;
	//}
	////std::find(gameManager->listMobs.begin(), gameManager->listMobs.end(), dynamic_cast<Entity*>(this))[0]->SetPosition(betterpos);
	//std::cout<<"position:" << std::get<0>(betterpos) << " , " << std::get<1>(betterpos) << std::endl;
}

void Golem::Attack()
{
	GetPlayer()->Attacked(getDamage());
}

void Golem::Death()
{
	gameManager->DeleteEntity(GetID());
}