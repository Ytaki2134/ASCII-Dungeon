#include "CombatState.h"

#include "StateManager.h"
#include "Mobs.h"

#include"NearPlayerState.h"
#include"DeathState.h"

void CombatState::Enter(StateManager* stateManager)
{
	if (stateManager->GetMobs()->GetLife() == 0)
		stateManager->ChangeState(dynamic_cast<State*>(stateManager->GetDeathState()));
	if(stateManager->GetMobs()->GetDistance()>1)
		stateManager->ChangeState(dynamic_cast<State*>(stateManager->GetNearPlayerState()));
	else
		Update(stateManager);
}

void CombatState::Update(StateManager* stateManager)
{
	stateManager->GetMobs()->Attack();
	Exit(stateManager);
}

void CombatState::Exit(StateManager* stateManager)
{

}
