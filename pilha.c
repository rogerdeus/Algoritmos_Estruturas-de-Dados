#include<stdio.h>
#include<stdlib.h>

struct no{
    int numero;
    struct no *proximo;
};
//////////////////////////////
// função que insere um no na pilha
////////////////////////////////////////

struct no *push(struct no *cabeca, int numero){
    /////////////////////////////q
    //criação de um novo no

    struct no *novoNO = (struct no *) malloc(sizeof(struct no));
    novoNO->numero = numero;
    novoNO->proximo = cabeca;

    return novoNO;
}

////////////////////////
//função que remove o no da pilha

struct no *pop(struct no *cabeca){
    /////////////
    //caso muito facil piha vazia

    if (cabeca == NULL){
        return NULL;
    }

    printf("%d\n", cabeca->numero );
    struct no*limpeza = cabeca;
    cabeca = cabeca -> proximo;
    free(limpeza);
    return cabeca;
}

int main(){
    struct no *cabeca = NULL;
    int i = 0;

    //processamento
    for(i = 0 ; i < 1000000; i++){
        cabeca = push(cabeca, i);
    }
    for(i=0; i < 1000000; i++){
        cabeca=pop(cabeca);
    }
}

