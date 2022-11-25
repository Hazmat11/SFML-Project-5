#include "Ennemies.h"

Ennemies::Ennemies() {
	arrangeSprite();
}

Ennemies::~Ennemies() {

}

void Ennemies::arrangeSprite()
{
	ennemiesSprite.scale(sf::Vector2f(2.3f, 2.3f));
	ennemiesSprite.setPosition(sf::Vector2f(900.f, 325.f));
}

void Ennemies::ennemiesTexture() {
	switch (frame){
	case 0:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(10, 10, 40, 60));
		refreshTexture();
		break;
	case 11:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(50, 10, 40, 60));
		refreshTexture();
		break;
	case 20:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(90, 10, 40, 60));
		refreshTexture();
		break;
	case 40:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(130, 10, 40, 60));
		refreshTexture();
		break;
	case 50:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(90, 10, 40, 60));
		refreshTexture();
		break;
	case 60:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(50, 10, 40, 60));
		refreshTexture();
		break;
	}
	frame++;
	if (frame == 60) {
		frame = 0;
	}
}

void Ennemies::refreshTexture() {
	ennemiesSprite.setTexture(texture);
}

void Ennemies::setEnnemiesCollisions(){	
	sf::FloatRect boundingBox = ennemiesSprite.getGlobalBounds();
	if (boundingBox.intersects(player.playerBox))
	{
		// collision!
	}
}