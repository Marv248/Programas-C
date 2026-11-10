#include <stdio.h>
#include <iostream>

int main() {
    int c = 0;
    int n;
    std::cin >> n;
    while(n){
        c++;
        n >>= 1;
    }

    std::cout << "Cantidad de CEROS: " << c << " en " << n << std::endl;
    system("pause");
}