/*
        IDEA
    Recorrer subgrafos conexos para contar los castillos
        Para esto vamos a comenzar por un nodo cualquiera y luego recorrer a sus vecinos
        Para buscar un nuevo castillo, tomaremos un nodo que no se haya visitados
    Para las paredes (separaciones) entre castillos
        Las paredes reflejaran con que nodos no se conecta el castillo
        Cuando tengamos que verificar que pasa si rompemos una pared, preguntaremos que pasa si añadimos al castillo los nodos adyacentes
    Para contar el castillo más grandes, tomaremos el máximo entre la longitud de un grafo y el de los anteriores.

    Hacer recorrimiento de bits para hallar las paredes
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<pair<int, int>> grafo(r*c); // Almacenar una lista de adyacencia de las coordenadas de los nodos
    vector<int> vistiados(r*c); // r*c = cantidad de habitaciones

    // Leer el mapa
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> grafo[i][j]; // Registrar las habitaciones
        }
    }

    // Armar grafo
    
}