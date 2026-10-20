#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        long long max_ans = n*k, ans;

        // Bynary Search para buscar el k eisimo número que divida a n
        // Restamos k - n para hallar la cantidad de no  multiplos a buscar, ya que los menores a n nunca van a ser multiplos enteros
        // Si k > n entonces buscamos los NO multiplos faltantes para llegar a k
        // Si k < n entonces regresamos simplemente k
        // Si k = n entonces regresamos k + 1

        if (k > n){
            long long left = 1, right = 2e18;
            while (left < right){
                long long mid = left + (right - left) / 2;
                long long count = mid - mid / n; // Cantidad de no multiplos de n hasta mid. Por que mid / n nos da la cantidad de multiplos de n hasta mid, y mid - (mid / n) nos da los que no son multiplos (el complemento)
                if (count < k){
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            ans = left;
        } else if (k < n){
            ans = k;
        } else {
            ans = k + 1;
        }
        cout << ans << endl;
    }
}