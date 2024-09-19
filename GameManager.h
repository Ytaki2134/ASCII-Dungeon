#pragma once
#include <windows.h>
#include <algorithm>
#include <random>
#include <string_view>
#include "map.h"
#include "Entity.h"
#include "Mobs.h"
#include "Player.h"
#include "GameRenderer.h"

class GameManager
{
	enum class axis { x, y };

public:
	void CheckInputs();
	void CheckDoor(Vector2);
	void ScanEntities();
	void InitGame(std::string);
	void DeleteEntity(int id);
	void MoveEntity(Entity*, int, int);

	Map GetMap();
	Entity GetEntity(int Id);
	Mobs GetLastMobSelected();
	Player GetPlayer();

	static GameManager* get();
private:
	GameManager();
	void SetMap(Map);
	GameRenderer m_gameRenderer;
	Map m_map;
	std::vector<Entity> m_entityVector;
	Mobs m_lastMobSelect;
	Player m_player;

	static inline GameManager* instance = nullptr;
};

