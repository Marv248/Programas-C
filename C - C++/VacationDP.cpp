#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> a, b, c;
vector<vector<int>> memo;

int maxHappiness(int i, int ultima) {
    // Paso 2: Caso base 
    //  Ya pasaron todos los días (0 a N-1)
    if (i == N) return 0;

    // Paso 4: Memoización
    if (memo[i][ultima] != -1) {
        return memo[i][ultima];
    }

    int mejor = 0;

    // Paso 3: Probar las 3 actividades
    if (ultima != 1) {
        mejor = max(mejor, a[i] + maxHappiness(i + 1, 1));
    }
    if (ultima != 2) {
        mejor = max(mejor, b[i] + maxHappiness(i + 1, 2));
    }
    if (ultima != 3) {
        mejor = max(mejor, c[i] + maxHappiness(i + 1, 3));
    }

    return memo[i][ultima] = mejor;
}

int main() {
    
    cin >> N;

    a.resize(N);
    b.resize(N);
    c.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // Matriz de memoiazción
    memo.assign(N, vector<int>(4, -1));

    cout << maxHappiness(0, 0) << endl;

    return 0;
}