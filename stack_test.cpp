#include "Stack.h"
#include <iostream>

using namespace std;

void test1() {
	Stack stack;

	stack.push('A');
	stack.push('B');
	stack.push('C');
	char p1 = stack.pop();
	cout << "Pop: " << p1 << endl;
	stack.push('D');
	stack.push('E');
	char p2 = stack.pop();
	cout << "Pop: " << p2 << endl;
	stack.push('F');

	stack.print();
}

bool bracketChecker(string text) {
	Stack stack(text.size());

	for (int i = 0; i < text.size(); i++) {
		char c = text.at(i);

		if (c == '(' || c == '{' || c == '[') {
			stack.push(c);
		}

		char t = stack.peek();
		if (c == ')') {
			if ('(' == t) {
				stack.pop();
			}
			else {
				return false;
			}
		}
		else if (c == '}') {
			if ('{' == t) {
				stack.pop();
			}
			else {
				return false;
			}
		}
		else if (c == ']') {
			if ('[' == t) {
				stack.pop();
			}
			else {
				return false;
			}
		}
	}

	return stack.isEmpty();
}

//int main() {
int stackMain() {
	string s = "void main() {int d[5]; if ((d[0] == 5) && (d[1] == 7)) {cout << \"Hello\"; }} ";

	bool isValid = bracketChecker(s);
	if (isValid) {
		cout << "Code is valid" << endl;
	}
	else {
		cout << "Code is not valid" << endl;
	}
	
	return 0;
}
