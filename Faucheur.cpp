#include "Faucheur.h"
#include "GameManager.h"
#include "Player.h"




void Faucheur::Attack()
{
	GetPlayer()->Attacked(GetDamage());
}

void Faucheur::Death()
{
	gameManager->DeleteEntity(GetID());
}

void Faucheur::ConfigureMonster(GameManager* gamemanager)
{
	SetLife(70);
	SetDamage(20);
	SetDetection(15);
	gameManager = gamemanager;
}

void Faucheur::GetDamagePlayer(int damage)
{
	TakeDamage(damage);
}