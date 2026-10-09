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

///////////////////
//funcao que faz a navegacao pre ordem

void navegar_preordem(struct no *raiz){
    if(raiz == NULL) return; //proteção

    printf("%d", raiz->numero);
    navegar_preordem(raiz->esquerda);
    navegar_preordem(raiz->direita);

}

//funcao que faz a navegação pos ordem

void navegar_posordem(struct no *raiz){
    if(raiz == NULL) return; //proteção

    
    navegar_posordem(raiz->esquerda);
    navegar_posordem(raiz->direita);
    printf("%d", raiz->numero);
    
}

void navegar_emordem(struct no *raiz){
    if(raiz == NULL) return; //proteção

    
    navegar_emordem(raiz->esquerda);
    printf("%d", raiz->numero);
    navegar_emordem(raiz->direita);
    
    
}



int main(){
    struct no *raiz = NULL;
    int i = 0;

    time_t t;
    srand(time(&t));

    for(i = 0; i< 10; i++){
        raiz = inserir(raiz, i);
    }

    //navegação

    printf("pre_ordem: ");
    navegar_preordem(raiz);
    printf("\n");
    printf("em_ordem: ");
    navegar_emordem(raiz);
    printf("\n");
    printf("pos_ordem");
    navegar_posordem(raiz);
    printf("\n");
}