#include <stdio.h>

int fatorialRec(int n){
    if (n==0){
        return 1;
    }else{
        return n*fatorialRec(n-1);
    }
}

int main()
{
    int n;
    
    printf("Qual é o n?");
    scanf("%d", &n);
    printf("O fatorial de %d é %d", n, fatorialRec(n));

    return 0;
}
