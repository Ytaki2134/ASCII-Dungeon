#include "CombatState.h"

void CombatState::OnEnter(StateManager* state, Mobs* monster)
{
	if (monster->getLife() == 0)
		state->ChangeState(state->GetDeathState());
	if(monster->GetDistance()>1)
		state->ChangeState(state->GetNearPlayerState());
	else
		OnUpdate(state, monster);
}

void CombatState::OnUpdate(StateManager* state, Mobs* monster)
{
	monster->Attack();
	OnExit(state, monster);
}

void CombatState::OnExit(StateManager* state, Mobs* monster)
{
}
