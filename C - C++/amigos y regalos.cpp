#include <bits/stdc++.h>
using namespace std;

int main() {
    int c1, c2, x, y;
    long long v, vc1, vc2;

    cin >> c1 >> c2 >> x >> y ;
    v = (c1 + c2) * 2;
    long long left = 1, right = v - 1; 
    long long ans = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        long long div_x = mid / x;
        long long div_y = mid / y;
        long long div_xy = mid / (x * y);

        long long solo_x = div_x - div_xy; // Exclusivos de X (para amigo 2)
        long long solo_y = div_y - div_xy; // Exclusivos de Y (para amigo 1)
        long long libres = mid - (div_x + div_y - div_xy); // Libres para cualquiera

        // Lo que le falta obligatoriamente al amigo 1 y amigo 2 de los exclusivos
        long long need1 = max(0LL, c1 - solo_y); // adpatado a long long
        long long need2 = max(0LL, c2 - solo_x); // adpatado a long long

        // ¿Los números libres alcanzan para cubrir lo que falta?
        if (libres >= need1 + need2) {
            ans = mid;
            right = mid - 1; // Intentamos buscar un V más pequeño
        } else {
            left = mid + 1; // Necesitamos un V más grande
        }
    }

    cout << ans << "\n";
    return 0;
}