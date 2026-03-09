#include<stdio.h>
#include<stdbool.h>
#include<string.h>


void verificadorEstado(int cpf[]){
    char vetorEstados[10][100] = {
    
    "Rio Grande do Sul",
    "Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul e Tocantins",
    "Amazonas, Pará, Roraima, Amapá, Acre e Rondônia",
    "Ceará, Maranhão e Piauí",
    "Paraíba, Pernambuco, Alagoas e Rio Grande do Norte",
    "Bahia e Sergipe",
    "Minas Gerais",
    "Rio de Janeiro e Espírito Santo",
    "São Paulo",
    "Paraná e Santa Catarina"
    
    };
    
    printf("\nCPF Registrado no(s) estado(s): %s", vetorEstados[ cpf[8] ]);
}

bool digitosRepetidos(int cpf[]){
    int i;
    for(i=1;i<11;i++){
        if(cpf[0] != cpf[i]){
           return false; 
        }
    }
    return true;
}


int calculaDigito(int cpf[], int mult[], int N){
    int soma=0, i;
	for(i=0; i<N; i++)
	{	soma = soma + cpf[i]*mult[i];
	}
	return ((soma*10) % 11) % 10;
}


int main()
{   int cpf[11];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	
	
	char entrada[50];
    int i, j=0, tam;
    
    printf("Entre com o CPF: ");
    gets(entrada);
    tam = strlen(entrada);
    for(i=0; i<tam; i++)
    {   if(entrada[i]>=48 && entrada[i]<=57)
        {   cpf[j] = entrada[i]-48;
            printf("%d", cpf[j]);
            j++;
        }
    }
	
	if(calculaDigito(cpf, m1, 9) == cpf[9] && calculaDigito(cpf, m2, 10) == cpf[10]
	&& digitosRepetidos(cpf) == false){
    		printf("\nCPF valido.");
    		verificadorEstado(cpf);
    	}
    	else{
    		printf("\nErro no CPF.");
    	}
	
	
  	
	
	return 0;
}