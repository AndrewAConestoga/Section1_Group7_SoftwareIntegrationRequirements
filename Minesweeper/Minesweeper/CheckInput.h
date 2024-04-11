#pragma once
#include "Location.h"
#include "Map.h"

int isValidMove(Location input, int n);

int InteractWithSquare(Map* map, Location location);

int FlagOrUnflagSquare(Map* map, Location location);

bool isMine(Map* map, Location location);

bool isFlagged(Map* map, Location location);

bool checkForWin(Map* map);