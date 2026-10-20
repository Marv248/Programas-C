#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, l;
    if (!(cin >> n >> l)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid == 0) {
            ans = 0;
            low = mid + 1;
            continue;
        }

        long long current_sum = 0;
        for (int i = 0; i < mid; i++) {
            current_sum += a[i];
        }
        long long max_window_sum = current_sum;

        for (int i = mid; i < n; i++) {
            current_sum += a[i] - a[i - mid];
            max_window_sum = max(max_window_sum, current_sum);
        }

        if (max_window_sum <= l) {
            ans = mid;      
            low = mid + 1;
        } else {
            high = mid - 1; 
        }
    }

    cout << ans << "\n";
    return 0;
}