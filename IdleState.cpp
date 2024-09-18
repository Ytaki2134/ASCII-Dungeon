#include "IdleState.h"
#include "StateManager.h"
#include "Mobs.h"
void IdleState::Enter(StateManager* stateManager)
{
	if (stateManager->GetMobs()->ControlDistance())
		stateManager->ChangeState(stateManager->GetNearPlayerState());
	if (stateManager->GetMobs()->getLife() == 0)
		stateManager->ChangeState(stateManager->GetDeathState());
	else
		Update(stateManager);
}

void IdleState::Update(StateManager* stateManager)
{	
	stateManager->GetMobs()->Move();
	Exit(stateManager);
}

void IdleState::Exit(StateManager* stateManager)
{
	//patrol
}

