#pragma once
#include "Mobs.h"
#include "Player.h"
class GameManager;
class Golem : public Mobs
{
private:

public:
	Golem();
	void Death() override;
	void ConfigureMonster() override;

	void GetDamagePlayer(int damage)override;
};

