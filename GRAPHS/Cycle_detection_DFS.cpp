// cycle Detection Undirected Graph using DFS
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
bool dfs(pair<int,int> node , vector<vector<int>> &adj , vector<int> &vis , int n){
    for(auto it: adj[node.first]){
        if(vis[it]==1 and node.second!=it ){
            return true;
        }
        else if(vis[it]!=1){
            vis[it]=1;
            if (dfs({it,node.first},adj,vis,n)==true){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> adj={
        {},
        {2,3},
        {1,5},
        {4,1,6},
        {3},
        {2,7},
        {3,7},
        {5,6},
    };
    int n=7; // number of nodes
    vector<int> vis(n+1,0);
    pair<int,int> start={1,-1};
    vis[start.first]=1;
    cout<<dfs(start,adj,vis,n);
return 0;
}