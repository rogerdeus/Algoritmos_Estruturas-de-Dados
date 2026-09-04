
////////////////////////////////////////////////////////////
//Programa que implementa uma lista circular de encadeamento simples
////////////////////////////////////////////////////////////////////////////

#include<stdlib.h>
#include<stdio.h>

struct no
{
    int numero;
    struct no *proximo;
};

///////////////////////////////////////
//funcao que insere um no na lista/////
//////////////////////////////////////
struct no *inserir(struct no *cabeca, int numero){
    //cracao do novo no 
    struct no *novoNO = (struct no *) malloc(sizeof(struct no));
    novoNO->numero=numero;
    novoNO->proximo=NULL;

    //caso facil lista vazia
    if (cabeca == NULL) {
        cabeca = novoNO;
        cabeca->proximo=cabeca;
        return cabeca;
    }
    ///////////////////////////////////////
    //caso de ficil lista não vazia

    struct no *ultimo = cabeca;
    while (ultimo->proximo != cabeca)
    {
        ultimo = ultimo->proximo;
    }

    ultimo->proximo=novoNO;
    novoNO->proximo=cabeca;
    return cabeca;
    
    
}


///////////////////////////////////
//funcao que exclui no da lista

struct no *excluir(struct no *cabeca, int numero){
    ////////////////////////
    //caso muito facil lista vazia

    if(cabeca == NULL){
        return NULL;
    }

    //caso facil: exclui o unico
    if((cabeca->numero==numero) && (cabeca->proximo == cabeca)){
        free(cabeca);
        return NULL;
    }

    ///caso dificil:exclui o primeiro
    if(cabeca->numero==numero){
        struct no *ultimo = cabeca;
     while (ultimo->proximo != cabeca)
     {
        ultimo = ultimo->proximo;
     }
     cabeca=cabeca->proximo;
     free(ultimo -> proximo);
     ultimo->proximo=cabeca;
     return cabeca;
    }
    ///////
    //caso muito dificil:exclui no meio ou final
    struct no *anterior = cabeca;
    while ((anterior-> proximo!=cabeca) && (anterior->proximo->numero != numero))
    {
        anterior = anterior-> proximo;
    }
    struct no *limpeza = anterior->proximo;
    anterior->proximo = anterior->proximo->proximo;
    free(limpeza);
    return cabeca;
}
/////////////
//funcao que imprime funcao na tela
void imprimir(struct no *cabeca){
    if(cabeca==NULL){
        return;
    }
    struct no *ponteiro = cabeca;
    do{
        printf("%d\n", ponteiro->numero);
        ponteiro = ponteiro->proximo;

    }while(ponteiro != cabeca);
}
///  /////////////////
/// funcao principal de execucao do progama 
int main(){
    struct no *cabeca = NULL;
    imprimir(cabeca);
    cabeca = excluir(cabeca, 0);

    cabeca = inserir(cabeca, 1);
    cabeca = inserir(cabeca, 2);
    cabeca = inserir(cabeca, 3);
    cabeca = inserir(cabeca, 4);
    cabeca = inserir(cabeca, 5);
    imprimir(cabeca);

    cabeca = excluir(cabeca, 1);
    cabeca = excluir(cabeca, 3);
    cabeca = excluir(cabeca, 5);
    imprimir(cabeca);

    cabeca = excluir(cabeca, 0);
    cabeca = excluir(cabeca, 2);
    cabeca = excluir(cabeca, 4);
    imprimir(cabeca);

}