#include "Snake.h"
#include "Defines.h"
#include <iostream>

Snake::Snake() {
	// sugeneruoja random pozicijas kiekviena kart
	srand(time(0));

	body[0].x = rand() % SIZE; // sugeneruoja x kord
	body[0].y = rand() % SIZE; // sugeneruoja y kord

	// pradzioj gyvate iskart yra 3 ilgio
	body[1] = body[2] = body[0];

	length = 3; // nustato ilgi 3
	direction = rand() % 4; // paduodama random kryptis
}

int Snake::getLength() {
	return length;
}

Component Snake::getComponent(int index) {
	return this->body[index];
}

int Snake::getDirection() {
	return direction;
}

void Snake::setComponentPosition(int index, Component comp) {
	body[index].x = comp.x;
	body[index].y = comp.y;
}

void Snake::setDirection(int newDirection) {
	//we must make sure that for example if snake is going up and new direction is down to not allow this because it can't just go down because there is part of his body
	// you can see that the condition above happens only when the difference of the new direction
	// and previous direction is +- 2, because of how we defined direction in Snake.h

	if (abs(direction - newDirection) != 2)
		direction = newDirection;
}



bool Snake::touch(Snake another) {
	// we check if the current snake touches the snake sent as parameter
	// and to do this we just have to check if head of snake (body[0]) has the same position with at least one component of the other snake
	for (int i = 0; i < another.getLength(); ++i)
		if (this->body[0] == another.getComponent(i))
			return true;

	return false;
}

bool Snake::hasLost() {
	bool spawned = true; // we need to check first if it's not the beggining and snake just spawned

	for (int i = 1; i < length; ++i) // this means that every piece of snake has same coordinates
		if (body[i] != body[0]) // if not we mark and go ahead
			spawned = false;

	if (spawned) // if it's spawned right now then it didn't lost even though every component of snake has same coordinates
		return false;

	for (int i = 1; i < length; ++i) // if it's not the beggining then we check if the head (body[0]) crashed into any other component of snake
		if (body[0] == body[i]) // if so then the player lost
			return true;

	return false; // otherwise we return false
}

// we give the parameters to this function the window where we want to draw and the color of the snake we want
void Snake::drawSnake(RenderWindow& window, Color color) {
	RectangleShape box(Vector2f(SIZE, SIZE)); // same as you i have a box of size 'SIZE'
	box.setFillColor(color); // we set the color

	for (int i = 0; i < length; ++i) {
		// and for every component of snake we set the position of the box and then we draw it
		box.setPosition(body[i].x * SIZE, body[i].y * SIZE);
		window.draw(box);
	}
}

bool Snake::ateFood(Component foodPosition) {
	// if head of snake (body[0]) has same position as food then it ate the food
	if (body[0] == foodPosition)
		return true;

	return false;
}

void Snake::addComponentToBody() {
	// to add a component to body we just have to set body[length] to have the same position as the tail (body[length - 1])
	body[length] = body[length - 1];

	// and then increase the length
	length++;
}

