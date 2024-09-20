#include "Golem.h"
#include <random>
#include "GameManager.h"

Golem::Golem()
{
	SetToken('G');
	SetLastTile('.');
}


void Golem::Death()
{
	GameManager* gameManager = GameManager::get();
	GetPlayer()->SetDamage(GetPlayer()->GetDamage() + 5);
	gameManager->GetMap().SetCurrentChunkCoords(GetPosition().GetVector()[0], GetPosition().GetVector()[1],GetLastTile());
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