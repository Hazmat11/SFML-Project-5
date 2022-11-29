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
	sf::Sprite actualMap;

	sf::Texture collision;
	sf::Sprite actualCollision;

	void spikeMap();
	void showMap();
	void nextMap();

	Map();
	Map(Player* p);
	~Map();

private:

	int currentMap;
	int time = 0;
	bool invincible;

};
