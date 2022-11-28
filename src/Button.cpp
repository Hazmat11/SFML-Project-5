#include "Button.h"

Button::Button() {

}

Button::~Button() {

}

void Button::setButton(int x, int y, int w, int h, std::string text, sf::RenderWindow* window, const sf::Color& color) {
	this->posx = x;
	this->posy = y;
	this->width = w;
	this->height = h;

	sf::Font fontIsaac;
	if (!fontIsaac.loadFromFile("upheavtt.ttf"))
	{
		std::cout << "Error TTF" << std::endl;
	}

	rect.setSize(sf::Vector2f(this->width, this->height));
	rect.setFillColor(color);
	rect.setPosition(sf::Vector2f(this->posx, this->posy));

	// select the font
	textSfml.setFont(fontIsaac);
	// set the string to display
	textSfml.setString(text);
	// set the character size
	textSfml.setCharacterSize(24); // in pixels, not points!
	// set the color
	textSfml.setFillColor(sf::Color::White);
	// set the text style
	//textSfml.setStyle(sf::Text::Bold);

	this->win = window;
}

bool Button::OnHover() {
	if (this->posx <= sf::Mouse::getPosition().x && sf::Mouse::getPosition().x <= (this->posx + this->width)) {
		if (this->posy <= sf::Mouse::getPosition().y && sf::Mouse::getPosition().y <= (this->posy + this->height)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	
}

void Button::RenderBT() {
	this->win->draw(this->rect);
	//this->win->draw(this->textSfml);
}