#pragma once

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Map.h"
#include "Location.h"

Map* InitializeGameBoard(int dimensions);
Map* GetGameState(Map* map);
void FreeMap(Map* map);
void DisplayMap(Map* map);

#endif
