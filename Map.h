#pragma once
#include "Chunk.h"

class Map
{
public:
	Map();

	void ImportMap(std::string);
	std::vector<Chunk> GetMap();

private:
	std::vector<Chunk> m_ChunkVector;
};

