#include <bits/stdc++.h>
using namespace std;

string getString(int d)
{
    if (d == 2)
        return "abc";
    else if (d == 3)
        return "def";
    else if (d == 4)
        return "ghi";
    else if (d == 5)
        return "jkl";
    else if (d == 6)
        return "mno";
    else if (d == 7)
        return "pqrs";
    else if (d == 8)
        return "tuv";
    else if (d == 9)
        return "wxyz";
    else
        return "";
}

void print_keypad(int num, string output)
{
    if (num == 0)
    {
        cout << output << endl;
        return;
    }
    string pd = dial(num % 10);
    for (int i = 0; i < pd.size(); i++)
    {
        pK(num / 10, pd[i] + out);
    }
}

int main()
{
    int num;
    cin >> num;
    string output = "";
    print_keypad(num, output);
}
