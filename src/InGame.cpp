#include "InGame.h"

InGame::InGame() {
	projectile.projectileArrangeSprite();
	ennemies = new Ennemies(&player);
}

InGame::~InGame() {

}

void InGame::GameLoop() {
	ennemies->ennemiesTexture();
	player.playerTexture();
	player.movePlayer();
	player.wallCollision();
	ennemies->setEnnemiesCollisions();
	player.playerShoot();

	projectile.showProjectileTexture();
}

void InGame::Render(sf::RenderWindow* window) {	
	player.playerHP(window);
	window->draw(map.actualMap);
	window->draw(ennemies.ennemiesSprite);

	player.playerRender(window);
	projectile.projectileRender(window);


}