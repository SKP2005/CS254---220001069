// t.c->O(V+E)
//s.c->O(V+E)
#include <bits/stdc++.h>
using namespace std;

void topoSort(int node,vector<bool>&visited,stack<int>&s,unordered_map<int,list<int>>&adj){
    visited[node]=1;
    for(auto nei:adj[node]){
         if(!visited[nei]){
            topoSort(nei,visited,s,adj);
        }
    }
    s.push(node);
}


int main() {
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {0, 2},
        {1, 3},

    };
    int v=4;
    int e=4;
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    vector<bool>visited(v,0);
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i,visited,s,adj);
        }
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    for(auto it:ans){
        cout<<it<<" ";
    }cout<<endl;

    return 0;
}