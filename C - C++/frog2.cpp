#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Representa un costo infinito para movimientos inválidos
int n;
int k;
vector<int> h;
vector<int> saltos; // Vector para almacenar los costos de salto
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

    // Paso 3: Transiciones (probar las k decisiones posibles)
    int minim = INF;
    for(int j = 0; j < k; j++){
        if (i +j + 1 < n) {
            saltos[i] = abs(h[i] - h[i + j + 1]) + mejorSaltoDP(i + j + 1);
            minim = min(minim, saltos[i]);
        } else {
            break;
        }
    }

    // Guardamos el mejor resultado en memo[i] antes de retornarlo
    return memo[i] = minim;
}

int main() {

    cin >> n >> k;

    h.resize(n);
    saltos.resize(n, INF); // Inicializamos los costos de salto con un valor alto
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    // Inicializamos la memoria con -1 (indicando que ningún estado ha sido visitado)
    memo.assign(n, -1);

    // Paso 5: Empezamos desde la piedra 0
    cout << mejorSaltoDP(0) << "\n";

    return 0;
}