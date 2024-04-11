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