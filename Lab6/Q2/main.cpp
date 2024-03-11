// t.c->O(V+E)
//s.c->O(V+E)
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {0, 2},
        {1, 3},
    };
    int V=4;
    int E=4;
    unordered_map<int,list<int>>adj;
    for(int i=0;i<E;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    vector<int>indegree(V);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    //push all with 0 indegree
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    //do bfs
    vector<int>ans;
    while(!q.empty()){
        int front =q.front();
        q.pop();
        ans.push_back(front);
        for(auto nbr:adj[front]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    int maxpath=0;
    vector<int>path(V,0);
    for(int x : ans) {
        for(int child : adj[x]) {
            path[child] = max(path[child], 1 + path[x]);
            maxpath = max(maxpath, path[child]);
        }
    }
    
    cout << maxpath<<endl;


    return 0;
}