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
    items={{1,2,10},{2,5,20},{3,7,15},{4,3,7},{5,1,5}};
    int wlimit=10;
    vector<vector<int>>dp(items.size()+1,vector<int>(wlimit+1,-1));
    int res=solve(0,items,wlimit,dp);
    cout<<res<<endl;
    return 0;
}