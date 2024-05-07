#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

void inputDateArray(Date* dateArray, int size);
void saveDateArray(Date* dateArray, int size, string fileName);
void loadDateArray(Date*& dateArray, int& size, string fileName);
void findNewestDate(Date* dateArray, int size);
