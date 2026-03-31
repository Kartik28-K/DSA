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
void dfs(int source , vector<vector<pair<int,int>>> &adj , stack<int> &st , vector<int> &vis){
    vis[source]=1;
    for ( auto it : adj[source])
    {   
        if(vis[it.first]!=1){
            dfs(it.first,adj,st,vis);
        }
    }
    st.push(source);
}
int main()
{
     vector<vector<pair<int,int>>> adj={
        {{1,2}},
        {{3,1}},
        {{3,3}},
        {},
        {{0,3},{2,1}},
        {{4,1}},
        {{4,2},{5,3}}
    };
    int n=7 ; 
    int source=6 ;
    vector<int> vis(n,0);
    vector<int> dist(n,INT_MAX);
    dist[source]=0;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            dfs(i,adj,st,vis);
        }
    }
    while (st.empty()!=1)
    {
        int node=st.top();
        st.pop();
        if(dist[node]!=INT_MAX){
            for (auto it : adj[node])
                {
                    int nd = it.first;
                    int wt = it.second;
                    if(dist[node]+wt<dist[nd]){
                        dist[nd]=dist[node]+wt;
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