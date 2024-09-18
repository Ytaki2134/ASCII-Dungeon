#pragma once
#include <windows.h>
#include <algorithm>
#include <random>
#include <string_view>
#include "map.h"
#include "Entity.h"
#include "Player.h"

class GameManager
{

public:
	void CheckInputs();
	void ScanEntities();
	void InitGame(std::string);
	Map GetMap();
	Entity GetEntity(int Id);
	void DeleteEntity(int id);
private:
	void SetMap(Map);
	class GameRenderer* m_gameRenderer;
	Map m_map;
	std::vector<Entity> m_entityVector;
	Player m_player;
};

