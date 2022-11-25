#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Menu {
public :
	sf::IntRect mouse;
	Menu();
	~Menu();
	void MenuLoop();
	void Render(sf::RenderWindow* win);
private :

};