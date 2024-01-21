#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    
    int first_minima = INT_MAX, second_minima = INT_MAX;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] < first_minima) {
            second_minima = first_minima;
            first_minima = a[i];
            continue;
        }
        if(a[i] < second_minima) second_minima = a[i];
    }
    cout << first_minima << "\n";
    cout<< second_minima << "\n";
}