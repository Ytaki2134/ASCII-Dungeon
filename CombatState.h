#pragma once
#include "State.h"
class CombatState : public State
{
public:
	void Enter(StateManager* stateManager) override ;
	void Update(StateManager* stateManager) override;
	void Exit(StateManager* stateManager) override ;
};

