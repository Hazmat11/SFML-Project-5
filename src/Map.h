#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Map
{
public:
	sf::Texture map1;
	sf::Sprite actualMap;

	sf::Texture collision;
	sf::Sprite actualCollision;

	void showMap();
	void setCollisions();

	Map();
	~Map();


private:



};

