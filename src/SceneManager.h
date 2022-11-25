#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "GameManager.h"
#include "InGame.h"
#include "Menu.h"

#define MENU 0
#define GAME 1

class SceneManager {
public :
	SceneManager();
	~SceneManager();
	void manageScene();
	void Draw();
private :
	InGame game;
	Menu menu;
	GameManager gm;
};
