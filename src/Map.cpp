#include "Map.h"

Map::Map() {
	showMap();
}

Map::Map(Player* p) {
	showMap();
	longMap();
	player = p;
}

Map::~Map() {

}

void Map::showMap()
{
	map.loadFromFile("img/map_2.png");
	actualMap.setTexture(map);
}

void Map::mapLoop() {
	nextMap();
}

void Map::nextMap()
{
	if (this->player->playerBox.intersects(sf::FloatRect(900, 130, 100, 50))) {
		map.loadFromFile("img/spikemap.png");
		actualMap.setTexture(map);
		this->player->playerSprite.setPosition(sf::Vector2f(885.f, 830.f));
		currentMap = 1;
	}
	if (this->player->playerBox.intersects(sf::FloatRect(177, 400, 50, 100))) {
		map.loadFromFile("img/longroom.png");
		actualMap.setTexture(map);
		this->player->playerSprite.setPosition(sf::Vector2f(1635.f, 527.f));
		currentMap = 2;
	}

	spikeMap();
	longMap();
}

void Map::spikeMap() {
	if (currentMap == 1 && !this->player->playerBox.intersects(sf::FloatRect(940, 860, 40, 30))) {
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
		spike.loadFromFile("img/spikes.png");
		object.setPosition(900.f, 500.f);
		object.setScale(2, 2);
		object.setTexture(spike);
		sf::FloatRect spikeBox = object.getGlobalBounds();
		if (this->player->playerBox.intersects(spikeBox)) {
			std::cout << "merde";
		}
	}
}