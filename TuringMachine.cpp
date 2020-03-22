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

// search a vector and return the index if found, -1 if not
int tapeSearch() {
	int head = 0, mid = 0;
	int tail = tape.size();

	while (head < tail) {
		mid = head + (tail - head) / 2;
		if (current < tape[mid]) {
			tail = mid;
		}
		else if (current > tape[mid]) {
			head = mid + 1;
		}
		else {
			return mid;
		}
	}

	return -1;
}

// change current to 0 or 1 based on input
void makeMark(bool mark) {
	int index = tapeSearch();

	if (index == -1 && mark) {
		if (tape.size() == 0) {
			tape.push_back(current);
		}
		else {
			int i = 0;

			while (i < tape.size()) {
				if (tape.at(i) < current)
					i++;
				else {
					tape.insert(tape.begin() + i, current);
					i = tape.size();
				}
			}
		}
	}

	else if (tape.at(index) == current && !mark) {
		tape.erase(current);
	}
}

// returns state of current square 0 = f, 1 = t
bool readSquare() {
	if (tapeSearch() > -1) {
		return true;
	}

	return false;
}

// Tape: [-2, -1, 0, 1, 2] Current square: -1
void printMachineInfo() {
	cout << "Tape: [ ";
	for (int i = 0; i < tape.size(); i++) {
		cout << tape.at(i);
		if (i < tape.size() - 1) {
			cout << ", ";
		}
	}
	cout << "] Current square: " << current << endl;
}
