#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <list>
#include "Button.h"

class Menu {
public :
	sf::IntRect mouse;

	Menu();
	Menu(sf::RenderWindow* win);
	~Menu();
	void MenuLoop();
	void Render(sf::RenderWindow* win);
private :
	Button buttons[3] = {quitBT, playBT, setBT};
	Button quitBT;
	Button playBT;
	Button setBT;
};