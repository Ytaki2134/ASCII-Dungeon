#include "GameManager.h"
#include "Player.h"
#include "Golem.h"
#include <cassert>

GameManager::GameManager()
{
	assert(instance == nullptr);
	instance = this;
}

void GameManager::CheckInputs()
{
	if (GetKeyState(VK_UP) & 0x8000)
	{
		Vector2 vector2 = m_player.GetPosition();
		if (vector2.GetVector()[0] <= 0)
			return;

		MoveEntity(&m_player, 0, -1);

		while (GetKeyState(VK_UP) & 0x8000);
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		Vector2 vector2 = m_player.GetPosition();
		if (vector2.GetVector()[0] >= ARRAY_SIZE-1)
			return;

		MoveEntity(&m_player, 0, 1);

		while (GetKeyState(VK_DOWN) & 0x8000);
	}
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		Vector2 vector2 = m_player.GetPosition();
		if (vector2.GetVector()[1] <= 0)
			return;

		MoveEntity(&m_player, 1, -1);

		while (GetKeyState(VK_LEFT) & 0x8000);
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		Vector2 vector2 = m_player.GetPosition();
		if (vector2.GetVector()[1] >= ARRAY_SIZE-1)
			return;

		MoveEntity(&m_player, 1, 1);

		while (GetKeyState(VK_RIGHT) & 0x8000);
	}
}

void GameManager::CheckDoor()
{
	Vector2 vector2 = m_player.GetPosition();
	std::string currentLine = m_map.GetCurrentChunk().getChunk(false)[vector2.GetVector()[0]];
	if (currentLine[vector2.GetVector()[1]] == '^' && m_map.GetCurrentChunkId() < m_map.GetChunkVector().size())
	{
		//Check if all room mobs are dead
		m_map.setCurrentChunkId(m_map.GetCurrentChunkId() + 1);
		//Clear Mob list to avoid memory leak
		ScanEntities();
		m_gameRenderer.RenderScreen(m_map);
	}
}

void GameManager::ScanEntities()
{
	Chunk tempChunk = m_map.GetCurrentChunk();

	//Scan
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::string str = tempChunk.getChunk(false)[i];
		Vector2 vector2;
		for (int j = 0; j < str.size(); j++)
		{
			vector2.SetVector(i, j);
			switch (str[j])
			{
			case 46:
			{
				break;
			}
			//@ - Player
			case 64:
			{
				Player _player;
				_player.SetPosition(vector2);
				m_player = _player;
				break;
			}
			default:
			{
				break;
			}
			}
		}
	}

	//Sort to have player as first item
}

void GameManager::InitGame(std::string path)
{
	//Init Map
	Map map;
	map.ImportMap(path);
	//Save Map
	SetMap(map);
	ScanEntities();

	//Render Visuals
	m_gameRenderer.RenderScreen(m_map);
}

Map GameManager::GetMap()
{
	return m_map;
}

void GameManager::Try()
{
	Player a;
	Golem b;
	
	a.SetPosition(std::tuple<int, int>(4,4));
	b.ConfigureMonster(this);
	b.Initialize();
	b.SetPlayer(&a);
	b.SetPosition(std::tuple<int, int>(5, 5));
	b.SetId(1);
	m_entityVector.push_back(a);
	m_entityVector.push_back(b);


	b.Play();

}

Entity GameManager::GetEntity(int id)
{
	return m_entityVector[id];
}

void GameManager::DeleteEntity(int id)
{
	m_entityVector.erase(m_entityVector.begin() + id);
}

bool GameManager::TestPosition(std::tuple<int, int> pos)
{
	auto map = GetMap().GetCurrentChunk().getChunk(false);
	if (map[std::get<1>(pos)][std::get<0>(pos)] == '.')
		return true;
	else
		return false;
}
void GameManager::MoveEntity(Entity* entity, int axis, int speed)
{
	m_map.SetCurrentChunkCoords(entity->GetPosition().GetVector()[0], entity->GetPosition().GetVector()[1], m_player.GetLastTile());

	Vector2 Position;
	if (axis == 0)
	{
		Position.SetVector(entity->GetPosition().GetVector()[0] + speed, entity->GetPosition().GetVector()[1]);
	}
	else if (axis == 1)
	{
		Position.SetVector(entity->GetPosition().GetVector()[0], entity->GetPosition().GetVector()[1] + speed);
	}
	else {
		throw std::runtime_error("Invalid input: must be 0 or 1");
	}

	entity->SetPosition(Position);
	entity->SetLastTile(m_map.GetCurrentChunk().getChunk(false)[Position.GetVector()[0]][Position.GetVector()[1]]);
	m_map.SetCurrentChunkCoords(Position.GetVector()[0], Position.GetVector()[1], entity->getToken());
	m_gameRenderer.RenderScreen(m_map);
	CheckDoor();
}

GameManager* GameManager::get()
{
	if (!instance)
		instance = new GameManager;
	return instance;
}

void GameManager::SetMap(Map map)
{
	m_map = map;
}
