#pragma once
#include <stdbool.h>
#include <stdio.h>
#include "Map.h"
#include "Constants.h"

// This function will save the data of a map structure to a 
// save state file
//
// Map*: Map to save data of
// 
// return: true is data could be saved, false if it could not 
bool SaveMapToFile(Map*);

// This function will load the data of a map from a save state file
// and clear the data afterward so another save state can be saved
// 
// return: Pointer to map that was loaded from the file
Map* LoadMapFromFile();

// This function saves a tile to the save state file
//
// File*: Pointer to file to save tile to
// Tile: tile to save in the file
void SaveTileToFile(FILE*, Tile);

// This function loads a single Tile from the save state file
//
// File*: Pointer to file to load from
// return: Tile that was loaded from the file
Tile LoadTileFromFile(FILE*);

// This function will clear the data from the save state file
//
// char*: name of file to clear data from
//
// return: true if data cleared from file, false if it was not able to
bool ClearMapData(char*);