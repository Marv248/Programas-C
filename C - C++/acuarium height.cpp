#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    long long x;
    cin >> t;

    while(t--){
        cin >> n >> x;
        vector<long long> h(n);
        for(int i=0; i<n; i++){
            cin >> h[i];
        }
        sort(h.begin(), h.end());
        vector<long long> prefix(n);
        prefix[0] = h[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + h[i];
        }

        long long i=1, f=2e9 + 7;
        long long ans = 1;
        while(i <= f){
            long long mid = i + (f-i)/2;
            // Búsqueda binaria manual para encontrar cuántos corales son <= mid
            long long low = 0, high = n - 1;
            long long idx = -1;
            while(low <= high){
                long long m = low + (high - low) / 2;
                if(h[m] <= mid){
                    idx = m;
                    low = m + 1; // Intentamos buscar más a la derecha
                } else {
                    high = m - 1;
                }
            }
            
            long long count = idx + 1;
            long long sum_corals = (count > 0) ? prefix[count - 1] : 0;
            long long water_needed = (count * mid) - sum_corals;
            
            if(water_needed <= x){
                ans = mid;
                i = f + 1;
            } else {
                f = mid;
            }
        }
        
        cout << ans << "\n";
    }
    system("pause");
}