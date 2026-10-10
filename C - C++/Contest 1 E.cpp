#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, izq=0, der=0, res;
    string s;
    cin >> t;

    while (t--)
    {
        izq = 0, der = 0, res = MAXINT;
        cin << s;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                izq++;
            }
            
        }
        
    }
    
}