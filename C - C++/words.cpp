#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, s_out;
    int lower = 0, upper = 0;
    cin >> s;
    s_out.resize(s.size());

    for(char st : s){
        if(st >= 'a' && st <= 'z'){
            lower++;
        }else{
            upper++;
        }
    }

    if(lower >= upper ){
        for(int i=0; i<s.size(); i++){
            s_out[i] = tolower(s[i]);
        }
    } else{
        for(int i=0; i<s.size(); i++){
            s_out[i] = toupper(s[i]);
        }
    }

    cout << s_out << endl;
    return 0;
}