#include <bits/stdc++.h>
using namespace std;

void dfs_iterativo(int inicio, const vector<vector<int>>& grafo) {
    int n = grafo.size();
    vector<bool> visitados(n, false);
    stack<int> s;

    s.push(inicio);

    while (!s.empty()) {
        int actual = s.top();
        s.pop();

        // Si ya fue visitado, lo ignoramos (evita procesar duplicados en la pila)
        if (visitados[actual]) {
            continue;
        }

        // Marcamos como visitado al procesarlo
        visitados[actual] = true;
        
        // Acción al visitar el nodo (ej. imprimirlo, procesarlo, etc.)
        cout << actual << " ";

        // Recorrer los vecinos. 
        // Nota: Si quieres mantener exactamente el mismo orden de visita que la recursión 
        // (de izquierda a derecha), puedes recorrer los vecinos en orden inverso (.rbegin() a .rend()).
        for (int i = (int)grafo[actual].size() - 1; i >= 0; i--) {
            int vecino = grafo[actual][i];
            if (!visitados[vecino]) {
                s.push(vecino);
            }
        }
    }
    cout << "\n";
}

int main() {

    int n, m; // n = nodos, m = aristas
    cin >> n >> m;

    vector<vector<int>> grafo(n + 1); // Grafo 1-indexado
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u); // Si es dirigido, elimina esta línea
    }

    cout << "Recorrido DFS iterativo desde el nodo 1: ";
    dfs_iterativo(1, grafo);

    return 0;
}