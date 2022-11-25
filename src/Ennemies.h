#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#define JIGGLY_TEXTURE_PATH "img/tilesJiggly.png"

class Ennemies
{
public:
	Player player;

	Ennemies();
	~Ennemies();
	void arrangeSprite();
	void ennemiesTexture();
	void refreshTexture();
	void setEnnemiesCollisions();


	sf::Sprite ennemiesSprite;
	sf::Texture texture;

private:
	int frame = 0;
	
};
