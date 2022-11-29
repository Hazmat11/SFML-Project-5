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
	map.loadFromFile("img/map_2.png");
	actualMap.setTexture(map);
}

void Map::nextMap()
{
	if (this->player->playerBox.intersects(sf::FloatRect(900, 130, 100, 100))) {
		map.loadFromFile("img/spikemap.png");
		actualMap.setTexture(map);
		this->player->playerSprite.setPosition(sf::Vector2f(885.f, 830.f));
		currentMap = 1;
	}
	spikeMap();
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