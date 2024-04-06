#define _CRT_SECURE_NO_WARNINGS

#include "Saveload.h"
#include "Constants.h"

#include "RandomInitialization.h"

#include <stdlib.h>
#include <stdio.h>

bool SaveMapToFile(Map* map) {

	// open the save file
	FILE* SaveState = fopen(SAVE_FILE, "w");

	// return false if there was an error opening the file 
	if (SaveState == NULL)
		return false;

	// otherwise, start saving the data of the map to the file
	fprintf(SaveState, "%d", getN(map));

	// write amount of tiles (nxn) in the map to the file
	for (int x = 0; x < getN(map); x++)
		for (int y = 0; y < getN(map); y++)
			SaveTileToFile(SaveState, map->tiles[x][y]);
	

	// close the file
	fclose(SaveState);

	return true;

}

Map* LoadMapFromFile() {

	// open the save file
	FILE* SaveState = fopen(SAVE_FILE, "r");

	// return NULL if there was an error opening the file 
	if (SaveState == NULL)
		return NULL;

	// Create a blank map, placeholder for the BlankInit function that needs to be created ///////////////
	Map* map = (Map*)malloc(sizeof(Map));		

	if (map == NULL)
		return NULL;
	
	// read amount of elements in the file 
	fscanf(SaveState, "%d", &(map->n));

	map->tiles = (Tile**)malloc(sizeof(Tile*) * getN(map));

	for (int i = 0; i < getN(map);i++) {
		map->tiles[i] = (Tile*)malloc(sizeof(Tile) * getN(map));
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////



	// start loading tiles from file int map
	for (int x = 0; x < getN(map); x++) {
		for (int y = 0; y < getN(map); y++) {

			// set tile in the map
			map->tiles[x][y] = LoadTileFromFile(SaveState);
		}
	}

	

	// close the file
	fclose(SaveState);

	// Clear the data in the file 
	// ClearMapData(SAVE_FILE);

	return map;
}

void SaveTileToFile(FILE* SaveState, Tile tile) {
	fprintf(SaveState, ",%d,%d,%d,%c,%d,%d", tile.bomb, tile.checked, tile.flagged, tile.location.letter,tile.location.number, tile.surrounding);
}

Tile LoadTileFromFile(FILE* SaveState) {

	char IgnoreComma;
	Tile tile;

	fscanf(SaveState, "%c%d%c%d%c%d%c%c%c%d%c%d", &IgnoreComma, &(tile.bomb), &IgnoreComma, &(tile.checked), &IgnoreComma, &(tile.flagged), &IgnoreComma, &(tile.location.letter), &IgnoreComma, &(tile.location.number), &IgnoreComma, &(tile.surrounding));

	return tile;

}

bool ClearMapData(char * filename) {

	// open the save file
	FILE* SaveState = fopen(SAVE_FILE, "w");

	// return false if there was an error opening the file 
	if (SaveState == NULL)
		return false;

	// close after opening so no data is written and file is blank
	fclose(SaveState);

	return true;
}