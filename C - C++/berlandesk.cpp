#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string mail;
    map<string, int> mails;

    cin >> n;
    while(n--){
        cin >> mail;
        mails[mail]++;

        if(mails[mail] == 1){
            cout <<"OK" << endl;
        } else{
            cout << mail << mails[mail]-1 << endl;
        }
    }
    return 0;
}