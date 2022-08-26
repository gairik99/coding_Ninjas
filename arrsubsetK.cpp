#include <bits/stdc++.h>
using namespace std;

void subset_arrK(int i, int n, int k, int arr[], vector<int> &vs)
{
    if (i == n)
    {
        if (k == 0)
        {
            for (auto it : vs)
                cout << it << " ";
            cout << endl;
        }
        return;
    }

    vs.push_back(arr[i]);
    k -= arr[i];
    subset_arrK(i + 1, n, k, arr, vs);
    k += arr[i];
    vs.pop_back();
    subset_arrK(i + 1, n, k, arr, vs);
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> vs;
    subset_arrK(0, n, k, arr, vs);
}