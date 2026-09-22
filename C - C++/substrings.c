#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main(){
    int t, n, m;
    int contador = 0;
    string x, s;
    cin >> t;
    for(int i = 0; i<t; i++){
        contador = 0; // Reiniciar el contador de movimientos
        cin >> n >> m;
        cin >> x >> s;

        while(!strstr(x.c_str(), s.c_str())){ // Mientras x no contenga a s     
            if(x.length()<m){
                x = x + x; // Duplicar la cadena x
                contador++;
            } else{
                // Si la longitud m es mayor o igual a la cadena s entonces duplicar por última vez y de seguir sin contener a s, entonces no es posible la operación
                x = x + x;
                contador++;
                if(!strstr(x.c_str(), s.c_str())){
                    contador = -1;
                    break;
                }
            }
        }
        cout << contador; // Si x contiene a s originalmente retorna 0
    }
    system("pause");
    return 0;
}