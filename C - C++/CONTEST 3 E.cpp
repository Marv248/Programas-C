#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l;
    cin >> n >> l;
    vector<int> a(n, 0); // donde hay linternas
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    double max_dist = 0;
    int izq = 0, der = 1;
    // two pointers para hallar el radio máximo entre linternas necesario para cubrir todo el camino
    // Comparar con el siguiente elemento de la lista y guardar el máximo de la distancia necesaria para llegar a la siguiente luz
    while(der < n){
        if(a[0]!=0 && izq == 0){
            int dist = a[izq];
            if (dist > max_dist){
                max_dist = (double) dist;
            }
        }
        if(a[n-1] != l && der == n-1){
            int dist = l - a[der];
            if (dist > max_dist){
                max_dist = (double) dist;
            }
        }
        int dist = a[der] - a[izq];
        if ((double)dist/2.0 > max_dist){
            max_dist = (double) dist / 2.0;
        }
        izq++;
        der++;
    }
    
    cout << max_dist << endl;
}