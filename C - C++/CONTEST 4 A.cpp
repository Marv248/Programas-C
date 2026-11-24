#include<bits/stdc++.h>
using namespace std;
int infinito = 1e9;
int main(){
    int t, n;
    int diferencia;
    cin >> t;
    while(t--){
        cin >> n;
        vector <int> numeros (n);
        for (int i = 0; i < n; i++)
        {
            cin >> numeros [i];
        }

        // Two pointers para tomar la diferencia mínima
        int minimo = infinito;
        int l=0, r = 1;
        while(l < r){
            diferencia = abs(numeros[r] - numeros[l]);
            minimo = min(minimo, diferencia);
            // Deslizar la ventana
            if (diferencia == 0) {
                break; // No hay diferencia menor que 0
            } 
            // Mantener fijo l y mover r
            if (r < n - 1) {
                r++;
            } else {
                l++;
            }
        }
        cout << minimo << endl;
    }
}