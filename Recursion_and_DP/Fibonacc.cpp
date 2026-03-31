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
int fibo(int n,vector<int> &memo){
    if(n==0) return 0;
    if(n==1) return 1;
    if(memo[n]!=-1){
        return memo[n];
    }
    int ans = fibo(n-1,memo)+fibo(n-2,memo);
    memo[n]=ans;
    return ans;
}
int main()
{
    int n=10;
    vector<int> memo(n+1,-1);

    // using tabulation
    int i=1;
    int j=0;
    int curr_ans=-1;
    for(int k=0 ; k<n-1 ; k++ )
    {
        curr_ans=i+j;
        j=i;
        i=curr_ans;
    }
    // memo[i]=memo[i-1]+memo[i-2];
    cout<<curr_ans;
return 0;
}