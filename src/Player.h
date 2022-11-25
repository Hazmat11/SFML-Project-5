#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define RIGHT 1;
#define LEFT 2;
#define UP 3;
#define DOWN 4;
#define PIKACHU_TEXTURE_PATH "img/player.png"


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
	void playerShoot();

	sf::Vector2f returnPos(const int, const int);

	sf::Vector2f playerPosition;


private :
	int a = 0;
	int direction;
};

