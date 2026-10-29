#include<stdio.h>

long int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n=0;
    printf("Ingrese un número para calcular su factorial: ");
    scanf("%d", &n);
    long int result = factorial(n);
    printf("El factorial de %d es: %ld\n", n, result);
    return 0;
}