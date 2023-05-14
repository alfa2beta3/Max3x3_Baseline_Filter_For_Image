#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string file1_name = "new_lenna512_1.dat";
    string file2_name = "new_lenna512.dat";

    ifstream file1(file1_name);
    ifstream file2(file2_name);

    if (!file1 || !file2) {
        cout << "Error: could not open input file(s)." << endl;
        return 1;
    }

    vector<string> lines1, lines2;
    string line;

    // Read all the lines from file1
    while (getline(file1, line)) {
        lines1.push_back(line);
    }

    // Read all the lines from file2
    while (getline(file2, line)) {
        lines2.push_back(line);
    }

    file1.close();
    file2.close();

    if (lines1.size() != lines2.size()) {
        cout << "The files have different numbers of lines." << endl;
        return 1;
    }

    for (size_t i = 0; i < lines1.size(); i++) {
        if (lines1[i] != lines2[i]) {
            cout << "The strings in the files are different." << endl;
            return 1;
        }
    }

    cout << "The strings in the files are the same." << endl;

    return 0;
}