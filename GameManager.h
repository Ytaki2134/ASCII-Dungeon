#pragma once
#include <windows.h>
#include "map.h"
#include "Entity.h"
#include "GameRenderer.h"
#include "Entity.h"
#include "Player.h"

class GameManager
{

public:
	void CheckInputs();
	void ScanEntities();
	void InitGame(std::string);
	Map GetMap();
	void Try();
	Entity GetEntity(int Id);
	void DeadEntity(int id);
private:
	void SetMap(Map);
	GameRenderer m_gameRenderer;
	Map m_map;
	std::vector<Entity> m_entityVector;
};

