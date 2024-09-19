#include "Faucheur.h"
#include "GameManager.h"
#include "Player.h"




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