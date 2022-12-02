#include <bits/stdc++.h>

using namespace std;

int computePoints (char me, char you) {
    int total = 0;
    if (you == 'A') {
        // they choose rock
        total += 3 * (me == 'X') + 4 * (me == 'Y') + 8 * (me == 'Z'); 
    } else if (you == 'B') {
        // they choose paper
        total += 1 * (me == 'X') + 5 * (me == 'Y') + 9 * (me == 'Z'); 
    } else {
        // they choose scissors
        total += 2 * (me == 'X') + 6 * (me == 'Y') + 7 * (me == 'Z');
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
