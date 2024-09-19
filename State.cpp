#include "State.h"

void State::Enter(StateManager* stateManager) { std::cout << "enter" << std::endl; }

void State::Update(StateManager* stateManager) { std::cout << "execute" << std::endl; }

void State::Exit(StateManager* stateManager) {std::cout << "out" << std::endl; }