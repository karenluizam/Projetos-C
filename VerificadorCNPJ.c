/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdbool.h>
#include<string.h>

int calculaDigitoCNPJ(int cnpj[], int multi[], int N)
{
    int i, soma=0, dig;
    
    for(i=0; i<N; i++){
        soma += cnpj[i]*multi[i];
    }
    
    soma = soma%11;
    
    if(soma<2){
        dig=0;
    }else{
        dig = 11-soma;
    }
    return dig;
}

int main()
{
    int m1[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int m2[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int cnpj[14], tam, i, j=0;
    char entrada[50];
    
    printf("Digite o CNPJ:");
    gets(entrada);
    tam = strlen(entrada);
    for(i=0; i<tam; i++)
    {   if(entrada[i]>=48 && entrada[i]<=57)
        {   cnpj[j] = entrada[i]-48;
            
            j++;
        }
    }
    
    if(calculaDigitoCNPJ(cnpj, m1, 12) == cnpj[12] && calculaDigitoCNPJ(cnpj, m2, 13) == cnpj[13]){
        printf("\nCNPJ Válido");
    }else{
        printf("\nCNPJ Inválido");
    }
    
    
    
    return 0;
}
