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

	sf::Texture texture;
	sf::Texture spike;

	sf::Sprite actualMap;

	void spikeMap();
	void showMap();
	void longMap();
	void nextMap();

	Map();
	Map(Player* p);
	~Map();

private:

	int currentMap;
	int time = 0;
	bool invincible;

};
