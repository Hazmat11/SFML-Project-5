#include "texture.h"

DoTexture::DoTexture()
{
}

DoTexture::~DoTexture() 
{

}

void DoTexture::showTexture() 
{
	
	if (a < 30) {
		texture.loadFromFile("img/player.png", sf::IntRect(10, 10, 60, 60));
		player.setTexture(texture);
		a++;
	}
	
	if (a < 60 && a > 29) {
		texture.loadFromFile("img/player.png", sf::IntRect(140, 10, 60, 60));
		player.setTexture(texture);
		a++;
	}

	if (a == 60) {
		a = 0;
	}
}

void DoTexture::arrangeSprite()
{
	player.scale(sf::Vector2f(2.f, 2.f));
	player.setPosition(sf::Vector2f(555.f, 325.f));
}