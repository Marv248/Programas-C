#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    long long total = 0;
    long long min_abs = 2e18;
    int neg_count = 0;
    bool has_zero = false;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            neg_count++;
        }
        if (arr[i] == 0) {
            has_zero = true;
        }
        min_abs = min(min_abs, abs(arr[i]));
        total += abs(arr[i]);
    }

    // Conteo correcto de operaciones permitiendo que los ceros conecten bloques negativos
    long long ops = 0;
    int i = 0;
    while (i < n) {
        // Avanzamos hasta encontrar un número negativo
        while (i < n && arr[i] >= 0) {
            i++;
        }
        
        if (i < n) {
            ops++; // Encontramos un bloque que requiere operación
            // Avanzamos mientras los elementos sean menores o iguales a 0 (negativos y ceros se absorben)
            while (i < n && arr[i] <= 0) {
                i++;
            }
        }
    }
    cout << total << " " << ops << "\n";
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    system("pause");
    return 0;
}