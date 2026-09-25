////////////////////////////////////////////
//programa que implementa arvore


#include <stdio.h>
#include <stdlib.h>

struct no
{
    int numero;
    struct no *filho1;
    struct no *filho2;
    struct no *filho3;
    struct no *filho4;
    struct no *filho5;
};

struct no *inserir(struct no *raiz, int numero){
    if (raiz == NULL){
        struct no *folha = (struct no *)malloc(sizeof(struct no));
        folha->numero = numero;
        folha->filho1=NULL;
        folha->filho2=NULL;
        folha->filho3=NULL;
        folha->filho4=NULL;
        folha->filho5=NULL;
        return folha;
    }

    //cenario facil
    int sorteio = (1+ (rand() % 5));

    if (sorteio == 1){
        raiz->filho1=inserir(raiz->filho1, numero);

        
    }
}


int main(){}