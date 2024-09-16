// ASCII Dungeon.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const int size = 16;
std::string chunk[size][size];

void ImportChunk(std::string path)
{
	std::vector<std::string> outputs;
	std::ifstream importFile(path);
	//temp buffer
	std::string currentLine;

	while (std::getline(importFile, currentLine))
	{
		outputs.push_back(currentLine);
	}

	for (size_t i = 0; i < size; i++)
	{
		currentLine = outputs[i];
		for (size_t j = 0; j < size; j++)
		{
			chunk[i][j] = currentLine[j];
		}
	}
}

void RenderChunk()
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			std::cout << chunk[i][j];
		}
		std::cout << std::endl;
	}
}

int main()
{
	ImportChunk("Chunks/chunk-full.txt");
	RenderChunk();
}
