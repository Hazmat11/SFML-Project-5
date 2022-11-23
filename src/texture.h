#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class DoTexture
{
public:

	sf::Sprite sprite;
	sf::Texture texture;

	void showTexture();

	DoTexture();
	~DoTexture();

	int a = 0;
};

