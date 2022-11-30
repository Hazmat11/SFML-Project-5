#include "InGame.h"

InGame::InGame() {
	ennemies = new Ennemies(&player);
	map = new Map(&player);
}

void InGame::projCollision() {
	if (player.shoot == true) {
		projectile->projectileBox = projectile->projectileSprite.getGlobalBounds();
		ennemies->ennemiesBox = ennemies->ennemiesSprite.getGlobalBounds();
		if (projectile->projectileBox.intersects(ennemies->ennemiesBox)) {
		
		}
	}
	else {
	}
}

InGame::~InGame() {

}

void InGame::GameLoop(sf::RenderWindow* win) {
	player.playerLoop(win);
	ennemies->ennemiesTexture();
	ennemies->setEnnemiesCollisions();
	map->mapLoop();
	projCollision();
}

void InGame::Render(sf::RenderWindow* window) {	
	window->draw(map->actualMap);
	window->draw(map->object);
	window->draw(ennemies->ennemiesSprite);
	player.playerRender(window);
}