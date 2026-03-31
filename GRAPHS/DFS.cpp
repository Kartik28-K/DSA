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
void dfs(vector<vector<int>> adj , int start , vector<int>& vis){
    int node = start;
    cout<<node<<" ";
    vis[node]=1;
    for (auto it : adj[node])
    {
        if(vis[it]==0){
            dfs(adj,it,vis);
        }
    }
    
}
int main()
{
    int m=8;
    int n=8;
    vector<vector<int>> adj={
        {},
        {2,6},
        {3,4},
        {2},
        {2,5},
        {4,7},
        {1,8,7},
        {6,5},
        {1,6}
    };
    int start=1;
    vector<int> vis(n+1,0);
    vis[start]=1;
    dfs(adj , start , vis);
return 0;
}