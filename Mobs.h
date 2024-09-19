#pragma once
#include "Entity.h"
#include "Player.h"
class StateManager;


class Mobs : public Entity{

private:

	Player* player = new Player();
	int detection = 10;

	StateManager* stateManager;


public:


	void Initialize();
	virtual void Move()  {};
	virtual void Chase() {};
	virtual void Attack(){};
	virtual void Death() {};

	void Play();

	void SetDetection(int range) { detection = range; };
	bool ControlDistance();
	bool ReadyToAttack() { return	(GetDistance() == 1) ? 1 : false; };
	int GetDistance();
	int CalculDistance(std::tuple<int, int> pos);
	Player* GetPlayer() ;
	void SetPlayer(Player* pl);

};
