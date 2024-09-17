#pragma once
#include "Entity.h"
class Player : public Entity
{
private:


public:
	void Attacked(int damage) { setLife(getLife() - damage); }
};

