#pragma once
#include "Global.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Chunk
{
public:
	Chunk();

	void ImportChunk(std::string);
	void RenderChunk();
private:
	std::string chunk[ARRAY_SIZE][ARRAY_SIZE];
};

