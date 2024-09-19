#include "Golem.h"
#include "GameManager.h"
#include "Player.h"
#include <random>





Golem::Golem()
{
	SetToken('G');
	SetLastTile('.');
}

void Golem::Attack()
{
	GetPlayer()->Attacked(GetDamage());
}

void Golem::Death()
{
	GameManager* gameManager = GameManager::get();
	gameManager->DeleteEntity(GetID());
}

void Golem::ConfigureMonster()
{
	setLife(100);
	setDamage(10);

}

void Golem::GetDamage(int damage) 
{
	srand(time(NULL));
	int deniedattack = (rand() % 100) + 1;
	if (deniedattack > 20)
		TakeDamage(damage);
}