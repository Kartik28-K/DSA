#include <iostream>
#include <string>
using namespace std;
string convertToBinary(int n){
    string res="";
    while(n!=1){
        int remainder = n%2;
        n=n/2;
        if(remainder==1) res+='1';
        else res+='0';
    }
    return res;
}
int main(){
    int num=7;
    string res = convertToBinary(num);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i];
    }
    
    return 0;
}