
#include "Location.h"

void setLetter(Location location, char letter) {
	location.letter = letter;
}
void setNumber(Location location, int number) {
	location.number = number;
}

char getLetter(Location location) {
	return location.letter;
}
int getNumber(Location location) {
	return location.number;
}