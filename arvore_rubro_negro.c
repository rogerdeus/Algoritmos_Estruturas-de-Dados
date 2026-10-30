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



int main(){}