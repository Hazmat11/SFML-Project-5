#include "Button.h"

Button::Button() {
	
	if (!this->fontIsaac.loadFromFile("upheavtt.ttf"))
	{
		std::cout << "Error TTF Regular Font" << std::endl;
	}
	
	if (!this->fontTitle.loadFromFile("IsaacGame.ttf"))
	{
		std::cout << "Error TTF Title Font" << std::endl;
	}
}

Button::~Button() {

}

void Button::setButton(int x, int y, int w, int h, std::string text, sf::RenderWindow* window, const sf::Color& color) {
	this->posx = x;
	this->posy = y;
	this->width = w;
	this->height = h;

	rect.setSize(sf::Vector2f(this->width, this->height));
	rect.setFillColor(color);
	rect.setPosition(sf::Vector2f(this->posx, this->posy));

	// select the font
	textSfml.setFont(fontIsaac);
	// set position
	textSfml.setPosition(sf::Vector2f(this->posx, this->posy));
	// set the string to display
	textSfml.setString(text);
	// set the character size
	textSfml.setCharacterSize(24); // in pixels, not points!
	// set the color
	textSfml.setFillColor(sf::Color::White);

	this->win = window;
}

bool Button::OnHover(sf::RenderWindow* rWin) {
	if (this->posx <= sf::Mouse::getPosition(*rWin).x && sf::Mouse::getPosition(*rWin).x <= (this->posx + this->width)) {
		if (this->posy <= sf::Mouse::getPosition(*rWin).y && sf::Mouse::getPosition(*rWin).y <= (this->posy + this->height)) {
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
	this->win->draw(this->textSfml);
}