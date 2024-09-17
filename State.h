#pragma once
#include "StateManager.h"
class State
{
private:




public:

	virtual void OnEnter(StateManager* state, Mobs* monster);
	virtual void OnUpdate(StateManager* state, Mobs* monster);
	virtual void OnExit(StateManager* state, Mobs* monster);

};

