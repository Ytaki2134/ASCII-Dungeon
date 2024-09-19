#include "Player.h"

Player::Player()
{
	SetToken('@');
	SetLastTile('.');
	SetMaxLife(100);
	SetLife(maxLife);
}

std::string Player::GetLastTile()
{
	std::string str;
	str.push_back(lastTile);
	return str;
}
