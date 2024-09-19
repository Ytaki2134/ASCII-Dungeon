#include "GameManager.h"
#include "Player.h"
#include "Golem.h"
#include "GameRenderer.h"
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
		std::tuple<int, int> tempTuple = m_player.GetPosition();
		if (std::get<0>(tempTuple) <= 0)
			return;

		//m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), ".");
		std::get<0>(tempTuple) -= 1;
		m_player.SetPosition(tempTuple);
		//m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), "@");
		m_gameRenderer.RenderScreen(m_map, m_entityVector);
		CheckDoor();

		while (GetKeyState(VK_UP) & 0x8000);
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		std::tuple<int, int> tempTuple = m_player.GetPosition();
		if (std::get<0>(tempTuple) >= ARRAY_SIZE-1)
			return;

		//m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), ".");
		std::get<0>(tempTuple) += 1;
		m_player.SetPosition(tempTuple);
		//m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), "@");
		m_gameRenderer.RenderScreen(m_map, m_entityVector);
		CheckDoor();

		while (GetKeyState(VK_DOWN) & 0x8000);
	}
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		std::tuple<int, int> tempTuple = m_player.GetPosition();
		if (std::get<1>(tempTuple) <= 0)
			return;

		//m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), ".");
		std::get<1>(tempTuple) -= 1;
		m_player.SetPosition(tempTuple);
		//m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), "@");
		m_gameRenderer.RenderScreen(m_map, m_entityVector);
		CheckDoor();

		while (GetKeyState(VK_LEFT) & 0x8000);
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		std::tuple<int, int> tempTuple = m_player.GetPosition();
		if (std::get<1>(tempTuple) >= ARRAY_SIZE-1)
			return;

		//m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), ".");
		std::get<1>(tempTuple) += 1;
		m_player.SetPosition(tempTuple);
		//m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), "@");
		m_gameRenderer.RenderScreen(m_map, m_entityVector);
		CheckDoor();

		while (GetKeyState(VK_RIGHT) & 0x8000);
	}
}

void GameManager::CheckDoor()
{
	std::tuple<int, int> tempTuple = m_player.GetPosition();
	std::string currentLine = m_map.GetCurrentChunk().getChunk(false)[std::get<0>(tempTuple)];
	if (currentLine[std::get<1>(tempTuple)] == '^' && m_map.GetCurrentChunkId() < m_map.GetChunkVector().size())
	{
		//Check if all room mobs are dead
		m_map.setCurrentChunkId(m_map.GetCurrentChunkId() + 1);
		//Clear Mob list to avoid memory leak
		ScanEntities();
		m_gameRenderer.RenderScreen(m_map, m_entityVector);
	}
}

void GameManager::ScanEntities()
{
	Chunk tempChunk = m_map.GetCurrentChunk();

	//Scan
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::string tempString = tempChunk.getChunk(false)[i];
		std::tuple<int, int> tempTuple;
		for (int j = 0; j < tempString.size(); j++)
		{
			tempTuple = { i, j };
			//if(tempString[j])
			switch (tempString[j])
			{
			case 46:
			{
				break;
			}
			//@ - Player
			case 64:
			{
				Player _player;
				_player.SetPosition(tempTuple);
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
	m_gameRenderer.RenderScreen(m_map, m_entityVector);
}

Map GameManager::GetMap()
{
	return m_map;
}

Entity GameManager::GetEntity(int id)
{
	return m_entityVector[id];
}

void GameManager::DeleteEntity(int id)
{
	m_entityVector.erase(m_entityVector.begin() + id);
}

GameManager* GameManager::get()
{
	if (!instance)
		instance = new GameRenderer;
	return instance;
}

void GameManager::SetMap(Map map)
{
	m_map = map;
}
