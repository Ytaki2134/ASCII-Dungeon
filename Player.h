#pragma once
#include "Entity.h"
#include <string>
class Player : public Entity
{
private:

public:
	Player();
	//char GetLastTile() override;
	void Attacked(int damage) { setLife(getLife() - damage); };
};

