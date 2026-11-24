#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Representa un costo infinito para movimientos inválidos
int n;
vector<int> h;
vector<int> memo; // Tabla de memoización para guardar estados ya resueltos

// Paso 1
//  Costo mínimo para ir de la piedra 'i' hasta 'n - 1'
int mejorSaltoDP(int i) {
    // Paso 2: Casos base
    if (i == n - 1) return 0;   // Llegamos a la última piedra, costo extra = 0
    if (i >= n) return INF;     // Nos pasamos del límite, camino inválido

    // Paso 4: Memoización (¿Ya resolvimos este subproblema antes?)
    if (memo[i] != -1) {
        return memo[i];
    }

    // Paso 3: Transiciones (probar las dos decisiones posibles)
    // Opción A: Saltar a i + 1
    int salto1 = abs(h[i] - h[i + 1]) + mejorSaltoDP(i + 1);

    // Opción B: Saltar a i + 2 (validamos que i + 2 exista para no leer basura en h[i+2])
    int salto2 = INF;
    if (i + 2 < n) {
        salto2 = abs(h[i] - h[i + 2]) + mejorSaltoDP(i + 2);
    }

    // Guardamos el mejor resultado en memo[i] antes de retornarlo
    return memo[i] = min(salto1, salto2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    h.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    // Inicializamos la memoria con -1 (indicando que ningún estado ha sido visitado)
    memo.assign(n, -1);

    // Paso 5: Empezamos desde la piedra 0
    cout << mejorSaltoDP(0) << "\n";

    return 0;
}