#include<bits/stdc++.h>
using namespace std;

// IDEA: switch elements of the string to order them in ascending order
int main(){
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i=i+2){
        for (int j=0; j<s.length(); j=j+2){
            if(s[i] < s[j]){
                swap(s[i], s[j]);
            }
        }
    }
    cout << s;
}