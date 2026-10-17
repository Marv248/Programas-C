#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Two pointers para encontrar el subarreglo de longitud máxima que sea menor o igual a b.
    int l = 0, r = 0, sum = 0, max_len = 0;
    while (r < n) { 
        sum += a[r];
        while (sum > b) {
            sum -= a[l];
            l++;
        }
        max_len = max(max_len, r - l + 1);
        r++;
    }
    cout << max_len << endl;
}