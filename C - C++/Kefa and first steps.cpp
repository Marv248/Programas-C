#include <bits/stdc++.h>
using namespace std;

// Hacerlo con vectores 
int main(){
    cin.tie(0) -> sync_with_stdio(0);   //Lectura rápida de lectura
    int n, anterior, actual, contador=0, max=1;
    cin >> n;
    while (n--){
        for(int i=0; i<n; i++){
            cin >> actual;
            if (i==0){
                anterior = actual;
            }
            if(anterior <= actual){
                contador++;
                anterior = actual;
            } else{
                if(contador>max){
                    max = contador;
                }
                contador = 0;
                anterior = actual;
            } if (i==(n-1) && max==1){
                if (anterior<=actual) contador++;
                max = contador;
            }
        }
    }
    cout << max << endl;  
    system("pause");
    return 0;
}