#include "Header.h"

// Copy file

// Use command prompt argument and binary file IO techniques to create a MYCOPYFILE program.
// User will enter :
// MYCOPYFILE path_of_source_file path_of_destination
// The destination file will have same name as the source file.

/* Sample CMD input:

cd C:\Users\huyph\Downloads\21120082\x64\Debug\

MYCOPYFILE C:\Users\huyph\Downloads\21120082\MYCOPYFILE\data.bin D:\data.bin

*/

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "Invalid arguments." << endl;
		return 1;
	}
	string source = argv[1];
	string destination = argv[2];
	copyFile(source, destination);

	system("pause");
	return 0;
}
