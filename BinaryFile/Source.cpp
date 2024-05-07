#include "Header.h"

void inputDateArray(Date* dateArray, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter date " << i + 1 << " (day month year): ";
		cin >> dateArray[i].day >> dateArray[i].month >> dateArray[i].year;
	}
}

void saveDateArray(Date* dateArray, int size, string fileName) {
	ofstream file(fileName, ios::binary);
	if (!file.is_open()) {
		cerr << "Cannot open file." << endl;
		return;
	}
	file.write((char*)&size, sizeof(int));
	file.write((char*)dateArray, size * sizeof(Date));
	file.close();
	cout << "Saved successfully!" << endl;
}

void loadDateArray(Date*& dateArray, int& size, string fileName) {
	ifstream file(fileName, ios::binary);
	if (!file.is_open()) {
		cerr << "Cannot open file." << endl;
		return;
	}
	file.read((char*)&size, sizeof(int));
	dateArray = new Date[size];
	file.read((char*)dateArray, size * sizeof(Date));
	file.close();
	cout << "Load successfully!" << endl;
}

void findNewestDate(Date* dateArray, int size) {
	if (size == 0) {
		cout << "Array is empty!" << endl;
		return;
	}
	Date newestDate = dateArray[0];
	for (int i = 1; i < size; i++) {
		if (dateArray[i].year > newestDate.year) {
			newestDate = dateArray[i];
		}
		else if (dateArray[i].year == newestDate.year) {
			if (dateArray[i].month > newestDate.month) {
				newestDate = dateArray[i];
			}
			else if (dateArray[i].month == newestDate.month) {
				if (dateArray[i].day > newestDate.day) {
					newestDate = dateArray[i];
				}
			}
		}
	}
	cout << "Newest date: " << newestDate.day << " " << newestDate.month << " " << newestDate.year << endl;
}