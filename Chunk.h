#pragma once
#include"Vector2.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Chunk
{
public:
#define ARRAY_SIZE 15
	Chunk();

	void ImportChunk(std::string);

	void SetChunkCoords(int, int, char);
	void SetChunkCoords(int, int, std::string);
	std::vector<std::string> getChunk(bool);
private:
	std::string m_chunk[ARRAY_SIZE][ARRAY_SIZE];
};
