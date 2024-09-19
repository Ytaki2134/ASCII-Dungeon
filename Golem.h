#pragma once
#include "Mobs.h"
class GameManager;
class Golem : public Mobs
{
private:

public:
	Golem();
	void Death() override;
	void ConfigureMonster();

	void GetDamagePlayer(int damage);
};

