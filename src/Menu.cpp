#include "Menu.h"

Menu::Menu() {

}

Menu::Menu(sf::RenderWindow* win) {
	this->mouse.width = 1;
	this->mouse.height = 1;
	quitBT.setButton(10, 10, 10, 10, "Quit", win, sf::Color::Red);
}

Menu::~Menu() {

}

void Menu::MenuLoop() {
	quitBT.OnHover();
}

void Menu::Render(sf::RenderWindow* win) {
	
}

