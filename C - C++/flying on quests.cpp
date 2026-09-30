#include<bits/stdc++.h>
using namespace std;    
int main(){
    int m, n, a=0;
    long long s, t, damage=0;
    cin >> n >> m;

    vector<long long> heights(n+1, 0);
    vector<long long> pref_izq(n+1, 0);
    vector<long long> pref_der(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin >> a;
        heights[i] = a;
    }

    pref_izq[0] = 0;
    for(int i = 1; i <= n; i++){
        long long caida = 0;
        if(heights[i] < heights[i-1]){
            caida = heights[i-1] - heights[i];
        }
        pref_izq[i] = pref_izq[i-1] + caida;
    }

    pref_der[n] = 0;
    for(int i = n-1; i >= 1; i--){
        long long caida = 0;
        if(heights[i] < heights[i+1]){
            caida = heights[i+1] - heights[i];
        }
        pref_der[i] = pref_der[i+1] + caida;
    }

    while(m--){
        cin >> s >> t;
        damage = 0;
        if(s < t){
            damage = pref_izq[t] - pref_izq[s];
        }else{
            damage = pref_der[t] - pref_der[s];
        }
        cout << damage << endl;
    }
    return 0;
}