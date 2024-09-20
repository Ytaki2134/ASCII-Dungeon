#pragma once
#include "Entity.h"

class Player : public Entity
{
private:

public:
	Player();
	void Attacked(int damage) { SetLife(GetLife() - damage); };
};

