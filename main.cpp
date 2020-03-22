#include <iostream>
#include <string>
#include "TuringMachine.h"

using namespace std;

int main() {
	TuringMachine alan;
	string command = "";

	while (command != "exit") {
		alan.printMachineInfo();
		cout << "type a command (left, right, mark0, mark1, read, exit)\n> ";
		cin >> command;

		if (command == "left")
			alan.moveLeft();
		else if (command == "right")
			alan.moveRight();
		else if (command == "mark0")
			alan.makeMark(false);
		else if (command == "mark1")
			alan.makeMark(true);
		else if (command == "read")
			cout << "current square is " << alan.readSquare() << endl;
		else
			cout << "I don't recognize that command.\n";
	}

	cout << "that's all, folks\n";

	return 0;
}
