#include "Projectiles.h"



Projectiles::Projectiles()
{
}

Projectiles::~Projectiles()
{
}



void Projectiles::setProjectileCollisions()
{
	projectileBox = projectileSprite.getGlobalBounds();
}

void Projectiles::showProjectileTexture()
{
	projectileTexture.loadFromFile(PROJECTILE_TEXTURE_PATH);

	if (a < 20) {

		projectileSprite.setTextureRect(sf::IntRect(0, 0, 8, 8));
	} else if (a < 40 && a > 19) {
		projectileSprite.setTextureRect(sf::IntRect(8, 0, 8, 8));
	} else if (a < 60 && a > 39) {
		projectileSprite.setTextureRect(sf::IntRect(0, 8, 8, 8));
	} else if (a == 60) {
		a = 0;
	}
	projectileSprite.setTexture(projectileTexture);
	a++;
}

void Projectiles::projectileArrangeSprite()
{
	projectileSprite.scale(sf::Vector2f(4.f, 4.f));
}

void Projectiles::projoLoop()
{



}

void Projectiles::projectileRender(sf::RenderWindow* window) 
{
	//window->draw(projectileSprite);


}