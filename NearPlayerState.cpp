#include "NearPlayerState.h"
#include "StateManager.cpp"
void NearPlayerState::Enter(StateManager* stateManager)
{
	
	//if (!GetMobs()->ControlDistance())
	//	GetStateManager()->ChangeState(GetStateManager()->GetIdle());
	//if (GetMobs()->getLife() == 0)
	//	GetStateManager()->ChangeState(GetStateManager()->GetDeathState());
	//else
		Update(stateManager);
}

void NearPlayerState::Update(StateManager* stateManager)
{
	//GetMobs()->Chase();
	Exit(stateManager);
}

void NearPlayerState::Exit(StateManager* stateManager)
{
	//if (GetMobs()->ReadyToAttack()) {
	//	GetStateManager()->ChangeState(GetStateManager()->GetCombatState());

	//	GetStateManager()->GetCurrentState().SetStateManager(GetStateManager());

	//	GetStateManager()->GetCurrentState().Enter();
	//}
}
