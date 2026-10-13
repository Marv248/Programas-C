#include <bits/stdc++.h>
using namespace std;
/*IDEA
    Iterar con dos punteros, uno en izq "l" y otro en der "r", en estos checar si los elementos "continuos" son iguales, dejar de interar hasta que sean distintos para poder así encontrar los "bloques" de sabores y saber que pasa al retirar los bloques
    Buscar que los sabores (contando los dulces dentro de bloques) no sobrepasen k
    Devolver la lista en un rango (l, r) donde se cumplan las condiciones de k y de máxima longitud posible
*/
int main(){

    int n, k, optimo = 0;
    cin >> n >> k;

    string candys, res, candys2, final;
    cin >> candys;
    set<char> flavors;
    for(char c : candys){
        flavors.insert(c);
    }

    
    for(char c: flavors){
        // Para cada sabor, buscamos el rango más largo que cumpla con la condición de no exceder k dulces del mismo sabor
        int l=0, r = n-1, count = 1, continuos = 0, eq = 0;
        while(l<r && r<candys.size()){
            if (continuos > k || count > k){
                res = candys.substr(l, r-l);
                if(res.size() > optimo){
                    final = res;
                    optimo = res.size();
                }
                break;
            }
            if(candys[l] == c){
                eq = 1;
                while(eq){
                    continuos++;
                    count++;
                    if(candys[l] != c){
                        eq = 0;
                    } else {
                        l++;
                        continuos++;
                        count++;
                    }
                    if(candys[l] != c){
                        eq = 0;
                    } else{
                        continuos++;
                        count++;
                        r--;
                    }
                }
                
            } else {
                continuos = 0;
                l++;
            }
        }
    }
    if(!optimo){
        cout << -1 << endl;
    } else {
        cout << optimo << endl;
        cout << final << endl;
    }
    system("pause");
    return 0;    
}