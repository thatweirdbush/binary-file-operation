#include "Header.h"

// Split file

// Use command prompt argument and binary file IO techniques to create a MYSPLITFILE program.
// User will enter :
//		MYSPLITFILE path_of_source_file path_of_destination - numpart x
// x is a positive integer number, number of splitted parts.
// OR
//		MYSPLITFILE path_of_source_file path_of_destination - sizeapart y
// y is a positive integer number(in bytes), size of a splitted part.
// For example :
//		MYSPLITFILE D : / film.mkv D : / Level1 / Level2 / Level3 - numpart 3
// OR
//		MYSPLITFILE D : / film.mkv D : / Level1 / Level2 / Level3 - sizeapart 1000000
// Names of splitted parts are : film.mkv.part01, film.mkv.part02, film.mkv.part03…
// (.part01, .part02… are the extensions you chose)


/* Sample CMD input:

cd C:\Users\huyph\Downloads\21120082\x64\Debug\

MYSPLITFILE -s C:\Users\huyph\Downloads\21120082\MYSPLITFILE\data.bin -d D:\TestFolder -numpart 3

*/

/* Sample CMD input 2:

cd C:\Users\huyph\Downloads\21120082\x64\Debug\

MYSPLITFILE -s C:\Users\huyph\Downloads\21120082\MYSPLITFILE\data.bin -d D:\TestFolder -sizeapart 5

*/

int main(int argc, char* argv[]) {
	if (argc != 7 || string(argv[1]) != "-s" || string(argv[3]) != "-d") {
		cerr << "Invalid arguments.\nTry this example: MYSPLITFILE -s C:\\data.txt -d D:\\TestFolder -numpart 3" << endl;
		return 1;
	}
	string source = argv[2];
	string destination = argv[4];
	string mode = argv[5];
	int numPartOrSizeApart = stoi(argv[6]);
	splitFile(source, destination, mode, numPartOrSizeApart);

	system("pause");
	return 0;
}
