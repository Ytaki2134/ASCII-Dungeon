#include "DeathState.h"

#include "StateManager.h"
#include "Golem.h"
#include "Faucheur.h"
#include "Spectre.h"

void DeathState::Enter(StateManager* stateManager)
{
	// animation ou autres
	Update(stateManager);
}

void DeathState::Update(StateManager* stateManager)
{
	//donner les recompenses
	switch (stateManager->GetMobs()->GetToken())
	{
	case 'G':
		Golem * mob = dynamic_cast<Golem*>(stateManager->GetMobs());
		mob->Death();
		break;
	case 'F':
		Faucheur * mob = dynamic_cast<Faucheur*>(stateManager->GetMobs());
		mob->Death();
		break;
	case 'S':
		Spectre * mob = dynamic_cast<Spectre*>(stateManager->GetMobs());
		mob->Death();
		break;
	default:
		break;
	}
	Exit(stateManager);
}

void DeathState::Exit(StateManager* stateManager)
{
	std::cout << "enemy kill" << std::endl;
	//clear l'ennemie
}
