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
int sum(int n){
    if(n==0) return 0;
    return n+sum(n-1);
}
int main()
{
    cout<<sum(10);
return 0;
}