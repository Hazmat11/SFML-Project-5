#include "Ennemies.h"

Ennemies::Ennemies() {
	arrangeSprite();
}

Ennemies::Ennemies(Player* p) {
	arrangeSprite();
	player = p;
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
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(0, 0, 40, 60));
		refreshTexture();
		break;
	case 11:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(40, 0, 40, 60));
		refreshTexture();
		break;
	case 20:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(80, 0, 40, 60));
		refreshTexture();
		break;
	case 40:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(125, 0, 40, 60));
		refreshTexture();
		break;
	case 50:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(80, 0, 40, 60));
		refreshTexture();
		break;
	case 60:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(40, 0, 40, 60));
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

	sf::FloatRect ennemiesBox = ennemiesSprite.getGlobalBounds();
	this->player->playerBox = this->player->playerSprite.getGlobalBounds();

	if (this->player->playerBox.intersects(ennemiesBox))
	{
		if (!invincible) {
			player->HP--;
			this->player->playerSprite.setColor(sf::Color(255, 255, 255, 128));
			invincible = true;
		}
	}
	else if (invincible) {
		time++;
	}
	if (time == 60) {
		invincible = false;
		time = 0;
		this->player->playerSprite.setColor(sf::Color(255, 255, 255, 255));
	}
}