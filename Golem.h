#pragma once
#include "Mobs.h"
class GameManager;
class Golem : public Mobs
{
private:

public:
	Golem();
	void Attack()	override;
	void Death()	override;
	void ConfigureMonster();

	void GetDamage(int damage);
};

