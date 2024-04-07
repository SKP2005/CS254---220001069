#include <bits/stdc++.h>
using namespace std;

int solve(int i,vector<vector<int>>&items,int wlimit,vector<vector<int>>&dp){
    if(i>=items.size()) return 0;
    if(dp[i][wlimit]!=-1) return dp[i][wlimit];
    int take=0;
    if(wlimit-items[i][1]>=0){
        take=items[i][2]+solve(i+1,items,wlimit-items[i][1],dp);
    }
    int nottake=0+solve(i+1,items,wlimit,dp);
    return dp[i][wlimit]=max(take,nottake);
}

int main(){
    vector<vector<int>>items;
    items={{1,4,1},{2,5,2},{3,1,3}};
    int wlimit=4;
    vector<vector<int>>dp(items.size()+1,vector<int>(wlimit+1,-1));
    int res=solve(0,items,wlimit,dp);
    cout<<res<<endl;
    return 0;
}