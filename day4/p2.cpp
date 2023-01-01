#include <bits/stdc++.h>

using namespace std;

bool overlap(pair<int, int> &fst, pair<int, int> &snd)
{
    if (fst.second < snd.first || snd.second < fst.first)
        return false;
    return true;
}

int main()
{
    ifstream input("camp.txt");
    string in;

    pair<int, int> elf1, elf2;
    int total = 0;

    string pair_delim = ",";
    string delim = "-";
    string fst, snd;

    while (getline(input, in))
    {
        fst = in.substr(0, in.find(pair_delim));
        snd = in.substr(in.find(pair_delim) + 1);

        elf1.first = stoi(fst.substr(0, fst.find(delim)));
        elf1.second = stoi(fst.substr(fst.find(delim) + 1));
        elf2.first = stoi(snd.substr(0, snd.find(delim)));
        elf2.second = stoi(snd.substr(snd.find(delim) + 1));

        cout << elf1.first << "," << elf1.second << " " << elf2.first << "," << elf2.second << endl;
        cout << "contained: " << overlap(elf1, elf2) << endl;
        total += overlap(elf1, elf2);
    }

    cout << "Total any overlaps: " << total << endl;

    return 0;
}