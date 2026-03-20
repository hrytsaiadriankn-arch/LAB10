#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// Function to check if a string is a valid number
bool isNumber(const string& str) {
    if (str.empty()) return false;
    char* end;
    strtod(str.c_str(), &end);
    return (*end == '\0');
}

// Function to calculate arithmetic mean
double calculateArithmeticMean(const vector<double>& numbers) {
    if (numbers.empty()) return 0.0;

    double sum = 0.0;
    for (double num : numbers) {
        sum += num;
    }
    return sum / numbers.size();
}

// Function to calculate geometric mean
double calculateGeometricMean(const vector<double>& numbers) {
    if (numbers.empty()) return 0.0;

    double product = 1.0;
    for (double num : numbers) {
        if (num <= 0) return 0.0; // geometric mean only for positive numbers
        product *= num;
    }
    return pow(product, 1.0 / numbers.size());
}

// Function to extract numbers from a line
vector<double> extractNumbers(const string& line) {
    vector<double> numbers;
    stringstream ss(line);
    string token;

    while (ss >> token) {
        if (isNumber(token)) {
            numbers.push_back(stod(token));
        }
    }
    return numbers;
}

// Function to process the file
void processFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile) {
        cout << "Error: Cannot open input file!\n";
        return;
    }

    string line;

    while (getline(inFile, line)) {
        vector<double> numbers = extractNumbers(line);

        double arithmeticMean = calculateArithmeticMean(numbers);
        double geometricMean = calculateGeometricMean(numbers);

        // Write original line + results
        outFile << line
            << " | Arithmetic Mean: " << arithmeticMean
            << " | Geometric Mean: " << geometricMean << endl;
    }

    cout << "Processing completed. Check output file.\n";

    inFile.close();
    outFile.close();
}

// Function to safely get file name from user
string getFileName(const string& message) {
    string fileName;
    cout << message;
    cin >> fileName;
    return fileName;
}

// Menu function
void showMenu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Process file\n";
    cout << "2. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;

    do {
        showMenu();

        // Input validation
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Enter a number: ";
        }

        switch (choice) {
        case 1: {
            string inputFile = getFileName("Enter input file name: ");
            string outputFile = getFileName("Enter output file name: ");

            processFile(inputFile, outputFile);
            break;
        }
        case 2:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 2);

    return 0;
}