#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class DoTexture
{
public:


	DoTexture();
	~DoTexture();

private:
	std::vector<sf::IntRect> animationPos;
};

