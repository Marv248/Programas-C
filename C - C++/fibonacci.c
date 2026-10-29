#include <stdio.h>
#include <iostream>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n = 0;
    printf("Ingrese un numero para calcular su Fibonacci: ");
    scanf("%d", &n);
    int result = fibonacci(n);
    printf("El Fibonacci de %d es: %d\n", n, result);
    system("pause");
    return 0;
}