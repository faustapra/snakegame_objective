
#pragma once
#include <SFML/Graphics.hpp>
#include "Defines.h"

using namespace sf;

struct Component {
	int x, y;

	bool operator == (Component second) {
		if (this->x == second.x && this->y == second.y)
			return true;

		return false;
	}

	bool operator != (Component second) {
		if (this->x != second.x || this->y != second.y)
			return true;

		return false;
	}
};