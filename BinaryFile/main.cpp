#include "Header.h"

// Date Array – Load & Save

// Write a small program with 2 features (the program should create menu options to allow user to choose one of them).
//	1. User enters an array of dates(day, month, year) from keyboard.
//  The program will save the array to a binary file.
//	2. User loads an array of dates from a binary file.
//  The program will find the newest date and output to console.
// 
//  Format of input.bin:
//	• 1st number : n, number of elements in the array.
//	• Next 3 * n numbers : elements in the array.

/* Sample input for command 1:
5
31 01 2003
15 02 2001
28 11 1999
30 04 2012
17 05 2019
data.bin

*/

int main() {
	int choice = -1;
	Date* dateArray = nullptr;
	int size = 0;
	string fileName;
	do {
		cout << "Menu:\n";
		cout << "1. Enter an array of dates & save to binary file.\n";
		cout << "2. Load an array of dates from a binary file & print newest date.\n";
		cout << "0. Exit.\n";
		cout << "Enter command: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter the number of dates: ";
			cin >> size;
			dateArray = new Date[size];
			inputDateArray(dateArray, size);
			cin.ignore();

			cout << "Save to file: ";
			getline(cin, fileName);
			saveDateArray(dateArray, size, fileName);

			delete[] dateArray;
			dateArray = nullptr;
			cout << endl;
			break;
		case 2:
			cin.ignore();
			cout << "Load from file: ";
			getline(cin, fileName);
			loadDateArray(dateArray, size, fileName);
			findNewestDate(dateArray, size);

			delete[] dateArray;
			dateArray = nullptr;
			cout << endl;
			break;
		}
	} while (choice != 0);

	system("pause");
	return 0;
}

