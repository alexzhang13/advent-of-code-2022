#include <bits/stdc++.h>

using namespace std;

int solve(int size, string stream)
{
    vector<int> seen(26, 0);
    int rem, curr, total = 0;

    for (int i = 0; i < stream.size(); i++)
    {
        curr = (int)stream[i] - 'a';
        cout << i << ": " << (char)(curr + 'a') << ", " << total << "; seen:" << seen[curr] << endl;

        if (seen[curr] == 0)
        {
            total++;
        }
        seen[curr]++;

        // remove from end
        if (i >= size)
        {
            rem = (int)(stream[i - size] - 'a');
            seen[rem]--;
            cout << "remove " << (char)(rem + 'a') << seen[rem] << endl;
            if (seen[rem] == 0)
            {
                total--;
            }
        }

        if (total >= size)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    ifstream input("code.txt");
    string in;

    while (getline(input, in))
    {
        int marker = solve(14, in);
        cout << marker << endl;
        cout << in.substr(marker - 14, 14) << endl;
    }

    return 0;
}