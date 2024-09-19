#pragma once
#include<iostream>
class StateManager;


class State
{
protected:

public:
	virtual void Enter(StateManager* stateManager) ;
	virtual void Update(StateManager* stateManager) ;
	virtual void Exit(StateManager* stateManager)  ;
};

