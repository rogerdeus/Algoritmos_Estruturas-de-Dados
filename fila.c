///////////////////////////////////////////////////////////////
//programa que implementa fila (fifo)

#include<stdio.h>
#include<stdlib.h>

struct no{
    int numero;
    struct no *proximo;
};
//////////////////////////////
// função que insere um no na fila
////////////////////////////////////////

struct no *entar(struct no *cabeca, int numero){
    /////////////////////////////q
    //criação de um novo no

    struct no *novoNO = (struct no *) malloc(sizeof(struct no));
    novoNO->numero = numero;
    novoNO->proximo = cabeca;

    return novoNO;
}

/////////////////////////////////
//função que remove no da fila
///////////////////////////////////q

struct no *sair(struct no *cabeca){
    
}

int main(){}