#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    for(int i=0; i<a.length(); i++){
        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
        if(a[i] < b[i]){
            cout << -1;
            break;
        }
        else if(a[i] > b[i]){
            cout << 1;
            break;
        }
        if(i == a.length()-1 && a[i] == b[i]){
            cout << 0;
        }
    }
}