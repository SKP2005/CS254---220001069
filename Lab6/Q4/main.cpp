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
  bool check_cycle(int V,stack<int>&s,unordered_map<int,list<int>>&adj)
{
    vector<int>ans;
    unordered_map<int, int> pos;
    int index = 0;
    while (!s.empty()) {
        pos[s.top()] = index;
        ans.push_back(s.top());
        index += 1;
        s.pop();
    }
 
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            if (pos[i] > pos[it]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
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
            topoSort(i,visited,s,adj);
        }
    }
    if(check_cycle(V,s,adj)){
        cout<<"cycle present"<<endl;
    }else{
        cout<<"cycle absent"<<endl;
    }
    return 0;
}