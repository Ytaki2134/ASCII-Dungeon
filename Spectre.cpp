#include "Spectre.h"
#include "GameManager.h"
#include "Player.h"


Spectre::Spectre()
{
	SetToken('S');
	SetLastTile('.');
}
void Spectre::Chase()
{


	Vector2 actualpos = GetPosition();
	Vector2 betterpos = Vector2(100, 100);

	Vector2 up = Vector2(GetPosition().GetVector()[0], GetPosition().GetVector()[1] + 1);
	Vector2 down = Vector2(GetPosition().GetVector()[0], GetPosition().GetVector()[1] - 1);
	Vector2 right = Vector2(GetPosition().GetVector()[0] + 1, GetPosition().GetVector()[1]);
	Vector2 left = Vector2(GetPosition().GetVector()[0] - 1, GetPosition().GetVector()[1]);


	int bestdist = CalculDistance(betterpos);
	if (int a = CalculDistance(up) > bestdist && gameManager->TestPosition(up)) {
		bestdist = a;
		betterpos = up;
	}
	if (int a = CalculDistance(down) > bestdist && gameManager->TestPosition(down)) {

		bestdist = a;
		betterpos = down;
	}
	if (int a = CalculDistance(left) > bestdist && gameManager->TestPosition(left)) {

		bestdist = a;
		betterpos = left;
	}
	if (int a = CalculDistance(right) > bestdist && gameManager->TestPosition(right)) {

		bestdist = a;
		betterpos = right;
	}
	SetPosition(betterpos);
}

void Spectre::Attack()
{
	GetPlayer()->Attacked(GetDamage());
}
void Spectre::Death()
{
	gameManager->DeleteEntity(GetID());
}

void Spectre::ConfigureMonster(GameManager* gamemanager)
{
	SetLife(100);
	SetDamage(10);
	SetDetection(5);
	gameManager = gamemanager;
}
void Spectre::GetDamagePlayer(int damage)
{
		TakeDamage(damage);
}