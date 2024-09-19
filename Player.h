#pragma once
#include "Entity.h"

class Player : public Entity
{
private:

public:
	Player();
	std::string GetLastTile();
	void Attacked(int damage) { SetLife(GetLife() - damage); };
};

