#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
void print_1(int count){
    if(count==0){
        return;
    }
    print_1(count-1);
    cout<<count<<endl;
}
void print_2(int count,int n){
    if(count>n){
        return;
    }
    print_2(count+1,n);
    cout<<count<<endl;
}
int main()
{
    print_1(10);
    print_2(1,10);


return 0;
}