//////////////////////////////////////////////////////////
//Lista que implementa uma lista duplamente encadeada//
////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
/////////////////////////////
//declaração da estrutura//
//////////////////////////////

struct no
{
    int numero;
    struct no *anterior;
    struct no *proximo;
};
/// /////////////////////////////////////////
//função um no na lista//
///////////////////////////////////////////////
///
struct no *inserir(struct no *cabeca, int numero){
    //criação novo No
    struct no *novoNO = (struct no *) malloc(sizeof(struct no));
    novoNO ->numero = numero;
    novoNO ->anterior = NULL;
    novoNO ->proximo = cabeca;
    ///////////////////
    //cabeça velha//
    //////////////////////
    
} 



int main(){}
