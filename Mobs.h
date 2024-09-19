#pragma once
#include "Entity.h"
#include "Player.h"
class StateManager;


class Mobs : public Entity{

private:

	int detection = 10;
	Player* player;

	StateManager* stateManager;


public:


	void Initialize(Mobs* mob);
	virtual void Move()  ;
	virtual void Chase() ;
	virtual void Attack(){};
	virtual void Death() {};

	void Play();

	void SetDetection(int range) { detection = range; };
	bool ControlDistance();
	bool ReadyToAttack() { return	(GetDistance() == 1) ? 1 : false; };
	int GetDistance();
	int CalculDistance(Vector2 pos);
	Player* GetPlayer() ;
	void SetPlayer(Player* pl);

	virtual void ConfigureMonster(Player* pl);

};
