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
		//X axis - 0 to 16
		for (size_t j = 0; j < ARRAY_SIZE; j++)
		{
			//Y axis - 0 to 16 then 18 to 33 ...
			for (size_t k = (ARRAY_SIZE + 2) * i; k < ARRAY_SIZE * (i+1) + 1*i; k++)
			{
				currentLine = outputs[k];
				tempChunk.SetChunk(j, k%16, currentLine[k%16]);
			}
		}
		m_ChunkVector.push_back(tempChunk);
	}
}

std::vector<Chunk> Map::GetMap()
{
	return Map::m_ChunkVector;
}
