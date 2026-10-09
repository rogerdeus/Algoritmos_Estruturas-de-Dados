#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/////////////////////////////////////////////
//declaracao de estrutura da arvore
/////////////////////////////////////////////////////
struct no
{
    int numero;
    struct no *esquerda;
    struct no *direita;
};

struct no *inserir(struct no *raiz, int numero){
    //criacao do novo no
    //senario facil arvore vazia
    if(raiz == NULL){

    
      struct no *novoNO = (struct no *)malloc(sizeof(struct no));
      novoNO->numero=numero;
      novoNO->esquerda=NULL;
      novoNO->direita=NULL;

      //retorna nova raiz

      return novoNO;
    }

    int sorteio = (rand()%2);
    if(sorteio){
        raiz->esquerda = inserir(raiz->esquerda,numero);

    }else{
        raiz->direita=inserir(raiz->direita,numero);
    }

    return raiz;

}


int main(){}