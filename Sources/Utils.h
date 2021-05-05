#pragma once
#include "State.h"
#include <stack>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Game {
private:

	//state klase abstrakti del to reikia pointer
	//kompiliatorius leidžia kurti nuorodas tik į tokio tipo klases
	stack<State*> states;
	Font font;

public:
	RenderWindow app;

	Game();
	~Game();
	void pushState(State*); 
	State* getState(); 
	void changeState(State*); 
	void popState(); 

	Font getFont(); 

	void gameLoop(); 
	
};

