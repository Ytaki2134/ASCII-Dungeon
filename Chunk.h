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

	void SetChunk(int, int, char);
	void SetChunk(int, int, std::string);
private:
	std::string chunk[ARRAY_SIZE][ARRAY_SIZE];
};

