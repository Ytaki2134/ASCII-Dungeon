#include "NearPlayerState.h"

void NearPlayerState::OnEnter(StateManager* state, Mobs* monster)
{
	if (!monster->ControlDistance())
		state->ChangeState(state->GetIdle());
	if (monster->getLife() == 0)
		state->ChangeState(state->GetDeathState());
	else
		OnUpdate(state, monster);
}

void NearPlayerState::OnUpdate(StateManager* state, Mobs* monster)
{
	monster->Chase();
	OnExit(state, monster);
}

void NearPlayerState::OnExit(StateManager* state, Mobs* monster)
{
	if (monster->ReadyToAttack()) {
		state->ChangeState(state->GetCombatState());
		state->GetCurrentState().OnEnter(state,monster);
	}
}
