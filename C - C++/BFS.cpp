
#include <bits/stdc++.h>
using namespace std;

// BFS: recorre el grafo por niveles.
// Complejidad: O(V + E), utilizando lista de adyacencia.
void bfs(vector<vector<int>>& grafo, vector<int>& visitados, int nodo) {

    // Creamos una cola para mantener el orden de exploración.
    queue<int> q;

    // Insertamos el nodo inicial y lo marcamos como visitado.
    q.push(nodo);
    visitados[nodo] = true;

    // Mientras existan nodos pendientes de explorar.
    while (!q.empty()) {

        // Consultamos el primer elemento de la cola.
        int nodo_actual = q.front();

        // Lo retiramos para procesarlo.
        q.pop();

        cout << nodo_actual << " ";

        // Exploramos todos sus vecinos.
        for (int vecino : grafo[nodo_actual]) {

            // Si todavía no fue visitado...
            if (!visitados[vecino]) {

                // Lo marcamos antes de introducirlo en la cola.
                visitados[vecino] = true;

                // Queda pendiente de procesamiento.
                q.push(vecino);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Lista de adyacencia, indexada desde 1.
    vector<vector<int>> grafo(n + 1);

    // Construcción del grafo no dirigido.
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    // Ningún vértice ha sido visitado inicialmente.
    vector<int> visitados(n + 1, 0);

    // Iniciamos BFS desde el vértice 1.
    bfs(grafo, visitados, 1);

    return 0;
}
