#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void openInputFile(ifstream& inputFile, string& filename);
void openOutputFile(ofstream& outputFile, string& filename);
void getInput(string& input);
void countLines(ifstream& inputFile, int& rowCount, size_t& maxLength, int& emptyLines);
bool findCharacters(ifstream& inputFile, string& startString, string& endString, bool& foundStartChar, bool& foundEndChar);
void writeResults(ofstream& outputFile, int rowCount, size_t maxLength, int emptyLines, bool foundStartChar, bool foundEndChar);

int main() {
    ifstream inputFile;
    ofstream outputFile;
    string filename, startString, endString;
    int rowCount = 0, emptyLines = 0;
    size_t maxLength = 0;
    bool foundStartChar = false, foundEndChar = false;

    cout << "Enter the filename: ";
    openInputFile(inputFile, filename);
    openOutputFile(outputFile, filename);
    getInput(startString);
    getInput(endString);
    countLines(inputFile, rowCount, maxLength, emptyLines);
    findCharacters(inputFile, startString, endString, foundStartChar, foundEndChar);
    writeResults(outputFile, rowCount, maxLength, emptyLines, foundStartChar, foundEndChar);

    cout << "Results written to Output.txt file" << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}

void openInputFile(ifstream& inputFile, string& filename) {
    cin >> filename;
    inputFile.open(filename);
    if (!inputFile) {
        cerr << "Unable to open " << filename << " file" << endl;
        exit(EXIT_FAILURE);
    }
}

void openOutputFile(ofstream& outputFile, string& filename) {
    outputFile.open("output.txt");
    if (!outputFile) {
        cerr << "Unable to open output.txt file" << endl;
        exit(EXIT_FAILURE);
    }
}

void getInput(string& input) {
    cout << "Enter the character you want to search: ";
    cin >> input;
    cin.ignore();
}

void countLines(ifstream& inputFile, int& rowCount, size_t& maxLength, int& emptyLines) {
    string line;
    while (getline(inputFile, line)) {
        rowCount++;
        if (line.length() > maxLength)
            maxLength = line.length();
        if (line.empty())
            emptyLines++;
    }
}

bool findCharacters(ifstream& inputFile, string& startString, string& endString, bool& foundStartChar, bool& foundEndChar) {
    inputFile.clear();
    inputFile.seekg(0);

    string line;
    while (getline(inputFile, line)) {
        if (!foundStartChar && line.find(startString) != string::npos)
            foundStartChar = true;
        if (!foundEndChar && line.find(endString) != string::npos)
            foundEndChar = true;
    }

    return foundStartChar && foundEndChar;
}

void writeResults(ofstream& outputFile, int rowCount, size_t maxLength, int emptyLines, bool foundStartChar, bool foundEndChar) {
    outputFile << "Number of lines: " << rowCount << endl;
    outputFile << "Maximum line length: " << maxLength << endl;
    outputFile << "Number of empty lines: " << emptyLines << endl;
    if (foundStartChar && foundEndChar)
        outputFile << "Line starting and ending with specified characters: Found" << endl;
    else
        outputFile << "Line starting and ending with specified characters: Not found" << endl;
}