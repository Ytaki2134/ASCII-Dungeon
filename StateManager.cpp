#include "StateManager.h"

void StateManager::EnterState()
{
	GetCurrentState().OnEnter(this,monster);
}


