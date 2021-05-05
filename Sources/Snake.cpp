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