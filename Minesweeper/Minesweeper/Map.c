#include "Map.h"


void setN(Map* map, int n) {
	map->n = n;
}

void setTile(Map* map, Tile tile, int x, int y) {
	map->tiles[x][y] = tile;
}

int getN(Map* map) {
	return map->n;
}

Tile getTile(Map* map, int x, int y) {
	return map->tiles[x][y];
}