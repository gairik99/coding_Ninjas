#include<bits/stdc++.h>
using namespace std;

string getString(int d){
    if(d==2)
        return "abc";
    else if(d==3)
        return "def";
    else if(d==4)
        return "ghi";
    else if(d==5)
        return "jkl";
    else if(d==6)
        return "mno";
    else if(d==7)
        return "pqrs";
    else if(d==8)
        return "tuv";
    else if(d==9)
        return "wxyz";
    else
        return " ";
}

int keypad(int n,string str[]){
if(n==0){
   str[0]="";
   return 1;}
   int d=n%10;
   int num=n/10;
   string s=getString(d);
   int size1=keypad(num,str);
   for(int i=0;i<s.length()-1;i++)
    {
        for(int j=0;j<size1;j++)
            str[(i+1)*size1+j]=str[j];
    }
     for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<size1;j++)
            str[i*size1+j]=str[i*size1+j]+s[i];
    }
    return s.length()*size1;
   }
int main(){
int n;cin>>n;
string str[100];
int cnt=keypad(n,str);
 for(int i=0;i<cnt;i++)
    cout<<str[i]<<endl;
 }
