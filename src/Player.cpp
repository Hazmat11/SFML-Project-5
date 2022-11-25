#include "Player.h"

Player::Player() {
}

Player::~Player() {

}

sf::Vector2f Player::returnPos(const int playerX, const int playerY){
	sf::Vector2f position = playerSprite.getPosition();
	std::cout << position.x << " " << position.y << "\n";
	return position; 
}

void Player::movePlayer() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
		playerSprite.move(2.5f, 0.f);
		playerSprite.getPosition();

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		playerSprite.move(-2.5f, 0.f);
		playerSprite.getPosition();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		playerSprite.move(0.f, -2.5f);
		playerSprite.getPosition();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playerSprite.move(0.f, 2.5f);
		playerSprite.getPosition();
	}


}

void Player::playerShoot()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->direction = RIGHT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->direction = LEFT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->direction = UP;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->direction = DOWN;
	}
}


void Player::showTexture()
{
	if (a < 30) {
		switch (direction) {
		default:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(10, 10, 60, 60));
			break;
		case 1:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(10, 140, 60, 60));
			break;
		case 2:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(10, 75, 60, 60));
			break;
		case 3:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(10, 200, 60, 60));
			break;
		case 4:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(10, 10, 60, 60));
			break;
		}
		playerSprite.setTexture(texture);
		a++;
	}
	if (a < 60 && a > 29) {
		switch (direction) {
		default:
			texture.loadFromFile(PIKACHU_TEXTURE_PATH, sf::IntRect(140, 10, 60, 60));
			break;
		case 1:
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
		a++;
	}

	if (a == 60) {
		a = 0;
	}
}

void Player::arrangeSprite()
{
	playerSprite.scale(sf::Vector2f(2.3f, 2.3f));
	playerSprite.setPosition(sf::Vector2f(555.f, 325.f));
}

void Player::setPlayerCollisions()
{
	sf::FloatRect boundingBox = playerSprite.getGlobalBounds();
}