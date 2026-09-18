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
    novoNO->proximoNO=ponteirodiretor->proximoNO;
    ponteirodiretor->proximoNO=novoNO;
}

void excluir(int numero){
    struct diretor *ponteirodiretor = procuradiretor(numero);
    //senario muit facil não tem numero

    if (ponteirodiretor->proximoNO == NULL)
    {
        return;
    }

    if(ponteirodiretor-> proximoNO->numero == numero){
        struct no *limpeza =ponteirodiretor->proximoNO;
        ponteirodiretor->proximoNO=ponteirodiretor->proximoNO->proximoNO;
        free(limpeza);
        return;

    }

    //senario dificil procurar pelo numero a ser excluidos parar no anterior
    struct no *anterior = ponteirodiretor->proximoNO;
    while ((anterior->proximoNO!=NULL) && (anterior->proximoNO->numero != numero))
    {
        anterior= anterior->proximoNO;
    }

    //senario não encontrei
    if(anterior->proximoNO ==NULL){
        return;
    }

    struct no *limpeza =anterior->proximoNO;
    anterior->proximoNO=anterior->proximoNO->proximoNO;
    free(limpeza);
    


}

//função que imprime matriz na tela

void imprimir(){
    struct diretor *ponteirodiretor = cabeca;
    printf("Resto \t Numero \n");
    while (ponteirodiretor !=NULL)
    {
        printf("%d\t", ponteirodiretor->resto);
        struct no *ponteiroNO = ponteirodiretor ->proximoNO;
        while (ponteiroNO != NULL)
        {
            printf("%d,", ponteiroNO ->numero);
            ponteiroNO =ponteiroNO->proximoNO;
        }
        printf("\n");
        ponteirodiretor = ponteirodiretor->proximodiretor;
        
    }
    
}




int main(){
    inserir(5);
    inserir(293);
    inserir(10);
    inserir(4);
    inserir(144);
    inserir(9);
    inserir(6);
    imprimir();

}