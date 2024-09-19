#include "Golem.h"
#include "GameManager.h"
#include "Player.h"
#include <random>





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