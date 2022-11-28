#include "GameManager.h"

GameManager::GameManager() {
}

GameManager::~GameManager() {

}

void GameManager::setGameManager(sf::Event* ev, sf::RenderWindow* renderW) {
	this->e = ev;
	this->rw = renderW;
}