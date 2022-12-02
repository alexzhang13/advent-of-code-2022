#include <bits/stdc++.h>

using namespace std;

int computePoints (char me, char you) {
    int total = (me == 'X') + 2 * (me == 'Y') + 3 * (me == 'Z');
    if (you == 'A') {
        total += 3 * (me == 'X') + 6 * (me == 'Y'); 
    } else if (you == 'B') {
        total += 3 * (me == 'Y') + 6 * (me == 'Z'); 
    } else {
        total += 3 * (me == 'Z') + 6 * (me == 'X');
    }
    return total;
}

int main () {
    ifstream input ("strat.txt");
    string inp;
    char me, you;
    int points = 0;
    
    while (getline(input, inp)) {
        me = inp[2];
        you = inp[0];   
        points += computePoints(me, you); 
        cout << me << " " << you << ": " << points << endl;
    }
    cout << "Point total: " << points << endl; 
    return 0;
}
