#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t=0, n=0, flag=0;
    cin >> t;
    while(t--){
        flag = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
 
        for(int i = 0; i<n-1; i++){
            if (n == 1){
                flag = 1;
                break;
            }
            if (a[i]>a[i+1]){
                flag = 1;
                break;
            }
        }
        if(flag){
            cout << 1 << endl;
        } else{
            cout <<  n << endl;
        }
    }
}