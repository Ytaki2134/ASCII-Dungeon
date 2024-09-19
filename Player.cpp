#include "Player.h"

std::string Player::GetLastTile()
{
	std::string str;
	str.push_back(m_lastTile);
	return str;
}

void Player::SetLastTile(char tile)
{
	m_lastTile = tile;
}
