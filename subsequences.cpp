#include <bits/stdc++.h>
using namespace std;

void print_subsequences(string str, string output)
{
    if (str.length() == 0)
    {
        cout << output << endl;
        return;
    }
    print_subsequences(str.substr(1), output);
    print_subsequences(str.substr(1), output + str[0]);
}
int main()
{
    string str;
    cin >> str;
    string output = "";
    print_subsequences(str, output);
}