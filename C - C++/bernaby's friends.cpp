#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    set<string> friends;
    string s1, s2;

    cin >> n >> k;
    while(n--){
        cin >> s1;
        s2.resize(k);

        if(s1.size() < 4){
            for(int i = 0; i<k+1; i++){
                s2[i] = s1[i];
            }
        } else{
            for(int i=0; i<k+1; i++){
                s2[i] = s1[i];
            }
        }
        friends.insert(s2);        
    }

    cout << friends.size() << endl;

    system("pause");
    return 0;
}