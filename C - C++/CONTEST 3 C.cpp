#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t (n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }

    // Hace window slide para encontrar el subarreglo de longitud máxima que cumpla con la condición.
    int l = 0, r = 0, sum = 0, max_len = 0;
    while(r < n){
        // Buscar la cadena más larga con mitad 1 y otra mitad 2
        // Buscar un termino (en l) y ver con que se puede combinar, teniendo
    }
}