#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int convertToDecimal(string num){
    int n=num.size();
    int k=0;
    int ans=0;
    for(int i=n-1 ; i>=0 ; i--){
        int numeric = int(num[i])-48;
        ans = ans+ numeric*pow(2,k);
        k++;
    }
    return ans;
}
int main(){
    string nums="111";
    int  res = convertToDecimal(nums);
    cout<<endl<<res<<endl;
    
    return 0;
}