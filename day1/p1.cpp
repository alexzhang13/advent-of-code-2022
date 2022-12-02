#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("./p1.txt");
    int maxElf = 0;
    int currElf = 0;   

    string val;
    while (getline(inputFile, val)) {
        if (val.empty()) {         
            cout << "maxing " << currElf << endl;
            maxElf = std::max(maxElf, currElf);
            currElf = 0;
        } else {
            cout << "adding " << val << endl;
            currElf += std::stoi(val);
        }

    }
    cout << "max elf: " << maxElf << endl;
    return 0; 
}
