#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int a, b, c;
    int count = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        if((a&&b) || (a&&c) || (b&&c)){
            count++;
        }
    }
    cout << count << endl;
}