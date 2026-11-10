#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>>& grafo, vector<int>& visitados, int nodo) {
    visitados[nodo] = true;
    for (int vecino : grafo[nodo]) {
        if (!visitados[vecino]) {
            dfs(grafo, visitados, vecino);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mapa(n, vector<char>(m));
    vector<vector<int>> grafo(n * m);
    vector<int> visitados(n * m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapa[i][j];
        }
    }

    // Direcciones para conectar arriba, abajo, izquierda y derecha
    int d_i[] = {-1, 1, 0, 0};
    int d_j[] = {0, 0, -1, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mapa[i][j] == '#') continue; // Ignorar paredes
            int nodo_actual = i * m + j;
            // Revisar los 4 vecinos adyacentes
            for (int k = 0; k < 4; k++) {
                int ni = i + d_i[k];
                int nj = j + d_j[k];

                // Verificar que el vecino esté dentro de los límites y sea un espacio libre '.'
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && mapa[ni][nj] == '.') {
                    int nodo_vecino = ni * m + nj;
                    grafo[nodo_actual].push_back(nodo_vecino);
                }
            }
        }
    }

    int habitaciones = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int nodo = i * m + j;
            
            // Si es un espacio libre y no ha sido visitado, es una nueva habitación
            if (mapa[i][j] == '.' && !visitados[nodo]) {
                dfs(grafo, visitados, nodo);
                habitaciones++;
            } else if (mapa[i][j] == '#') {
                visitados[nodo] = true; // Marcar las paredes como visitadas para ignorarlas
            }
        }
    }

    cout << habitaciones << endl;
    return 0;
}