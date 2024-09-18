#include "CombatState.h"
#include "StateManager.cpp"
void CombatState::Enter(StateManager* stateManager)
{
	//if (stateManager->GetMobs()->getLife() == 0)
	//	stateManager->ChangeState(stateManager->GetDeathState());
	//if(stateManager->GetMobs()->GetDistance()>1)
	//	stateManager->ChangeState(GetStateManager()->GetNearPlayerState());
	//else
	//	Update(stateManager);
}

void CombatState::Update(StateManager* stateManager)
{
	//GetMobs()->Attack();
	//Exit();
}

void CombatState::Exit(StateManager* stateManager)
{

}
