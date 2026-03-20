#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to store the result
struct Result {
    bool found;
    int line;
    int position;
    int dotCount;
};

// Function to open a file
bool openFile(ifstream& file, const string& filename) {
    file.open(filename);
    return file.is_open();
}

// Function to find the third dot in the file
Result findThirdDot(const string& filename) {
    Result result = { false, -1, -1, 0 };

    ifstream file;
    if (!openFile(file, filename)) {
        return result;
    }

    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;

        // Skip empty lines
        if (line.empty()) continue;

        for (int i = 0; i < (int)line.length(); i++) {
            if (line[i] == '.') {
                result.dotCount++;

                // When the third dot is found
                if (result.dotCount == 3) {
                    result.found = true;
                    result.line = lineNumber;
                    result.position = i + 1; // position starts from 1
                    file.close();
                    return result;
                }
            }
        }
    }

    file.close();
    return result;
}

// Function to print the result
void printResult(const Result& result) {
    if (!result.found) {
        cout << "Error: fewer than three dots in the file or file cannot be opened.\n";
        return;
    }

    cout << "The third dot is found:\n";
    cout << "Line (i): " << result.line << endl;
    cout << "Position (j): " << result.position << endl;
    cout << "Total number of dots in the file: " << result.dotCount << endl;
}

int main() {
    string filename;

    cout << "Enter file name: ";
    getline(cin, filename);

    // Check if filename is not empty
    if (filename.empty()) {
        cout << "Error: file name cannot be empty!" << endl;
        return 1;
    }

    Result result = findThirdDot(filename);

    printResult(result);

    return 0;
}