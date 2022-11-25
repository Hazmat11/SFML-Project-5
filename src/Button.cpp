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

	sf::RectangleShape r(sf::Vector2f(this->posx, this->posy));
	rect.setSize(sf::Vector2f(this->width, this->height));
	rect.setFillColor(color);

	sf::Text txt;
	// select the font
	txt.setFont(fontIsaac);
	// set the string to display
	txt.setString(text);
	// set the character size
	txt.setCharacterSize(24); // in pixels, not points!
	// set the color
	txt.setFillColor(sf::Color::White);
	// set the text style
	//textSfml.setStyle(sf::Text::Bold);

	rect = r;
	textSfml = txt;

	this->win = window;
}

void Button::ButtonLoop() {
	RenderBT();
}

bool Button::OnHover() {
	if (this->posx <= sf::Mouse::getPosition().x && sf::Mouse::getPosition().x <= (this->posx + this->width)) {
		if (this->posy <= sf::Mouse::getPosition().y && sf::Mouse::getPosition().y <= (this->posy + this->height)) {
			return true;
		}
	}
	return false;
}

void Button::RenderBT() {
	this->win->draw(this->rect);
	this->win->draw(this->textSfml);
}