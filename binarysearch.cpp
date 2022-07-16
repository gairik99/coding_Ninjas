#include <iostream>
using namespace std;

int binarySearch1(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = (r+l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch1(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch1(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
      return binarySearch1( input, 0, size-1, element);
}


int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    {
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
