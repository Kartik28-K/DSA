#include <iostream>
using namespace std;
int main(){
    int m , n;
    int adj[n+1][m+1];
    for (int i = 0; i < m; i++)
    {
        int u , v ;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][v]=1;
    }
    return 0;

}