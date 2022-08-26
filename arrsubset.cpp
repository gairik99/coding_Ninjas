#include <bits/stdc++.h>
using namespace std;

void subset_arr(int i, int n, int arr[], vector<int> &vs)
{
    if (i == n)
    {
        for (auto it : vs)
            cout << it << " ";
        cout << endl;
        return;
    }
    vs.push_back(arr[i]);
    subset_arr(i + 1, n, arr, vs);
    vs.pop_back();
    subset_arr(i + 1, n, arr, vs);
}
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>vs;
    subset_arr(0,n,arr,vs);
}