#pragma once
#include <windows.h>
#include "map.h"

class GameManager
{

public:
	void CheckInputs();
	void InitGame(std::string);
	Map GetMap();
private:
	void SetMap(Map);

	Map m_map;
};

