#include<stdio.h>
#include <iostream>

#define INIT -1
#define MAX 100

int almacenado[MAX];

void _initialize(){
    for (int i = 0; i<MAX; i++) almacenado [i] = INIT;    
}

int fibonacci (int n){
    if(almacenado[n] == INIT){
        if( n<= 1 ) almacenado[n] = n;
        else almacenado[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return almacenado[n];
}

int main(){
    int n;
    scanf("%d", &n);
    _initialize();
    printf("FIBONACCI: %d", fibonacci(n));
    system("pause");
    return 0;
}