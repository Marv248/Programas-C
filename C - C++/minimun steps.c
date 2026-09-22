#include<bits/stdc++.h>
using namespace std;

int main(){
    int coordenate;
    cin >> coordenate;
    int count = 0;

    while(coordenate > 0){
        if(coordenate >= 5){
            coordenate -= 5;
            count++;
        }
        else if(coordenate == 4){
            coordenate -= 4;
            count++;
        }
        else if(coordenate == 3){
            coordenate -= 3;
            count++;
        }
        else if(coordenate == 2){
            coordenate -= 2;
            count++;
        }
        else if(coordenate == 1){
            coordenate -= 1;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}