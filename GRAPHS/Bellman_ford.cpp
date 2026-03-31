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
    vector<vector<pair<int,int>>> adj={
        {{1,5}},
        {{2,-2},{5,-3}},
        {{4,3}},
        {{2,6},{4,-2}},
        {},
        {{3,1}},
    };
    // make the vector of edges 
    int n=adj.size();
    vector<int> dist(n,INT_MAX);
    dist[0]=0;
    vector<pair<pair<int,int>,int>> edges; //{{u,v},wt}
    for ( int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            int v1 = it.first;
            int u1=i;
            int wt1=it.second;
            edges.push_back({{u1,v1},wt1});
        }
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int i = 0; i < edges.size(); i++)
        {
        int u2=edges[i].first.first;
        int v2=edges[i].first.second;
        int wt2=edges[i].second;
        if(dist[u2]!=INT_MAX){
            if(dist[u2]+wt2<dist[v2]){
                dist[v2]=dist[u2]+wt2;
            }
        }
        }
    }
    
    for (int i = 0; i < dist.size(); i++)
    {
        cout<<dist[i]<<" ";
    }
    
    
return 0;
}