#include<bits/stdc++.h>
using namespace std;
void swap1(int arr[],int i,int j)
{
    int temp;
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int part(int arr[],int l,int r)
{
   int p=arr[r];
   int i=l-1;
   for(int j=l;j<r;j++)
   {
       if(arr[j]<p)
       {
           i++;
           swap1(arr,i,j);
       }
   }
   swap1(arr,i+1,r);
   return i+1;
}

void quicksort(int arr[],int l,int r)
{
    if(l<r)
    {
    int p=part(arr,l,r);
    quicksort(arr,l,p-1);
    quicksort(arr,p+1,r);
    }

}


int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    }
