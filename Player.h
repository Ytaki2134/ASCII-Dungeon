#pragma once
#include "Entity.h"
#include <string>
class Player : public Entity
{
private:

public:
	Player();
	void Attacked(int damage) { SetLife(GetLife() - damage); };
};

