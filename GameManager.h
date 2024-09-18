#pragma once
#include <windows.h>
#include "map.h"
#include "GameRenderer.h"

class GameManager
{

public:
	void CheckInputs();
	void CheckDoor();
	void ScanEntities();
	void InitGame(std::string);
	Map GetMap();
private:
	void SetMap(Map);

	GameRenderer m_gameRenderer;
	Map m_map;
};

