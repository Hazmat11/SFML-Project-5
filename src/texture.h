#pragma once
#include <SFML/Graphics.hpp>

class DoTexture
{
public:

	sf::Sprite sprite;
	sf::Texture texture;

	void showTexture();

	DoTexture();
	~DoTexture();
};

