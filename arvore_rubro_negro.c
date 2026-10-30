//////////////////////////////////////////
// inplementando uma arvore rubro negra//
/////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/////////////////////////
//declaracao da estrutura do no

struct no
{
    int numero;
    struct no *esquerda;
    struct no *direita;
    int vermelho;
};
///////////////////////////////
//funcao de rotacao a esquerda
/////////////////////////////////

struct no * rotaciona_esquerda(struct no *raizvelha){
    //corecao dos ponteiros
    struct no *raizNova = raizvelha ->direita;
    //o filho da direita vai subir
    raizvelha->direita = raizNova ->esquerda;
    raizNova->esquerda = raizvelha;
    //correcao das cores
    raizNova->vermelho = raizvelha->vermelho;
    raizvelha->vermelho = 1;

    return raizNova;
}

struct no * rotaciona_direita(struct no *raizvelha){
    //corecao dos ponteiros
    struct no *raizNova = raizvelha ->esquerda;
    //o filho da direita vai subir
    raizvelha->esquerda = raizNova ->direita;
    raizNova->direita = raizvelha;
    //correcao das cores
    raizNova->vermelho = raizvelha->vermelho;
    raizvelha->vermelho = 1;
    
    return raizNova;
}

/////////////////////////////
//funcao que executa a subida do vermelho

void subirVermelho(struct no *raiz){
    raiz -> vermelho = 1;
    raiz->esquerda ->vermelho = 0;
    raiz->direita ->vermelho = 0;
}

//funcao que avalia cor do no
int isVermelho(struct no *raiz){
    if(raiz == NULL) return 0;
    return raiz -> vermelho;
}

//funcao que insere um NO na arvore

struct no *inserir(struct no *raiz, int numero){
    //caso facil arvore vazia

    if (raiz ==NULL){
        struct no * novoNO = (struct no *) malloc(sizeof(struct no));
        novoNO->numero = numero;
        novoNO->esquerda = NULL;
        novoNO->direita = NULL;
        novoNO->vermelho = 1;
        return novoNO;
    }

    //senario dificil

    if(numero < raiz->numero){
        raiz ->esquerda = inserir(raiz->esquerda, numero);

    }else
    {
        raiz->direita = inserir(raiz-> direita,numero);
    }

    //correcao de balanceamento


    

}



int main(){}