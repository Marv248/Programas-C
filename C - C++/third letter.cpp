#include <bits/stdc++.h>
using namespace std;

/*      IDEA
    1. Recorrer el grafo y usar una lista complementaria que guarde la distancia que se debería tener para llegar al nodo siguiente.
    2. Esta lista comenzará por 0 desde el nodo base de cualquier subgrafo conexo.
    3. Cuando pasemos al siguiente nodo, añadimos a la lista en i la distancia que se debería tener entre los nodos antiguo y actual.
    4. Al llegar a un nodo preguntaremos:
        4.1. Si ya está recorrido el nodo A (primer nodo dado en la relación)
            sumamos la distancia directamente como nos la dan
        4.2. Si no, si ya está visitado B (el segundo nodo en la relación)
            Sumamos la distancia por -1 (invertida) ya que se volteó la relación
        4.3. Si ninguno está visitado
            Entonces llegamos a un nuevo componente del grafo
    Buscaremos recorrer cada subgrafo conexo para asegurar que se cumpla para todos los soldados.
    Una incongruencia es cuando un nodo llega a tener dos posiciones asignadas.
*/

// Optimizamos declarando estructuras globales para evitar reasignaciones de memoria costosas (evita TLE)
const int MAXN = 200005;
vector<vector<pair<int, long long>>> grafo(MAXN);
vector<long long> distancia(MAXN);
vector<bool> visitado(MAXN);

int main() {
    // Optimización máxima de la entrada/salida estándar
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, m;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        cin >> n >> m;

        // Limpiamos únicamente la porción del grafo y vectores que usaremos en este test case
        for (int i = 1; i <= n; i++) {
            grafo[i].clear();
            distancia[i] = LLONG_MAX;
            visitado[i] = false;
        }

        // Armar el grafo con las relaciones dadas
        for (int i = 0; i < m; i++) {
            int a, b;
            long long c;
            cin >> a >> b >> c;
            grafo[a].push_back({b, c});
            grafo[b].push_back({a, -c}); // Invertimos la relación para el otro nodo
        }

        bool posible = true;

        // 1. Recorrer el grafo completo para asegurar que cubrimos cada subgrafo conexo (bosque)
        for (int i = 1; i <= n; i++) {
            // 4.3. Si ninguno está visitado (detectamos un nuevo componente conexo)
            if (!visitado[i]) {
                queue<int> q;
                q.push(i);
                
                // 2. Esta lista comenzará por 0 desde el nodo base de cualquier subgrafo conexo.
                distancia[i] = 0;
                visitado[i] = true; // Marcamos de inmediato para evitar duplicados en la cola

                while (!q.empty() && posible) {
                    int actual = q.front();
                    q.pop();

                    // Recorremos las relaciones/vecinos del nodo actual
                    for (auto vecino : grafo[actual]) {
                        int nodoVecino = vecino.first;
                        long long pesoArista = vecino.second; // Peso directo o invertido según corresponda

                        // Evaluamos si el nodo vecino ya ha sido visitado o no
                        if (!visitado[nodoVecino]) {
                            // 4.3. Si ninguno está visitado, llegamos a un nuevo nodo del componente
                            // 3. Cuando pasemos al siguiente nodo, añadimos a la lista la distancia acumulada
                            distancia[nodoVecino] = distancia[actual] + pesoArista;
                            visitado[nodoVecino] = true; // Marcamos como visitado
                            q.push(nodoVecino);
                        } else {
                            // Si el nodo vecino ya fue visitado previamente:
                            // 4.1 y 4.2. Verificamos la congruencia comparando la distancia acumulada 
                            // contra la nueva ruta calculada desde el nodo actual.
                            if (distancia[nodoVecino] != distancia[actual] + pesoArista) {
                                posible = false; // Incongruencia encontrada (dos posiciones distintas para un mismo soldado)
                                break;
                            }
                        }
                    }
                }
            }
            if (!posible) break;
        }
        cout << (posible ? "YES\n" : "NO\n");
    }    
    system("pause");
    return 0;
}