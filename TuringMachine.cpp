#include <iostream>
#include <vector>
#include "TuringMachine.h"

using namespace std;

// creat new machine with empty squares, current = 0
TuringMachine() {
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

	if (!doNothing && mark) { // add current to the list if it's not there
		if (onSquares.size() == 0) {
			onSquares.push_back(current);
		}
		else {
			int i = 0;

			while (i < onSquares.size()) {
				if (onSquares.at(i) < current)
					i++;
				else {
					onSquares.insert(onSquares.begin() + i, current);
					i = onSquares.size();
				}
			}
		}
	}
}

// returns state of current square 0 = f, 1 = t
bool readSquare() {
	for (int i = 0; i < onSquares.size(); i++) {
		if (onSquares.at(i) == current)
			return true;
	}

	return false;
}

// Tape: [-2, -1, 0, 1, 2] Current square: -1
void printMachineInfo() {
	cout << "Tape: [ ";
	for (int i = 0; i < onSquares.size(); i++) {
		cout << onSquares.at(i);
		if (i < onSquares.size() - 1) {
			cout << ", ";
		}
	}
	cout << "] Current square: " << current << endl;
}
