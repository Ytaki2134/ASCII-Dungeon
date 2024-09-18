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
			m_chunk[i][j] = currentLine[j];
		}
	}
}

void Chunk::SetChunkCoords(int x, int y, char content)
{
	m_chunk[x][y] = content;
}

void Chunk::SetChunkCoords(int x, int y, std::string content)
{
	m_chunk[x][y] = content;
}

std::vector<std::string> Chunk::getChunk(bool display)
{
	std::vector<std::string> vector;

	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		std::string currentLine;
		if (display) {
			for (size_t j = 0; j < ARRAY_SIZE; j++)
			{
				currentLine = currentLine + " " + m_chunk[i][j] + " ";
			}
		}
		else {
			for (size_t j = 0; j < ARRAY_SIZE; j++)
			{
				currentLine = currentLine + m_chunk[i][j];
			}
		}
		vector.push_back(currentLine);
	}

	return vector;
}