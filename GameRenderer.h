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
public:
	GameRenderer();
	std::string Center(const std::string&, int);
	void ImportTitle(std::string);
	void RenderScreen(Map);
	void RenderTitle();
    void RenderChunk(std::vector<std::string>) ;
};

