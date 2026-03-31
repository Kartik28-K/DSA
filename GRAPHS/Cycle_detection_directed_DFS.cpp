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
bool dfs(int source, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path)
{
    vis[source] = 1;
    path[source] = 1;
    for (auto it : adj[source])
    {
        if (vis[it] == 0)
        {
            if (dfs(it, adj, vis, path) == true)
            {
                return true;
            }
        }
        else if (path[it] == 1)
        {
            return true;
        }
    }
    path[source] = 0;
    return false;
}
int main()
{
    vector<vector<int>> adj = {
        {},
        {2},
        {3},
        {4, 7},
        {5},
        {6},
        {},
        {5},
        {9},
        {10},
        {8}};
    int n = 10;
    vector<int> vis(n + 1, 0);
    vector<int> path(n + 1, 0);
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs(i, adj, vis, path) == 1)
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
    {
        cout << "Cycle is Present";
    }
    else
    {
        cout << "Cycle is not Present";
    }

    return 0;
}