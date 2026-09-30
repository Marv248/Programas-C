#include<bits/stdc++.h>
using namespace std;

int main () {                                                                                                       
    int n, der;
    cin >> n;
    vector<long long> arreglo (n+1,0);
    vector<long long> p_max (n+1,0);
    vector<long long> p_min (n+2,0);
    for (int i=1; i<=n; i++){
        cin >> arreglo[i];  
    }

    p_max[0] = arreglo[0];
    der = 1; // Limpiar la variable
    long long  prefix_max = *min_element(arreglo.begin(), arreglo.end());
    for (int i = 1; i <= n; i++){
        p_max[i] = p_max[i-1] + arreglo[i];

        if(p_max[i]>prefix_max){
            prefix_max = p_max[i];
            der = i;
        }
    }
    p_min[der+1] = 0;
    long long prefix_min = arreglo[der]; // Asignamos por determinado el valor del extremo máximo
    for (int i = der; i > 0; i--){
        p_min[i] = p_min[i+1] + arreglo[i];
        if(p_min[i]>prefix_min){
            prefix_min = p_min[i];
        }
    }
    cout << prefix_min << endl;

    system("pause");
    return 0;
}