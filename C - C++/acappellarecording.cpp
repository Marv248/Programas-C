#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> notes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> notes[i];
    }

    int sub_sets = 0;
    sort(notes.rbegin(), notes.rend());
    
    int l=0, r=1, res=1;

    while(l<=r && r<notes.size()){
        if(notes[l] - notes[r] <= d){
            r++;
        } else{
            res++;
            l=r;
            r++;
        }
    }

    cout << res << endl;
    return 0;   
}