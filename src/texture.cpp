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
		texture.loadFromFile("C:/Users/ebertrand/Documents/SFML/img/player.png", sf::IntRect(10, 10, 60, 60));
		player.setTexture(texture);
		a++;
	}
	
	if (a < 60 && a > 29) {
		texture.loadFromFile("C:/Users/ebertrand/Documents/SFML/img/player.png", sf::IntRect(130, 10, 60, 60));
		player.setTexture(texture);
		a++;
	}

	if (a == 60) {
		a = 0;
	}
}