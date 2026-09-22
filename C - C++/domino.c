#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int fichas_n, fichas_m;
    fichas_n = (n/2)*m;
    if((n%2)==1){
        fichas_m = m/2;
    }

    int count = fichas_n + fichas_m;
    cout << count;    
    system("pause");
    return 0;
}