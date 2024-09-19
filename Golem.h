#pragma once
#include "Mobs.h"
class GameManager;
class Golem : public Mobs
{
private: 	
	GameManager* gameManager;

public :


	void Attack()	override;
	void Death()	override;
	void ConfigureMonster(GameManager* gamemanager);

	void GetDamage(int damage);

};

