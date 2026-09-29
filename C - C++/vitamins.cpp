#include<bits/stdc++.h>
using namespace std;

int main(){
    short n;
    int c, pay, total=0;
    string s;
    map<string, int> vitamins;

    cin >> n;
    while(n--){
        cin >> c >> s;
        pay = c;
        for (int i = 0; i < s.size(); i++)
        {
            c = c/(s.size());
            if(!vitamins.count(string(1, s[i]))){
                vitamins[string(1, s[i])] = c;
            } else{
                if(vitamins[string(1, s[i])] > c){
                    total -= vitamins[string(1, s[i])];
                    vitamins[string(1, s[i])] = c;
                }
                else{
                    total -= pay;
                }
            }
        }
        total += pay;
        
    }
    if(vitamins.size() < 3){
        cout << -1 << endl;
    } else{
        cout << total << endl;
    }
    system("pause");
    return 0;
}