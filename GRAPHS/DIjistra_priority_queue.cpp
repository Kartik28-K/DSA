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
        {{1,4},{2,4}},
        {{0,4},{2,2}},
        {{0,4},{1,2},{3,3},{4,1},{5,6}},
        {{2,3},{5,2}},
        {{2,1},{5,3}},
        {{2,6},{3,2},{4,3}}
    };
    int n=6; // number fo nodes
    vector<int> dist(n,1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
    int source=0;
    dist[source]=0;
    pq.push({0,source});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int edgeWt=it.second;
            int adjNode=it.first;
            int temp_dist = dis+edgeWt;
            if(temp_dist < dist[adjNode]){
                dist[adjNode]=temp_dist;
                pq.push({temp_dist,adjNode});
            }
        }
        
    }
    for (int i = 0; i < dist.size(); i++)
    {
        cout<<dist[i]<<" ";
    }
    
    
return 0;
}