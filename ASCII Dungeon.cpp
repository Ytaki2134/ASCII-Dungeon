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
	Map FirstMap;

	FirstMap.ImportMap("Chunks/map-empty.txt");
	FirstMap.GetMap()[2].RenderChunk();
}
