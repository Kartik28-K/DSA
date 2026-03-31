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
        else if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main()
{
    // DisjointSet ds(7);
    // ds.unionByRank(1,2);
    // ds.unionByRank(2,3);
    // ds.unionByRank(4,5);
    // ds.unionByRank(6,7);
    // ds.unionByRank(5,6);
    // // if 3 and 7 belong to same component or not
    // if(ds.findUPar(3)==ds.findUPar(7)){
    //     cout<<"sma";
    // }
    // else{
    //     cout<<"notsmae";
    // }
    // ds.unionByRank(3,7);
    // if(ds.findUPar(3)==ds.findUPar(7)){
    //     cout<<"sma";
    // }
    // else{
    //     cout<<"notsmae";
    // }
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    // if 3 and 7 belong to same component or not
    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"same";
    }
    else{
        cout<<"not same";
    }
    ds.unionByRank(3,7);
    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"same";
    }
    else{
        cout<<"not same";
    }

return 0;
}