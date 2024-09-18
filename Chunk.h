#pragma once
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
	void RenderChunk();

	void SetChunkCoords(int, int, char);
	void SetChunkCoords(int, int, std::string);
private:
	std::string m_chunk[ARRAY_SIZE][ARRAY_SIZE];
};

