#include "InGame.h"

InGame::InGame() {
	projectile.projectileArrangeSprite();
}
InGame::~InGame() {

}

void InGame::GameLoop() {
	ennemies.ennemiesTexture();
	ennemies.setEnnemiesCollisions();

	player.playerTexture();
	player.movePlayer();
	player.playerShoot();

	projectile.showProjectileTexture();
}

void InGame::Render(sf::RenderWindow* window) {	
	window->draw(map.actualMap);
	window->draw(ennemies.ennemiesSprite);

	player.playerRender(window);
	projectile.projectileRender(window);


}