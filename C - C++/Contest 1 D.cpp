#include <bits/stdc++.h>
using namespace std;

int main(){
    int t=0, n=0, eq=0, dif_anterior, dif_actual;
    bool flag;
    cin >> t;

    while(t--){
        n=0, eq=1, dif_anterior = 0, dif_actual = 0;
        flag = true;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++)
        {
            if(a[i] != b[i]){
                eq = 0;
            }
            if(i>0){
                dif_anterior= b[i-1] - a[i-1];
                dif_actual = a[i] - b[i];
                if(!(dif_actual<=0 || dif_anterior-dif_actual==1 || dif_anterior-dif_actual==0 || dif_anterior - dif_actual ==-1)){
                    flag = false;
                }
            }
        }
        
        if(eq){
            cout << "YES" << endl;
        } else if(n>2 && flag){
            cout << "YES" << endl;
        } else if (n==1 && a[0]<=b[0]){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}