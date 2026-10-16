////////////////////////////////////////////////
//programa que implementa arvore de busca
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct no
{
    int numero;
    struct no *esqueda;
    struct no *direita;
    
};

//funcao que insere um no na arvore

struct no *inserir(struct no *raiz, int numero){
    //caso facil arvore vazia

    if(raiz == NULL){
        struct no *novoNO = (struct no *) malloc(sizeof(struct no));
        novoNO->numero = numero;
        novoNO->esqueda = NULL;
        novoNO->direita = NULL;
        return novoNO;
    }

    
}




int main(){}