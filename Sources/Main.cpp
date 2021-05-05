#include "Utils.h"
#include "MenuState.h"

int main() {
	Game game; 
	//nuoroda i zaidimo kintamaji
	game.pushState(new MenuState(&game));

	game.gameLoop(); // pradedamas zaidimo ciklas
	return 0;
}