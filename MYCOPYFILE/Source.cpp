#include "Header.h"

void copyFile(string source, string destination) {
	// Open source file
	ifstream sourceFile(source, ios::binary);

	// Get filename from source path
	string filename = source.substr(source.find_last_of("/\\") + 1);

	// Check if the filename is not found in destination path
	if (destination.find(filename) == string::npos) {
		destination += "/" + filename;
	}

	ofstream destinationFile(destination, ios::binary);
	if (!sourceFile.is_open()) {
		cerr << "Cannot open source file." << endl;
		return;
	}
	if (!destinationFile.is_open()) {
		cerr << "Cannot open destination file." << endl;
		return;
	}
	char c;
	while (sourceFile.get(c)) {
		destinationFile.put(c);
	}
	sourceFile.close();
	destinationFile.close();
	cout << "Copy file successfully." << endl;
}
