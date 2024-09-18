// ASCII Dungeon.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#pragma once
#include "GameManager.h"

int main()
{
	//bool GameRunning = true;
	GameManager gameManager;

	//gameManager.InitGame("Ressources/map-empty.txt");
	gameManager.Try();
	
	/*while (GameRunning)
	{
		gameManager.CheckInputs();
	}*/
}
