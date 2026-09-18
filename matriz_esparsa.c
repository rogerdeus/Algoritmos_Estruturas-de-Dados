////////////////////////////////////////////////
//programa que implementa uma matriz esparsa
////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>

#define MODULO 3

struct no
{
    //controle de coluna
    int numero;
    struct no *proximoNO;
};

struct diretor
{
    //controle de linhas
    int resto;
    struct no *proximoNO;
    struct diretor *proximodiretor;

};

struct diretor *cabeca =NULL;
//funcao que procura o diretor correto, se não encontrar cria

struct diretor *procuradiretor( int numero){

    struct diretor *ponteiro = cabeca;

    int resto = (numero % MODULO);
    
    while ((ponteiro != NULL) && (ponteiro->resto !=resto))
    {
        ponteiro = ponteiro->proximodiretor;
    }
    //senario que encontrou diretor correto
    if (ponteiro != NULL)
    {
        return ponteiro;
    }
    //senario que diretor correto não foi encontrado

    struct diretor *NOVOdiretor =(struct diretor *)malloc(sizeof(struct diretor));
    NOVOdiretor->resto=resto;
    NOVOdiretor->proximoNO=NULL;
    NOVOdiretor->proximodiretor=cabeca;
    cabeca=NOVOdiretor;
    return NOVOdiretor;
    
}

//funcao que insere um numero na matriz

void inserir(int numero){
    struct diretor *ponteirodiretor = procuradiretor(numero);

    struct no *novoNO = (struct no *)malloc(sizeof(struct no));
    novoNO->numero=numero;
    novoNO->proximoNO=
}




int main(){}