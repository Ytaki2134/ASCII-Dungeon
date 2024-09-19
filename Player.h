#pragma once
#include "Entity.h"
#include <string>
class Player : public Entity
{
private:
	char m_lastTile = '.';

public:

	std::string GetLastTile();
	void SetLastTile(char);
	void Attacked(int damage) { setLife(getLife() - damage); };
};

