#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public :

	Player();
	~Player();
	sf::Sprite playerSprite;
	sf::Texture texture;

	void move();
	void showTexture();
	sf::Vector2f returnPos(const int, const int);

private :
	int a = 0;
};

