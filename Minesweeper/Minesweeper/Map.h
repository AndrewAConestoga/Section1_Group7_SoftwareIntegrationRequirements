#pragma once

#include "Tile.h"

typedef struct map {

	int n;
	Tile* tiles;

}Map;

// getter and setters

void setN(Map*, int);
void setTiles(Map*, Tile*);

int getN(Map*);
Tile* getTiles(Map*);