#include <iostream>
#include <string>
using namespace std;

string dial(int d){
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

void pK(int num,string out){

    if(num==0){
        cout<<out<<endl;
        return;
    }
    string pd=dial(num%10);
    for(int i=0;i<pd.size();i++){
        pK(num/10,pd[i]+out);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    pK(num,"");

}
int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
