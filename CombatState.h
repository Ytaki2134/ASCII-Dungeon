#pragma once
#include "State.h"
class CombatState :public State
{
	void OnEnter(StateManager* state, Mobs* monster) override;
	void OnUpdate(StateManager* state, Mobs* monster)override;
	void OnExit(StateManager* state, Mobs* monster)override;
};

