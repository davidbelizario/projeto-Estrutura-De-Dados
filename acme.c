//nome: David Belizario Rodrigues � prontu�rio: gu3011631 � Turma: ADS2�SEM.

//nome: Felipe Saldanha de Souza � prontu�rio: gu3011801 � Turma: ADS2�SEM.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acme.h"
//Importando as bibliotecas padr�es de C(todas com <>) e o header das fun��es do TAD("acme.h").

struct elemento{
FUNC dados;
struct elemento *prox;
};
typedef struct elemento ELEM;

//Declarando a struct elemento para fazer o papel dos nos da lista ligada.
//Tendo como variaveis uma struct do tipo FUNC(onde ser� armazenado os dados desse n�).
//E o endere�o do proximo elemento, que � basicamente o pr�ximo n�.

Lista *criaLista(){
    Lista *li;
    li =(Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
}
//FUN��O crialista: declara o malloc que vai alocar dinamicamente os dados futuros.
void apagaLista(Lista *li){
    if(li !=NULL){
        ELEM *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}
//FUN��O apagaLista: ir� apagar a lista ligada e seus respectivos nos.
int listaVazia(Lista *li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}
//FUN��O listaVazia: verifica se a lista existe ou se est� vazia.
int insere_ordenado_lista(Lista *li, FUNC fc){
    if(li == NULL){
        return 0;
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = fc;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    }
    else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.ID <fc.ID){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox =(*li);
            *li = no;
        }
        else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}
//FUN��O insere_ordenado_lista: insere de forma ordenada os dados na lista ligada pelas posi��es no prox de cada n�, tamb�m tem a fun��o de garantir a inser��o inicial.
int remove_lista(Lista *li, int Id){
    int sel=0;
    printf("\n//////////////////////////////////\n");
    printf("Deseja mesmo remover o funcionario do ID %d ?\nEssa acao e irreversivel\n Digite 1 para sim e qualquer outro numero para nao.\n",Id);
    scanf("%d", &sel);
    if(sel == 1){
    if(li == NULL){
        return 0;
    }

    ELEM *ant, *no = *li;
    while(no != NULL && no->dados.ID != Id){
        ant = no;
        no =  no->prox;
    }

    if(no == NULL){
        return 0;
    }

    if(no == *li){
        *li = no->prox;
    }

    else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
    }
    else{
        printf("Retornando ao menu, aviso de erro eminente.");
        return 0;
    }
}
//FUN��O remove_lista: remove um certo n� da lista ligada a partir da sua posi��o e ID(dado da struct funcionario).
int consulta_lista_ID(Lista *li, int Id, FUNC *funci){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.ID != Id){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    else{
        *funci = no->dados;
        return 1;
    }
}
//FUN��O  consulta_lista_ID: essa fun��o ir� consultar um n� na lista ligada pelo seu ID.
int listar_ordenado_ID(Lista *li){
 if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL){
            printf("\n//////////////////////////////////\n");
            printf("ID: %d\n",no->dados.ID);
            printf("Nome: %s\n",no->dados.Nome);
            printf("Endereco: %s\n",no->dados.Endereco);
            printf("Idade: %d\n",no->dados.Idade);
            printf("Salario: %.2f\n",no->dados.Salario);
            printf("Cargo: %s\n",no->dados.Cargo);
        no = no->prox;
    }
    return 1;
}
//FUN��O listar_ordenado_ID: percore todas as posi��es da lista ligada imprimindo todos os dados inseridos, � ordenado pelo motivo de todas as inser��es serem ordenadas.
int listar_amplitude_salario(Lista *li, float salarioMin, float salarioMax){
 if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL){

            if(no->dados.Salario <= salarioMax && no->dados.Salario >= salarioMin){
                printf("\n//////////////////////////////////\n");
                printf("ID: %d\n",no->dados.ID);
                printf("Nome: %s\n",no->dados.Nome);
                printf("Endereco: %s\n",no->dados.Endereco);
                printf("Idade: %d\n",no->dados.Idade);
                printf("Salario: %.2f\n",no->dados.Salario);
                printf("Cargo: %s\n",no->dados.Cargo);
                no = no->prox;
            }
            else{
              no = no->prox;
            }
    }
    return 1;
}
//FUN��O listar_amplitude_salario: recebe dois valores e assim os usam de parametro para imprimir os valores da lista ligada que atendam certas condi��es de salario minimo e maximo.
int alterar_lista_ID(Lista *li, int Id, FUNC *funcA, int Op){
    if(Op == 1){
        if(li == NULL){
            return 0;
        }
        ELEM *no = *li;
            while(no != NULL && no->dados.ID != Id){
            no = no->prox;
        }
        if(no == NULL){
            return 0;
        }
        else{
         no->dados.ID = no->dados.ID;
         memset(no->dados.Nome,0,strlen(no->dados.Nome));
         memcpy(no->dados.Nome, funcA->Nome, strlen(funcA->Nome) + 1);
         memset(no->dados.Endereco,0,strlen(no->dados.Endereco));
         memcpy(no->dados.Endereco, funcA->Endereco, strlen(funcA->Endereco)  + 1);
         no->dados.Idade = funcA->Idade;
         memset(no->dados.Cargo,0,strlen(no->dados.Cargo));
         memcpy(no->dados.Cargo, funcA->Cargo, strlen(funcA->Cargo) + 1);
            return 1;
        }
    }
    else if(Op == 2){
           if(li == NULL){
        return 0;
        }
        ELEM *no = *li;
            while(no != NULL && no->dados.ID != Id){
            no = no->prox;
        }
        if(no == NULL){
            return 0;
        }
        else{
         no->dados.Salario = funcA->Salario;
            return 1;
        }
    }
    else{
        return 0;
    }
}
//FUN��O alterar_lista_ID: fun��o mais complexa do codigo, feita para alterar os dados inseridos em um n� especificado pelo ID recebido, al�m de verificar a op��o de altera��o seja ela salarial ou de informa��es.
//Usa tamb�m de fun��es de memoria, como a memcpy e memset, memcpy copia certa informa��o de um ponteiro para outro com certo tamanho, copiando assim o valor da struct enviada.
//J� o memset estabelece um valor num ponteiro, aqui ele foi usado para limpar o campo para a proxima inser��o, que � feita pelo memcpy.
