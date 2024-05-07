#include "Header.h"

// Merge file

// Use command prompt argument and binary file IO techniques to create a MYMERGEFILE program.
// User will enter :
//		MYMERGEFILE path_of_part01 path_of_destination
// The program will find all* .part01, * .part02, * .part03… files and merge into a single file.
// The program will print errors if there is any part does not exist.

/* Sample CMD input:

cd C:\Users\huyph\Downloads\21120082\x64\Debug\

MYMERGEFILE C:\Users\huyph\Downloads\21120082\MYMERGEFILE\data.bin.part1 D:\TestFolder

*/

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "Invalid arguments." << endl;
		return 1;
	}
	string source = argv[1];
	string destination = argv[2];
	mergeFile(source, destination);

	system("pause");
	return 0;
}
