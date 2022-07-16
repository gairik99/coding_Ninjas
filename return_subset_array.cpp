#include <iostream>
using namespace std;

int subset1(int input[], int n, int startIndex, int output[][20])
{
    	if(startIndex==n)
        {
            output[0][0]=0;
            return 1;
        }
     int smsize= subset1(input,n,startIndex+1,output);
    for(int i=0;i<smsize;i++)
    {
       output[i+smsize][0]=output[i][0]+1;
       output[i+smsize][1]=input[startIndex];
       for(int j=1;j<=output[i][0];j++)
           output[i+smsize][j+1]=output[i][j];
    }
    return 2*smsize;
}

int subset(int input[], int n, int output[][20]) {
    // Write your code here
	int k;
    k=subset1(input,n,0,output);
	return k;
}

int main() {
  int input[20],length, output[350][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  int size1 = subset(input, length, output);

  for( int i = 0; i < size1; i++) {
	for( int j = 1; j <= output[i][0]; j++) {
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
