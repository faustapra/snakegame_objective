#pragma once


class Game;

class State {
public:

	Game* game;
	virtual void handleInput() = 0;
	virtual void update(double dt) = 0;
	virtual void draw() = 0;
};