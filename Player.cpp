#include "Player.h"

Player::Player()
{
	SetToken('@');
	SetLastTile('.');
}

std::string Player::GetLastTile()
{
	std::string str;
	str.push_back(lastTile);
	return str;
}
