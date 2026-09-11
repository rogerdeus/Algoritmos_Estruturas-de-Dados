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
        return NULL;
    }
    //caso facil so tem um unico no na fila
    if(fila->proximo == NULL){
        printf("%d\n", fila->numero);
        free(fila);
        return NULL;
    }
    //caso dificil tem mais de um no na fila

    struct no *penultimo =fila;
    while (penultimo ->proximo ->proximo != NULL)
    {
        penultimo = penultimo ->proximo;
    }
    printf("%d\n", penultimo->proximo->numero);
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
           printf("va tomar um cafe\n");
        return;
    }
//aqui so tem normal
    if(cabeca->filapreferencial ==NULL){
        cabeca->filaNormal = remover(cabeca->filaNormal);
        return;
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

    atender(cabeca);
    int i = 0;
    for(i = 0;i<10; i++){
        cabeca->filaNormal = inserir(cabeca->filaNormal, i);
    }
    for(i = 0; i<10;i++){
        atender(cabeca);
    }

        for(i = 1000;i<1010; i++){
        cabeca->filapreferencial = inserir(cabeca->filapreferencial, i);
    }
    for(i = 0; i<10;i++){
        atender(cabeca);
    }
    
}