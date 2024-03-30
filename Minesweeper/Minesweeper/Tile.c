#include "Tile.h"


void setLocation(Tile tile, Location location) {
	tile.location = location;
}

void setBomb(Tile tile, bool bomb) {
	tile.bomb = bomb;
}

void setChecked(Tile tile, bool checked) {
	tile.checked = checked;
}

void setFlagged(Tile tile, bool flagged) {
	tile.flagged = flagged;
}

void setSurrounding(Tile tile, int n) {
	tile.surrounding = n;
}

Location getLocation(Tile tile) {
	return tile.location;
}

bool getBomb(Tile tile) {
	return tile.bomb;
}

bool getChecked(Tile tile) {
	return tile.checked;
}

bool getFlagged(Tile tile) {
	return tile.flagged;
}

int getSurrounding(Tile tile) {
	return tile.surrounding;
}