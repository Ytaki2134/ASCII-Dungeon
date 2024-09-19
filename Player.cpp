#include "Player.h"

Player::Player()
{
	SetToken('@');
	SetLastTile('.');
	SetMaxLife(100);
	SetLife(maxLife);
	SetDamage(25);
	SetName("Player");
}

std::string Player::GetLastTile()
{
	std::string str;
	str.push_back(lastTile);
	return str;
}
