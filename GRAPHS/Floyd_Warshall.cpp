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
    int inf=INT_MAX;
    int n=4;//number of vertex
    vector<vector<int>> adj={
       {0,2,inf,inf},
       {1,0,3,inf}, 
       {inf,inf,0,inf},
       {3,5,4,0},
    };
    vector<vector<int>> cost=adj;
    for (int k = 0; k< n;k++)
    {
        for (int  i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][k] != inf && cost[k][j] != inf) cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    
return 0;
}