// ASCII Dungeon.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#pragma once
#include "GameManager.h"

int main()
{
	bool gameRunning = true;
	GameManager GameManager;

	GameManager.InitGame("Chunks/map-empty.txt");

	while (gameRunning)
	{
		GameManager.CheckInputs();
	}
}
