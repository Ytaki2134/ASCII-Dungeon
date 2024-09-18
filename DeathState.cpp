#include "DeathState.h"
#include "StateManager.cpp"
void DeathState::Enter(StateManager* stateManager)
{
	// animation ou autres
	Update(stateManager);
}

void DeathState::Update(StateManager* stateManager)
{
	//donner les recompenses
	Exit(stateManager);
}

void DeathState::Exit(StateManager* stateManager)
{
	std::cout << "enemy kill" << std::endl;
	//clear l'ennemie
}
