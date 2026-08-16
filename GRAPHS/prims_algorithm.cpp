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
        {{1,2},{2,1}},
        {{0,2},{2,1}},
        {{0,1},{1,1},{4,2},{3,2}},
        {{2,2},{4,1}},
        {{2,2},{3,1}}
    };
    int n=adj.size(); // number of nodes
    vector<pair<int,int>> mst;
    vector<int> vis(n,0);
    // min heap
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq; //{wt,{node,parent}}
    pq.push({0,{0,-1}}); // strart from any node ( its wt i.e 0 and its parent)
    int sum=0;
    while (!pq.empty())
    {
        int wt=pq.top().first;
        int node=pq.top().second.first;
        int parent= pq.top().second.second;
        pq.pop();
        if(vis[node]==1) continue; // cycle wala case when node is alreday visited it means already added in MST
        vis[node]=1;
        if(parent!=-1){
            sum=sum+wt;
            mst.push_back({node,parent});
        }
        for(auto it : adj[node]){
            int adjNode=it.first;
            int adjWt=it.second;
            if(!vis[adjNode]){
                pq.push({adjWt,{adjNode,node}});
            }
        }
    }
    for (int i = 0; i < mst.size(); i++)
    {
        cout<<mst[i].first<<mst[i].second<<endl;
    }
    return 0;
}
