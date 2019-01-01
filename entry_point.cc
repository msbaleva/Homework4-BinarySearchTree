#include <iostream>
#include "binary_search_tree.h"
using namespace std;

void operationParser() {
	BinarySearchTree binSearchTree;
	string input;
	cin >> input;
	unsigned long long fn;
	while (input != "exit") {

		if (input == "insert") {
			Student st;
			cin >> st;
			binSearchTree.addStudent(st);
			cout << "Record inserted!\n";
		}
		else if (input == "delete") {

			do { cin >> fn; } while (fn < 0 || fn>pow(2, 50));
			binSearchTree.deleteStudent(fn);

		}
		else if (input == "find") {

			do { cin >> fn; } while (fn < 0 || fn>pow(2, 50));
			binSearchTree.findStudent(fn);

		}
		else if (input == "traverseInorder") {

			binSearchTree.traverseInorder();
			cout << endl;

		}
		else { cout << "Invalid operation!\n"; }
		cin >> input;
	}
}

int main() {

	operationParser();
	return 0;
}