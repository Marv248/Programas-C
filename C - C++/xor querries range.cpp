#include <bits/stdc++.h>
using namespace std;

int main(){
    int q, n;
    cin >> n >> q;
    
    vector<int> lista(n+1);
    vector<int> p(n+1);

    // Read the elements of the list from input, from 1 to n, since we are using 1-based indexing
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        lista[i] = x;
    }

    // Initialize the prefix XOR array
    p[0] = 0;
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1] ^ lista[i];
    }

    // Create a prefix XOR vector to store the cumulative XOR of the elements
    while(q--){
        int a, b;
        cin >> a >> b;
        
        long ans = p[b] ^ p[a-1];
        cout << ans << endl;
    }
    return 0;
}