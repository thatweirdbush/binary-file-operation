#include "Header.h"

void mergeFile(string source, string destination) {
	// Get origin filename from source path
	string originFilename = source.substr(source.find_last_of("/\\") + 1);

	// Remove .part01 from filename
	originFilename = originFilename.substr(0, originFilename.find(".part1"));

	// Concate the filename to destination path
	destination += "\\" + originFilename;

	ofstream ofs(destination, ios::binary);
	if (!ofs.is_open()) {
		cerr << "Cannot create merge file " << originFilename << endl;
		return;
	}
	int i = 1;
	cout << "Merging file..." << endl;
	while (true) {
		string partFile = destination + ".part" + to_string(i);
		ifstream ifs(partFile, ios::binary);
		if (!ifs.is_open()) {
			ifs.close();
			break;
		}
		cout << partFile << endl;
		// Get part file size
		ifs.seekg(0, ios::end);
		int partSize = ifs.tellg();

		// Move the file pointer back to the beginning of the file
		ifs.seekg(0, ios::beg);
		char* buffer = new char[partSize];

		// Read part file and write to merge file
		ifs.read(buffer, partSize);
		ofs.write(buffer, partSize);

		delete[] buffer;
		buffer = nullptr;
		ifs.close();
		i++;
	}
	ofs.close();
	cout << "Merge file successfully." << endl;
	cout << "Destination: " << destination << endl;
}
