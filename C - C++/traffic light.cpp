#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    char c;

    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        string luces;
        cin >> luces;

        string luces2 = luces + luces;

        int l=0, r=1, min_dist=1, res=0;
        
        while(l<=r && r<luces2.size()){
            if(luces2[l] != c){
                l++;
                r++;
            } else{
                if(luces2[r] != 'g'){
                    r++;
                    min_dist++;
                } else{
                    res = max(res, min_dist);
                    l=r;
                    r++;
                    min_dist = 1;
                }
            }
        }  
        if (c=='g'){
            res = 0;
        }   
        cout << res << endl;
    }
}