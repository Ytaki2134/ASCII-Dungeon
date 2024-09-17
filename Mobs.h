#pragma once
#include "Entity.h"
#include "Player.h"
#include "StateManager.h"
class Mobs : public Entity{

private:

	Player* player;
	int detection = 6;

	StateManager stateManager;
	// RecompenseOnDeath deathmob;
	// StateMachine ia;
	// Skill uniqueskill;

public:

	//virtual void SetRecompenseOnDeath(recompenseondeath _deathmob) {deathmob=_deathmob;} 
	//virtual void SetStateMachine( StateMachine _ia) {ia = _ia;}
	//virtual void SetUniqueSkill ( Skill skill) {uniqueskill = skill;}
	virtual void Move()		= 0;
	virtual void Chase()	= 0;
	virtual void Attack()	= 0;
	virtual void Death()	= 0;

	bool ControlDistance();
	bool ReadyToAttack()	{	return	(GetDistance() == 1) ?  1 : false; }
	int GetDistance()		{	return  (std::get<0>(GetPosition()) - std::get<0>(player->GetPosition())) + (std::get<1>(GetPosition()) - std::get<1>(player->GetPosition())); }// ( x B − x A ) + ( y B − y A )
	Player* GetPlayer()		{	return player; }

	//virtual RecompenseOnDeath getRecompenseOnDeat(){return dethmob;}
	//virtual StateMachine getStateMachine(){return ia;}
	//virtual Skill getUniqueSkill(){return uniqueskill;}


};

