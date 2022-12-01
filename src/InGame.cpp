#include "InGame.h"

InGame::InGame() {
	ennemies = new Ennemies(&player);
	map = new Map(&player);
}

void InGame::projCollision() {
	for (int i = 0; i < player.projos.size(); i++)
	{
		player.projos[i].projectileBox = player.projos[i].projectileSprite.getGlobalBounds();

		std::cout << player.projos[i].projectileBox.left << "\n";
		std::cout << "enemy" << ennemies->ennemiesBox.left << "\n";

		if (player.projos[i].projectileBox.intersects(ennemies->ennemiesBox)) {
			std::cout << "wooooaaaaaaah";
		}
	}
}

InGame::~InGame() {

}

void InGame::GameLoop(sf::RenderWindow* win) {
	player.playerLoop(win);
	ennemies->ennemiesLoop();
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