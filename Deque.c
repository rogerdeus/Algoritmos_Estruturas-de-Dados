//////////////////////////////
//programa que implementa um deque

#include<stdio.h>
#include<stdlib.h>

int contador =0;
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

struct no *remover(struct no *fila){
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

    struct no *penultimo =fila;
    while (penultimo ->proximo ->proximo != NULL)
    {
        penultimo = penultimo ->proximo;
    }
    printf("%d\n", penultimo->proximo->proximo);
    free(penultimo->proximo);
    penultimo->proximo=NULL;
    return fila;

    //função que realiza o atendimento



    
}

void atender(struct Deque *cabeca){
    //caso muito facil duas filas vazias
//aqui não tem ninguem
    if((cabeca->filaNormal ==NULL) && (cabeca->filapreferencial == NULL)){
        contador = 1;
        return;
    }
//aqui so tem normal
    if(cabeca->filapreferencial ==NULL){
        cabeca->filaNormal = remover(cabeca->filaNormal);
    }

    //caso facil so tem preferencial

    if(cabeca->filaNormal ==NULL){
        cabeca ->filapreferencial = remover(cabeca->filapreferencial);
        contador = 1;
        return;
    }

    //caso dificil tem gente em ambas as filas

    if((contador % 4) == 0){
        cabeca->filaNormal = remover(cabeca->filaNormal);
    }else
    {
        cabeca->filapreferencial = remover(cabeca->filapreferencial);
    }
    contador++;


    

}








//funcao de execução de programa
int main(){
    struct Deque *cabeca = (struct Deque*) malloc(sizeof(struct Deque));
    cabeca->filaNormal = NULL;
    cabeca->filapreferencial =NULL;

    
}