#include "Map.h"


Map::Map()
{
}

void Map::ImportMap(std::string path)
{
	std::vector<std::string> outputs;
	std::ifstream importFile(path);
	//temp buffer
	std::string currentLine;

	int chunkCount = 1;
	while (std::getline(importFile, currentLine))
	{
		outputs.push_back(currentLine);
		if (currentLine.find("$") != std::string::npos) {
			chunkCount += 1;
		}
	}

	for (int i = 0; i < chunkCount; i++)
	{
		Chunk tempChunk;
		//Step - 0,17,34 ...
		int step = (ARRAY_SIZE + 1) * i;

		//X axis - 0 to 16
		for (int j = 0; j < ARRAY_SIZE; j++)
		{
			currentLine = outputs[j + step];
			//Y axis - 0 to 16
			for (int k = 0; k < ARRAY_SIZE; k++)
			{
				tempChunk.SetChunkCoords(j, k, currentLine[k]);
			}
		}
		m_chunkVector.push_back(tempChunk);
	}
}

std::vector<Chunk> Map::GetChunkVector()
{
	return m_chunkVector;
}

Chunk Map::GetCurrentChunk()
{
	return m_chunkVector[GetCurrentChunkId()];
}

void Map::SetCurrentChunkCoords(int x, int y, std::string content)
{
	m_chunkVector[m_currentChunkId].SetChunkCoords(x, y, content);
}

void Map::SetCurrentChunkCoords(int x, int y, char content)
{
	m_chunkVector[m_currentChunkId].SetChunkCoords(x, y, content);
}

int Map::GetCurrentChunkId()
{
	return m_currentChunkId;
}

void Map::setCurrentChunkId(int newId)
{
	m_currentChunkId = newId;
}
