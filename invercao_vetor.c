#include <stdio.h>

int main(){
    //declaracao de variavel
    int vetor_original[5];
    int vetor_invertido[5];
    int i;

    // entrada de dados

    for (int i = 0 ; i < 5 ; i++){
        printf("digite o valor da posição %d: ", i);
        scanf("%d", &vetor_original[i]);

    }

    // processsamento 

    for (int i = 0 ; i < 5 ; i++){
        vetor_invertido[5 - 1 - i] = vetor_original[i];
    }

    // saida de dados 

    printf("vetor_invertido[%d] = %d\n", i, vetor_invertido[i]);


    //conclusao

    return 0;
}