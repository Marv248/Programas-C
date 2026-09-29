#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a;
    int anterior=0, actual=0, count=0, max=0;
    cin >> n;
    while(n--){
        cin >> actual;
        if(anterior <= actual){
            count++;
            anterior = actual;
        } else{
            if(count > max){
                max = count;
            }
            count = 1;
            anterior = actual;
        }
        if(n==0){
            if(count > max){
                max = count;
            }
        }
    }

    cout << max;
    return 0;
}