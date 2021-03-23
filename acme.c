//nome: David Belizario Rodrigues – prontuário: gu3011631 – Turma: ADS2ºSEM.

//nome: Felipe Saldanha de Souza – prontuário: gu3011801 – Turma: ADS2ºSEM.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acme.h"
//Importando as bibliotecas padrões de C(todas com <>) e o header das funções do TAD("acme.h").

struct elemento{
FUNC dados;
struct elemento *prox;
};
typedef struct elemento ELEM;

//Declarando a struct elemento para fazer o papel dos nos da lista ligada.
//Tendo como variaveis uma struct do tipo FUNC(onde será armazenado os dados desse nó).
//E o endereço do proximo elemento, que é basicamente o próximo nó.

Lista *criaLista(){
    Lista *li;
    li =(Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
}
//FUNÇÃO crialista: declara o malloc que vai alocar dinamicamente os dados futuros.
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
//FUNÇÃO apagaLista: irá apagar a lista ligada e seus respectivos nos.
int listaVazia(Lista *li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}
//FUNÇÃO listaVazia: verifica se a lista existe ou se está vazia.
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
//FUNÇÃO insere_ordenado_lista: insere de forma ordenada os dados na lista ligada pelas posições no prox de cada nó, também tem a função de garantir a inserção inicial.
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
//FUNÇÃO remove_lista: remove um certo nó da lista ligada a partir da sua posição e ID(dado da struct funcionario).
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
//FUNÇÃO  consulta_lista_ID: essa função irá consultar um nó na lista ligada pelo seu ID.
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
//FUNÇÃO listar_ordenado_ID: percore todas as posições da lista ligada imprimindo todos os dados inseridos, é ordenado pelo motivo de todas as inserções serem ordenadas.
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
//FUNÇÃO listar_amplitude_salario: recebe dois valores e assim os usam de parametro para imprimir os valores da lista ligada que atendam certas condições de salario minimo e maximo.
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
//FUNÇÃO alterar_lista_ID: função mais complexa do codigo, feita para alterar os dados inseridos em um nó especificado pelo ID recebido, além de verificar a opção de alteração seja ela salarial ou de informações.
//Usa também de funções de memoria, como a memcpy e memset, memcpy copia certa informação de um ponteiro para outro com certo tamanho, copiando assim o valor da struct enviada.
//Já o memset estabelece um valor num ponteiro, aqui ele foi usado para limpar o campo para a proxima inserção, que é feita pelo memcpy.
