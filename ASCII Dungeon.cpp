// ASCII Dungeon.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "map.h"

int main()
{
	Chunk FirstChunk;
	Map FirstMap;

	/*FirstChunk.ImportChunk("Chunks/chunk-empty.txt");
	FirstChunk.RenderChunk();*/

	FirstMap.ImportMap("Chunks/map-empty.txt");
	FirstMap.GetMap()[0].RenderChunk();
}
