#include <bits/stdc++.h>
using namespace std;

int main(){
    short n;
    cin >> n;
    deque <int> lista;
    int s, d, a, maxim;
    
    for(int i= 0; i < n; i++){
        cin >> a;
        lista.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if(i%2 == 0){
            if(lista.back() > lista.front()){
                s += lista.back();
                lista.pop_back();
            } else{
                s += lista.front();
                lista.pop_front();
            }
        } else{
            if(lista.back() > lista.front()){
                d += lista.back();
                lista.pop_back();
            } else{
                d += lista.front();
                lista.pop_front();
            }
        }
    }

    cout << s << " "<< d << endl;
    system("pause");
    return 0;    
}