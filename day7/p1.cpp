#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string name;
    int size;
    int totalSize;
    bool updated; // lazy updates
    vector<Node *> children;
};

class FileDirectory
{
public:
    FileDirectory()
    {
        root = new Node();
        root->name = "/";
        root->size = 0;
    }

    void processMessage(string command, vector<string> messages)
    {
    }

    void addChild(string name, int size)
    {
    }

    void getSize()
    {
    }

private:
    Node *root;
    Node *curr; // current directory
};

int main()
{

    ifstream input("dir.txt");
    string in;
    bool processing = false;

    while (getline(input, in))
    {
        if ()
    }

    return 0;
}