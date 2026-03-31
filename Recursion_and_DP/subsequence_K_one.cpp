// print any one subsequence
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
int subseq(vector<int>& arr , int i , int n,vector<int>& ans,int m,int& sum){
    if(i>=n){
        if (sum==m)
        {
            for (int k = 0; k < ans.size(); k++)
            {
                cout<<ans[k]<<" ";
            }
            cout<<endl;
           return 1;
        }
        else{
            return 0;
        }
    }
    ans.push_back(arr[i]);
    sum+=arr[i];
    int l=subseq(arr,i+1,n,ans,m,sum);
    ans.pop_back();
    sum-=arr[i];
    int r=subseq(arr,i+1,n,ans,m,sum);
    return l+r;
    
}
int main()
{
    vector<int> arr={1,2,1};
    vector<int> ans;
    int m=2;
    int sum=0;
    subseq(arr,0,arr.size(),ans,m,sum);
return 0;
}