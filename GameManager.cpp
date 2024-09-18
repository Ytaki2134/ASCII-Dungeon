#include "GameManager.h"
#include "Player.h"
#include "Golem.h"


void GameManager::CheckInputs()
{
	if (GetKeyState(VK_UP) & 0x8000)
	{
		m_map.setCurrentChunkId(m_map.GetCurrentChunkId() + 1);
		m_gameRenderer.RenderScreen(m_map);
		while (GetKeyState(VK_UP) & 0x8000);
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		m_map.setCurrentChunkId(m_map.GetCurrentChunkId() - 1);
		m_gameRenderer.RenderScreen(m_map);
		while (GetKeyState(VK_DOWN) & 0x8000);
	}
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		std::cout << "UP" << std::endl;
		//Do something
		while (GetKeyState(VK_LEFT) & 0x8000);
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		std::cout << "UP" << std::endl;
		//Do something
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
				m_entityVector.push_back(_player);
				break;
			}
			default:
				break;
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

	a.SetPosition(std::tuple<int, int>(10, 10));
	b.SetPlayer(&a);
	b.SetPosition(std::tuple<int, int>(10, 7));
	b.Chase();

}

Entity GameManager::GetEntity(int Id)
{
	return std::find(m_entityVector.begin(), m_entityVector.end(), Id)[0];
}

void GameManager::DeadEntity(int id)
{
	std::remove(m_entityVector.begin(), m_entityVector.end() , id);
}

void GameManager::SetMap(Map map)
{
	m_map = map;
}
