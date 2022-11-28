#include "Menu.h"

Menu::Menu() {

}

Menu::Menu(sf::RenderWindow* win) {
	this->mouse.width = 1;
	this->mouse.height = 1;
	quitBT.setButton(10, 10, 10, 10, "Quit", win, sf::Color::Red);
	buttons.push_back(quitBT);
	playBT.setButton(100, 100, 100, 40, "Play", win, sf::Color::Green);
	buttons.push_back(playBT);
	setBT.setButton(100, 200, 100, 40, "Settings", win, sf::Color::Green);
	buttons.push_back(setBT);
}

Menu::~Menu() {

}

void Menu::MenuLoop(sf::RenderWindow* rw) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		for (int i = 0; i < buttons.size(); i++) {
			if (buttons[i].OnHover()) {
				switch (i) {
				case 0 :
					// close window
					std::cout << "close window" << std::endl;
					rw->close();
					break;
				case 1 :
					// play game
					std::cout << "play" << std::endl;
					break;
				case 2 :
					// open settings
					std::cout << "settings" << std::endl;
					break;
				default:
					// Do a Flip
					std::cout << "BOB !! DO SOMETHING !!" << std::endl;
					break;
				}
			}
		}
	}*/
}

void Menu::Render(sf::RenderWindow* win) {
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i].RenderBT();
	}
}

