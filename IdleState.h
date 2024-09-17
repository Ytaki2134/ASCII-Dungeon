#pragma once
#include"State.h"
#include"Mobs.h"

class IdleState :public State {

public:

	void OnEnter(StateManager* state , Mobs* monster) override;
	void OnUpdate(StateManager* state, Mobs* monster)override;
};