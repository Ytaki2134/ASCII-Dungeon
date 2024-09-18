#include "Golem.h"
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
