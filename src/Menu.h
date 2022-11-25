#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
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
	Button quitBT;
};