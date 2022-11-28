#include "Menu.h"

Menu::Menu() {

}

Menu::Menu(sf::RenderWindow* win) {
	this->mouse.width = 1;
	this->mouse.height = 1;
	quitBT.setButton(10, 10, 10, 10, "Quit", win, sf::Color::Red);
	playBT.setButton(100, 100, 100, 40, "Play", win, sf::Color::Green);
	setBT.setButton(100, 200, 100, 40, "Settings", win, sf::Color::Green);
}

Menu::~Menu() {

}

void Menu::MenuLoop(sf::Event* event) {
	/*if (event->type = sf::Event::KeyPressed) {
		for (int i = 0; i < buttons.size(); i++) {

		}
	}*/
}

void Menu::Render(sf::RenderWindow* win) {
	for (int i = 0; i < 3; i++) {
		buttons[i].RenderBT();
	}
}

