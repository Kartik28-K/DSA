#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void swapNum(){
    int a = 5;
    int b = 10;
    cout<<"before swap:"<<a<<" "<<b<<endl;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"after swap:"<<a<<" "<<b<<endl;
}
void check(){
    // chech if the ith bit of a number is set or not
    int num=13;
    int i=2;
    if( num && (i<<2)!=0) cout<<"it is a set"<<endl;
    else cout<<"it is not a set"<<endl;
}
void set(){
    // set ith bit to one
    int num = 9;
    int i = 2;
    int temp = 1<<i; //right shift to ith places
    cout<<(num | temp)<<endl;
}
void clear(){
    // clear the ith bit
    int num = 13;
    int i=2;
    int temp = ~(1<<i);
    cout<<(num & temp)<<endl;
}
void rightMost(){
    // remove the rightmost one
    int num = 40;
    cout<<(num & num-1)<<endl;
}
void toggle(){
    // toggle the ith bit
    int num = 13;
    int i=2;
    int temp = (1<<i);
    cout<<(num ^ temp)<<endl;
}

int main(){
    //swapNum();
    //check();
    //set();
    //clear();
    //toggle();
    rightMost();
    return 0;
}