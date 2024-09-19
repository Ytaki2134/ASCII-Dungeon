#pragma once
#include "IdleState.h"
#include "NearPlayerState.h"
#include "CombatState.h"
#include "Deathstate.h"
class Mobs;

class StateManager
{
private:
	Mobs* monster;
	State* currentState = new IdleState();
	IdleState* Idle = new IdleState();
	NearPlayerState* NearPlayer = new NearPlayerState();
	CombatState* Combat = new CombatState();
	DeathState* Death = new DeathState();
public:

	void Initialize();
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

