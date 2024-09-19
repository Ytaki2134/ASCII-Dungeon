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
			//Find ID
			if (str.at(j == 'I') && str.at(j + 1) == 'D')
			{
				std::ostringstream oss;
				if (playerStat)
				{
					oss << " " << gameManager->GetPlayer().GetName();
					playerStat = false;
				}
				else
				{
					if (gameManager->GetLastMobSelected() == NULL)
						oss << " ?";
					else
						oss << " " << gameManager->GetLastMobSelected()->GetName();
					playerStat = true;
				}
				std::string ID = oss.str();
				str.replace(j + 4, ID.size(), ID);
				j += 4 + ID.size();
				m_sub[i] = str;
			}
			//Find HP
			else if (str.at(j == 'H') && str.at(j + 1) == 'P')
			{
				std::ostringstream oss;
				if (playerStat)
				{
					oss << " " << gameManager->GetPlayer().GetLife() << " / " << gameManager->GetPlayer().GetMaxLife();
					playerStat = false;
				}
				else
				{
					if (gameManager->GetLastMobSelected() == NULL)
						oss << " ? / ?";
					else
						oss << " " << gameManager->GetLastMobSelected()->GetLife() << " / " << gameManager->GetLastMobSelected()->GetMaxLife();
					playerStat = true;
				}
				std::string HP = oss.str();
				str.replace(j + 4, HP.size(), HP);
				j += 4 + HP.size();
				m_sub[i] = str;
			}
			//Find ATK
			else if (str.at(j == 'A') && str.at(j + 1) == 'T' && str.at(j + 2) == 'K')
			{
				std::ostringstream oss;
				if (playerStat)
				{
					oss << " " << gameManager->GetPlayer().GetDamage();
					playerStat = false;
				}
				else
				{
					if (gameManager->GetLastMobSelected() == NULL)
						oss << " ?";
					else
						oss << " " << gameManager->GetLastMobSelected()->GetDamage();
					playerStat = true;
				}
				std::string ATK = oss.str();
				str.replace(j + 5, ATK.size(), ATK);
				j += 5 + ATK.size();
				m_sub[i] = str;
			}
			//Find ROOM
			else if (str.at(j == 'R') && str.at(j + 1) == 'O' && str.at(j + 2) == 'O')
			{
				std::ostringstream oss;
				oss << " " << gameManager->GetMap().GetCurrentChunkId() + 1;
				playerStat = false;
				std::string ROOM = oss.str();
				str.replace(j + 6, ROOM.size(), ROOM);
				j += 6 + ROOM.size();
				m_sub[i] = str;
			}
			//Find STATUS
			else if (str.at(j == 'S') && str.at(j + 1) == 'T' && str.at(j + 2) == 'A')
			{
				std::ostringstream oss;
				oss << " NONE";
				playerStat = true;
				std::string STATUS = oss.str();
				str.replace(j + 8, STATUS.size(), STATUS);
				j += 8 + STATUS.size();
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


