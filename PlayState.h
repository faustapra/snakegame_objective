#pragma once
#include "State.h"
#include "Snake.h"
#include "Utils.h"

class PlayState : public State {
private:

	//dvi gyvates, obuolys
	Snake playerSnake, computerSnake;
	Component food;
	double timeElapsed;

	

public:
	PlayState(Game* game);

	
};

