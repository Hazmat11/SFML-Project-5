#include "Menu.h"

Menu::Menu() {
	if (!menu.loadFromFile("img/menu.png")) {
		std::cout << "Error for Menu Background" << std::endl;
	}
	MenuBG.setTexture(menu);
	MenuBG.setScale(sf::Vector2f(1.25f, 1.25f));

	// Title //
	if (!this->fontTitle.loadFromFile("upheavtt.ttf"))
	{
		std::cout << "Error TTF Title Font" << std::endl;
	}
	title.setFont(fontTitle);
	title.setPosition(sf::Vector2f(25, 50));
	title.setString("THE BINDING");
	title.setCharacterSize(200);
	title.setFillColor(sf::Color(120, 116, 64, 255));

	title2.setFont(fontTitle);
	title2.setPosition(sf::Vector2f(25, 175));
	title2.setString("OF PIKACHU");
	title2.setCharacterSize(200);
	title2.setFillColor(sf::Color(120, 116, 64, 255));
}

Menu::Menu(sf::RenderWindow* win) {
	// Load Background Menu
	if (!menu.loadFromFile("img/menu.png")) {
		std::cout << "Error for Menu Background" << std::endl;
	}
	MenuBG.setTexture(menu);
	MenuBG.setScale(sf::Vector2f(1.5f, 1.5f));

	// Title //
	if (!this->fontTitle.loadFromFile("upheavtt.ttf"))
	{
		std::cout << "Error TTF Title Font" << std::endl;
	}
	title.setFont(fontTitle);
	title.setPosition(sf::Vector2f(600, 150));
	title.setRotation(-6.0f);
	title.setString("THE BINDING");
	title.setCharacterSize(100);
	title.setFillColor(sf::Color(120, 116, 64, 255));

	title2.setFont(fontTitle);
	title2.setPosition(sf::Vector2f(650, 225));
	title2.setRotation(-6.0f);
	title2.setString("OF PIKACHU");
	title2.setCharacterSize(100);
	title2.setFillColor(sf::Color(120, 116, 64, 255));

	// Set Menu's Buttons
	quitBT.setButton(1450, 150, 200, 200, "Quit", 100, 15.0f, 115, 62, 62, 255, win, sf::Color(0, 0, 0, 0));
	buttons.push_back(quitBT);
	playBT.setButton(750, 400, 400, 250, "Play", 200, -10.0f, 143, 141, 141, 255, win, sf::Color(0, 0, 0, 0));
	buttons.push_back(playBT);
}

Menu::~Menu() {

}

int Menu::MenuLoop(sf::RenderWindow* rw) {
	// On Click
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		for (int i = 0; i < buttons.size(); i++) {
			if (buttons[i].OnHover(rw)) {
				switch (i) {
				case QUIT :
					// close window
					std::cout << "close window" << std::endl;
					rw->close();
					return 0;
					break;
				case PLAY :
					// play game
					std::cout << "play" << std::endl;
					return 1;
					break;
				default:
					// Do a Flip
					std::cout << "BOB !! DO SOMETHING !!" << std::endl;
					return 0;
					break;
				}
			}
			else {
				// Do a Flip
			}
		}
	}
	
	// Title
	switch (frame) {
	case 0 :
		title2.setString("OF PIKACHU");
		frame++;
		break;
	case 4 :
		title2.setString("OF  IKACHU");
		frame++;
		break;
	case 8:
		title2.setString("OF P KACHU");
		frame++;
		break;
	case 12:
		title2.setString("OF PI ACHU");
		frame++;
		break;
	case 16:
		title2.setString("OF PIK CHU");
		frame++;
		break;
	case 20:
		title2.setString("OF PIKA HU");
		frame++;
		break;
	case 24:
		title2.setString("OF PIKAC U");
		frame++;
		break;
	case 28:
		title2.setString("OF PIKACH ");
		frame++;
		break;
	default:
		if (frame == 59) {
			frame = 0;
		}

		if (frame >= 29) {
			title2.setString("OF PIKACHU");
		}
		frame++;
		break;
	}

	return 0;
}

void Menu::Render(sf::RenderWindow* win) {
	win->draw(MenuBG);
	win->draw(title);
	win->draw(title2);
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i].RenderBT();
	}
}

