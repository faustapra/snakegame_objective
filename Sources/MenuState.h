#pragma once
#include "Defines.h"
#include "Utils.h"
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

	//privatus metodai, nes bus naudojami tik kituose šios klasės metoduose

	void moveUp();
	void moveDown();

public:
	MenuState(Game* game);

	void handleInput() override;
	void update(double dt) override;
	void draw() override;

};

