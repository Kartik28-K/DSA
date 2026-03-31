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
void print(int count){
    if(count==0){
        return;
    }
    else{
        cout<<count<<endl;
        print(count-1);
    }
    return;
}
int main()
{
    print(10);

return 0;
}