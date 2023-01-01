#include <bits/stdc++.h>

using namespace std;

int convert(map<int, int> &dupes)
{
    int sum = 0;
    int add;
    for (auto i : dupes)
    {
        if (i.first - 'a' >= 0)
        {
            add = i.first - 'a' + 1;
        }
        else
        {
            add = i.first - 'A' + 27;
        }
        sum += add;
        cout << (char)i.first << " " << add << endl;
    }
    return sum;
}

int main()
{
    ifstream inputFile("rucksack.txt");
    string in;

    int sum = 0;
    int half;
    map<int, int> dupes;
    map<int, int> appeared;

    while (getline(inputFile, in))
    {
        cout << in << " " << in.length() << endl;
        half = in.length() / 2;

        for (int i = 0; i < half; i++)
        {
            appeared[(int)in[i]] = 1;
        }

        for (int i = half; i < in.length(); i++)
        {
            if (appeared.find((int)in[i]) != appeared.end())
            {
                dupes[(int)in[i]] = 1;
            }
        }
        sum += convert(dupes);
        // Clear for next
        appeared.clear();
        dupes.clear();
    }

    cout << sum << endl;

    return 0;
}
