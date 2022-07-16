#include <iostream>
using namespace std;

void PrintAllSubsets(int arr[],int i,int size1,int subset[],int j)
{
    if(i==size1){
        // print the subset array
        int idx = 0;
        while(idx<j){
            cout<<subset[idx]<<' ';
            ++idx;
        }
        cout<<endl;
        return;
    }
     // for each index i, we have 2 options
    // case 1: i is not included in the subset
    // in this case simply increment i and move ahead
    PrintAllSubsets(arr,i+1,size1,subset,j);
    // case 2: i is included in the subset
    // insert arr[i] at the end of subset
    // increment i and j
    subset[j] = arr[i];
    PrintAllSubsets(arr,i+1,size1,subset,j+1);
}

void printSubsetsOfArray(int input[], int size1) {
	// Write your code here
    int subset[100];
    PrintAllSubsets(input,0,size1,subset,0);

}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
