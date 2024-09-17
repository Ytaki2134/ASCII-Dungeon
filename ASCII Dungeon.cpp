// ASCII Dungeon.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Chunk.h"

//void ImportChunk(std::string path)
//{
//	std::vector<std::string> outputs;
//	std::ifstream importFile(path);
//	//temp buffer
//	std::string currentLine;
//
//	while (std::getline(importFile, currentLine))
//	{
//		outputs.push_back(currentLine);
//	}
//
//	for (size_t i = 0; i < ARRAY_SIZE; i++)
//	{
//		currentLine = outputs[i];
//		for (size_t j = 0; j < ARRAY_SIZE; j++)
//		{
//			chunk[i][j] = currentLine[j];
//		}
//	}
//}
//
//void RenderChunk()
//{
//	for (size_t i = 0; i < ARRAY_SIZE; i++)
//	{
//		for (size_t j = 0; j < ARRAY_SIZE; j++)
//		{
//			std::cout << chunk[i][j];
//		}
//		std::cout << std::endl;
//	}
//}

int main()
{
	Chunk FirstChunk;

	FirstChunk.ImportChunk("Chunks/chunk-empty.txt");
	FirstChunk.RenderChunk();
}
