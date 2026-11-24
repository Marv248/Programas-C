/*          IDEA
    La idea es armar un grafo dirigido con las relaciones de modo A -> B
    Buscaremos hacer un DFS desde cada nodo, cuando encontremos un nodo desde donde podamos recorrer todo el grafo, retornamos el orden de recorrimiento del nodo
    Si no podemos recorrer todas las materias de alguna forma, retornaremos imposible, esto con ayuda de una bandera
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grafo (n+1); // Uno indexado
    vector<int> grado_nodo(n+1);  // Total de dependencias sin resolver de la materia
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grado_nodo[b]++; // Si b depende de a, entonces se suma una dependencia más
    }

    // DFS Iterativo
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if(grado_nodo[i] == 0) q.push(i); // El nodo no tiene materias que cursar antes así que lo agregamos a la lista de materias disponibles
    }

    vector<int> orden; // Orden en que habría que inscribir las materias

    while(!q.empty()){
        int actual = q.front(); // Tomamos un elemento de los disponibles
        q.pop(); // Ya no está disponible por qué lo tomamos
        orden.push_back(actual); // Lo agregamos al orden en que hay que tomar materias
        for(int vecino : grafo[actual]){
            grado_nodo[vecino] --; // Le quitamos un grado al nodo por que lo vamos a tomar, simulamos una dependencia menos o resuelta
            if(grado_nodo[vecino] == 0) q.push(vecino); // Si el grado del nodo que visitamos ya es 0 (dependencias resueltas) la materia ya está disponible 
        }
    }

    if(orden.size() == n){ // Si logramos meter a la lista de materias ordenadas un total de n materias, entonces ya las inscribimos todas GG'S
        for (int i = 0; i < n; i++)
        {
            cout << orden[i] << (i == n-1 ? "" : " ");
        } 
        cout << endl;
    } else{
        cout << "IMPOSSIBLE";
    }
    return 0;
}