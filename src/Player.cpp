#include "Player.h"
#include "texture.h"

Player::Player() {
}

Player::~Player() {

}

void Player::move() {
    DoTexture sprite;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        // la touche "fl�che gauche" est enfonc�e : on bouge le personnage
        sprite.player.move(0.f, 1.f);
        sprite.player.getPosition();
    }
}