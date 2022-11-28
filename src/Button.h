#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Button {
public :
	Button();
	~Button();
	void setButton(int x, int y, int w, int h, std::string txt, sf::RenderWindow* window, const sf::Color& color);
	bool OnHover(sf::RenderWindow* rWin);
	void RenderBT();

private :
	sf::Font fontIsaac;
	sf::Font fontTitle;

	sf::RectangleShape rect;
	sf::Text textSfml;
	sf::RenderWindow* win;

	int posx, posy, width, height;
};