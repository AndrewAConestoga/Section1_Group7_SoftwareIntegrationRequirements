#include "checkInput.h"
#include "Location.h"
#include "Map.h"
#include "UserInterface.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int isValidMove(Location input, int n) {
    return (input.number >= n || input.number < 0 || (input.letter - 'a' >= n || input.letter - 'a' < 0));
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

    if (isMine(map, map->tiles[x][y].location)) {                                                // Square is a bomb
        printf("Game Over! You clicked on a mine.\n\n\n");
        FreeMap(map);
        return -1;
    }
    else {                                                                      // Square is not a bomb
        int surroundingMines = 0;
        if (x - 1 >= 0) {
            if (map->tiles[x - 1][y].bomb) {
                surroundingMines++;
            }
        }
        if (x + 1 < map->n) {
            if (map->tiles[x + 1][y].bomb) {
                surroundingMines++;
            }
        }
        if (x - 1 >= 0 && y - 1 >= 0) {
            if (map->tiles[x - 1][y - 1].bomb) {
                surroundingMines++;
            }
        }
        if (x - 1 >= 0 && y + 1 < map->n) {
            if (map->tiles[x - 1][y + 1].bomb) {
                surroundingMines++;
            }
        }
        if (y - 1 >= 0) {
            if (map->tiles[x][y - 1].bomb) {
                surroundingMines++;
            }
        }
        if (y + 1 < map->n) {
            if (map->tiles[x][y + 1].bomb) {
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

int FlagOrUnflagSquare(Map* map, Location location) {
    if (map->tiles[location.letter - 'a'][location.number].flagged == false) {
        map->tiles[location.letter - 'a'][location.number].flagged = true;
    }
    else {
        map->tiles[location.letter - 'a'][location.number].flagged = false;
    }
}

bool isMine(Map* map, Location location) {
    return map->tiles[location.letter-'a'][location.number].bomb;
}

bool isFlagged(Map* map, Location location) {
    return map->tiles[location.letter-'a'][location.number].flagged;
}

bool checkForWin(Map* map) {

    bool PlayerWon = true;
    for (int i = 0; i < getN(map); i++) {

        for (int j = 0; j < getN(map); j++) {

            if (map->tiles[i][j].bomb == false && map->tiles[i][j].checked == false) {
                PlayerWon = false;
            }
        }
    }

    return PlayerWon;
}