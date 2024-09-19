#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>

#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include "ConsoleColor.h"

class GameRenderer
{
private:
	std::vector<std::string> m_title;
	std::vector<std::string> m_sub;
	void ImportTitle(std::string);
	void ImportSub(std::string);
	void RenderTitle();

    void RenderChunk(std::vector<std::string>);
	void RenderSubScreen();

	std::string Center(const std::string&, int);
public:

	GameRenderer();
	void RenderScreen(Map);
	//void ColorStringChar(int, std::ostream*);
};

