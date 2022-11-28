#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <list>
#include "Button.h"
#include "GameManager.h"

class Menu {
public :
	sf::IntRect mouse;

	Menu();
	Menu(sf::RenderWindow* win);
	~Menu();
	void MenuLoop(sf::RenderWindow* rw);
	void Render(sf::RenderWindow* win);
private :
	std::vector<Button> buttons;
	Button quitBT;
	Button playBT;
	Button setBT;
};