#include "IdleState.h"

void IdleState::OnEnter(StateManager* state, Mobs* monster)
{
	if (monster->ControlDistance())
		state->ChangeState(state->GetNearPlayerState());
	if (monster->getLife() == 0)
		state->ChangeState(state->GetDeathState());
	else
		OnUpdate(state , monster);
}

void IdleState::OnUpdate(StateManager* state, Mobs* monster)
{	
	monster->Move();
	OnExit(state, monster);
}

