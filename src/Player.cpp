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
        // la touche "flèche gauche" est enfoncée : on bouge le personnage
        sprite.player.move(0.f, 1.f);
        sprite.player.getPosition();
    }
}