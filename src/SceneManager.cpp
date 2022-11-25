#include "SceneManager.h"

SceneManager::SceneManager() {
}

SceneManager::SceneManager(sf::RenderWindow* win) {
	rWin = win;
}

SceneManager::~SceneManager() {
}

void SceneManager::SetGameManager(sf::Event* event) {
	gm.setGameManager(event, rWin);
}

void SceneManager::manageScene() {
	switch (gm.index) {
	case MENU :
		menu.MenuLoop();
		break;
	case GAME :
		game.GameLoop();
		break;
	default :
		std::cout << "Error Scene !" << std::endl;
	}
}

void SceneManager::Draw() {
	switch (gm.index) {
	case MENU:
		menu.Render(gm.rw);
		break;
	case GAME:
		game.Render(gm.rw);
		break;
	default:
		std::cout << "Error Render Scene !" << std::endl;
	}
}