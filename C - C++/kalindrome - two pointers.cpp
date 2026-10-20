#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int izq = 0, der = n - 1;
        int x = -1, y = -1;
        bool ok = true;

        while (izq < der) {
            if (a[izq] != a[der]) {
                x = a[izq];
                y = a[der];
                ok = false;
                break;
            }
            izq++;
            der--;
        }

        if (ok) {
            cout << "YES\n";
            continue;
        }

        bool ok1 = true;
        int i = 0, j = n - 1;
        while (i < j) {
            if (a[i] == x) {
                i++;
            } else if (a[j] == x) {
                j--;
            } else if (a[i] != a[j]) {
                ok1 = false;
                break;
            } else {
                i++;
                j--;
            }
        }

        bool ok2 = true;
        i = 0;
        j = n - 1;
        while (i < j) {
            if (a[i] == y) {
                i++;
            } else if (a[j] == y) {
                j--;
            } else if (a[i] != a[j]) {
                ok2 = false;
                break;
            } else {
                i++;
                j--;
            }
        }

        if (ok1 || ok2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}