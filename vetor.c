#include <stdio.h>

int main(){

    int vetor[10];
    int i;

    // Entradas de dados
    for (i = 0 ; i < 10; i++){
        printf("difgite o valor do indice %d: ", i);
        scanf("%d", &vetor[i]);

    }

    for (i = 0 ; i < 10 ; i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

 return 0;

}