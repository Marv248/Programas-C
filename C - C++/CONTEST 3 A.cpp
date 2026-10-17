#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        // Busqueda binaria de -1 y 0.
        // Se hará upper bound y lower bound para contar la frecuencia de 0's y -1's.
        int lower = lower_bound(a.begin(), a.end(), 0) - a.begin();
        int upper = upper_bound(a.begin(), a.end(), 0) - a.begin();
        int ceros = upper - lower;

        lower = lower_bound(a.begin(), a.end(), -1) - a.begin();
        upper = upper_bound(a.begin(), a.end(), -1) - a.begin();
        int menos_uno = upper - lower;

        if(menos_uno % 2 == 1){
            cout << ceros + 2<< endl;
        } else {
            cout << ceros << endl;
        }
    }
    return 0;
}