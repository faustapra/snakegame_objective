#pragma once
#include "State.h"
#include "Defines.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class MenuState : public State {
private:
	// sriftas, sukuriamas teksto masyvas meniu parinktims
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];
	int selectedItemIndex;
	int pressedItemIndex;
	double timeElapsed;

	

public:
	MenuState(Game* game);


};

