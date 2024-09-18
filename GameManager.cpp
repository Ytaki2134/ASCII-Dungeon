#include "GameManager.h"

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
		for (int j = 0; j < tempString.size(); j++)
		{
			switch (tempString[j])
			{
			//@ - Player
			case 64:
				//Player _player;
				//setPosition
				break;
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

void GameManager::SetMap(Map map)
{
	m_map = map;
}
