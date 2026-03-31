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
    int m=8;
    int n=8;
    vector<vector<int>> adj={
        {},
        {2,6},
        {3,4},
        {2},
        {2,5},
        {4,7},
        {1,8,7},
        {6,5},
        {1,6}
    };
    vector<int> vis(n+1,0);
    queue<int> q; 
    int start=1;
    q.push(start);
    vis[start]=1;
    while (q.empty()!=true)
    {
        int c=q.front();
        q.pop();
        //vis[c]=1;
        cout<<c<<endl;
        for(auto it : adj[c]){
            if(vis[it]!=1){
                q.push(it);
                vis[it]=1;
            }
        }
        
    }
return 0;
}