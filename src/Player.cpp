#include "Player.h"

Player::Player() {
	arrangeSprite();
}

Player::~Player() {

}

sf::Vector2f Player::returnPos(){
	playerPosition = playerSprite.getPosition();
	playerSprite.setPosition(playerPosition);
	return playerPosition; 
}

void Player::wallCollision() {
	returnPos();
	if (playerPosition.x > 1635) {
		playerSprite.move(-3.f, 0.f);
	}
	if (playerPosition.y < 135) {
		playerSprite.move(0.f, 3.f);
	}
	if (playerPosition.x < 175) {
		playerSprite.move(3.f, 0.f);
	}
	if (playerPosition.y > 830) {
		playerSprite.move(0.f, -3.f);
	}
}

void Player::movePlayer() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
		playerSprite.move(3.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		playerSprite.move(-3.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		playerSprite.move(0.f, -3.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playerSprite.move(0.f, 3.f);
	}
}

void Player::playerShoot()
{
	Projectiles prj;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && shootTimer > 1)
	{
		shootTimer = 0;

		listeProjectiles.push_back(Projectiles(prj));

		this->direction = RIGHT;
		projectile.projectileLaunchedRight = true;
		projectile.projectilePosition();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && shootTimer > 1)
	{
		shootTimer = 0;

		listeProjectiles.push_back(Projectiles(prj));

		this->direction = LEFT;
		projectile.projectileLaunchedLeft = true;
		projectile.projectilePosition();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && shootTimer > 1)
	{
		shootTimer = 0;

		listeProjectiles.push_back(Projectiles(prj));

		this->direction = UP;
		projectile.projectileLaunchedUp = true;
		projectile.projectilePosition();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && shootTimer > 1)		//A faire: incrémenter shootTimer dans la fonction Update
	{
		shootTimer = 0;

		listeProjectiles.push_back(Projectiles(prj));

		this->direction = DOWN;
		projectile.projectileLaunchedDown = true;
		projectile.projectilePosition();
	}
}

void Player::playerHP(sf::RenderWindow* window) {
	if (HP == 0) {
		window->close();
	}
}


void Player::playerTexture()
{
	if (frame < 30) {
		switch (direction) {
		default:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(10, 24, 40, 50));
			break;
		case 1:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(10, 140, 40, 50));
			break;
		case 2:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(10, 75, 40, 50));
			break;
		case 3:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(10, 200, 40, 50));
			break;
		case 4:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(10, 10, 40, 50));
			break;
		}
		playerSprite.setTexture(texture);
		frame++;
	}
	if (frame < 60 && frame > 29) {
		switch (direction) {
		default:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(140, 24, 60, 60));
			break;
		case 1 :
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(140, 140, 60, 60));
			break;
		case 2:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(140, 75, 60, 60));
			break;
		case 3:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(140, 200, 60, 60));
			break;
		case 4:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(140, 10, 60, 60));
			break;
		}
		playerSprite.setTexture(texture);
		frame++;
	}

	if (frame == 60) {
		frame = 0;
	}
}

void Player::arrangeSprite()
{
	playerSprite.scale(sf::Vector2f(2.3f, 2.3f));
	playerSprite.setPosition(sf::Vector2f(555.f, 325.f));
}