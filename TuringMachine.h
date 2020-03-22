#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

#include <vector>

using namespace std;

class TuringMachine {
	private:
		vector<int> tape;
		int current;

	public:
		TuringMachine(); // creat new machine with empty squares, current = 0
		void moveLeft(); // select the square to the left
		void moveRight(); // select the square to the right
		int tapeSearch(); // search tape, return the index if found, -1 if not
		void makeMark(bool mark); // change current to 0 or 1 based on input
		bool readSquare(); // returns state of current square 0 = f, 1 = t
		void printMachineInfo(); // Tape: [-2, -1, 0, 1, 2] Current square: -1
};

#endif
