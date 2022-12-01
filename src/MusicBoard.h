#pragma once

#include <iostream>
#include <SFML/Audio/Music.hpp>

class MusicBoard {
public :
	MusicBoard();
	~MusicBoard();
private :
	sf::Music menuMusic;
	sf::Music inGameMusic;
};