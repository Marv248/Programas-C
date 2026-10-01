#include<bits/stdc++.h>
using namespace std;

int main(){
    short t=0;
    cin >> t;
    
    short n, m;
    
    while(t--)
    {   
        cin >> n;
        vector<short> red(n+1);
        vector<short> p_red(n+1, 0);
        short redMax=0;
        for (int i = 1; i <= n; i++)
        {
            cin >> red[i];
        }
        for (int i = 1; i <= n; i++)
        {
            p_red[i] = p_red[i-1] + red[i];
            redMax = max(p_red[i], redMax);
        }

        cin >> m;
        vector<short> blue(m+1, 0);
        vector<short> p_blue(m+1, 0);
        short blueMax = 0;
        for (int i = 1; i <= m; i++)
        {
            cin >> blue[i];
        }
        for (int i = 1; i <= m; i++)
        {
            p_blue[i] = p_blue[i-1] + blue[i];
            blueMax = max(p_blue[i], blueMax);
        }

        cout << redMax + blueMax << endl;      
        
    }
    return 0;    
}