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
	sf::FloatRect projectileBox;

	void shootProjectile();
	void showProjectileTexture();
	void projectileArrangeSprite();
	void projectilePosition();
	void setProjectileCollisions();

	bool projectileLaunchedRight = false;
	bool projectileLaunchedLeft = false;
	bool projectileLaunchedUp = false;
	bool projectileLaunchedDown = false;


private:

	int a = 0;


};

