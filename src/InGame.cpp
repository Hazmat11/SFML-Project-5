#include "InGame.h"

InGame::InGame() {

}
InGame::~InGame() {

}

void InGame::GameLoop() {
	ennemies.ennemiesTexture();
	player.playerTexture();
	player.movePlayer();
}

void InGame::Render(sf::RenderWindow* window) {

}