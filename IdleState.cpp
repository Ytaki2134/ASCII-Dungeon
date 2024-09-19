#include "IdleState.h"
#include "StateManager.h"
#include "Mobs.h"

#include"NearPlayerState.h"
#include"DeathState.h"

#include "Golem.h"
#include "Faucheur.h"
#include "Spectre.h"

void IdleState::Enter(StateManager* stateManager)
{
	if (stateManager->GetMobs()->ControlDistance()) {
		stateManager->ChangeState(dynamic_cast<State*>(stateManager->GetNearPlayerState()));
		stateManager->EnterState();
	}
	else if (stateManager->GetMobs()->GetLife() <= 0) {
		stateManager->ChangeState(dynamic_cast<State*>(stateManager->GetDeathState()));
		stateManager->EnterState();
	}
	
	else

		Update(stateManager);
}

void IdleState::Update(StateManager* stateManager)
{	
	switch (stateManager->GetMobs()->GetToken())
	{
	case 'G':
		Golem * mob = dynamic_cast<Golem*>(stateManager->GetMobs());
		mob->Move();
		break;
	case 'F':
		Faucheur * mob = dynamic_cast<Faucheur*>(stateManager->GetMobs());
		mob->Move();
		break;
	case 'S':
		Spectre * mob = dynamic_cast<Spectre*>(stateManager->GetMobs());
		mob->Move();
		break;
	default:
		break;
	}
	Exit(stateManager);
}

void IdleState::Exit(StateManager* stateManager)
{
	//patrol
}

