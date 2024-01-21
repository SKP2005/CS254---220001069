#include <bits/stdc++.h>
using namespace std;

void median(vector<int>& a, int l, int r) {
    int m = (l+r)/2;
    if(a[r] < a[l]) swap(a[l], a[r]);     
    if(a[m] < a[l]) swap(a[m], a[l]);
    if(a[r] < a[m]) swap(a[r], a[m]);
    swap(a[m], a[r-1]);
}

int partition(vector<int>& a, int l, int r) {
    median(a, l, r);
    int x = a[r-1];
    int i = l-1, j = r;
    for(int j = l; j < r-1; ++j) 
        if(a[j] < x) swap(a[++i], a[j]);
    swap(a[i+1], a[r-1]);
    return i+1;
}

void quicksort(vector<int>& a, int l, int r) {
    if(r>l) {
        int p = partition(a, l, r);
        quicksort(a, l, p-1);
        quicksort(a, p+1, r);
    }
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

    quicksort(a, 0, n - 1);
    for (int x : a) cout << x << " "; 
}