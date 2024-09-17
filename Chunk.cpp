#include "Chunk.h"

Chunk::Chunk()
{
}

void Chunk::ImportChunk(std::string path)
{
	std::vector<std::string> outputs;
	std::ifstream importFile(path);
	//temp buffer
	std::string currentLine;

	while (std::getline(importFile, currentLine))
	{
		outputs.push_back(currentLine);
	}

	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		currentLine = outputs[i];
		for (size_t j = 0; j < ARRAY_SIZE; j++)
		{
			Chunk::chunk[i][j] = currentLine[j];
		}
	}
}

void Chunk::RenderChunk()
{
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		for (size_t j = 0; j < ARRAY_SIZE; j++)
		{
			std::cout << Chunk::chunk[i][j];
		}
		std::cout << std::endl;
	}
}

void Chunk::SetChunk(int x, int y, char content)
{
	chunk[x][y] = content;
}

void Chunk::SetChunk(int x, int y , std::string content)
{
	chunk[x][y] = content;
}
