#include <bits/stdc++.h>
using namespace std;

// parent[x] es el representante del conjunto al que pertenece x.
const int MAXN = 200005;
int parentNode[MAXN], rankNode[MAXN];

// potential[x] representa valor[x] - valor[parent[x]].
// Al aplicar find, se actualiza para que represente valor[x] - valor[raiz].
long long potential[MAXN];

// Busca la raiz y comprime el camino para que las siguientes búsquedas sean rápidas.
int findSet(int node) {
    if (parentNode[node] == node) return node;

    int oldParent = parentNode[node];
    parentNode[node] = findSet(oldParent);
    potential[node] += potential[oldParent];
    return parentNode[node];
}

int main() {
    // Desactiva sincronización innecesaria y acelera la entrada/salida.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        // Cada vértice comienza como un conjunto independiente, sin diferencia conocida.
        for (int node = 1; node <= n; ++node) {
            parentNode[node] = node;
            rankNode[node] = 0;
            potential[node] = 0;
        }

        bool possible = true;

        // Cada restricción equivale a: valor[a] - valor[b] = c.
        // El DSU ponderado permite comprobarla sin construir el grafo ni recorrerlo.
        while (m--) {
            int a, b;
            long long c;
            cin >> a >> b >> c;

            // findSet deja potential[a] y potential[b] como diferencias respecto a sus raíces.
            int rootA = findSet(a);
            int rootB = findSet(b);
            long long differenceToA = potential[a];
            long long differenceToB = potential[b];

            if (rootA == rootB) {
                // Si ya están conectados, la nueva restricción debe ser consistente.
                if (differenceToA - differenceToB != c) possible = false;
            } else {
                // Unimos por rango y calculamos la diferencia entre ambas raíces.
                if (rankNode[rootA] < rankNode[rootB]) {
                    // potential[rootA] = valor[rootA] - valor[rootB].
                    parentNode[rootA] = rootB;
                    potential[rootA] = c - differenceToA + differenceToB;
                } else {
                    // potential[rootB] = valor[rootB] - valor[rootA].
                    parentNode[rootB] = rootA;
                    potential[rootB] = differenceToA - differenceToB - c;
                    if (rankNode[rootA] == rankNode[rootB]) ++rankNode[rootA];
                }
            }
        }

        // La respuesta es válida únicamente si ninguna restricción fue contradictoria.
        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}