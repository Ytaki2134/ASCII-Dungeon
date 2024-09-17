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

	for (size_t i = 0; i < chunkCount; i++)
	{
		Chunk tempChunk;
		//Step - 0,17,34 ...
		int step = (ARRAY_SIZE + 1) * i;

		//X axis - 0 to 16
		for (size_t j = 0; j < ARRAY_SIZE; j++)
		{
			currentLine = outputs[j + step];
			//Y axis - 0 to 16
			for (size_t k = 0; k < ARRAY_SIZE; k++)
			{
				tempChunk.SetChunk(j, k, currentLine[k]);
			}
		}
		m_ChunkVector.push_back(tempChunk);
	}
}

std::vector<Chunk> Map::GetMap()
{
	return Map::m_ChunkVector;
}
