#include <iostream>
#include <vector>
#include "TurringMachine.h"

using namespace std;

// creat new machine with empty squares, current = 0
TuringMachine() {
	onSquares;
	current = 0;
}

// select the square to the left
void moveLeft() {
	current -= 1;
}

// select the square to the right
void moveRight() {
	current += 1;
}

// change current to 0 or 1 based on input
void makeMark(bool mark) {
	bool doNothing = false;

	for (int i = 0; i < onSquares.size(); i++) {
		if (onSquares.at(i) == current) {
			if (!mark)
				onSquares.erase(current);
			doNothing = true;	// either remove current from the list,
								// or confirm it's there and do nothing
		}
	}

	if (!doNothing && mark) // add current to the list if it's not there
		onSquares.push_back(current);
}

// returns state of current square 0 = f, 1 = t
bool readSquare() {

}

// Tape: [-2, -1, 0, 1, 2] Current square: -1
void printMachineInfo() {

}
