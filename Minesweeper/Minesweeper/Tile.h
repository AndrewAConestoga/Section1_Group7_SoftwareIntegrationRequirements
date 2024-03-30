#pragma once

#include <stdbool.h>

#include "Location.h"

typedef struct tile {

	Location location;
	bool bomb;
	bool checked;
	bool flagged;
	int surrounding;

}Tile;

// getters and setters

void setLocation(Tile, Location);
void setBomb(Tile, bool);
void setChecked(Tile, bool);
void setFlagged(Tile, bool);
void setSurrounding(Tile, int);

Location getLocation(Tile);
bool getBomb(Tile);
bool getChecked(Tile);
bool getFlagged(Tile);
int getSurrounding(Tile);