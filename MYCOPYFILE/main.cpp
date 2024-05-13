#include "Header.h"

// Copy file

// Use command prompt argument and binary file IO techniques to create a MYCOPYFILE program.
// User will enter :
// MYCOPYFILE path_of_source_file path_of_destination
// The destination file will have same name as the source file.

/* Sample CMD input:

cd C:\Users\huyph\Downloads\21120082\x64\Debug\

MYCOPYFILE -s C:\Users\huyph\Downloads\21120082\MYCOPYFILE\data.bin -d D:\

*/

int main(int argc, char* argv[]) {
	if (argc != 5 || string(argv[1]) != "-s" || string(argv[3]) != "-d") {
		cerr << "Invalid arguments.\nTry this example: MYCOPYFILE -s C:\\data.txt -d D:\\data.txt" << endl;
		return 1;
	}
	string source = argv[2];
	string destination = argv[4];
	copyFile(source, destination);

	system("pause");
	return 0;
}
