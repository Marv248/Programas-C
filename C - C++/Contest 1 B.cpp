#include <bits/stdc++.h>
using namespace std;

int main(){
    int t=0, n=0;
    int m;
    string s;
    cin >> t;
    while(t--){
        int min_01=0, min_10 = 0, min_11 = 0;
        cin >> n;
        while(n--){
            cin >> m;
            cin >> s;
            if(s == "01" && (min_01==0 || m < min_01)){
                min_01 = m;
            } else if(s == "10" && (min_10==0 || m < min_10)){
                min_10 = m;
            } else if(s == "11" && (min_11==0 || m < min_11)){
                min_11 = m;
            }
        }

        if(min_11 != 0){
            if ((min_10 != 0) && (min_01 != 0)){
                if (min_11 < (min_01 + min_10)){       
                    cout << min_11 << endl;
                }
                else {
                    cout << (min_01 + min_10) << endl;
                }
            } else{
                cout << min_11 << endl;
            }
        } else{
            if((min_10 != 0) && (min_01 != 0)){
                cout << (min_01 + min_10) << endl;
            } else{
                cout << -1 << endl;
            }
        }
    }
    return 0;
}