/////////////////////////////////////////////////////////////////////
//ISSO É UM TESTE DE AULA 



///////////////////////////////
// Programa que implementa lisata encadeada
//////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////
//Estrutura que modela o no da lista//
///////////////////////////////////////////

struct no
{
    int numero;
    struct no *proximo; 
    
};

///////////////////////////////////////////////////
//Função que insere um no na lista
/////////////////////////////////////////////////////


struct no *inserir( struct  no *cabeca, int numero)
{

    // criação novo no
    struct no *novoNO = (struct no *) malloc(sizeof(struct no));
    novoNO ->numero = numero;
    novoNO ->proximo = NULL;
  //senario facil: lista vazia

    if (cabeca == NULL){
        return novoNO;

    }


    // senario dificil: lista não vazia

    struct no *ultimo = cabeca;
    while (ultimo -> proximo != NULL){
        ultimo = ultimo -> proximo;

    }

    ultimo -> proximo = novoNO;
    return cabeca;
       //////////////////////////////////////////
       // Teve otimização no codigo então esta reduzido
}


/////////
// int main para parar de dar erro
/////////////////////


///////////////////////////////////////////////////////////////////
// Função excluir um no da lista
///////////////////////////////////////////////
// Existem 4 cenarios
///////////////////////////////

struct no *excluir(struct no *cabeca, int numero){
    /////////////////
    //Cenario muito facil: lista vazia

    if (cabeca == NULL){
        return cabeca;
    }

    //cenario facil:excuir o primeiro
    if(cabeca ->numero == numero){
        struct no *Limpa = cabeca;
        cabeca = cabeca -> proximo;
        free(Limpa);

        return cabeca;
    }

    //Procura do no ANTERIOR da lista
    struct no *anterior = cabeca;
    while ((anterior ->proximo != NULL) && //NÃO ACHEI e parei no ultimo
    (anterior ->proximo ->numero != numero))
    { // ACHEI e parei no anterior
        anterior = anterior ->proximo;

    }
    //cenario dificil: NÂO foi ENCONTRADO 

    if(anterior ->proximo == NULL){
        printf("CACETE NÃO TEM NUMERO");
        return cabeca;
    }

    struct no *Limpa = anterior -> proximo;
    anterior -> proximo = anterior ->proximo -> proximo;
    free(Limpa);
    return cabeca;
    

}

////////////////////////////////////////////
// Função que impreme a lista

void imprimir(struct no *cabeca){
    struct no *ponteiro = cabeca;
    while (ponteiro != NULL)
    {
        printf("%d\n", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;
    }
    
}
 
int main(){
    struct no *cabeca = NULL;

    //primeiro test

    imprimir(cabeca);
    cabeca = excluir(cabeca, 180);

    cabeca = inserir(cabeca, 1);
    cabeca = inserir(cabeca, 2);
    cabeca = inserir(cabeca, 3);
    cabeca = inserir(cabeca, 4);
    cabeca = inserir(cabeca, 5);
    imprimir(cabeca);
    cabeca = inserir(cabeca, 1);
    cabeca = inserir(cabeca, 3);
    cabeca = inserir(cabeca, 5);
    imprimir(cabeca);

    //segundo test
   // int i;
    //for (i = 0; i<1000000; i++){
      //  cabeca = inserir(cabeca, i);
        //printf("%d\n", i);

    //}

}
