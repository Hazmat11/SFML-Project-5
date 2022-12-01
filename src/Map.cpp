#include "Map.h"

Map::Map() {
	showMap();

}

Map::Map(Player* p) {
	showMap();
	longMap();
	player = p;
	key.loadFromFile("img/doors.png", sf::IntRect(90, 200, 25, 30));
	spike.loadFromFile("img/spikes.png");
	object.setPosition(900.f, 500.f);
	keySprite.setPosition(325, 500);
	object.setScale(2, 2);
	keySprite.setScale(2, 2);
}

Map::~Map() {

}

//show the first map
void Map::showMap()
{
	map.loadFromFile("img/map_2.png");
	actualMap.setTexture(map);
}

//Loop for the map
void Map::mapLoop() {
	firstMap();
	nextMap();
}

//The map where the player spawn
void Map::firstMap() {
	if (currentMap == 3) {
		if (!this->player->playerBox.intersects(sf::FloatRect(300, 275, 1390, 590))) {
			counterMove();
		}
	}
}

//Changing between the maps
void Map::nextMap()
{
	if (this->player->playerBox.intersects(sf::FloatRect(900, 130, 100, 50)) && currentMap != 1) {
		map.loadFromFile("img/spikemap.png");
		actualMap.setTexture(map);
		this->player->playerSprite.setPosition(sf::Vector2f(885.f, 830.f));
		currentMap = 1;
	}
	if (this->player->playerBox.intersects(sf::FloatRect(177, 500, 50, 100)) && currentMap != 2) {
		map.loadFromFile("img/longroom.png");
		actualMap.setTexture(map);
		this->player->playerSprite.setPosition(sf::Vector2f(1635.f, 527.f));
		currentMap = 2;
	}
	if (player->playerBox.intersects(sf::FloatRect(1715, 450, 20, 100)) && currentMap == 2) {
		map.loadFromFile("img/map_2.png");
		actualMap.setTexture(map);
		this->player->playerSprite.setPosition(sf::Vector2f(300, 527.f));
		deleteSprite = true;
		currentMap = 3;
	}
	if (currentMap == 3 && keyPossession == true) {
		if (player->playerBox.intersects(sf::FloatRect(1750, 540, 100, 100))) {

		}
	}
	
	spikeMap();
	longMap();
}

//The map with the spikes and the collision
void Map::spikeMap() {
	if (currentMap == 1 && !this->player->playerBox.intersects(sf::FloatRect(940, 860, 40, 30))) {
		player->takeDamage();
		if (!player->playerBox.intersects(sf::FloatRect(500, 115, 930, 845))) {
			counterMove();
		}
	}
	player->invincibility();
}

//The longmap and it collision
void Map::longMap() {
	if (currentMap == 2) {
		deleteSprite = false;
		object.setTexture(spike);
		keySprite.setTexture(key);
		takeKey();
		sf::FloatRect spikeBox = object.getGlobalBounds();
		if (this->player->playerBox.intersects(spikeBox)) {
			player->takeDamage();
		}
		player->invincibility();
		if (!player->playerBox.intersects(sf::FloatRect(250, 420, 1630, 280))) {
			counterMove();
		}
	}
}

//Send a opposite force in the chosen direction of the player
void Map::counterMove() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player->playerSprite.move(-5.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		player->playerSprite.move(5.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		player->playerSprite.move(0.f, 5.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player->playerSprite.move(0.f, -5.f);
	}
}

//Take the keys
void Map::takeKey() {
	sf::FloatRect keyBox = keySprite.getGlobalBounds();
	if (player->playerBox.intersects(keyBox)) {
		keySprite.setColor(sf::Color(0,0,0,0));
		keyPossession = true;
	}
}