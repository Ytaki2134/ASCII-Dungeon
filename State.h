#pragma once
#include "StateManager.h"
class State
{
private:

public:

	virtual void OnEnter(StateManager* state, Mobs* monster)	=	0 ;
	virtual void OnUpdate(StateManager* state, Mobs* monster)	=	0 ;
	virtual void OnExit(StateManager* state, Mobs* monster)		=	0 ;

};

