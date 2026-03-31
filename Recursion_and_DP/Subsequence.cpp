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
void subseq(vector<int>& arr , int i , int n,vector<int>& ans){
    if(i>=n){
        for (int k = 0; k < ans.size(); k++)
        {
            cout<<ans[k]<<" ";
        }
        cout<<endl;
        return;
    }
    ans.push_back(arr[i]);
    subseq(arr,i+1,n,ans);
    ans.pop_back();
    subseq(arr,i+1,n,ans);
    return;
    
}
int main()
{
    vector<int> arr={3,1,2};
    vector<int> ans;
    subseq(arr,0,arr.size(),ans);
return 0;
}