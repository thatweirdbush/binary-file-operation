#include "Header.h"

// Merge file

// Use command prompt argument and binary file IO techniques to create a MYMERGEFILE program.
// User will enter :
//		MYMERGEFILE path_of_part01 path_of_destination
// The program will find all* .part01, * .part02, * .part03… files and merge into a single file.
// The program will print errors if there is any part does not exist.

/* Sample CMD input:

cd C:\Users\huyph\Downloads\21120082\x64\Debug\

MYMERGEFILE -s C:\Users\huyph\Downloads\21120082\MYMERGEFILE\data.bin.part1 -d D:\TestFolder

*/

int main(int argc, char* argv[]) {
	if (argc != 5 || string(argv[1]) != "-s" || string(argv[3]) != "-d") {
		cerr << "Invalid arguments.\nTry this example: MYMERGEFILE -s C:\\data.txt.part1 -d D:\\TestFolder" << endl;
		return 1;
	}
	string source = argv[2];
	string destination = argv[4];
	mergeFile(source, destination);

	system("pause");
	return 0;
}
