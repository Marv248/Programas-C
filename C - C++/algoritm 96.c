#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int count0, count1;
    cin >> s;
    count0 = 0;
    count1 = 0;
    for(int i=0; i<s.size(); i++){
        if (i==0){
            if (s[i]=='0'){
                count0++;
            }
            else {
                count1++;
            }
        }    
        else{
            if(s[i]==s[i-1]){
                if(s[i]=='0'){
                    count0++;
                }
                else {
                    count1++;
                }
            }
            else{
                count0=0;
                count1=0;
                if(s[i]=='0'){
                    count0++;
                }
                else {
                    count1++;
                }
            }
        }
        if(count0>=7||count1>=7){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}