#include "Mobs.h"
#include "IdleState.h"
#include "StateManager.h"


State* StateManager::GetCurrentState() const
{
    return currentState;
}

IdleState* StateManager::GetIdle() const { return Idle; }

NearPlayerState* StateManager::GetNearPlayerState() const { return NearPlayer; }

CombatState* StateManager::GetCombatState() const { return Combat; }

DeathState* StateManager::GetDeathState() const { return Death; }

Mobs* StateManager::GetMobs() { return monster; }

void StateManager::EnterState() { GetCurrentState()->Enter(this); }

void StateManager::ChangeState(State* newstate) { currentState = newstate; }

void StateManager::SetMonster(Mobs* _monster) { monster = _monster; }
