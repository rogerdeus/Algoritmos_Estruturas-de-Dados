#include<stdio.h>
#include<stdlib.h>

//programa que implemeta uma arvore AVL

struct no
{
    int numero;
    struct no *esquerda;
    struct no *direita;
    int altura;
};

//funcao que recupera altura do no

int getAlturaDoNo(struct no *raiz){
    if(raiz == NULL)return 0;
    return raiz->altura;
}


int main(){}