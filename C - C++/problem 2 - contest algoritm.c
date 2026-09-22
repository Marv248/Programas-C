#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n;
        int x[n];
        int y[n];
        int matriz[2*n];
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                // La matriz guarda los elementos donde deberían estar permutados
                cin >> matriz[k+j+1];
            }
        }
        // Crear una lista de los numeros que deberían estar en la permutacion
        int numbers[2*n];
        for(int j=0; j<2*n; j++){
            numbers[j] = j+1;
        }

        // Comparar con los números que deberían estar y los que están
        for(int j=0; j<2*n; j++){
            int tiene = 0; // booleano para ver si el numero está o no en la matriz
            for(int k=0; k<2*n; k++){
                if(matriz[k]==numbers[j]){
                    tiene = 1;
                }
            }
            if(tiene==0){
                matriz[0] = numbers[j];
                break;
            }
        }
        for(int j=0; j<2*n; j++){
            cout << matriz[j] << " ";
        }   
        cout << endl;
    }
    system("pause");
    return 0;
}