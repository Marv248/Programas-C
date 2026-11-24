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

// Primer término mayor o igual
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

// Primer término estrictamente mayor
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

int main() {
    vector<int> arr = {1, 2, 2, 2, 4, 5, 8, 12, 15, 17, 20};
                     //0  1  2  3  4  5  6   7   8   9  10

    int pos = binarySearch(arr, 2);
    cout << "binarySearch: " << pos << endl;
    
    pos = lowerBound(arr, 7);
    cout << "lowerBound: " << pos << endl;
    
    pos = upperBound(arr, 7);
    cout << "upperBound: " << pos << endl;
    
    pos = recursiveBinarySearch(arr, 2, 0, 10);
    cout << "recursiveBinarySearch: " << pos << endl;
    

    return 0;
}