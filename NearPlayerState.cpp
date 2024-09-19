#include "NearPlayerState.h"
#include "StateManager.h"
#include "Mobs.h"

#include "IdleState.h"
#include "DeathState.h"

void NearPlayerState::Enter(StateManager* stateManager)
{
	
	if (!stateManager->GetMobs()->ControlDistance()) {
		stateManager->ChangeState(dynamic_cast<State*>(stateManager->GetIdle()));
		stateManager->EnterState();
	}
	else if (stateManager->GetMobs()->ReadyToAttack()) {
		stateManager->ChangeState(dynamic_cast<State*>(stateManager->GetCombatState()));
		stateManager->GetCurrentState()->Enter(stateManager);
	}
	else if (stateManager->GetMobs()->getLife() <= 0) {
		stateManager->ChangeState(dynamic_cast<State*>(stateManager->GetDeathState()));
		stateManager->EnterState();
	}
	else
	{
		Update(stateManager);

	}
}

void NearPlayerState::Update(StateManager* stateManager)
{
	stateManager->GetMobs()->Chase();
	Exit(stateManager);
}

void NearPlayerState::Exit(StateManager* stateManager)
{
	if (stateManager-> GetMobs()->ReadyToAttack()) {
		stateManager->ChangeState(dynamic_cast<State*>(stateManager->GetCombatState()));
		stateManager->GetCurrentState()->Enter(stateManager);
	}
}
