#include <bits/stdc++.h>
using namespace std;
void getPermutation(int l, int r, string s)
{
    if (l == r)
    {
        cout << s << endl;
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(s[l], s[i]);
        getPermutation(l + 1, r, s);
        swap(s[l], s[i]);
    }
}

int main()
{
    string str = "ADE";
    int n = str.size();
    getPermutation(0, n - 1, str);
    return 0;
}