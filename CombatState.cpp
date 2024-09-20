#include "CombatState.h"

#include "StateManager.h"
#include "Mobs.h"



#include"NearPlayerState.h"
#include"DeathState.h"

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
    case 'G': {
        Golem* golem = dynamic_cast<Golem*>(stateManager->GetMobs());
        if (golem) {
            golem->Attack();  // Appelle Attack() seulement si le cast a réussi
        }
        else {
            std::cerr << "Error: Failed to cast to Golem." << std::endl;
        }
        break;
    }
    case 'F': {
        Faucheur* faucheur = dynamic_cast<Faucheur*>(stateManager->GetMobs());
        if (faucheur) {
            faucheur->Attack();
        }
        else {
            std::cerr << "Error: Failed to cast to Faucheur." << std::endl;
        }
        break;
    }
    case 'S': {
        Spectre* spectre = dynamic_cast<Spectre*>(stateManager->GetMobs());
        if (spectre) {
            spectre->Attack();
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

void CombatState::Exit(StateManager* stateManager)
{

}
