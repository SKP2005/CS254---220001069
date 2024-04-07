#include <bits/stdc++.h>
using namespace std;

//T.C->O(nlogn+n*maxDeadline)

int greedy(vector<vector<int>>&modified,vector<int>&ans){
    int total_profit=0;
    int maxdead=0;
    for(int i=0;i<modified.size();i++){
        maxdead=max(maxdead,modified[i][2]);
    }
    vector<int>schedule(maxdead+1,-1);
    for(int i=0;i<modified.size();i++){
        int curprofit=modified[i][0];
        int curjobID=modified[i][1];
        int curdead=modified[i][2];

        for(int k=curdead;k>0;k--){
            if(schedule[k]==-1){
                total_profit+=curprofit;
                schedule[k]=curjobID;
                ans.push_back(curjobID);
                break;
            }
        }
    }
    return total_profit;
}

int main(){
    vector<vector<int>>jobs;
    jobs={{1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,3,15}};
    vector<vector<int>>modified;
    for(auto it:jobs){
        vector<int>temp;
        temp.push_back(it[2]);
        temp.push_back(it[0]);
        temp.push_back(it[1]);
        modified.push_back(temp);
    }
    vector<int>ans;
    sort(modified.rbegin(),modified.rend());
    int res=greedy(modified,ans);
    cout<<res<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }cout<<endl;
    return 0;
}