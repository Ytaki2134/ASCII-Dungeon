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

void GameManager::InitGame(std::string path)
{
	//Init Map
	Map map;
	map.ImportMap(path);
	//Save Map
	SetMap(map);

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
