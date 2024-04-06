// This file will be used to test the SaveLoad module because i can not get the native unit tests solution to work


#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>

#include "Constants.h"
#include "Tile.h"

#include "SaveLoad.h"
#include "RandomInitialization.h"

/*
// testing saveload module
int main(void) {

	/*
	////////////////////////// Test 1 //////////////////////////////
	/// SAVELOAD_011

	FILE* SaveState = fopen(SAVE_FILE, "w");

	Tile tile;

	tile.bomb = true;
	tile.checked = false;
	tile.flagged = false;
	tile.location.letter = 'k';
	tile.location.number = 9;
	tile.surrounding = 2;

	// check to see if tile saved to file
	SaveTileToFile(SaveState, tile);

	fclose(SaveState);
	*/

	/*
	////////////////////////// Test 2 //////////////////////////////
	/// SAVELOAD_021
	SaveState = fopen(SAVE_FILE, "r");

	tile = LoadTileFromFile(SaveState);

	if (tile.bomb = true && tile.checked == false
		&& tile.flagged == false && tile.surrounding == 2
		&& tile.location.letter == 'k' && tile.location.number == 9) {
		printf("Tile is correct");
	}
	else {
		printf("Tile is wrong");
	}

	fclose(SaveState);
	*/

	/*
	////////////////////////// Test 3 //////////////////////////////
	/// SAVELOAD_001

	Map* map = BlankInit(6);

	if (SaveMapToFile(map)) {
		printf("\n6x6 map saved");
	}
	else {
		printf("\n6x6 map not saved");
	}
	*/


	/*
	////////////////////////// Test 4 //////////////////////////////
	/// SAVELOAD_002

	Map* map = BlankInit(16);

	if (SaveMapToFile(map)) {
		printf("\n16x16 map saved");
	}
	else {
		printf("\n16x16 map not saved");
	}

	*/

	/*
	////////////////////////// Test 5 //////////////////////////////
	/// SAVELOAD_003

	Map* map = BlankInit(10);

	if (!SaveMapToFile(map)) {
		printf("Map was not able to save, pass");
	}
	else {
		printf("map was able to save, fail");
	}
	*/
	

	////////////////////////// Test 6/7/8/9 //////////////////////////////
	/// SAVELOAD_031 and SAVELOAD_032 and SAVELOAD_033 and SAVELOAD_052 

	/*
	Map* loadmap = LoadMapFromFile();

	if (loadmap == NULL) {
		printf("\nMap was not loaded");
	}
	else {

		printf("\nmap was loaded");

		// used to see if the map is the same as the one in the file
		printf("%c,%d", loadmap->tiles[5][2].location.letter, loadmap->tiles[5][2].location.number);

		// used to check if size of map generated is the same as the map in the file for test case SAVELOAD_052
		printf("\nElements in map: %d\n", loadmap->n);

	}
	
	*/

/*


	return 0;

}

*/