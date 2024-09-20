#include "IdleState.h"
#include "StateManager.h"


#include"NearPlayerState.h"
#include"DeathState.h"

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
    case 'G': {
        Mobs* a = stateManager->GetMobs();
        Golem* golem = dynamic_cast<Golem*>(a);
        if (golem) {
            golem->Move();  // Appelle Move() seulement si le cast a réussi
        }
        else {
            // Gestion d'erreur si le cast échoue
            std::cerr << "Error: Failed to cast to Golem." << std::endl;
        }
        break;
    }
    case 'F': {
        Faucheur* faucheur = dynamic_cast<Faucheur*>(stateManager->GetMobs());
        if (faucheur) {
            faucheur->Move();
        }
        else {
            std::cerr << "Error: Failed to cast to Faucheur." << std::endl;
        }
        break;
    }
    case 'S': {
        Spectre* spectre = dynamic_cast<Spectre*>(stateManager->GetMobs());
        if (spectre) {
            spectre->Move();
        }
        else {
            std::cerr << "Error: Failed to cast to Spectre." << std::endl;
        }
        break;
    }
    default: {
        std::cerr << "Error: Unknown token." << std::endl;
        break;
    }
    }
	Exit(stateManager);
}

void IdleState::Exit(StateManager* stateManager)
{
	//patrol
}

