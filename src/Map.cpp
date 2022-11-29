#include "Map.h"

Map::Map() {
	showMap();
}

Map::Map(Player* p) {
	showMap();
	player = p;
}

Map::~Map() {

}

void Map::showMap()
{
	texture.loadFromFile("img/map_2.png");
	actualMap.setTexture(texture);
}

void Map::nextMap()
{
	if (this->player->playerBox.intersects(sf::FloatRect(900, 130, 100, 50))) {
		texture.loadFromFile("img/spikemap.png");
		actualMap.setTexture(texture);
		this->player->playerSprite.setPosition(sf::Vector2f(885.f, 830.f));
		currentMap = 1;
	}
	if (this->player->playerBox.intersects(sf::FloatRect(177, 400, 50, 100))) {
		texture.loadFromFile("img/longroom.png");
		actualMap.setTexture(texture);
		this->player->playerSprite.setPosition(sf::Vector2f(1635.f, 527.f));
		currentMap = 2;
	}

	spikeMap();
	longMap();
}

void Map::spikeMap() {
	if (!this->player->playerBox.intersects(sf::FloatRect(940, 860, 40, 40)) && currentMap == 1) {
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

void Map::longMap() {
	if (currentMap == 2) {
		spike.loadFromFile("img/spikes.png", sf::IntRect(900, 500, 32, 32));
		actualMap.setTexture(spike);
	}
}