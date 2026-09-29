#include<bits/stdc++.h>
using namespace std;

int main(){
    string n;
    int count=0;
    short is_lucky = 1;
    cin >> n;

    for(char c : n){
        if(c=='4' || c=='7'){
            count++;
        }
    }

    for(char c : to_string(count)){
        if(c!='4' && c!='7'){
            is_lucky = 0;
        }
    }

    if(is_lucky){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    return 0;
}