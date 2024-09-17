#include "Golem.h"
#include <random>


void Golem::Move()
{
	srand(time(NULL));
	int direction = (rand() % 3) + 1;
	switch (direction)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
	//fonctions random
}

void Golem::Chase()
{
	
	//if(std::get<0>(GetPlayer()->GetPosition()))
	//	GetPosition();

}

void Golem::Attack()
{
	GetPlayer()->Attacked(getDamage());
}

void Golem::Death()
{
	
}
