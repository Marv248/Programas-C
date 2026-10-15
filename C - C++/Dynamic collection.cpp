#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int t) {
    int l = 0, r = arr.size() - 1;
    
    while(l <= r) {
        int m = l + (r - l)/2;
        if(arr[m] == t) return m;
        
        if(arr[m] < t)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int lowerBound(vector<int> &arr, int t) {
    int l = 0, r = arr.size() - 1;
    
    while(l <= r) {
        int m = l + (r - l)/2;
        
        if(arr[m] < t)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

int upperBound(vector<int> &arr, int t) {
    int l = 0, r = arr.size() - 1;
    
    while(l <= r) {
        int m = l + (r - l)/2;
        
        if(arr[m] <= t)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

int recursiveBinarySearch(vector<int>& arr, int t, int l, int r) {
    if (l > r) {
        return -1;
    }

    int m = l + (r - l)/2;

    if (arr[m] == t) return m;
    

    if (arr[m] < t) return recursiveBinarySearch(arr, t, m + 1, r);

    return recursiveBinarySearch(arr, t, l, m - 1);
}


int main(){
    int n, q;
    cin >> n >> q;
    vector<int> arr (n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    short operation;
    int a, b, k;
    while(q--){
        cin >> operation;
        if(operation == 1){
            cin >> k;
            if(binarySearch(arr,k) == -1){
                if(arr[arr.size()-1] >= k){
                    arr[lowerBound(arr,k+1)] = k;
                } else{
                    arr.push_back(k);
                }
            }
        } else{
            cin >> a >> b;
            int res = upperBound(arr, b) - lowerBound(arr,a);
            cout << res << endl;
        }
    }
}