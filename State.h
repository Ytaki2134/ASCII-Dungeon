#pragma once
#include<iostream>
#include "Golem.h"
#include "Faucheur.h"
#include "Spectre.h"


class StateManager;


class State
{
protected:

public:
	virtual void Enter(StateManager* stateManager) ;
	virtual void Update(StateManager* stateManager) ;
	virtual void Exit(StateManager* stateManager)  ;
};

