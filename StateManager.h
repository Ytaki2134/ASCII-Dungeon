#pragma once
#include <variant>
#include "NearPlayerState.h"
#include "CombatState.h"
#include "Deathstate.h"
class Mobs;
class IdleState;

class StateManager
{
private:

	Mobs* monster;
	State* currentState  = nullptr;
	IdleState* Idle;
	NearPlayerState* NearPlayer;
	CombatState* Combat ;
	DeathState* Death;
public:
	
	State* GetCurrentState()				const ;
	IdleState* GetIdle()					const ;
	NearPlayerState* GetNearPlayerState()	const ;
	CombatState* GetCombatState()			const ;
	DeathState* GetDeathState()				const ;


	Mobs* GetMobs() ;
	void EnterState() ;
	void ChangeState(State* newstate) ;


	void SetMonster(Mobs* _monster) ;
};

