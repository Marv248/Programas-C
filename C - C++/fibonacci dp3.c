#include<stdio.h>
#include<iostream>

long fibo(int n){
    long prev2, prev, actual;

    prev2 = 0;
    prev = 1;
    actual = 1;

    for(int i = 2; i <= n; i++){
        actual = prev2 + prev;
        prev2 = prev;
        prev = actual;
    }

    return actual;
}

int main(){
    printf("Numero para fibonacci:\n");
    int n;
    scanf ("%d", &n);

    printf("RESULTADO:\t%ld", fibo(n));
    system("pause");
    return 0;
}