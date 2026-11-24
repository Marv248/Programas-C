#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimización de E/S
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    // Matriz que almacena la máscara de bits de las paredes de cada celda
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    // Matriz para identificar el ID del cuarto (componente conexa) de cada celda
    vector<vector<int>> room_id(r, vector<int>(c, -1));
    vector<int> room_size; // Almacena el tamaño de cada cuarto
    int total_rooms = 0;

    // --- PASO 1 y 2: Encontrar todos los cuartos y sus tamaños usando BFS ---
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (room_id[i][j] == -1) { 
                int size = 0;
                queue<pair<int, int>> q; 
                q.push({i, j});
                room_id[i][j] = total_rooms;
                
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    size++;

                    // Verificamos las 4 direcciones según los bits del problema:
                    // 1. Izquierda (W) = 1 -> Vecino en (x, y - 1)
                    if (!(grid[x][y] & 1) && y > 0 && room_id[x][y - 1] == -1) {
                        room_id[x][y - 1] = total_rooms;
                        q.push({x, y - 1});
                    }
                    // 2. Arriba (N) = 2 -> Vecino en (x - 1, y)
                    if (!(grid[x][y] & 2) && x > 0 && room_id[x - 1][y] == -1) {
                        room_id[x - 1][y] = total_rooms;
                        q.push({x - 1, y});
                    }
                    // 3. Derecha (E) = 4 -> Vecino en (x, y + 1)
                    if (!(grid[x][y] & 4) && y < c - 1 && room_id[x][y + 1] == -1) {
                        room_id[x][y + 1] = total_rooms;
                        q.push({x, y + 1});
                    }
                    // 4. Abajo (S) = 8 -> Vecino en (x + 1, y)
                    if (!(grid[x][y] & 8) && x < r - 1 && room_id[x + 1][y] == -1) {
                        room_id[x + 1][y] = total_rooms;
                        q.push({x + 1, y});
                    }
                }
                room_size.push_back(size);
                total_rooms++;
            }
        }
    }

    // Encontramos el tamaño del cuarto más grande inicialmente
    int max_room = 0;
    for (int size : room_size) {
        max_room = max(max_room, size);
    }

    // --- PASO 3: Probar destruir cada pared para maximizar el tamaño ---
    int max_combined = max_room;
    int best_i = 0, best_j = 0; 
    char best_dir = 'N'; 

    // Recorremos las columnas de izquierda a derecha (j) y las filas de abajo hacia arriba (i)
    for (int j = 0; j < c; j++) {
        for (int i = r - 1; i >= 0; i--) {
            
            // Opción A: Intentar tirar la pared de Arriba (N = bit 2)
            if (i > 0 && (grid[i][j] & 2)) {
                int r1 = room_id[i][j];
                int r2 = room_id[i - 1][j];
                if (r1 != r2) { 
                    int combined = room_size[r1] + room_size[r2];
                    if (combined > max_combined) {
                        max_combined = combined;
                        best_i = i;     
                        best_j = j;     
                        best_dir = 'N';
                    }
                }
            }

            // Opción B: Intentar tirar la pared de la Derecha (E = bit 4)
            if (j < c - 1 && (grid[i][j] & 4)) {
                int r1 = room_id[i][j];
                int r2 = room_id[i][j + 1];
                if (r1 != r2) {
                    int combined = room_size[r1] + room_size[r2];
                    if (combined > max_combined) {
                        max_combined = combined;
                        best_i = i;     
                        best_j = j;     
                        best_dir = 'E';
                    }
                }
            }
        }
    }
    // Primera línea: número de cuartos y el tamaño del cuarto más grande
    cout << total_rooms << " " << max_room << "\n";
    
    // Segunda línea: coordenada del módulo (1-indexed -> +1) y dirección de la pared óptima
    cout << (best_i + 1) << " " << (best_j + 1) << " " << best_dir << "\n";
    
    return 0;
}