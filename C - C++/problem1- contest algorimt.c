#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int a,b,c;
    int chargoy;
    cin >> t;

    for(int i=0; i<t; i++){
        cin >> a >> b >> c;
        if(a==b){
            chargoy = c;
        } else if(b==c){
            chargoy = a;
        } else{
            chargoy = b;
        }
        cout << chargoy << endl;
    }
    system("pause");
    return 0;
}