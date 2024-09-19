#pragma once
#include "Entity.h"
#include "Player.h"
class StateManager;


class Mobs : public Entity{

private:

	Player* player = new Player();
	int detection = 6;

	StateManager* stateManager;
	// RecompenseOnDeath deathmob;
	// StateMachine ia;
	// Skill uniqueskill;

public:

	//virtual void SetRecompenseOnDeath(recompenseondeath _deathmob) {deathmob=_deathmob;} 
	//virtual void SetStateMachine( StateMachine _ia) {ia = _ia;}
	//virtual void SetUniqueSkill ( Skill skill) {uniqueskill = skill;}


	void Initialize();
	virtual void Move()  {};
	virtual void Chase() {};
	virtual void Attack(){};
	virtual void Death() {};

	void Play();

	bool ControlDistance();
	bool ReadyToAttack() { return	(GetDistance() == 1) ? 1 : false; };
	int GetDistance();
	int CalculDistance(std::tuple<int, int> pos);
	Player* GetPlayer() ;
	void SetPlayer(Player* pl);




	//virtual RecompenseOnDeath getRecompenseOnDeat(){return dethmob;}
	//virtual StateMachine getStateMachine(){return ia;}
	//virtual Skill getUniqueSkill(){return uniqueskill;}


};
