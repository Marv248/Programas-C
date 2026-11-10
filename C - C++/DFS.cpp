
#include <bits/stdc++.h>
using namespace std;

// DFS: recorre el grafo en profundidad.
// Complejidad: O(V + E), utilizando lista de adyacencia.
void dfs(vector<vector<int>>& grafo, vector<int>& visitados, int nodo) {

    // Marcamos el nodo actual como visitado.
    // Esto evita volver a procesarlo y entrar en ciclos infinitos.
    visitados[nodo] = true;

    cout << nodo << " "; // Procesamos o mostramos el nodo.

    // Exploramos todos los vecinos del nodo actual.
    for (int vecino : grafo[nodo]) {

        // Solo exploramos vecinos que todavía no visitamos.
        if (!visitados[vecino]) {

            // Llamada recursiva: profundizamos por ese vecino.
            dfs(grafo, visitados, vecino);
        }
    }

    // Cuando no quedan vecinos sin visitar, la función termina
    // y regresa a la llamada anterior (backtracking).
}

int main() {
    int n, m;
    cin >> n >> m;

    // Lista de adyacencia: vértices numerados de 1 a n.
    vector<vector<int>> grafo(n + 1);

    // Construimos las conexiones.
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        grafo[u].push_back(v);

        // Si el grafo es no dirigido, también agregamos:
        grafo[v].push_back(u);
    }

    // Inicialmente ningún vértice ha sido visitado.
    vector<int> visitados(n + 1, 0);

    // Iniciamos DFS desde el vértice 1.
    dfs(grafo, visitados, 1);

    return 0;
}
