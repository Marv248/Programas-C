#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);   //Lectura rápida de lectura
    short t, n,c = 0, a=0, b=0;
    cin >> t;
    while (t--) {
        a=0;
        b=0;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> c;
            if(c==1){
                a++;
            } else{
                b++;
            }
        }
        if(a>=b){
            cout << "Bessie" << endl;
        } else{
            cout << "Elsie" << endl;
        }
    }
    system("pause");
    return 0;
}