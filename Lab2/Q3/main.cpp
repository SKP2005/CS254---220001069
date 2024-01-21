#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int l, int m, int r) {
    int i = l;
    int j = m + 1;

    while (i <= m && j <= r) {
        if (a[i] <= a[j]) i++;
        else {
            int temp = a[j];
            for (int k = j; k > i; k--) a[k] = a[k - 1];
            a[i] = temp;
            i++, j++, m++;
        }
    }
}

void mergeSort(vector<int>& a, int l, int r) {
    if (r>l) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    mergeSort(a, 0, n - 1);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}