#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t (n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }

    // Hace window slide para encontrar el subarreglo de longitud máxima que cumpla con la condición.
    int l = 0, r = 1, max_len_eel = 1, max_len_tuna = 1, ans = 0;
    int bigger_tuna = 0, bigger_eel = 0, actual_class = 0;  // 1 = tuna, 2 = eel
    int i_tuna, f_tuna, i_eel, f_eel;

    // ESTO CALCULA CUAL ES LA CADENA CONTINUA MÁS PEQUEÑA DE CADA TIPO, PERO NO SE HA IMPLIMENTADO VERIFICAR SI PUEDE SER COMBINADA A LA IZQUIERDA  O A LA DERECHA

    while(r < n){
        // Si el segmento no es continuo con la clase anterior
        if(actual_class != t[l]){
            // De que tipo es el sushi
            if(t[l] == 1){
                bigger_tuna = 1;
                actual_class = 1;
            } else {
                bigger_eel = 1;
                actual_class = 2;
            }
        } else{
            // Si hay un cambio de tipo en medio de la iteración, se reinicia el window
            if((actual_class != t[r])){
                l = r;
                bigger_tuna = 0;
                bigger_eel = 0;
                r++;
            } else{
                // Si la clase sigue siendo la misma
                if(actual_class == 1){
                    bigger_tuna++;
                    // SI LA CADENA SUPERA LA MAXIMA ANTERIOR, ACTUALIZAR LA LONGITUD MAXIMA Y LAS COORDENADAS DE INICIO Y FIN
                    if(bigger_tuna >= max_len_tuna){
                        max_len_tuna = bigger_tuna;
                        i_tuna = l;
                        f_tuna = r;
                    }
                } else{
                    bigger_eel++;
                    // SI LA CADENA SUPERA LA MAXIMA ANTERIOR, ACTUALIZA LA LONGITUD MAXIMA Y LAS COORDENADAS DE INICIO Y FIN
                    if (bigger_eel >= max_len_eel){
                        max_len_eel = bigger_eel;
                        i_eel = l;
                        f_eel = r;
                    }
                }
                r++;
            }
        }
    }

    // Revisar vecinos a la izquierda y derecha de la cadena máxima de tuna
    int tuna_neighbor_len = 0;
    if (i_tuna > 0) {
        int idx = i_tuna - 1;
        int val = t[idx];
        int count_n = 0;
        while (idx >= 0 && t[idx] == val) {
            count_n++;
            idx--;
        }
        tuna_neighbor_len = max(tuna_neighbor_len, count_n);
    }
    if (f_tuna + 1 < n) {
        int idx = f_tuna + 1;
        int val = t[idx];
        int count_n = 0;
        while (idx < n && t[idx] == val) {
            count_n++;
            idx++;
        }
        tuna_neighbor_len = max(tuna_neighbor_len, count_n);
    }

    // Revisar vecinos a la izquierda y derecha de la cadena máxima de eel
    int eel_neighbor_len = 0;
    if (i_eel > 0) {
        int idx = i_eel - 1;
        int val = t[idx];
        int count_n = 0;
        while (idx >= 0 && t[idx] == val) {
            count_n++;
            idx--;
        }
        eel_neighbor_len = max(eel_neighbor_len, count_n);
    }
    if (f_eel + 1 < n) {
        int idx = f_eel + 1;
        int val = t[idx];
        int count_n = 0;
        while (idx < n && t[idx] == val) {
            count_n++;
            idx++;
        }
        eel_neighbor_len = max(eel_neighbor_len, count_n);
    }

    // Combinar las longitudes máximas encontradas con sus vecinos más grandes
    int ans_tuna = 2 * min(max_len_tuna, tuna_neighbor_len);
    int ans_eel = 2 * min(max_len_eel, eel_neighbor_len);

    ans = max({ans, ans_tuna, ans_eel});
    if(ans){
        cout << ans << endl;
    } else{
        cout << 2 << endl;
    }
}