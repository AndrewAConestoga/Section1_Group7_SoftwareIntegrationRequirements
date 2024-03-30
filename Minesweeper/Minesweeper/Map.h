#pragma once

#include "Tile.h"

typedef struct map {

	int n;
	Tile** tiles;

}Map;

// getter and setters

void setN(Map*, int);
void setTile(Map*, Tile, int, int);

int getN(Map*);
Tile getTile(Map*, int, int);