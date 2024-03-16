#include <bits/stdc++.h>
using namespace std;

int greedy(vector<vector<float>>&modified,int wlimit,vector<int>&ans){
    int total_cost=0;
    for(int i=0;i<modified.size();i++){
        if(wlimit-modified[i][2]>=0){
            wlimit-=modified[i][2];
            total_cost+=modified[i][3];
            ans.push_back(modified[i][1]);
        }
    }
    return total_cost;
}

int main(){
    vector<vector<float>>items;
    items={{1,2,10.00},{2,5,20.00},{3,7,15.00},{4,3,7.00},{5,1,5.00}};
    int wlimit=10;
    vector<vector<float>>modified;
    for(auto it:items){
        vector<float>temp;
        temp.push_back(it[2]/it[1]);
        temp.push_back(it[0]);
        temp.push_back(it[1]);
        temp.push_back(it[2]);
        modified.push_back(temp);
    }
    vector<int>ans;
    sort(modified.rbegin(),modified.rend());
    int res=greedy(modified,wlimit,ans);
    cout<<res<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }cout<<endl;
    return 0;
}