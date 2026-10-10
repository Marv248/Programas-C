#include<stdio.h>
#include<iostream>

int main(){
    int n=0, factorial=1;

    printf("n:\t");
    scanf("%d", &n);

    // For
    for (int i = 1; i <= n; i++)
    {
        factorial*=i;
    }
    printf("\nFactorial de %d:\t%d", n, factorial);

    // While
    factorial=1;
    int i=1;
    while (i <= n)
    {
        factorial*=i;
        i++;
    }
    printf("\nFactorial de %d:\t%d", n, factorial);

    // Do While
    factorial=1;
    i=1;
    do
    {
        factorial*=i;
        i++;
    } while (i <= n);
    printf("\nFactorial de %d:\t%d", n, factorial);
    return 0;
}