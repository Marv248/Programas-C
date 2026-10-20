#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n;

    vector<int> x (n); // Precios
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    cin >> q;
    vector<int> m(q);
    while (q--)
    {
        int m = 0; // Presupuesto
        cin >> m;
        int l = 0, r = n-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(x[mid] <= m){
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        cout << l << endl;
    }

    system("pause");  
    
}