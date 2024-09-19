#pragma once
#include <windows.h>
#include <algorithm>
#include <random>
#include <string_view>
#include "map.h"
#include "Entity.h"
#include "Player.h"
#include "GameRenderer.h"

class GameManager
{
	enum class axis { x, y };

public:
	void CheckInputs();
	void CheckDoor();
	void ScanEntities();
	void InitGame(std::string);
	void MoveEntity(Entity*, int, int);

	Map GetMap();
	void Try();
	Entity GetEntity(int Id);
	void DeleteEntity(int id);
	bool TestPosition(std::tuple<int, int> pos);


	static GameManager* get();
private:
	GameManager();
	void SetMap(Map);
	GameRenderer m_gameRenderer;
	Map m_map;
	std::vector<Entity> m_entityVector;
	Player m_player;

	static inline GameManager* instance = nullptr;
};

