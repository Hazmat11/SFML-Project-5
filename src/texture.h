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

	DoTexture();
	~DoTexture();

	int a = 0;
};

