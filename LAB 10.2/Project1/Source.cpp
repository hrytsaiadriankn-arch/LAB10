#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

bool isLetter(char ch) {
    return isalpha((unsigned char)ch);
}

string capitalizeFirstLetter(const string& word) {
    if (word.empty()) return word;

    string result = word;
    if (isLetter(result[0])) {
        result[0] = toupper((unsigned char)result[0]);
    }
    return result;
}

void createFileIfNotExists(const string& filename) {
    ifstream fin(filename);

    if (!fin.is_open()) {
        ofstream fout(filename);
        fout << "hello world. this is a test file.\n";
        fout.close();

        cout << "Input file was not found. Created default t1.txt\n";
    }

    fin.close();
}

bool processFile(const string& inputFile, const string& outputFile) {
    ifstream fin(inputFile);
    ofstream fout(outputFile);

    if (!fin.is_open()) {
        cout << "Error opening input file\n";
        return false;
    }

    if (!fout.is_open()) {
        cout << "Error opening output file\n";
        return false;
    }

    char ch;
    bool afterDot = false;
    string word = "";

    while (fin.get(ch)) {
        if (isLetter(ch)) {
            word += ch;
        }
        else {
            if (!word.empty()) {
                if (afterDot) {
                    word = capitalizeFirstLetter(word);
                    afterDot = false;
                }
                fout << word;
                word.clear();
            }

            fout << ch;

            if (ch == '.') {
                afterDot = true;
            }
        }
    }

    if (!word.empty()) {
        if (afterDot) {
            word = capitalizeFirstLetter(word);
        }
        fout << word;
    }

    fin.close();
    fout.close();

    return true;
}

int main() {
    string inputFile = "t1.txt";
    string outputFile = "t2.txt";

    createFileIfNotExists(inputFile);

    if (processFile(inputFile, outputFile)) {
        cout << "Processing completed. Result is in t2.txt\n";
    }

    return 0;
}