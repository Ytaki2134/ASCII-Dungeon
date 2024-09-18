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

//void Chunk::RenderChunk()
//{
//	for (size_t i = 0; i < ARRAY_SIZE; i++)
//	{
//		std::string currentLine;
//		for (size_t j = 0; j < ARRAY_SIZE; j++)
//		{
//			currentLine = currentLine + " " + m_chunk[i][j] + " ";
//		}
//		std::cout << currentLine << std::endl;
//	}
//}

void Chunk::SetChunkCoords(int x, int y, char content)
{
	chunk[x][y] = content;
}

void Chunk::SetChunkCoords(int x, int y, std::string content)
{
	chunk[x][y] = content;
}

std::vector<std::string> Chunk::getChunk()
{
	std::vector<std::string> vector;

	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		std::string currentLine;
		for (size_t j = 0; j < ARRAY_SIZE; j++)
		{
			currentLine = currentLine + " " + m_chunk[i][j] + " ";
		}
		vector.push_back(currentLine);
	}

	return vector;
}