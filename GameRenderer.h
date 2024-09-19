#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "map.h"

class GameRenderer
{
private:
	std::vector<std::string> m_title;
	void ImportTitle(std::string);
	void RenderTitle();
    void RenderChunk(std::vector<std::string>);
	std::string Center(const std::string&, int);
public:

	GameRenderer();
	void RenderScreen(Map);
	//void ColorStringChar(int, std::ostream*);
};

