#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include "SceneManager.h"


#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 750
#define TITLE std::string("The Binding of Pikachu")

void Game();
void Render(sf::RenderWindow*, SceneManager sm);