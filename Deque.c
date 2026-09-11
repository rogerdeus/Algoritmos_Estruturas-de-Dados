//////////////////////////////
//programa que implementa um deque

#include<stdio.h>
#include<stdlib.h>
//modelagem da estrutura de dados

struct no
{
    int numero;
    struct no *proximo;

};

struct Deque
{
    struct no *filaNormal;
    struct no *filapreferencial;
};

////////////////////////////////////
//funcao que insere um no no em uma fila especifica

struct no *inserir(struct no *fila, int numero){
    struct no *novoNO =(struct no *) malloc(sizeof(struct no));
    novoNO ->numero = numero;
    novoNO ->proximo =fila;
    return novoNO;

}

////////////////////////////////
//

struct no *remove(struct no *fila){
    //caso muito facil fila vazia
    if(fila == NULL){
        printf("va tomar um cafe");
        return NULL;
    }
    //caso facil so tem um unico no na fila
    if(fila->proximo == NULL){
        printf("%d\n", fila->proximo);
        free(fila);
        return NULL;
    }
    //caso dificil tem mais de um no na fila

    
}









int main(){}