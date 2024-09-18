#pragma once
#include "Chunk.h"

class Map
{
public:
	Map();

	void ImportMap(std::string);
	void RenderChunk(int);

	std::vector<Chunk> GetMap();
	int GetCurrentChunk();

private:
	std::vector<Chunk> m_ChunkVector;
	int m_currentChunk;
};

