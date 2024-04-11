#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "Constants.h"
#include "RandomInitialization.h"
#include "SaveLoad.h"
#include "CheckInput.h"
#include "UserInterface.h"


int main(int argc, char* argv[]) {

	// placeholder for the command line argument 
	 int n = atoi(argv[1]);;
	// int n = 8;
	char* alpha = "abcdefghijklmnopqrstuvwxyz";

	srand(time(NULL));

	int input;
	int err;

	// game loop
	while (true) {

		// display start menu

		printf("Minesweeper\n");
		printf("\n");
		printf("1. Start New Game Board\n");
		printf("2. Load Previous Game Board\n");
		printf("3. Quit\n");

		// ask user for input
		printf("Select an Option: ");
		err = scanf_s("%d", &input);

		if (err != 1) {
			printf("Invalid input, pleases enter a number that corresponds to one of the options\n\n\n\n\n\n\n");
			while(fgetc(stdin)!='\n');
			continue;
		}

		else if (input==1 || input==2) {

			Map* map;

			if (input == 1)
				map = InitializeGameBoard(n);
			else 
				map = LoadMapFromFile();

			if (input == 1) {

				Location inputLoc;

				while (true) {

					// display map to user
					DisplayMap(map);

					// ask user to select tile
					printf("Enter coordinate to check in order of (a1): ");

					// stub for CheckInput
					err = scanf("%c%d", &inputLoc.letter, &inputLoc.number);

					// check for invalid input
					if (err != 2) {
						printf("Invalid input, please enter a number that corresponds to one of the options\n\n\n\n\n\n\n");
						continue;
					}

					// check if input is out of bounds 
					else if (inputLoc.number >= n || inputLoc.number < 0 || (inputLoc.letter - 'a' >= n || inputLoc.letter - 'a' < 0)) {
						printf("Invalid input, please enter a number that corresponds to one of the options\n\n\n\n\n\n\n");
						continue;
					}

					Tile tile;
					tile.location = inputLoc;
					tile.bomb = false;
					tile.checked = false;
					tile.flagged = false;
					tile.surrounding = 0;

					map = RandomInit(n, tile);

					map->tiles[inputLoc.letter - 'a'][inputLoc.number].checked = true;
					break;

				}
				

			}

			// true game loop

			Location inputLoc;
			char flag;

			while (true) {

				// display map to user
				DisplayMap(map);

				// ask user to select tile
				printf("\n\nEnter coordinate to check in order (a1), or (a1!) to flag tile, or (@0) to save and quit: ");

				// stub for CheckInput
				flag = ' ';
				err = scanf("%c%d%c", &inputLoc.letter, &inputLoc.number, &flag);

				if (inputLoc.letter == '@' && inputLoc.number == 0) {
					SaveMapToFile(map);
					FreeMap(map);
					exit(true);
				}

				// check for invalid input
				else if (isValidMove(inputLoc, n)) {
					printf("Invalid input, please enter a number that corresponds to one of the options\n\n\n\n\n\n\n");
					continue;
				}

				else if (flag == '!') {
					FlagOrUnflagSquare(map, inputLoc);
				}

				else if (isFlagged(map, inputLoc)) {
					printf("\n\nCannot select flagged tile\n\n");
				}

				else {
					if (InteractWithSquare(map, inputLoc) == -1) {
						break;
					}

					// check to see if all tiles are checked or bombs
					if (checkForWin(map)) {
						printf("\n\n\n\n\n\n\n\n\nYou Won!\n\n\n");
						break;
					}
					

				}

			}

		}
		else if (input == 3) {
			break;
		}
		else {
			printf("Invalid input, pleases enter a number that corresponds to one of the options\n\n\n\n\n\n\n");
			continue;
		}
		
	}


	return 0;

}
