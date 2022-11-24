#pragma once
#include <SFML/Graphics.hpp>
#define RIGHT 1;
#define LEFT 2;
#define UP 3;
#define DOWN 4;


class Player
{
public :

	Player();
	~Player();

	sf::Sprite playerSprite;
	sf::Texture texture;

	void movePlayer();
	void showTexture();
	void arrangeSprite();
	void setPlayerCollisions();

	sf::Vector2f returnPos(const int, const int);

private :
	int a = 0;
	int direction;
};

