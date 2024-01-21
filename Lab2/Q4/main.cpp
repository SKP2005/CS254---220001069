#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int l, int r) {
    int x = a[r];
    int i = l-1;
    for(int j = l; j < r; ++j) 
        if(a[j] < x) swap(a[++i], a[j]);
    swap(a[i+1], a[r]);
    return i+1;
}

int quickselect(vector<int>& a, int l, int r, int k) {
    if(r>l) {
        int p = partition(a, l, r);
        if(k < p) return quickselect(a, l, p-1, k);
        if(k > p) return quickselect(a, p+1, r, k);
        if(k == p) return a[k];
    }
    if(l == k) return a[l];
    if(r == k) return a[r];
    return INT_MAX;
}

int main() {
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.push_back(t);
    }


    int x = quickselect(a, 0, n-1, (n-1)/2);
    int y = quickselect(a, 0, n-1, n/2);

    cout << (x+y)/2 << "\n";
    return 0;
}