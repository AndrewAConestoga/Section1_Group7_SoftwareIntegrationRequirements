#include <stdio.h>
#include <stdlib.h>
#include "Map.h"
#include "Location.h"
#include "Tile.h"
#include "UserInterface.h"
#include "RandomInitialization.h"

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
        return -1;
    }

    // Mark square as revealed
    map->tiles[x][y].checked = true;

    if (map->tiles[x][y].bomb) {                                                // Square is a bomb
        printf("Game Over! You clicked on a mine.\n");
        FreeMap(map);
        exit(true);
    }
    else {                                                                      // Square is not a bomb
        int surroundingMines = 0;
        if (x-1>=0) {
            if (map->tiles[x-1][y].bomb) {
                surroundingMines++;
            }
        }
        if (x + 1 < map->n) {
            if (map->tiles[x + 1][y].bomb) {
                surroundingMines++;
            }
        }
        if (x - 1 >= 0 && y - 1 >=0) {
            if (map->tiles[x - 1][y-1].bomb) {
                surroundingMines++;
            }
        }
        if (x - 1 >= 0 && y + 1 < map->n) {
            if (map->tiles[x - 1][y+1].bomb) {
                surroundingMines++;
            }
        }
        if (y - 1 >= 0) {
            if (map->tiles[x][y-1].bomb) {
                surroundingMines++;
            }
        }
        if (y + 1 < map->n) {
            if (map->tiles[x][y+1].bomb) {
                surroundingMines++;
            }
        }
        if (x + 1 < map->n && y - 1 >= 0) {
            if (map->tiles[x + 1][y - 1].bomb) {
                surroundingMines++;
            }
        }
        if (x + 1 < map->n && y + 1 < map->n) {
            if (map->tiles[x + 1][y + 1].bomb) {
                surroundingMines++;
            }
        }
        map->tiles[x][y].surrounding = surroundingMines;
        return surroundingMines;
    }
}

void FreeMap(Map* map) {
    for (int i = 0; i < map->n; i++) {
        free(map->tiles[i]);
    }
    free(map->tiles);
    free(map);
}

void DisplayMap(Map* map) {
    printf("\n");

    printf(" |");
    for (int i = 0; i < map->n;i++) {
        printf(" %2d |", i);
    }
    printf("\n_|");
    for (int i = 0; i < map->n; i++) {
        printf("____|");
    }

    for (int i = 0; i < map->n; i++) {

        printf("\n |");

        for (int j = 0; j < map->n; j++) {
            printf("    |");
        }
        printf("\n%c|", map->tiles[i][0].location.letter);

        for (int j = 0; j < map->n; j++) {
            if (map->tiles[i][j].checked == true && map->tiles[i][j].surrounding == 0) {
                printf("    |");
            }
            else if (map->tiles[i][j].checked == true && map->tiles[i][j].surrounding != 0) {
                printf(" %2d |", map->tiles[i][j].surrounding);
            }
            else if (map->tiles[i][j].flagged == true) {
                printf(" !> |");
            }
            else if (map->tiles[i][j].checked == false) {
                printf(" XX |");
            }
        }

        printf("\n_|");

        for (int j = 0; j < map->n; j++) {
            printf("____|");
        }

    }
    printf("\n");

}