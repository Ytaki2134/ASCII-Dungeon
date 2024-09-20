#pragma once
#include "Mobs.h"
class GameManager;
class Spectre :public Mobs
{
private:
	

public:
	Spectre();
	void Move()		override;
	void Chase()	override;
	void Attack()	override;
	void Death()	override;
	void ConfigureMonster(GameManager* gamemanager);
	void GetDamagePlayer(int damage);
};

