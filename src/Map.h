#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Ennemies.h"

class Map
{
public:
	Player* player;
	Ennemies ennemies;

	sf::Texture map;
	sf::Texture spike;
	sf::Texture key;

	sf::Sprite actualMap;
	sf::Sprite object;
	sf::Sprite keySprite;

	void firstMap();
	void spikeMap();
	void showMap();
	void longMap();
	void nextMap();
	void mapLoop();
	void counterMove();
	void takeKey();

	Map();
	Map(Player* p);
	~Map();

	bool deleteSprite;
	bool done;
	bool keyPossession = false;

private:

	int currentMap = 3;
	int time = 0;
	bool invincible;

};
