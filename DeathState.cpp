#include "DeathState.h"


#include "StateManager.h"


#include"NearPlayerState.h"

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
	case 'G': {
		Golem* golem = dynamic_cast<Golem*>(stateManager->GetMobs());
		golem->Death();
		break;
	}
	case 'F': {
		Faucheur* faucheur = dynamic_cast<Faucheur*>(stateManager->GetMobs());
		faucheur->Death();
		break;
	}
	case 'S': {
		Spectre* spectre = dynamic_cast<Spectre*>(stateManager->GetMobs());
		spectre->Death();
		break;
	}
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
