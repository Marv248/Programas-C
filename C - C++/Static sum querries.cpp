#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q, a,b;
    cin >> n >> q;

    vector<int> lista(n+1);
    
    for(int i=1;i<=n;i++){
        cin >> lista[i];
    }

    vector<long long> p(n+1, 0);

    p[0] = lista[0];
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1] + lista[i];
    }

    while(q--){
        cin >> a >> b;
        long long sum = p[b] - p[a-1];
        cout << sum << endl;
    }

    return 0;
}