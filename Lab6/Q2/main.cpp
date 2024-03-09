#include <bits/stdc++.h>
using namespace std;

int ans=0;
int bfs(int node,set<int>&vis,unordered_map<int,list<int>>&adj){
        
 }


int main() {
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {0, 2},
        {1, 3},
        {2, 4},
        {1, 5}
    };
    int v=6;
    int e=6;
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    set<int>vis;
    for(int i=0;i<v;i++){
        if(vis.find(i)==vis.end()){
            bfs(i,vis,adj);
        }
    }
    return 0;
}