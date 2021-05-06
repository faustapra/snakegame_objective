#pragma once

#include "Objects.h"

class Snake {
private:
	Component body[100];
	int length, direction;

public:
	Snake();

	int getLength(); // return the length of the snake
	Component getComponent(int index); // return the piece located at index in body
	int getDirection(); // to get the direction of the snake
	void setComponentPosition(int index, Component comp); // set the component position located at index to position of comp
	void setDirection(int newDirection); // changes the direction of snake
	bool touch(Snake another); // to check if one snake touches the other, useful to check if player went into computer
	bool hasLost(); // checks if snake went into it
	void drawSnake(RenderWindow& window, Color color);
	bool ateFood(Component foodPosition); // check if the snake ate the food
	void addComponentToBody(); // this will increase snake size with one when it will eat the food
	
};