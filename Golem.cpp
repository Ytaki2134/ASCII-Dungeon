#include "Golem.h"
#include "GameManager.h"
#include "Player.h"
#include <random>





Golem::Golem()
{
	SetToken('G');
	SetLastTile('.');
}


void Golem::Death()
{
	GameManager* gameManager = GameManager::get();
	gameManager->DeleteEntity(GetID());
}

void Golem::ConfigureMonster()
{
	SetLife(100);
	SetDamage(10);

}

void Golem::GetDamagePlayer(int damage) 
{
	srand(time(NULL));
	int deniedattack = (rand() % 100) + 1;
	if (deniedattack > 20)
		TakeDamage(damage);
}