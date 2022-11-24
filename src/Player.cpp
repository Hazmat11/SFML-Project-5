#include "Player.h"
#include "texture.h"

Player::Player() {
}

Player::~Player() {

}

sf::Vector2f Player::returnPos(const int playerX, const int playerY){
	playerSprite.setPosition(100, 500);
	sf::Vector2f position = playerSprite.getPosition();
	std::cout << position.x << " " << position.y << "\n";
	return position; 
}

void Player::movePlayer() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
		playerSprite.move(1.f, 0.f);
		playerSprite.getPosition();
		this->direction = RIGHT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		playerSprite.move(-1.f, 0.f);
		playerSprite.getPosition();
		this->direction = LEFT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		playerSprite.move(0.f, -1.f);
		playerSprite.getPosition();
		this->direction = UP;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		playerSprite.move(0.f, 1.f);
		playerSprite.getPosition();
		this->direction = DOWN;
	}
}


void Player::showTexture()
{
	if (a < 30) {
		switch (direction) {
		default:
			texture.loadFromFile("img/player.png", sf::IntRect(10, 10, 60, 60));
			break;
		case 1:
			texture.loadFromFile("img/player.png", sf::IntRect(10, 140, 60, 60));
			break;
		case 2:
			texture.loadFromFile("img/player.png", sf::IntRect(10, 75, 60, 60));
			break;
		case 3:
			texture.loadFromFile("img/player.png", sf::IntRect(10, 200, 60, 60));
			break;
		case 4:
			texture.loadFromFile("img/player.png", sf::IntRect(10, 10, 60, 60));
			break;
		}
		playerSprite.setTexture(texture);
		a++;
	}
	if (a < 60 && a > 29) {
		switch (direction) {
		default:
			texture.loadFromFile("img/player.png", sf::IntRect(140, 10, 60, 60));
			break;
		case 1:
			texture.loadFromFile("img/player.png", sf::IntRect(140, 140, 60, 60));
			break;

		case 2:
			texture.loadFromFile("img/player.png", sf::IntRect(140, 75, 60, 60));
			break;
		case 3:
			texture.loadFromFile("img/player.png", sf::IntRect(140, 200, 60, 60));
			break;
		case 4:
			texture.loadFromFile("img/player.png", sf::IntRect(140, 10, 60, 60));
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