#pragma once
#include"Mobs.h"
#include "State.h"
#include"IdleState.h"
#include"NearPlayerState.h"
#include"CombatState.h"
#include"Deathstate.h"

class StateManager
{
private:

	Mobs* monster;
	State currentState;
	IdleState Idle;
	NearPlayerState NearPlayer;
	CombatState Combat;
	DeathState Death;
public:

	void EnterState();
	void ChangeState(State newstate) { currentState = newstate; }

	State GetCurrentState()					{ return currentState; }
	IdleState GetIdle()						{ return Idle; }
	NearPlayerState GetNearPlayerState()	{ return NearPlayer; }
	CombatState GetCombatState()			{ return Combat; }
	DeathState GetDeathState()				{ return Death; }

	void SetMonster(Mobs* mobs) { monster = mobs; }
};

