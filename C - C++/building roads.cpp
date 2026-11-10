#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &grafo, vector<int> &roads_visitados, int actual ){
    queue<int>
}

int main(){
    int n, m;

    cin >> n >> m;

    vector<vector<int>> grafo (n+1); // Lista de adyacencia
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        grafo[a].push_back[b];
        grafo[b].push_back[a];
    }

    vector<int> roads_visitados (n+1, 0);
    
}