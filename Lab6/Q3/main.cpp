// t.c->O(V+E)
//s.c->O(V+E)
#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<bool>&visited,stack<int>&s,unordered_map<int,list<int>>&adj){
    visited[node]=1;
    for(auto nei:adj[node]){
         if(!visited[nei]){
            dfs(nei,visited,s,adj);
        }
    }
    s.push(node);
}
void revDFS(int node,vector<bool>&visited,unordered_map<int,list<int>>&adj){
    visited[node]=1;
    for(auto nbr:adj[node]){
        revDFS(nbr,visited,adj);
    }
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
    int V=6;
    int E=6;
    unordered_map<int,list<int>>adj;
    for(int i=0;i<E;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    vector<bool>visited(V,0);
    stack<int>s;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,visited,s,adj);
        }
    }
    //create transpose graph
    unordered_map<int,list<int>>transpose;
    for(int i=0;i<V;i++){
        visited[i]=0;
        for(auto nbr:adj[i]){
            transpose[nbr].push_back(i);
        }
    }
    //dfs call using above ordering
    int count=0;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(!visited[top]){
            count++;
            revDFS(top,visited,transpose);
        }
    }
    cout<<count<<endl;

    return 0;
}