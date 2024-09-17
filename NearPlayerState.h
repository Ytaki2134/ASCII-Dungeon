#pragma once
#include "State.h"
class NearPlayerState : public State
{

private:

public:

	void OnEnter(StateManager* state, Mobs* monster) override;
	void OnUpdate(StateManager* state, Mobs* monster)override;
	void OnExit(StateManager* state, Mobs* monster)override;

};

