#include "StateManager.h"
#include "Mobs.h"

void StateManager::Initialize()
{
    currentState = GetIdle();
}

State* StateManager::GetCurrentState() 
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
