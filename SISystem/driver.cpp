#include "User.h"
#include "Student.h"
#include "SISystem.h"
#include <iostream>

using namespace std;

int main() {
	SISystem siSystem;
	if (siSystem.login()) {
		while (true) {
			char o;
			cout << "Choose an option: ";
			cin >> o;
			if (o == 'q') break;

			siSystem.handleRequest(o);
		}
	}

	return 0;
}