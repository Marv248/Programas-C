#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, w, k;
    int count, loan;
    cin >> k >> n >> w;
    for(int i=1; i<=w; i++){
        count = count + i*k;
    }
    loan = count - n;
    if(loan < 0){
        cout << 0 << endl;
    }
    else{
        cout << loan << endl;
    }
    system("pause");
    return 0;
}