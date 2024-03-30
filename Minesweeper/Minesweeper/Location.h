#pragma once

typedef struct location {

	char letter;
	int number;

}Location;

// setters and getters

void setLetter(Location, char);
void setNumber(Location, int);

char getLetter(Location);
int getNumber(Location);
