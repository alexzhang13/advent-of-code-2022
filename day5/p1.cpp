#include <bits/stdc++.h>

using namespace std;

void getState(vector<stack<char>> &stacks)
{
    for (int i = 0; i < stacks.size(); i++)
    {
        if (stacks[i].empty())
        {
            cout << '.';
        }
        else
        {
            cout << stacks[i].top();
        }
    }
    cout << endl;
}

void init(vector<stack<char>> &stacks)
{
    stack<char> one, two, three, four, five, six, seven, eight, nine;

    // bin 1
    one.push('Z');
    one.push('P');
    one.push('M');
    one.push('H');
    one.push('R');

    // bin 2
    two.push('P');
    two.push('C');
    two.push('J');
    two.push('B');

    // bin 3
    three.push('S');
    three.push('N');
    three.push('H');
    three.push('G');
    three.push('L');
    three.push('C');
    three.push('D');

    // bin 4
    four.push('F');
    four.push('T');
    four.push('M');
    four.push('D');
    four.push('Q');
    four.push('S');
    four.push('R');
    four.push('L');

    five.push('F');
    five.push('S');
    five.push('P');
    five.push('Q');
    five.push('B');
    five.push('T');
    five.push('Z');
    five.push('M');

    six.push('T');
    six.push('F');
    six.push('S');
    six.push('Z');
    six.push('B');
    six.push('G');

    seven.push('N');
    seven.push('R');
    seven.push('V');

    eight.push('P');
    eight.push('G');
    eight.push('L');
    eight.push('T');
    eight.push('D');
    eight.push('V');
    eight.push('C');
    eight.push('M');

    nine.push('W');
    nine.push('Q');
    nine.push('N');
    nine.push('J');
    nine.push('F');
    nine.push('M');
    nine.push('L');

    stacks.push_back(one);
    stacks.push_back(two);
    stacks.push_back(three);
    stacks.push_back(four);
    stacks.push_back(five);
    stacks.push_back(six);
    stacks.push_back(seven);
    stacks.push_back(eight);
    stacks.push_back(nine);
}

void move(string command, vector<stack<char>> &stacks)
{
    cout << command << ": ";

    string delim = " ";
    size_t pos = command.find(delim);

    command.erase(0, pos + delim.length());
    pos = command.find(delim);

    cout << command.substr(0, pos) << endl;
    int amt = stoi(command.substr(0, pos));
    int idx_from = 0;
    int idx_to = 0;

    // find stack index from
    delim = "from ";
    pos = command.find(delim);
    command.erase(0, pos + delim.length());
    pos = command.find(" ");

    idx_from = stoi(command.substr(0, pos)) - 1;

    // // find stack index to
    delim = "to ";
    pos = command.find(delim);
    command.erase(0, pos + delim.length());
    idx_to = stoi(command) - 1;

    cout << idx_from << " " << idx_to << " amt: " << amt << endl;

    while (amt != 0 && !stacks[idx_from].empty())
    {
        char move = stacks[idx_from].top();
        stacks[idx_to].push(move);
        stacks[idx_from].pop();
        amt--;
    }

    getState(stacks);
}

int main()
{
    ifstream input("stack.txt");
    string in;

    vector<stack<char>> stacks; // 9 stacks

    init(stacks);

    while (getline(input, in))
    {
        move(in, stacks);
    }

    getState(stacks);

    return 0;
}