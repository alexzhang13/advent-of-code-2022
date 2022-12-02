#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("./p1.txt");
    vector<int> elves;
    int currElf = 0; 
    int top3 = 0;

    string val;
    while (getline(inputFile, val)) {
        if (val.empty()) {         
            elves.push_back(currElf);
            currElf = 0;
        } else {
            cout << "adding " << val << endl;
            currElf += std::stoi(val);
        }
    }
    sort(elves.rbegin(), elves.rend());
    for (int i = 0; i < 3; i++) {
        top3 += elves[i];
        cout << elves[i] << endl;
    }    
    cout << "top 3: " << top3 << endl;
    return 0; 
}
