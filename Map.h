#pragma once
#include "Chunk.h"

class Map
{
public:
	Map();

	void ImportMap(std::string);

	std::vector<Chunk> GetChunkVector();
	Chunk GetCurrentChunk();
	void SetCurrentChunkCoords(int, int, std::string);
	void SetCurrentChunkCoords(int, int, char);
	int GetCurrentChunkId();
	void setCurrentChunkId(int);

private:
	std::vector<Chunk> m_chunkVector;
	int m_currentChunkId = 0;
};

