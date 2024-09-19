#pragma once
#include <vector>
class Vector2
{
private:
	int m_x;
	int m_y;
public:
	Vector2();
	Vector2(int, int);
	void SetVector(int, int);
	std::vector<int> GetVector();
};

