#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    int map[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                n = i+1;
                m = j+1;
            }
        }
    }

    int count = abs(n-3) + abs(m-3);
    cout << count;
    system("pause");
    return 0;
}