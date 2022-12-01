#include "Button.h"

Button::Button() {	
	if (!this->fontIsaac.loadFromFile("IsaacGame.ttf"))
	{
		std::cout << "Error TTF Title Font" << std::endl;
	}
}

Button::~Button() {

}

//Manage the buttons displaying on screen
void Button::setButton(int x, int y, int w, int h, std::string text, int fontSize, float angle, int r, int g, int b, int a, sf::RenderWindow* window, const sf::Color& color) {
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
	textSfml.setRotation(angle);
	// set the string to display
	textSfml.setString(text);
	// set the character size
	textSfml.setCharacterSize(fontSize); // in pixels, not points!
	// set the color
	textSfml.setFillColor(sf::Color(r, g, b, a));

	this->win = window;
}

//Manage the position of the mouse
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

//Render the buttons
void Button::RenderBT() {
	this->win->draw(this->rect);
	this->win->draw(this->textSfml);
}