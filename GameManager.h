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
	void MoveEntity(Entity*, int, int);

	Map GetMap();
	void Try();
	Mobs GetEntity(int Id);
	void DeleteEntity(int id);
	bool TestPosition(Vector2 pos);

	Player* GetPlayer() { return &m_player; };
	static GameManager* get();
private:
	GameManager();
	void SetMap(Map);
	GameRenderer m_gameRenderer;
	Map m_map;
	std::vector<Mobs> m_entityVector;
	Player m_player;

	static inline GameManager* instance = nullptr;
};

