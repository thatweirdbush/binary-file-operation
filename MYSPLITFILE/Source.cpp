#include "Header.h"

void splitFile(string source, string destination, string mode, int numPartOrSizeApart) {
	// Open source file
	ifstream sourceFile(source, ios::binary);
	if (!sourceFile.is_open()) {
		cerr << "Cannot open source file." << endl;
		return;
	}
	// Get filename from source path
	string filename = source.substr(source.find_last_of("/\\") + 1);

	// Concate the filename to destination path
	destination += "\\" + filename;

	// Move the file pointer to the end of the file
	sourceFile.seekg(0, ios::end);

	// Get the file size
	int fileSize = sourceFile.tellg();

	// Move the file pointer back to the beginning of the file
	sourceFile.seekg(0, ios::beg);

	// Get the number of parts
	int numPart = 0;

	if (mode == "-numpart") {
		int partSize = fileSize / numPartOrSizeApart;
		numPart = numPartOrSizeApart;
		for (int i = 1; i <= numPart; i++) {
			ofstream partFile(destination + ".part" + to_string(i), ios::binary);
			if (!partFile.is_open()) {
				cerr << "Cannot open part file " << i << endl;
				return;
			}
			char c;
			for (int j = 0; j < partSize; j++) {
				sourceFile.get(c);
				partFile.put(c);
			}
			partFile.close();
		}
	}
	else if (mode == "-sizeapart") {
		int partSize = numPartOrSizeApart;
		numPart = fileSize / numPartOrSizeApart;
		for (int i = 1; i <= numPart; i++) {
			ofstream partFile(destination + ".part" + to_string(i), ios::binary);
			if (!partFile.is_open()) {
				cerr << "Cannot open part file " << i << endl;
				return;
			}
			char c;
			for (int j = 0; j < partSize; j++) {
				sourceFile.get(c);
				partFile.put(c);
			}
			partFile.close();
		}
	}
	else {
		cerr << "Invalid mode." << endl;
		cout << "Try -numpart or -sizeapart" << endl;
		sourceFile.close();
		return;
	}
	sourceFile.close();
	cout << "Split file successfully." << endl;
	cout << "Destination path: \n";
	for (int i = 1; i <= numPart; i++)
		cout << destination + ".part" + to_string(i) << endl;
}