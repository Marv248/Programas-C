#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    int count = 0;
    cin >> t;
    for (int i = 0; i < t; i++){
        count = 0;
        cin >> n;
        while(n != 1){
            if(n%6==0){
                n/=6;
                count++;
            } else{
                n*=2;
                count++;
                if(n%6==0){
                    n/=6;
                    count++;
                } else{
                    count = -1;
                    break;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}