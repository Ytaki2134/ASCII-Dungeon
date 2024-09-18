#pragma once
#include "Chunk.h"

class Map
{
public:
	Map();

	void ImportMap(std::string);

	std::vector<Chunk> GetMap();
	Chunk GetCurrentChunk();
	int GetCurrentChunkId();
	void setCurrentChunkId(int);

private:
	std::vector<Chunk> m_ChunkVector;
	int m_currentChunk = 0;
};

