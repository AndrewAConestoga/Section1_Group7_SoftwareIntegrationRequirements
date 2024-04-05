#include <stdio.h>
#include <stdlib.h>
#include "Map.h"
#include "Location.h"
#include "Tile.h"
#include "UserInterface.h"

Map* InitializeGameBoard(int dimensions) {
    return BlankInit(dimensions);
}

Map* GetGameState(Map* map) {
    return map;
}

int InteractWithSquare(Map* map, Location location) {
    int x = location.letter - 'a'; // Convert letter to array index
    int y = location.number;

    if (x < 0 || x >= getN(map) || y < 0 || y >= getN(map)) {
        // Invalid coordinates
        return 0;
    }

    // Mark square as revealed
    map->tiles[x][y].checked = true;

    if (map->tiles[x][y].bomb) {                                                // Square is a bomb
        printf("Game Over! You clicked on a mine.\n");
    }
    else {                                                                      // Square is not a bomb
        int surroundingMines = map->tiles[x][y].surrounding;
        printf("Number of adjacent mines: %d\n", surroundingMines);
    }

    return 1;
}

void FreeMap(Map* map) {
    for (int i = 0; i < map->n; i++) {
        free(map->tiles[i]);
    }
    free(map->tiles);
    free(map);
}