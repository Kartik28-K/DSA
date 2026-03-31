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
void print(string s ,int count){
    if(count==5){
        return;
    }
    else{
        cout<<s<<endl;
        print(s,count+1);
    }
    return;
}
int main()
{
    string name="Hello";
    print(name,0);

return 0;
}