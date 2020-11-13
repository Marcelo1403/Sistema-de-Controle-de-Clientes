#include "assinaturas.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int chartoint(char);
char inttochar(int);

// Função para limmpar tela

void limpaTela(void) {
        if (system("CLS")) 
            system("clear");
}


// FUNÇÃO PARA NAVEGAÇÃO DOS MENUS CLIENTES

void gerenciarCliente(void){
    char op = ' ';
    system("clear");
    
    do{
        limpaTela();
        menuCliente();
        printf("Escolha sua opção: \n");
        scanf(" %c",&op);
        getchar();
        switch(op){
            case '1':
                    system("clear");
                    cadastrarCliente();
                    break;

            case'2':
                    system("clear");
                    pesquisarCliente();
                    break;
            
            case '3':
                    system("clear");
                    atualizarCliente();
                    break;   

            case '4':
                    system("clear");
                    excluirCliente();
                    break;
            
            case '5':
                    system("clear");
                    listarCliente();
                    break;
                    
            case '0':
                    system("clear");
                    printf("\n");
                    printf(" Obrigado por ultilizar nossos serviços.Volte sempre.\n");
                    printf("\n");
                    break;
            
            default:
		    printf("\n");
		    printf(">>>Opção errada. Digite uma opção válida: ");
		    printf("\n");

            }
    } while(op!='0');
}

// MODOLO CLIENTE
void cadastrarCliente(void) {
        char nome[100];
        char end[200];
        char email[100];
        char estado[40];
        char sexo[10];
        char cidade[70];
        char cpf[20];
        char indentidade[20];
        char nasc[12];
        char *pcpf = cpf;
        char *pnome = nome;
        printf("==============================================\n");
        printf("------|||     Cadastro cliente      |||-------\n");
        printf("==============================================\n");     

        printf("\nNome: ");
        gets(nome);
        validaNome(pnome);
        while((validaNome(pnome))) {
        printf("Nome invalido, digite novamente: ");
        gets(pnome);
    }


        /*
        printf("\n Email: ");
        scanf(" %99[a-z.@]", email); */
        
        printf("\nDigite seu CPF: ");
        gets(pcpf);
        validaCpf(pcpf);
        while(!(validaCpf(pcpf))){
                printf("CPF invalido, digite novamente: ");
                gets(pcpf);
        }
        menuCliente();
        /*
        printf("\n Indentidade: ");
        scanf(" %19[^\n]", indentidade);
        printf("\n Endereço: ");
        scanf(" %9[^\n]", end);
        printf("\n Cidade: ");
        scanf(" %69[^\n]", cidade);
        printf("\n Estado: ");
        scanf(" %19[^\n]", estado);
        printf("\nData de nascimento(dd/mm/aaaa): ");
        scanf(" %10[^\n]", nasc);
        printf("\nInforme o sexo do cliente (M/F): ");
        scanf("%c", sexo); */
        getchar();

}



void pesquisarCliente(void) {
	printf("\n\n\nMódulo pesquisar Cliente\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}


void atualizarCliente(void) {
	printf("\n\n\nMódulo atualizar Cliente\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void excluirCliente(void) {
	printf("\n\n\nMódulo excluir Cliente\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void listarCliente(void) {
	printf("\n\n\nMódulo excluir Cliente\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}




// FUNÇÃO PARA NAVEGAÇÃO DA EMPRESA

void gerenciarRelatorios(void){
    char opc = ' ';
    system("clear");
    
    do{
        limpaTela();
        menuRelatorios();
        printf("Escolha sua opção: \n");
        scanf(" %c",&opc);
        getchar();
        switch(opc){
            case '1':
                    system("clear");
                    printf("Opção Relatório financeiro em desenvolvimento.");
                    break;

            case'2':
                    system("clear");
                    printf("Opção Relatório de vendas em desenvolvimento.");
                    break;
            
            default:
		    printf("\n");
		    printf(">>>Opção errada. Digite uma opção válida: ");
		    printf("\n");

            }
    } while(opc!='0');
}


void gerenciarCompras(void){
    char op = ' ';
    system("clear");
    
    do{
        limpaTela();
        menuCompras();
        printf("Escolha sua opção: \n");
        scanf(" %c",&op);
        getchar();
        switch(op){
            case '1':
                    system("clear");
                    cadastrarCompra();
                    break;

            case'2':
                    system("clear");
                    pesquisarCompra();
                    break;
            
            case '3':
                    system("clear");
                    atualizarCompra();
                    break;   

            case '4':
                    system("clear");
                    excluirCompra();
                    break;
            
            case '5':
                    system("clear");
                    listarCompra();
                    break;
                    
            case '0':
                    system("clear");
                    printf("\n");
                    printf(" Obrigado por ultilizar nossos serviços.Volte sempre.\n");
                    printf("\n");
                    break;
            
            default:
		    printf("\n");
		    printf(">>>Opção errada. Digite uma opção válida: ");
		    printf("\n");

            }
    } while(op!='0');
}

// MODOLO COMPRAS
void cadastrarCompra(void) {
        char nome[100];
        char codBarra[70];
        char preco[100];
         
        printf("==============================================\n");
        printf("------|||    Cadastro de Compras    |||-------\n");
        printf("==============================================\n");     

        printf("\n Nome do produto: ");
        scanf(" %99[^\n]", nome);
        printf("\n Preço: ");
        scanf(" %99[^\n]", preco);
        printf("\n Código de barras: ");
        scanf(" %69[^\n]", codBarra);
        getchar();

}



void pesquisarCompra(void) {
	printf("\n\n\nMódulo pesquisar Compra\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}


void atualizarCompra(void) {
	printf("\n\n\nMódulo atualizar Compra\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void excluirCompra(void) {
	printf("\n\n\nMódulo excluir Compra\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void listarCompra(void) {
	printf("\n\n\nMódulo excluir Compra\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}