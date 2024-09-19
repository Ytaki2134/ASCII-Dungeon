#include "CombatState.h"

#include "StateManager.h"
#include "Mobs.h"

#include"NearPlayerState.h"
#include"DeathState.h"

#include "Golem.h"
#include "Faucheur.h"
#include "Spectre.h"
void CombatState::Enter(StateManager* stateManager)
{
	if (stateManager->GetMobs()->GetLife() <= 0){
		stateManager->ChangeState(dynamic_cast<State*>(stateManager->GetDeathState()));
		stateManager->EnterState();
	}
	else if (stateManager->GetMobs()->GetDistance() > 1) {
		stateManager->ChangeState(dynamic_cast<State*>(stateManager->GetNearPlayerState()));
		stateManager->EnterState();
	}
	else
		Update(stateManager);
}

void CombatState::Update(StateManager* stateManager)
{
	switch (stateManager->GetMobs()->GetToken())
	{
	case 'G':
		Golem * mob = dynamic_cast<Golem*>(stateManager->GetMobs());
		mob->Attack();
		break;
	case 'F':
		Faucheur * mob = dynamic_cast<Faucheur*>(stateManager->GetMobs());
		mob->Attack();
		break;
	case 'S':
		Spectre * mob = dynamic_cast<Spectre*>(stateManager->GetMobs());
		mob->Attack();
		break;
	default:
		break;
	}
	Exit(stateManager);
}

void CombatState::Exit(StateManager* stateManager)
{

}
