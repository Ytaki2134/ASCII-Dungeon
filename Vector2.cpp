#include "Vector2.h"

Vector2::Vector2(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Vector2::SetVector(int x, int y)
{
	m_x = x;
	m_y = y;
}

std::vector<int> Vector2::GetVector()
{
	std::vector<int> vector;
	vector.push_back(m_x);
	vector.push_back(m_y);

	return vector;
}
