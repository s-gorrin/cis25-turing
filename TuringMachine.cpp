#include <iostream>
#include <vector>
#include "TuringMachine.h"

using namespace std;

// creat new machine with empty squares, current = 0
TuringMachine::TuringMachine() {
	current = 0;
}

// select the square to the left
void TuringMachine::moveLeft() {
	current -= 1;
}

// select the square to the right
void TuringMachine::moveRight() {
	current += 1;
}

// search a vector and return the index if found, -1 if not
int TuringMachine::tapeSearch() {
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
void TuringMachine::makeMark(bool mark) {
	int index = tapeSearch();

	if (index == -1 && mark) {
		if (tape.size() == 0) {
			tape.push_back(current);
		}
		else {
			int i = 0;

			while (i < tape.size() && tape.at(i) < current) {
				i++;
			}
			tape.insert(tape.begin() + i, current);
		}
	}

	else if (!mark && index > -1 && tape.at(index) == current) {
		tape.erase(tape.begin() + index);
	}
}

// returns state of current square 0 = f, 1 = t
bool TuringMachine::readSquare() {
	if (tapeSearch() > -1) {
		return true;
	}

	return false;
}

// Tape: [-2, -1, 0, 1, 2] Current square: -1
void TuringMachine::printMachineInfo() {
	cout << "Tape: [";
	for (int i = 0; i < tape.size(); i++) {
		cout << tape.at(i);
		if (i < tape.size() - 1) {
			cout << ", ";
		}
	}
	cout << "] Current square: " << current << endl;
}
