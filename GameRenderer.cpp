#include "GameRenderer.h"

GameRenderer::GameRenderer()
{
	ImportTitle("Ressources/Title.txt");
}

std::string GameRenderer::Center(const std::string& input, int width = 120)
{
	int half_width = width / 2;
	int half_input_len = input.length() / 2;
	std::string padded_str = std::string(half_width - half_input_len, ' ') + input;
	return padded_str;
}

void GameRenderer::ImportTitle(std::string path)
{
	std::ifstream importFile(path);
	//temp buffer
	std::string currentLine;

	while (std::getline(importFile, currentLine))
	{
		m_title.push_back(currentLine);
	}
}

void GameRenderer::RenderScreen(Map map)
{
	std::system("cls");
	RenderTitle();
	RenderChunk(map.GetCurrentChunk().getChunk(true));
}

void GameRenderer::RenderTitle()
{
	for (size_t i = 0; i < m_title.size(); i++)
	{
		std::cout << Center(m_title[i]) << std::endl;
	}
}

void GameRenderer::RenderChunk(std::vector<std::string> mapVector)
{
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		std::string tempString = mapVector[i];
		for (int j = 0; j < tempString.size(); j++)
		{
			//map vector[i] == entityVector[j]
		}
		std::cout << Center(tempString) << std::endl;
	}
}

//void GameRenderer::ColorStringChar(int charID, std::ostream*)
//{
//
//}


