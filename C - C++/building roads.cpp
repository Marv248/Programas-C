#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grafo(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    vector<int> visitados(n + 1, false);
    queue<int> q;

    q.push(1);
    visitados[1] = true;

    while (!q.empty()) {
        int actual = q.front();
        q.pop();

        for (int vecino : grafo[actual]) {
            if (!visitados[vecino]) {
                visitados[vecino] = true;
                q.push(vecino);
            }
        }
    }

    vector<pair<int, int>> new_roads;

    for (int i = 2; i <= n; i++) {
        if (!visitados[i]) {
            new_roads.push_back({1, i});
            visitados[i] = true;
            q.push(i);
            
            while (!q.empty()) {
                int actual = q.front();
                q.pop();

                for (int vecino : grafo[actual]) {
                    if (!visitados[vecino]) {
                        visitados[vecino] = true;
                        q.push(vecino);
                    }
                }
            }
        }
    }

    cout << new_roads.size() << endl;
    for (auto par : new_roads) {
        cout << par.first << " " << par.second << endl;
    }

    return 0;
}