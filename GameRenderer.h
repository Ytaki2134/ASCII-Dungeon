#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "map.h"

class GameRenderer
{
public:

	GameRenderer();
	std::string Center(const std::string&, int);
	void ImportTitle(std::string);
	void RenderScreen(Map);
	void RenderTitle();
    void RenderChunk(std::vector<std::string>) ;
private:
	std::vector<std::string> m_title;
};

