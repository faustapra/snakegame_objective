#include "Utils.h"
#include "Defines.h"


//konstruktorius sukuriantis langa ir pakraunantis srifta
Game::Game() {
	app.create(VideoMode(WIDTH, HEIGHT), "Snake Game");
	app.setFramerateLimit(60);

	font.loadFromFile("ARIAL.TTF");
}


//destruktorius sunaikinantis atminti
Game::~Game() {
	while (!states.empty()) {
		delete states.top();
		states.pop();
	}
}


void Game::pushState(State* state) {
	states.push(state);
}


//išimtis
State* Game::getState() {
	try {
		return states.top();
	}
	//jei tuscia busena returnina null pointeri
	catch (exception e) {
		return NULL;
	}
}

void Game::changeState(State* state) {
	//kviecia popState() tuo atveju jei yra kita busena
	popState();

	//prideda nauja busena
	states.push(state);
}

void Game::popState() {
	//jei busena ne tuscia, ja istrina
	if (!states.empty())
		states.pop();
}

Font Game::getFont() {
	return font;
}

void Game::gameLoop() {
	Clock clock;

	while (app.isOpen()) {
		Time elapsed = clock.restart(); // praejes laikas nuo paskutinio kadro
		double dt = elapsed.asSeconds(); // pavercia i sekundes

		if (getState() == NULL) { 
			continue;
		}

		getState()->handleInput(); // ivestis
		getState()->update(dt); // atnaujinimas

		app.clear(); // išvalomas langas

		getState()->draw(); // priešiama viskas ekrane

		app.display(); // paleidzia ekrana
	}
}