#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> fibo (n+1,0);
    fibo[0] = 0ll;
    fibo[1] = 1;

    for (long long i = 2; i <= n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    cout << fibo[n] << endl;
    system("pause");
    return 0;
}