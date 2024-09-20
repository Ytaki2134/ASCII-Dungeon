#include "NearPlayerState.h"
#include "StateManager.h"

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
    case 'G': {
        Golem* golem = dynamic_cast<Golem*>(stateManager->GetMobs());
        if (golem) {
            golem->Chase();  // Appelle Chase() seulement si le cast a réussi
        }
        else {
            std::cerr << "Error: Failed to cast to Golem." << std::endl;
        }
        break;
    }
    case 'F': {
        Faucheur* faucheur = dynamic_cast<Faucheur*>(stateManager->GetMobs());
        if (faucheur) {
            faucheur->Chase();
        }
        else {
            std::cerr << "Error: Failed to cast to Faucheur." << std::endl;
        }
        break;
    }
    case 'S': {
        Spectre* spectre = dynamic_cast<Spectre*>(stateManager->GetMobs());
        if (spectre) {
            spectre->Chase();
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

void NearPlayerState::Exit(StateManager* stateManager)
{
	if (stateManager-> GetMobs()->ReadyToAttack()) {
		stateManager->ChangeState(dynamic_cast<State*>(stateManager->GetCombatState()));
		stateManager->GetCurrentState()->Enter(stateManager);
	}
}
