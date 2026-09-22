#include<bits/stdc++.h>
using namespace std;

int main(){
    string name;
    int contador, cuenta = 1;
    cin >> name;
    for(int i=0; i<name.length(); i++){
        for(int j=0; j<i; j++){
            if(name[i] == name[j]){
                cuenta = 0;
                break;
            } else{
                cuenta = 1;
            }
        }
        if(cuenta == 1){
            contador++;
        }
    }
    if(contador%2 == 0){
        cout << "CHAT WITH HER!";
    } else{
        cout << "IGNORE HIM!";
    }
    system("pause");
    return 0;
}