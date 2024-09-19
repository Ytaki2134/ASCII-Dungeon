#pragma once
#include "Mobs.h"
class GameManager;
class Golem : public Mobs
{
private: 

	
	GameManager* gameManager;


public :

	void Move()		override;
	void Chase()	override;
	void Attack()	override;
	void Death()	override;


};

