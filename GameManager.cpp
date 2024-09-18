#include "GameManager.h"

void GameManager::CheckInputs()
{
	if (GetKeyState(VK_UP) & 0x8000)
	{
		m_map.RenderChunk(m_map.GetCurrentChunk() + 1);
		while (GetKeyState(VK_UP) & 0x8000);
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		m_map.RenderChunk(m_map.GetCurrentChunk() - 1);
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
	Map FirstMap;
	FirstMap.ImportMap(path);

	//Save Map to global
	SetMap(FirstMap);

	//Render First Room
	FirstMap.RenderChunk(0);
}

Map GameManager::GetMap()
{
	return m_map;
}

void GameManager::SetMap(Map map)
{
	m_map = map;
}
