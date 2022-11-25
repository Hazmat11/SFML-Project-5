#include "Projectiles.h"
#include "Player.h"


Projectiles::Projectiles()
{
}

Projectiles::~Projectiles()
{
}

void Projectiles::shootProjectile()
{
	//Création d'un clone de projectile




	//Apparition du projectile à la position du joueur






	//Détection d'une flèche du clavier appuyée

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		projectileLaunchedRight = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		projectileLaunchedLeft = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		projectileLaunchedUp = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		projectileLaunchedDown = true;
	}


	//Mouvements du projectile

	if (projectileLaunchedRight == true)
	{
		projectileSprite.move(10.f, 0.f);
	}

	if (projectileLaunchedLeft == true)
	{
		projectileSprite.move(-10.f, 0.f);
	}

	if (projectileLaunchedUp == true)
	{
		projectileSprite.move(0.f, -10.f);
	}

	if (projectileLaunchedDown == true)
	{
		projectileSprite.move(0.f, 10.f);
	}

}

void Projectiles::showProjectileTexture()
{
	if (a < 20) {

		projectileTexture.loadFromFile(PROJECTILE_TEXTURE_PATH, sf::IntRect(0, 0, 8, 8));
		projectileSprite.setTexture(projectileTexture);
		a++;
	}


	if (a < 40 && a > 19) {

		projectileTexture.loadFromFile(PROJECTILE_TEXTURE_PATH, sf::IntRect(8, 0, 8, 8));
		projectileSprite.setTexture(projectileTexture);
		a++;
	}

	if (a < 60 && a > 39) {

		projectileTexture.loadFromFile(PROJECTILE_TEXTURE_PATH, sf::IntRect(0, 8, 8, 8));
		projectileSprite.setTexture(projectileTexture);
		a++;
	}


	if (a == 60) {
		a = 0;
	}
}

void Projectiles::projectileArrangeSprite()
{
	projectileSprite.scale(sf::Vector2f(4.f, 4.f));
	projectileSprite.setPosition(sf::Vector2f(555.f, 325.f));
}
