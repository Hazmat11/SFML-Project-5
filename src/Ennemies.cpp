#include "Ennemies.h"

Ennemies::Ennemies() {
	arrangeSprite();
}

Ennemies::Ennemies(Player* p) {
	arrangeSprite();
	player = p;
}

Ennemies::Ennemies(Projectiles* proj) {

	projectiles = proj;
}

Ennemies::~Ennemies() {

}

void Ennemies::ennemiesLoop() {
	ennemiesBox = ennemiesSprite.getGlobalBounds();
	ennemiesTexture();
	setEnnemiesCollisions();
	this->moveEnemyX();
	this->moveEnemyY();
	systemHP();
}

void Ennemies::arrangeSprite()
{
	ennemiesSprite.setOrigin({20, 20 });
	ennemiesSprite.scale(sf::Vector2f(2.3f, 2.3f));
	ennemiesSprite.setPosition(sf::Vector2f(900.f, 325.f));
}

void Ennemies::ennemiesTexture() {
	switch (frame){
	case 0:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(0, 0, 40, 40));
		refreshTexture();
		break;
	case 11:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(40, 0, 40, 40));
		refreshTexture();
		break;
	case 20:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(80, 0, 40, 40));
		refreshTexture();
		break;
	case 40:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(125, 0, 40, 40));
		refreshTexture();
		break;
	case 50:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(80, 0, 40, 40));
		refreshTexture();
		break;
	case 60:
		texture.loadFromFile(JIGGLY_TEXTURE_PATH, sf::IntRect(40, 0, 40, 40));
		refreshTexture();
		break;
	}
	frame++;
	if (frame == 60) {
		frame = 0;
	}

	if(faceRight == true)
		{
			ennemiesSprite.setScale({ -2.3, 2.3 });
			faceRight = false;
	}
	else if (faceLeft == true)
	{
		ennemiesSprite.setScale({ 2.3, 2.3 });
		faceLeft = false;
		}

}

bool Ennemies::systemHP() {
	if (HP == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Ennemies::refreshTexture() {
	ennemiesSprite.setTexture(texture);
}

void Ennemies::setEnnemiesCollisions(){
	this->player->playerBox = this->player->playerSprite.getGlobalBounds();

	if (this->player->playerBox.intersects(ennemiesBox))
	{
		if (!invincible) {
			player->HP--;
			this->player->playerSprite.setColor(sf::Color(255, 255, 255, 128));
			invincible = true;
		}
	}
	else if (invincible) {
		time++;
	}
	if (time == 60) {
		invincible = false;
		time = 0;
		this->player->playerSprite.setColor(sf::Color(255, 255, 255, 255));
	}
}

void Ennemies::moveEnemyX()
{
	int enemyX = ennemiesSprite.getPosition().x;
	int enemyY = ennemiesSprite.getPosition().y;

	int xdistance = player->playerSprite.getPosition().x - ennemiesSprite.getPosition().x;

	if (xdistance > 2)
	{
		ennemiesSprite.setPosition(enemyX + 2, enemyY);
		faceRight = true;
	}
	else if (xdistance < 2) {
		ennemiesSprite.setPosition(enemyX - 2, enemyY);
		faceLeft = true;
	}

}

void Ennemies::moveEnemyY()
{
	int enemyX = ennemiesSprite.getPosition().x;
	int enemyY = ennemiesSprite.getPosition().y;

	int ydistance = player->playerSprite.getPosition().y - ennemiesSprite.getPosition().y;

	if (ydistance > 2)
	{
		ennemiesSprite.setPosition(enemyX, enemyY + 2);
	}
	else if (ydistance < 2) {
		ennemiesSprite.setPosition(enemyX, enemyY - 2);
	}

}