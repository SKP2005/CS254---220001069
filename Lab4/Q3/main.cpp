//O(nlogk)
#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue <int, vector<int>, greater<int> > pq; 
    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }
    for(int i=k;i<nums.size();i++){
        if(nums[i]>pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}
int main()
{
	vector<int>nums1={3,8,3,1,7,3,5,5,6};
    int ans=findKthLargest(nums1,4);
    cout<<"4th largest element is: "<<ans<<endl;
	return 0;
}