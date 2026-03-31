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
class DisjointSet{
public:
    vector<int> rank ,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);// will work for both one based and zero based graph
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for (int i = 0; i < parent.size(); i++) parent[i]=i;
    }
    int findUPar(int node){
        if (node == parent[node]){
            return parent[node];
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u , int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;// belonging to same component
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u , int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;// belonging to same component
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    vector<vector<pair<int,int>>> adj={
        {},
        {{2,2},{4,1},{5,4}},
        {{1,2},{3,3},{4,3},{6,7}},
        {{4,5},{2,3},{6,8}},
        {{1,1},{5,9},{3,5},{2,3}},
        {{4,9},{1,4}},
        {{3,8},{2,7}}
    };
    int n = adj.size();
    vector<pair<int,pair<int,int>>> edges; // while making edges same edge 2 2 bar push hongi but disjoint set will manage that itself
    for (int i = 1 ; i < adj.size(); i++)
    {
        for(auto it: adj[i]){
            edges.push_back({it.second,{i,it.first}});
        }
    }
    sort(edges.begin(),edges.end());
    int mst = 0;
    vector<pair<int,int>> ans_mst;
    DisjointSet ds(n);
    for ( int i = 0; i < edges.size(); i++)
    {
        int wt = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(ds.findUPar(u)!=ds.findUPar(v)){
            mst += wt;
            ans_mst.push_back({u,v});
            ds.unionBySize(u,v);
        }
    }

    for (int i = 0; i < ans_mst.size(); i++)
    {
        cout<<ans_mst[i].first<<" "<<ans_mst[i].second<<endl;
    }
    cout<<mst<<endl;
    
    
return 0;
}