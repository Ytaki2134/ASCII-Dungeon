#pragma once
#include "Entity.h"
class StateManager;
class Player;

class Mobs : public Entity{

private:

	Player* player;
	int detection = 6;

	StateManager* stateManager ;
	// RecompenseOnDeath deathmob;
	// StateMachine ia;
	// Skill uniqueskill;

public:

	//virtual void SetRecompenseOnDeath(recompenseondeath _deathmob) {deathmob=_deathmob;} 
	//virtual void SetStateMachine( StateMachine _ia) {ia = _ia;}
	//virtual void SetUniqueSkill ( Skill skill) {uniqueskill = skill;}


	virtual void Move()  {};
	virtual void Chase() {};
	virtual void Attack(){};
	virtual void Death() {};

	bool ControlDistance();
	bool ReadyToAttack() { return	(GetDistance() == 1) ? 1 : false; };
	int GetDistance();
	int ComputeDistance(Vector2 pos);
	Player* GetPlayer() ;
	void SetPlayer(Player* pl);




	//virtual RecompenseOnDeath getRecompenseOnDeat(){return dethmob;}
	//virtual StateMachine getStateMachine(){return ia;}
	//virtual Skill getUniqueSkill(){return uniqueskill;}


};
