// Topo Sort
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
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int>& st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] != 1)
        {
            dfs(it, adj, vis ,st);
        }
    }
    st.push(node);
}
int main()
{
    vector<vector<int>> adj = {
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2},
    };
    int n = 6; // number of nodes
    vector<int> vis(n,0);
    stack<int> st;
    // When returning from dfs put it into the stack
    for (int i = 0; i < vis.size(); i++)
    {
        if (vis[i] != 1)
        {
            dfs(i, adj, vis, st);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}