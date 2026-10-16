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

    if(numero < raiz->numero){
        raiz->esqueda = inserir(raiz->esqueda, numero);

    }else{
        raiz->direita = inserir(raiz->direita,numero);
    }

    return raiz;


}



int contador = 0; 

void procurar(struct no *raiz, int numero){
    if(raiz==NULL){
        printf("NAO ACHEI\n");
        contador =0;
        return;
    }

    if(numero == raiz->numero){
        printf("PARABENS ACHEI\n");
    }

    contador++;
    if(numero<raiz->numero){
        procurar(raiz->esqueda, numero);
    }else{
        procurar(raiz->direita,numero);
    }
}

void navegarEmOrdem(struct no *raiz){
    if(raiz==NULL) return;

    navegarEmOrdem(raiz->esqueda);
    printf("%d, ",raiz->numero);
    navegarEmOrdem(raiz->direita);
}




int main(){}