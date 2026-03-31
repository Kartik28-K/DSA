// cycle detection in undirected Graph
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
int main()
{
    vector<vector<int>> adj={
        {},
        {2,3},
        {1,5},
        {1,4,6},
        {3},
        {2,7},
        {3,7},
        {5,6},
    };
    int start=1;
    int m=7 ; // number of nodes;
    vector<int> vis(m+1,0);
    vis[start]=1;
    queue<pair<int,int>> q;
    q.push({start,-1});
    while (q.empty()!=true)
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it: adj[node]){
            if (vis[it]==1 and parent!=it)
            {
                cout<<"Cycle is Present";
                return 0;
            }
            else if(vis[it]!=1){
                q.push({it,node});
                vis[it]=1;
            }
        }
    }
    
return 0;
}