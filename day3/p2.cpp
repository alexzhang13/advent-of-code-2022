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

    int groupMember = 0;

    while (getline(inputFile, in))
    {
        cout << groupMember << " " << in << endl;
        for (int i = 0; i < in.length(); i++)
        {
            if (appeared.find((int)in[i]) != appeared.end())
            {
                if (groupMember == 1)
                {
                    appeared[(int)in[i]] = 2;
                }
                if (groupMember == 2 && appeared[(int)in[i]] == 2)
                    dupes[(int)in[i]] = 1;
            }
            else if (groupMember == 0)
            {
                appeared[(int)in[i]] = 1;
            }
        }

        if (groupMember == 2)
        {
            sum += convert(dupes);
            // Clear for next
            appeared.clear();
            dupes.clear();
            groupMember = 0;
        }
        else
        {
            groupMember++;
        }
    }

    cout << sum << endl;

    return 0;
}
