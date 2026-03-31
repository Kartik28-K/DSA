// Topological sort using BFS
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
vector<int> topoSort(int n, vector<vector<int>> &adj)
{
    vector<int> indeg(n,0);

    // compute indegree
    for(int i = 0; i < n; i++){
        for(auto it : adj[i]){
            indeg[it]++;
        }
    }

    queue<int> q;

    // push all nodes with indegree 0
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(auto it : adj[node]){
            indeg[it]--;

            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }

    return topo;
}
int main()
{
    vector<vector<int>> adj={
        {},
        {},
        {3},
        {1},
        {0,1},
        {0,2}
    };
    int n = 6; // number of nodes
    vector<int> indeg(n,0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indeg[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        cout<<node<<endl;
        q.pop();
        for ( auto it : adj[node])
        {
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }
return 0;
}