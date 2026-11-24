#include <bits/stdc++.h>
using namespace std;

const int MAX_X = 10000;   
const int MAX_P = 200;     
const int INF = 1e9;

int memo[MAX_X + 1][MAX_P + 1];

int dp(int h, int att_power) {
    if (h <= 0) return 0;
    if (memo[h][att_power] != -1) {
        return memo[h][att_power];
    }
    // 1: Atacar
    int nuevo_poder = (att_power > 1) ? att_power - 1 : 1;
    int atacar = 1 + dp(h - att_power, nuevo_poder);
    // 2: Cargar
    int cargar = INF;
    if (att_power < h && att_power < MAX_P) {
        cargar = 1 + dp(h, att_power + 1);
    }
    return memo[h][att_power] = min(atacar, cargar);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    memset(memo, -1, sizeof(memo));
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << dp(x, 1) << "\n";
    }
    system("pause");
    return 0;
}