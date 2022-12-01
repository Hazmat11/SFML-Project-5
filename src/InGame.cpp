#include "InGame.h"

InGame::InGame() {
	ennemies = new Ennemies(&player);
	enemiesList.push_back(ennemies);
	map = new Map(&player);
}

InGame::~InGame() {

}

//Manage the collision between projectiles and enemies
void InGame::projCollision() {
	for (int i = 0; i < player.projos.size(); i++)
	{
		if (ennemies->ennemiesBox.contains(player.projos[i].projectileSprite.getPosition())) {
			player.projos.erase(player.projos.begin() + i);

			if (!ennemies->buffer.loadFromFile(JIGGLYPUFF_HURT_SOUND_PATH))
				std::cout << "-1";
			ennemies->jigglyoofSound.setBuffer(ennemies->buffer);
			ennemies->jigglyoofSound.setVolume(25);
			ennemies->jigglyoofSound.play();

			ennemies->HP--;
		}
	}

	for (int i = 0; i < enemiesList.size(); i++) {
		if (enemiesList[i]->systemHP()) {
			enemiesList.erase(enemiesList.begin() + i);
		}
	}
}

//Update loop for every gameplay elements
void InGame::GameLoop(sf::RenderWindow* win) {
	player.playerLoop(win);
	ennemies->ennemiesLoop();
	ennemies->ennemiesTexture();
	ennemies->setEnnemiesCollisions();
	map->mapLoop();
	projCollision();
}

//Update loop for every rendered elements
void InGame::Render(sf::RenderWindow* window) {	
	window->draw(map->actualMap);
	window->draw(map->object);
	if (!ennemies->deleteSprite) {
		window->draw(ennemies->ennemiesSprite);
	}
	player.playerRender(window);
}