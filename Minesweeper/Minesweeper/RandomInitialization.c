#include "RandomInitialization.h"
#include "Map.h"
#include "Tile.h"
#include <time.h>
#include <stdlib.h>

//This function will create and return a Map struct which is random and uses the 
//startingTile to generate a safe tile so the user does not immediately lose
Map* RandomInit(int mapSize, Tile startingTile) {
	//create new map struct initialized as blank
	Map* map = BlankInit(mapSize);


	//Maybe create a larger safe area around it

	//decide how many bombs will be created
	int bombCount = (mapSize * mapSize) / 6;

	
	//Use a for loop that loops a number of times equal to the number of bombs
	int xRand, yRand;
	for (int i = 0; i < bombCount; i++) {

		//in each loops, randomly generate a tile on on the board
		xRand = rand() % mapSize;
		yRand = rand() % mapSize;
		//check if it's currently empty
		if (map->tiles[xRand][yRand].bomb == true ||
			(map->tiles[xRand][yRand].location.letter == startingTile.location.letter &&
				map->tiles[xRand][yRand].location.number == startingTile.location.number)) {
			//if it's occupied, generate a new random tile
			i--;
		}
		else {
			//If it's empty, set it as a bomb
			map->tiles[xRand][yRand].bomb = true;
		}


	}

	return map;
	//once the loop is done, return the map struct

}

//This function will create and return a map full of empty tiles
Map* BlankInit(int mapSize) {
	//create a new map struct

	if (mapSize > 20) mapSize = 20;
	
		Map* map = (Map*)malloc(sizeof(Map));
		map->n = mapSize;

		char alphabet[] = { "abcdefghijklmnopqrstuvwxyz" };

		Tile * *indexes = (Tile**)malloc(sizeof(Tile*) * mapSize);

		for (int i = 0; i < mapSize; i++) {
			indexes[i] = (Tile*)malloc(sizeof(Tile) * getN(map));
		}

		//use a nested for loop to initialize the map as empty
		for (int i = 0; i < mapSize; i++) {
			for (int j = 0; j < mapSize; j++) {
				indexes[i][j].location.letter = alphabet[i];
				indexes[i][j].location.number = j;
				indexes[i][j].bomb = false;
				indexes[i][j].checked = false;
				indexes[i][j].flagged = false;
				indexes[i][j].surrounding = 0;
			}
		}

		map->tiles = indexes;
		return map;
	
}