#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mapa(n, vector<char>(m));
    int nodo_A = -1, nodo_B = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapa[i][j];
            if (mapa[i][j] == 'A') {
                nodo_A = i * m + j;
            } else if (mapa[i][j] == 'B') {
                nodo_B = i * m + j;
            }
        }
    }

    // Estructuras para la BFS y reconstrucción del camino
    vector<bool> visitados(n * m, false);
    vector<int> parent(n * m, -1);
    vector<char> move_dir(n * m, ' ');

    queue<int> q;
    q.push(nodo_A);
    visitados[nodo_A] = true;

    // Direcciones: Arriba, Abajo, Izquierda, Derecha
    int d_i[] = {-1, 1, 0, 0};
    int d_j[] = {0, 0, -1, 1};
    char dir_char[] = {'U', 'D', 'L', 'R'};

    bool encontrado = false;

    while (!q.empty()) {
        int actual = q.front();
        q.pop();

        if (actual == nodo_B) {
            encontrado = true;
            break;
        }

        int r = actual / m;
        int c = actual % m;

        for (int k = 0; k < 4; k++) {
            int ni = r + d_i[k];
            int nj = c + d_j[k];

            // Verificar límites y que no sea una pared
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && mapa[ni][nj] != '#') {
                int vecino = ni * m + nj;
                if (!visitados[vecino]) {
                    visitados[vecino] = true;
                    parent[vecino] = actual;
                    move_dir[vecino] = dir_char[k];
                    q.push(vecino);
                }
            }
        }
    }

    if (!encontrado) {
        cout << "NO\n";
        return 0;
    }

    // Reconstruir el camino desde B hasta A
    string path = "";
    int curr = nodo_B;
    while (curr != nodo_A) {
        path += move_dir[curr];
        curr = parent[curr];
    }
    
    // Como el camino se armó de B a A, lo invertimos para que sea de A a B
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.length() << "\n";
    cout << path << "\n";
    return 0;
}