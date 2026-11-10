#include <bits/stdc++.h>
using namespace std;

bool bfs_colorear(int inicio, const vector<vector<int>>& grafo, vector<int>& color) {
    queue<int> q;
    q.push(inicio);
    color[inicio] = 1; // Asignamos el grupo 1 al nodo inicial

    while (!q.empty()) {
        int nodo_act = q.front();
        q.pop();

        for (int amigo : grafo[nodo_act]) {
            if (color[amigo] == 0) {
                // Si el amigo no tiene grupo, le asignamos el opuesto (si es 1 pasa a 2, si es 2 pasa a 1)
                color[amigo] = 3 - color[nodo_act];
                q.push(amigo);
            } else if (color[amigo] == color[nodo_act]) {
                // Si el amigo ya tiene grupo y es el mismo que el actual, hay conflicto
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Grafo 1-indexado de tamaño n + 1 para evitar desbordamientos
    vector<vector<int>> grafo(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // Las relaciones de amistad son bidireccionales
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    
    // Vector para almacenar el grupo asignado (0 = sin visitar, 1 o 2 = grupos)
    vector<int> color(n + 1, 0);
    bool possible = true;

    // Recorrer todos los nodos por si el grafo tiene componentes desconexas
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (!bfs_colorear(i, grafo, color)) {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        for (int i = 1; i <= n; i++) {
            cout << color[i] << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}