// t.c->O(V+E)
//s.c->O(V+E)

#include <bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,vector<int>&disc,vector<int>&low,unordered_map<int,bool>&vis,
unordered_map<int,list<int>>&adj,vector<int>&ap,int &timer,vector<vector<int>> &result){
    vis[node]=true;
    disc[node]=low[node]=timer++;
    int child=0; //child is for handeling parent=-1 case
    for(auto nbr:adj[node]){
        if(nbr==parent) continue;

        if(!vis[nbr]){
            dfs(nbr,node,disc,low,vis,adj,ap,timer,result);
            low[node]=min(low[node],low[nbr]);

            //check edge is bridge
            if(low[nbr]>disc[node]){
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
            //check ap or not
            if(low[nbr]>=disc[node] && parent!=-1){
                ap[node]=1;
            }
            else{
                //node already visited and not parent
                //back edge
                low[node]=min(low[node],disc[nbr]);
            }
            child++;
        }
        if(parent==-1 && child>1){
            ap[node]=1;
        }
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
    int timer=0;
    vector<int>disc(V),low(V);
    unordered_map<int,bool>vis;
    vector<int>ap(V,0);
    vector<vector<int>>result;
    int parent=-1;
    for(int i=0;i<V;i++){
        disc[i]=-1;
        low[i]=-1;
    }
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,-1,disc,low,vis,adj,ap,timer,result);
        }
    }
    //print ap
    cout<<"Articulation points are: "<<endl;
    for(int i=0;i<V;i++){
        if(ap[i]!=0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    cout<<"Bridges are: "<<endl;
    for(auto r:result){
        cout<<r[0]<<"-"<<r[1]<<endl;

    }
    cout<<endl;

    return 0;
}