#include "texture.h"

DoTexture::DoTexture()
{

}

DoTexture::~DoTexture() 
{

}

void DoTexture::showTexture() 
{
	texture.loadFromFile("C:/Users/ebertrand/Documents/SFML/img/player.png", sf::IntRect(10, 10, 60, 60));
	sprite.setTexture(texture);
}