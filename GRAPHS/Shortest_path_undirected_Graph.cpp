// Shortest Path undirected Graph (unit Length)
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
    int n = 9 ;
    vector<vector<int>> adj={
        {1,3},
        {0,2,3},
        {1,6},
        {0,4},
        {3,5},
        {4,6},
        {2,5,7,8},
        {6,8},
        {6,7},
    };
    vector<int> dist(n,INT_MAX);
    queue<pair<int,int>> q; // {node , distance from source}
    int source=0;
    dist[source]=0;
    q.push({source , 0});
    while (q.empty()!=1)
    {
        int node=q.front().first;
        int dis=q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            int temp_dist = dis + 1;
            if(temp_dist < dist[it]){
                dist[it]=temp_dist;
                q.push({it,temp_dist});
            }
        }
    }
    for (int i = 0; i < dist.size(); i++)
    {
        cout<<dist[i]<<" ";
    }  
return 0;
}