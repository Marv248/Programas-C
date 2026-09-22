#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, r, range=0;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> r;
        if (r>n){
            int list1[r/2];
            int list2[r/2];
            if(range == 0 || range == 1){
                for(int j=0; j<r/2; j++){
                    list1[j]=j+1;
                    if(n == j+1){
                        range = 1;
                    }
                }
                for(int j=0; j<r/2; j++0){
                    list2[j] = j + 1 + r/2;
                    if(n == j+1 + r/2){
                        range = 2;
                    }
                }
            } else if(range == 2){
                for(int j=r/2; j<3*(r/4); j++){
                    list1[j]=j+1;
                    if(n == j+1){
                        range = 1;
                    }
                }
                for(int j=3*(r/4); j<r; j++0){
                    list2[j] = j + 1 + r/2;
                    if(n == j+1 + r/2){
                        range = 2;
                    }
                }
            }
            r = r/2;
        }
    }
}