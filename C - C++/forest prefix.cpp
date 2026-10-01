#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q, x1, x2, y1, y2, total=0;
    cin >> n >> q;
    char sq;

    int grid[n+1][n+1];
    int prefix[n+1][n+1];

    grid[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> sq;
            grid[i][j] = (sq=='*')? 1:0;
        }
    }

    prefix[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            prefix[i][j] = grid[i][j] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
        }
    }

    while (q--)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        total = prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1];
        cout << total << endl;
    }
    return 0;    
}