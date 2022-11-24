#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class DoTexture
{
public:

	sf::Sprite player;
	sf::Texture texture;

	void showTexture();
	void arrangeSprite();
	void setPlayerCollisions();

	DoTexture();
	~DoTexture();

	int a = 0;
};

