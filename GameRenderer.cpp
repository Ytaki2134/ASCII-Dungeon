#include "GameRenderer.h"
#include "GameManager.h"


GameRenderer::GameRenderer()
{
	ImportTitle("Ressources/Title.txt");
	ImportSub("Ressources/SubScreen.txt");
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

void GameRenderer::ImportSub(std::string path)
{
	std::ifstream importFile(path);
	//temp buffer
	std::string currentLine;

	while (std::getline(importFile, currentLine))
	{
		m_sub.push_back(currentLine);
	}
}

void GameRenderer::RenderScreen(Map map)
{
	std::system("cls");
	RenderTitle();
	RenderChunk(map.GetCurrentChunk().getChunk(true));
	RenderSubScreen();
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
		std::cout << Center(mapVector[i]) << std::endl;
	}
}

void GameRenderer::RenderSubScreen()
{
	bool playerStat = true;
	GameManager* gameManager = GameManager::get();
	for (size_t i = 0; i < m_title.size(); i++)
	{
		std::string str = m_sub[i];
		for (size_t j = 0; j < str.size() - 1; j++)
		{
			//Find HP
			if (str.at(j == 'H') && str.at(j + 1) == 'P')
			{
				std::ostringstream oss;
				if (playerStat)
				{
					oss << " " << gameManager->GetPlayer().GetLife() << " / " << gameManager->GetPlayer().GetMaxLife();
					playerStat = false;
				}
				else
				{
					oss << " " << gameManager->GetLastMobSelected().GetLife() << " / " << gameManager->GetLastMobSelected().GetMaxLife();
					playerStat = true;
				}
				std::string HP = oss.str();
				str.replace(j + 4, HP.size(), HP);
				m_sub[i] = str;
			}
		}
		std::cout << Center(m_sub[i]) << std::endl;
	}
}

//void GameRenderer::ColorStringChar(int charID, std::ostream*)
//{
//
//}


