#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <list>
#include "Button.h"
#include "GameManager.h"

#define QUIT 0
#define PLAY 1

class Menu {
public :
	sf::IntRect mouse;

	Menu();
	Menu(sf::RenderWindow* win);
	~Menu();
	int MenuLoop(sf::RenderWindow* rw);
	void Render(sf::RenderWindow* win);
private :
	int frame = 0;

	// Menu Background
	sf::Texture menu;
	sf::Sprite MenuBG;
	
	// Load Font
	sf::Font fontTitle;
	sf::Font fontIsaac;

	// Title Text
	sf::Text title;
	sf::Text title2;

	// Credit Text
	sf::Text credit;
	sf::Text names;

	// Menu's Buttons
	std::vector<Button> buttons;
	Button quitBT;
	Button playBT;
};