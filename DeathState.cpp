#include "DeathState.h"

void DeathState::OnEnter(StateManager* state, Mobs* monster)
{
	// animation ou autres
	OnUpdate(state,monster);
}

void DeathState::OnUpdate(StateManager* state, Mobs* monster)
{
	//donner les recompenses
	OnExit(state, monster);
}

void DeathState::OnExit(StateManager* state, Mobs* monster)
{
	//clear l'ennemie
}
