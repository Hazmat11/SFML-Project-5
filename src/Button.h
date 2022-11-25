#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Button {
public :
	Button();
	~Button();
	void setButton(int x, int y, int w, int h, std::string txt, sf::RenderWindow* window, const sf::Color& color);
	void ButtonLoop();
	bool OnHover();
private :
	sf::RectangleShape rect;
	sf::Text textSfml;
	sf::RenderWindow* win;

	int posx, posy, width, height;
	
	void RenderBT();
};