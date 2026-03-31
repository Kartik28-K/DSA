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
void print(int n,int count){
    if(count>n){
        return;
    }
    else{
        cout<<count<<endl;
        print(n,count+1);
    }
    return;
}
int main()
{
    print(10,1);

return 0;
}