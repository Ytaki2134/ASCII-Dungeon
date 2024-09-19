#include "NearPlayerState.h"
#include "StateManager.h"
#include "Mobs.h"

#include "IdleState.h"
#include "DeathState.h"

#include "Golem.h"
#include "Faucheur.h"
#include "Spectre.h"

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
	else if (stateManager->GetMobs()->GetLife() <= 0) {
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
	switch (stateManager->GetMobs()->GetToken())
	{
	case 'G':
		Golem * mob = dynamic_cast<Golem*>(stateManager->GetMobs());
		mob->Chase();
		break;
	case 'F':
		Faucheur * mob = dynamic_cast<Faucheur*>(stateManager->GetMobs());
		mob->Chase();
		break;
	case 'S':
		Spectre * mob = dynamic_cast<Spectre*>(stateManager->GetMobs());
		mob->Chase();
		break;
	default:
		break;
	}
	Exit(stateManager);
}

void NearPlayerState::Exit(StateManager* stateManager)
{
	if (stateManager-> GetMobs()->ReadyToAttack()) {
		stateManager->ChangeState(dynamic_cast<State*>(stateManager->GetCombatState()));
		stateManager->GetCurrentState()->Enter(stateManager);
	}
}
