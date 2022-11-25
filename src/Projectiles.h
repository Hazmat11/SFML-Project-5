#pragma once

#include <SFML/Graphics.hpp>

#define PROJECTILE_TEXTURE_PATH "img/boule_elek.png"



class Projectiles
{
public:

	Projectiles();
	~Projectiles();

	sf::Sprite projectileSprite;
	sf::Texture projectileTexture;

	void shootProjectile();
	void showProjectileTexture();
	void projectileArrangeSprite();

	bool projectileLaunchedRight = false;
	bool projectileLaunchedLeft = false;
	bool projectileLaunchedUp = false;
	bool projectileLaunchedDown = false;

	sf::Vector2f projectilePosition;

private:

	int a = 0;


};
