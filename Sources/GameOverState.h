#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include "Defines.h"
#include "Utils.h"

using namespace sf;

class GameOverState : public State {
private:
	//teksto masyvas skirtas meniu 
	Text menu[MAX_NUMBER_OF_ITEMS];
	Font font;
	double timeElapsed;
	int selectedItemIndex;
	int pressedItemIndex;

	////privatus metodai, nes bus naudojami tik kituose šios klasės metoduose
	void moveUp();
	void moveDown();

public:
	GameOverState(Game* game);

	void handleInput() override;
	void update(double dt) override;
	void draw() override;

};