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


