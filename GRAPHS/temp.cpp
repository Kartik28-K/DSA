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
    // topo sort using df
    vector<vector<int>> adj={
        {},
        {},
        {3},
        {1},
        {0,1},
        {0,2}
    };
    int n=adj.size();
    vector<int> indeg(n,0);
    for ( int i = 0; i < n; i++)
    {
        for ( auto it : adj[i])
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
    while (!q.empty()){
        int node = q.front();
        for ( auto it : adj[node])
        {
            
        }
    }
    
return 0;
}