#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

    int i,j, sapatocad, aumento;
    int codigo[100];
    float valor [100];
    int qtsapato[100];
    float valortotal = 0;
    float TotalEstoque = 0;


int main() {
    setlocale(LC_ALL, "ptb");
    system("color F4");

    printf("\n\n\t   +++++++++++++++++++++++\n");
    printf("\t   +    SAPATARIA DIAS   +");
    printf("\n\t   +++++++++++++++++++++++\n\n");
    printf("\n\t   Seja Bem- Vindo(a)\n\n\t   Press Enter... ");
    getch(stdin);
    system("cls");

    printf("\n\n Em alguns segundos, voce sera redirecionado para o Menu !!");
    sleep(3);
    system("cls");

    menu();
}


void menu(){
int op = 0;
    while(op!=5){

        printf("\n*************** MENU **************\n");
        printf("\n  1 - CADASTRAR SAPATO");
        printf("\n  2 - ATUALIZAR PREÇOS");
        printf("\n  3 - LISTAR ESTOQUE");
        printf("\n  4 - SOBRE");
        printf("\n  5 - SAIR DO PROGRAMA\n");
        printf("\n***********************************");
        printf("\n\n Escolha uma opcao: ");
        fflush(stdin);
        scanf("%d",&op);

        switch(op){
        case 1:

        //CADASTRO DE ITENS
            system("cls");
            printf("\n\n Quantidade de sapatos que deseja cadastrar: ");
            scanf("%d",&sapatocad);
            system("cls");

            for (i = 0 ;i<sapatocad;i ++){

                    printf("\n Entre com o codigo do sapato %d:\n --> ", i+1);
                    fflush(stdin);//LIMPAR O BUFFER
                    scanf("%d" ,&codigo[i]);
                    printf(" Entre com o Valor do Sapato %d:\n --> ", i+1);
                    fflush(stdin);
                    scanf("%f", &valor[i]);
                    printf(" Entre com a quantidade de sapato %d:\n --> ", i+1);
                    fflush(stdin);
                    scanf("%d",&qtsapato[i]);
                    system("cls");
                    }

                system("cls");
                    printf("\n\n Sapatos Cadastrados com sucesso!!\n");
                    printf("\n\t Press Enter");
                    getch(stdin);
                    system("cls");

        break;

        case 2:
            //ATUALIZAR PREÇO
            atualizaPreco();
            break;

        case 3:
            //LISTAR ESTOQUE
            system("cls");
            listarEstoque();
         break;

        case 4:
        system("cls");
        printf("\n\t PROJECT CREATE ON 08/10/2022 BY LARISSA DIAS\n");
        sleep(3);
        system("cls");

        break;

        case 5:
            //FECHAR PROGRAMA
            system("cls");
            printf("\n Voce optou por encerrar o programa\n");
            exit(0);
        break;
        default:

            //CASO DE OPÇÕES INVÁLIDAS
            system("cls");
            printf("\n\n Error\n");
            printf(" Tente novamente.\n");
            main(); // retorna ao main
            break;
        }
    }
}


//FUNÇÃO LISTAR ESTOQUE
void listarEstoque(){

int op2 = 0 ; //VARIAVEL PARA PARAMETRO

    printf("\n\n OPCAO: LISTAR ESTOQUE");

    //LAÇO PARA CONTINUAR NA OPÇÃO DESEJADA ATÉ O USUARIO DECIDIR SAIR
     while (op2 != 2){
        printf("\n\n 1 - Continuar");
        printf("\n 2 - Voltar");
        printf("\n --> ");
        fflush(stdin);
        scanf("%d" , &op2);
        getchar();

        system("cls");
        printf("\n\n \tINFORMACOES DO ESTOQUE\n\n");

        // CONDICIONAL CASO O USUARIO DESEJA CONTINUAR
        if (op2 == 1){

             // TABELA
             printf("\t_____________________________________________________\n");
             printf("\t Cod produto     Preço     Quantidade    Valor total\n");
             printf("\t_____________________________________________________\n");

            for (i = 0 ; i<sapatocad ; i++){
                valortotal = valor[i] * qtsapato[i];
                printf("\t     %d       R$%.2f       %d          %.2f\n",
                codigo[i], valor[i], qtsapato[i], valortotal);
                TotalEstoque = TotalEstoque + valortotal;
 }
         printf("\t_____________________________________________________\n");
         printf("\t Valor total do estoque:                R$%.2f \n ",TotalEstoque);
         printf("\t_____________________________________________________\n");

                /*
                printf("\n\n SAPATO %d: ", i+1);
                printf("\n\n Codigo: %d", codigo[i]);
                printf("\n Valor: %.2f", valor[i]);
                printf("\n qt em estoque: %d", qtsapato[i]);
                printf("\n====================================");
*/
            }
        }

        system("cls");
        menu(); // CASO O USUARIO DESEJA SAIR DA OPÇÃO RETORNA AO MENU

}


void atualizaPreco(){

int op3 = 0;

    system("cls");
    printf("\n\n OPCAO: ATUALIZAR PRECOS");


    while(op3 != 2){
        printf("\n\n 1 - Continuar");
        printf("\n 2 - Voltar");
        printf("\n --> ");
        fflush(stdin);
        scanf("%d" , &op3);
        getchar();

        system("cls");
       // printf("\n\n ATUALIZANDO PREÇOS\n\n");

        if (op3 == 1){

            printf("\n Digite o valor do aumento do preço: ");
            fflush(stdin);
            scanf("%d", &aumento);

            for (i = 0 ; i<sapatocad ; i++){
                printf("\n\n Valor do sapado %d atual: %.2f R$", i+1,valor[i]);

                valor[i] = valor[i] + aumento;

                printf("\n Valor do sapato %d depois do aumento: %.2f R$ ", i+1 , valor[i]);
        }
       // getchar();
    }

}
system("cls");
    menu();
}
