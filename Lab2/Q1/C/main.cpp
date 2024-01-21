#include<bits/stdc++.h>
using namespace std;
vector<int> merge(int A[],int n,int B[],int m) {
 
    vector<int> C;
    size_t i = 0, j = 0;

 while (i < n && j < m) {
        if (A[i] < B[j]) {
            i++;
        } else if (B[j] < A[i]) {
            j++;
        } else {
            C.push_back(A[i]);
            i++;
            j++;
        }
    }

    return C;
}

int main() {
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<m;j++){
        cin>>b[j];
    }
    vector<int>C=merge(a,n,b,m);
    for (int num : C) {
        cout << num << " ";
    }
    cout <<endl;

    return 0;
}