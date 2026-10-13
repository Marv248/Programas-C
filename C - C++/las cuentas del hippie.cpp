
#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, n;
    cin >> c >> n;

    vector<int> cuentas(n);

    for (int i = 0; i < n; i++) {
        cin >> cuentas[i];
    }

    vector<int> hilo = cuentas;
    hilo.insert(hilo.end(), cuentas.begin(), cuentas.end());

    int izquierda = 0;
    int negras = 0;
    int mejor = n + 1;

    for (int derecha = 0; derecha < 2 * n; derecha++) {
        if (hilo[derecha] == 0) {
            negras++;
        }

        while (negras >= c && izquierda < n) {
            mejor = min(mejor, derecha - izquierda + 1);

            if (hilo[izquierda] == 0) {
                negras--;
            }

            izquierda++;
        }

        if (izquierda >= n) {
            break;
        }
    }

    cout << mejor - c << '\n';

    return 0;
}