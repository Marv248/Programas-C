#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        int grid [n*n];
        for (int j = 0; j < n*n; j++){
            cin >> grid[j];
        }

        // Checar que figura es
        // Si hay un uno solo en la fila, por lógica es un triangulo
        int solito = 0; // Booleano para ver si el uno está solo en su fila
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if(solito != -1){
                    break;
                }
                if (solito==1 && grid[j+k]==1){
                    solito = -1; // Si halla más de un 1 ya no está solito el uno
                }
                else if (grid[j+k] == 1){
                    solito = 1; // El primer uno que encuentre
                }
            }
        }
        if (solito == 1){
            cout << "TRIANGLE" << endl;
        } else{
            cout << "SQUARE" << endl;
        }   
    }
    system("pause");
    return 0;
    
}