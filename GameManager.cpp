#include "GameManager.h"
#include "Player.h"
#include "Golem.h"
#include "GameRenderer.h"

void GameManager::CheckInputs()
{
	if (GetKeyState(VK_UP) & 0x8000)
	{
		std::tuple<int, int> tempTuple = m_player.GetPosition();
		if (std::get<0>(tempTuple) <= 0)
			return;

		m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), ".");
		std::get<0>(tempTuple) -= 1;
		m_player.SetPosition(tempTuple);
		m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), "@");
		m_gameRenderer->RenderScreen(m_map);
		while (GetKeyState(VK_UP) & 0x8000);
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		std::tuple<int, int> tempTuple = m_player.GetPosition();
		if (std::get<0>(tempTuple) >= ARRAY_SIZE-1)
			return;

		m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), ".");
		std::get<0>(tempTuple) += 1;
		m_player.SetPosition(tempTuple);
		m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), "@");
		m_gameRenderer->RenderScreen(m_map);
		while (GetKeyState(VK_DOWN) & 0x8000);
	}
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		std::tuple<int, int> tempTuple = m_player.GetPosition();
		if (std::get<1>(tempTuple) <= 0)
			return;

		m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), ".");
		std::get<1>(tempTuple) -= 1;
		m_player.SetPosition(tempTuple);
		m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), "@");
		m_gameRenderer->RenderScreen(m_map);
		while (GetKeyState(VK_LEFT) & 0x8000);
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		std::tuple<int, int> tempTuple = m_player.GetPosition();
		if (std::get<1>(tempTuple) >= ARRAY_SIZE-1)
			return;

		m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), ".");
		std::get<1>(tempTuple) += 1;
		m_player.SetPosition(tempTuple);
		m_map.SetCurrentChunkCoords(std::get<0>(tempTuple), std::get<1>(tempTuple), "@");
		m_gameRenderer->RenderScreen(m_map);
		while (GetKeyState(VK_RIGHT) & 0x8000);
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
	//m_gameRenderer.RenderScreen(m_map);
	GameRenderer::get()->RenderScreen(m_map);
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

void GameManager::SetMap(Map map)
{
	m_map = map;
}
