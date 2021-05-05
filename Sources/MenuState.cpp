#include "MenuState.h"
#include "PlayState.h"
#include <iostream>



MenuState::MenuState(Game* game) {
	// „MenuState“ tipo objekto kintamojo žaidimas į kintamąjį, siunciamas kaip parametras
	// žaidimui nustatomas šriftas
	this->game = game;
	this->font = game->getFont();

	//inicializuojami pasirinkimai
	menu[0].setString("Play");
	menu[1].setString("Exit");

	menu[0].setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	
	//nustatomas sriftas, jo dydis, spalva kiekvienam pasirinkimui

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i) {
		menu[i].setFont(font);
		menu[i].setCharacterSize(40);
		menu[i].setFillColor(Color::White);
		menu[i].setOrigin(menu[i].getLocalBounds().width / 2, //nustato i centra
		menu[i].getLocalBounds().height / 2);

		// nustatoma kiekvienos parinkties pozicija pagal jos ankstesnę poziciją
		if (i > 0) {
			menu[i].setPosition(sf::Vector2f(WIDTH / 2, menu[i - 1].getPosition().y + 50));
		}
	}

	selectedItemIndex = 0; // defoltiskai pirmasis pasirinkimas parinktas jau yra
	menu[0].setFillColor(Color::Red); // parenkama skirtinga spalva

	pressedItemIndex = -1;

	timeElapsed = 0; 
}


void MenuState::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void MenuState::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void MenuState::handleInput() {
	Event event;

	while (game->app.pollEvent(event)) {
		if (event.type == Event::Closed)
			game->app.close();

		//tikrina ar paspausta aukstyn,zemyn ar enter
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Up)
				moveUp();

			else if (event.key.code == Keyboard::Down)
				moveDown();

			else if (event.key.code == Keyboard::Enter)
				//jei enter paspaudziamas tada atnaujamas „PressItemIndex“ į dabartinį „selectedItemIndex“
				pressedItemIndex = selectedItemIndex;
		}
	}
}


void MenuState::draw() {
	// nupiesiamos parinktys i ekrana
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i)
		game->app.draw(menu[i]);
}