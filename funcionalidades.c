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
        int data[3];
        int dia = data[0];
        int mes = data[1];
        int ano = data[2];
        char nome[100];
        char email[100];
        char cpf[20];
        
        printf("==============================================\n");
        printf("------|||     Cadastro cliente      |||-------\n");
        printf("==============================================\n");     

        printf("\nNome: ");
        scanf("%s", nome);
        getchar();
        validaNome(nome);
        while((validaNome(nome))) {
        printf("Nome invalido, digite novamente: ");
        gets(nome);
        }

        printf("\nDigite seu CPF: ");
        gets(cpf);
        validaCpf(cpf);
        while(!(validaCpf(cpf))){
                printf("CPF invalido, digite novamente: ");
                gets(cpf);
        }

         printf("\nDigite sua data de nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d",&data[0], &data[1], &data[2]);
        getchar();
        dataValida(dia, mes, ano);
        while(!dataValida(data[0], data[1], data[2])){
        printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
        scanf("%d/%d/%d",&data[0], &data[1], &data[2]);
        }

        printf("\nDigite seu email: ");
        gets(email);
        validaEmail(email);
        while(!(validaEmail(email))){
        printf("Email invalido, digite novamente: ");
        gets(email);
    }

        printf("\nUsuario cadastrado! Digite > Enter < para voltar ao menu Cliente!\n");
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