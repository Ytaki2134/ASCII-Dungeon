#pragma once
#include "Global.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Chunk
{
public:
#define ARRAY_SIZE 16
	Chunk();

	void ImportChunk(std::string);

	void SetChunkCoords(int, int, char);
	void SetChunkCoords(int, int, std::string);
	std::vector<std::string> getChunk();
private:
	std::string chunk[ARRAY_SIZE][ARRAY_SIZE];
};
