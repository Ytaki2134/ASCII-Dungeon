#pragma once
#include "Entity.h"
#include "Player.h"

class StateManager;
class GameManager;
class Mobs : public Entity {

private:

	int detection = 10;
	Player* player;

	StateManager* stateManager;
	GameManager* gameManager;

public:
	void Initialize(Mobs* mob);
	virtual void Move();
	virtual void Chase();
	virtual void Attack();
	virtual void Death();

	virtual void ConfigureMonster() {};

	virtual void GetDamagePlayer(int damage) {};

	void Play();

	void SetDetection(int range) { detection = range; };
	bool ControlDistance();
	bool ReadyToAttack() { return	(GetDistance() == 1) ? true : false; };
	int GetDistance();
	int CalculDistance(Vector2 pos);
	Player* GetPlayer();
	void SetPlayer(Player* pl);

	virtual void ConfigureMonster(Player* pl);

};
