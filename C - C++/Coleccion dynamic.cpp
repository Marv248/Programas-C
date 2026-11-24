/*
        IDEA
    Hacer una lista ordenada para guardar los elementos
    OPERACIÓN 1
        Actualizar 
        Buscar el primer elemento mayor a k con bynary search en la lista
        Si no hay lo agregamos
        Si hay, lo reemplazamos por k
        Si k está en la lista (ps ni modo no pasa nada) (método externo como .contains() o algo así)
    
    Operación 2
        Querry
        Contar el subarreglo generado desde el primer a hasta el último b
*/

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &lista,  int k){
    int l = 0, r = lista.size()-1;
    while(l<=r){
        int mid = l + (r-l) / 2;
        if(lista[mid] <= k){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int lowerBound(vector<int> &lista, int k){
    int l = 0, r = lista.size() - 1;
    while(l<= r){
        int mid = l + (r-l)/2;
        if (lista[mid] < k){
            l = mid + 1;
        } else{
            r = mid -1;
        }
    }
    return l;
}

int bynSearch(vector<int> &lista, int k){
    int l = 0, r = lista.size() - 1;
    while(l<=r){
        int mid = l + (r-l) / 2;
        if (lista[mid] < k)l = mid +1; 
        else r = mid -1;
        if (lista[mid] == k) return k;
    }
    return -1;
}

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> lista;

    while (n--)
    {
        int elemento;
        cin >> elemento;
        lista.push_back(elemento);
    }
    
    
    sort(lista.begin(), lista.end()); // Ordenar la lista

    int operacion;
    while(q--){
        cin >> operacion;
        if (operacion == 1){
            // Actualizar
            int k;
            cin >> k;
            if (bynSearch(lista, k) == -1){ // Si k NO está en la lista
                int index = upperBound(lista, k);
                if(index != lista.size()){ // Si k no es mayor que cualquier elemento (hasta la derecha)
                    lista[index] = k; // Actualizar el primer elemento inmediatamente superior a k en la lista por k
                } else {
                    lista.push_back(k); // Si k es el mayor, lo ponemos hasta el final de la lista
                }
            }
        } else{ // operacion == 2
            // Recorrer la lista desde el primer elemento igual a A hasta el último B
            int a , b;
            cin >> a >> b;
            int idx_a, idx_b;
            idx_a = lowerBound(lista, a);
            idx_b = upperBound(lista, b) - 1; // -1 ya que upperBound te devuelve el primer número estrictamente mayor, y queremos el último menor o igual a b

            int ans = (idx_b-idx_a) + 1;
            cout << ans << endl;
        }
    }
    return 0;
}