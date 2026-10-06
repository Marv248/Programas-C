#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);   //Lectura rápida de lectura
    short t;
    string original, broken;

    cin >> t;

    while(t--){
        stack<int> uppers, lowers; 
        broken = ""; 
        broken.reserve(original.size());
        cin >> original;

        for(int i = 0; i < original.size(); i++){
            if(original[i] == 'b'){
                if(!lowers.empty()){
                    broken[lowers.top()] = ' ';
                    lowers.pop(); 
                }
            } else if(original[i] == 'B'){
                if(!uppers.empty()){
                    broken[uppers.top()] = ' ';
                    uppers.pop(); 
                }
            } else if(islower(original[i])){
                broken += original[i]; 
                lowers.push(broken.size() - 1); 
            } else if(isupper(original[i])){
                broken += original[i]; 
                uppers.push(broken.size() - 1);
            }
        }

        for(char c : broken){
            if(c != ' '){
                cout << c;
            }
        }
        cout << "\n";
    }
    return 0;
}