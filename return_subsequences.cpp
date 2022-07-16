#include<bits/stdc++.h>
using namespace std;
int sub(string str,string arr[]){
if(str.length()==0)
    {
        arr[0]="";
        return 1;
    }
    string s=str.substr(1);
    int size1=sub(s,arr);
    for(int i=0;i<size1;i++){
        arr[i+size1]=str[0]+arr[i];
    }
        return 2*size1;
}

int main(){
string str;
cin>>str;
string *arr=new string[1000];
int p=sub(str,arr);
for(int i=0;i<p;i++)
    cout<<arr[i]<<endl;
}

