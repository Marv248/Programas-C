#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, n, a, trades;
    set<int> gems;
    cin >> N;
    n = N;
    while(n--){
        cin >> a;
        gems.insert(a);
    }

    trades = N - gems.size();
    cout << trades << endl;
    return 0;
}