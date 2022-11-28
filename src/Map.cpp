#include "Map.h"

Map::Map() {
	showMap();
}

Map::~Map() {

}

void Map::showMap()
{
	map1.loadFromFile("img/map_2.png");
	actualMap.setTexture(map1);
}

void Map::setCollisions()
{

}