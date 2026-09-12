#include<bits/stdc++.h>
using namespace std;

int main(){
    string word;
    int size;

    int n;

    cin >>  n;
    for(int i = 0; i < n; i++){
        cin >> word;
        size = word.length();
        if(size > 10){
            cout << word[0] << size - 2 << word[size - 1] << endl;
        }else{
            cout << word << endl;
        }
    }
}