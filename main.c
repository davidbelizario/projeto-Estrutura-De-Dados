//nome: David Belizario Rodrigues – prontuário: gu3011631 – Turma: ADS2ºSEM.

//nome: Felipe Saldanha de Souza – prontuário: gu3011801 – Turma: ADS2ºSEM.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acme.h"
//Importando as bibliotecas padrões de C(todas com <>) e o header das funções do TAD("acme.h").
int main()
{
    //Declarando o ponteiro do tipo Lista para sustentar a lista ligada que vai compôr este projeto.
    Lista *li;
    li = criaLista();
    //Chamando a função pela variavel li para basicamente fazer a alocação dinâmica.
    int menu=1;
    //Declarando variavel menu como 1 para agir como true na função while seguinte, isto controlará o funcionamento do projeto.
    int valida;
    //Declarando variavel valida para além de invocar funções, trazer o resultado verdadeiro ou falso das funções.
    int I=0;
    //Declarando variavel I para controlar as opções do switch dentro do while.
    while(menu){
    //while criado para repetir as funções do menu.
    I=0;
    //O I sempre voltará a zero para não criar um loop infinito.
    printf("\n//////////////////////////////////\n");
    printf("\nMENU - ACME\n");
    printf("ESCOLHA UMA DAS FUNCIONALIDADES:\n");
    printf(" 1-Adicionar funcionario\n");
    printf(" 2-Excluir funcionario\n");
    printf(" 3-Editar funcionario\n");
    printf(" 4-Buscar funcionario\n");
    printf(" 5-Exibir funcionario ordenado por ID\n");
    printf(" 6-Exibir funcionarios por faixa salarial\n");
    printf(" 7-Sair da aplicacao\n");
    //Vários prints mostrando as opções do menu.
    printf("Escolha: ");
    scanf("%d", &I);
    //Scanenando o I para escolher uma opção.
    switch(I){
        //ADICIONANDO FUNCIONÁRIO
    case 1:
        printf("\n//////////////////////////////////\n");
        FUNC funci;
        //Declarando variavel do tipo FUNC para a inserção na lista.
        printf("\nDigite o ID do funcionario:\n");
        scanf("%d",&funci.ID);
        getchar();
        printf("\nDigite o nome do funcionario:\n");
        gets(funci.Nome);
        printf("\nDigite o endereco do funcionario:\n");
        gets(funci.Endereco);
        printf("\nDigite a idade do funcionario:\n");
        scanf("%d", &funci.Idade);
        printf("\nDigite o salario do funcionario:\n");
        scanf("%f", &funci.Salario);
        getchar();
        printf("\nDigite o cargo do funcionario:\n");
        gets(funci.Cargo);
        printf("\n//////////////////////////////////\n");
        valida=insere_ordenado_lista(li,funci);
        //Printfs, scanfs e gets para conseguir os dados para a inserção.
        if(valida){
            printf("Inserido ordenadamente com sucesso.\n");
        }
        else{
             printf("ERRO:Nao foi possivel inserir.\n");
        }
        //Teste para validar se a função foi ou não executada.
        break;
        //EXCLUINDO FUNCIONÁRIO
    case 2:
        printf("\n//////////////////////////////////\n");
        printf("\nDigite o ID do funcionario que deseja excluir:\n");
        int IDR;
        //Declarando variavel IDR para carregar o ID de remoção.
        scanf("%d",&IDR);
        valida = remove_lista(li,IDR);
        if(valida){
            printf("Removido com sucesso.\n");
        }
        else{
             printf("ERRO:Nao foi possivel remover.\n");
        }
        //Teste para validar se a função foi ou não executada.
        break;
        //ALTERAR FUNCIONÁRIO POR ID
    case 3:
        printf("\n//////////////////////////////////\n");
        printf("Digite o ID do funcionario que deseja alterar:\n");
        int IDA,OP;
        //Declarando variavel IDA para carregar o ID de alteração e OP para a opção de alteração.
        scanf("%d",&IDA);
        printf("AS INFORMACOES INSERIDAS A PARTIR DE AGORA IRAO ALTERAR OS DADOS DO FUNCIONARIO DO ID ESCOLHIDO:\n");
        FUNC funcA;
        printf("1-EDICAO DE INFORMACOES ou 2-REAJUSTE SALARIAL:\n");
        scanf("%d",&OP);
        if(OP==1){
            getchar();
            printf("\nDigite o nome do funcionario:\n");
            gets(funcA.Nome);
            printf("\nDigite o endereco do funcionario:\n");
            gets(funcA.Endereco);
            printf("\nDigite a idade do funcionario:\n");
            scanf("%d", &funcA.Idade);
            getchar();
            printf("\nDigite o cargo do funcionario:\n");
            gets(funcA.Cargo);
        //Printfs, scanfs e gets para conseguir os dados para a alteração.
        }
        else if(OP==2){
            printf("\nDigite o salario do funcionario:\n");
            scanf("%f", &funcA.Salario);
        //Printf e scanf para conseguir os dados para a alteração.
        }
        else{
            printf("VALOR INVALIDO");
        }
        printf("\n//////////////////////////////////\n");
        valida=alterar_lista_ID(li,IDA,&funcA, OP);
        if(valida){
            printf("Alterado com sucesso.\n");
        }
        else{
             printf("ERRO:Nao foi possivel alterar.\n");
        }
        //Teste para validar se a função foi ou não executada.
        break;
        //ENCONTRAR POR ID.
    case 4:
        printf("\n//////////////////////////////////\n");
        printf("\nDigite o ID do funcionario que deseja encontrar:\n");
        int IDE;
        //Declarando variavel IDE para carregar o ID que vai ser encontrado.
        FUNC funcE;
        //Declarando variavel do tipo FUNC para armazenar e demonstrar os dados.
        scanf("%d",&IDE);
        valida = consulta_lista_ID(li,IDE,&funcE);
        if(valida){
            printf("Encontrado com sucesso.\n");
            printf("\n//////////////////////////////////\n");
            printf("ID: %d\n",funcE.ID);
            printf("Nome: %s\n",funcE.Nome);
            printf("Endereco: %s\n",funcE.Endereco);
            printf("Idade: %d\n",funcE.Idade);
            printf("Salario: %.2f\n",funcE.Salario);
            printf("Cargo: %s\n",funcE.Cargo);
            system("pause");
            //Printfs para imprimir os valores encontrados.
        }
        else{
             printf("ERRO:Nao foi possivel encontrar.\n");
        }
        break;
        //ORDENANDO FUNCIONARIOS POR ID
    case 5:
        printf("\n//////////////////////////////////\n");
        printf("Lista de funcionarios ordenados por ID:\n");
        valida = listar_ordenado_ID(li);
        printf("Enter para continuar para o menu:\n");
        system("pause");
        break;
        //AMPLITUDE SALARIO MINIMO - SALARIO MAXIMO
    case 6:
        printf("\n//////////////////////////////////\n");
        printf("\nDigite o salario minimo de funcionario:\n");
        float salMin;
        scanf("%f",&salMin);
        printf("\nDigite o salario maximo de funcionario:\n");
        float salMax;
        scanf("%f",&salMax);
        valida = listar_amplitude_salario(li,salMin,salMax);
        printf("Enter para continuar para o menu:\n");
        system("pause");
        break;
        //SAINDO DA APLICAÇÃO
    case 7:
        printf("\n//////////////////////////////////\n");
        printf("Saindo da aplicacao!\n");
        menu=0;
        //Quebra o loop while(menu) e termina o programa.
        break;
        //VALOR INVALIDO, REPETINDO LOOP MENU
    default:
        printf("\n//////////////////////////////////\n");
        printf("Valor invalido, retornando ao menu!\n");
    }
    }
    apagaLista(li);
    return 0;
}
