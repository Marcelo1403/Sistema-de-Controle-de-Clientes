#include "assinaturas.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Função para limmpar tela

void limpaTela(void) {
        system("cls || clear");
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
                    system("cls || clear");
                    cadastrarCliente();
                    break;

            case'2':
                    system("cls || clear");
                    pesquisarCliente();
                    break;
            
            case '3':
                    system("cls || clear");
                    atualizarCliente();
                    break;   

            case '4':
                    system("cls || clear");
                    excluirCliente();
                    break;
            
            case '5':
                    system("cls || clear");
                    listarCliente();
                    break;
                    
            case '0':
                    system("cls || clear");
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
        Usuario* usu;

        printf("==============================================\n");
        printf("------|||     Cadastro cliente      |||-------\n");
        printf("==============================================\n");     
        usu = (Usuario*) malloc(sizeof(Usuario));
        printf("\nNome: ");
        scanf(" %[^\n]", usu->nome);
        while((validaNome(usu->nome))) {
                printf("Nome invalido, digite novamente: ");
                scanf(" %[^\n]", usu->nome);
        }

        printf("\nDigite seu CPF: ");
        scanf(" %[^\n]", usu->cpf);
        while(!(validaCpf(usu->cpf))){
                printf("CPF invalido, digite novamente: ");
                scanf(" %[^\n]", usu->cpf);
        }

        printf("\nDigite sua data de nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d",&usu->dia, &usu->mes, &usu->ano);
        while(!dataValida(usu->dia, usu->mes, usu->ano)){
                printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
                scanf("%d/%d/%d",&usu->dia, &usu->mes, &usu->ano);
        }

        printf("\nDigite seu email: ");
        scanf(" %[^\n]", usu->email);
        while(!(validaEmail(usu->email))){
                printf("Email invalido, digite novamente: ");
                scanf(" %[^\n]", usu->email);    
        }
        usu->status = '1';
        gravaCliente(usu);
        printf("\nUsuario cadastrado! Digite > Enter < para voltar ao menu Cliente!");
        getchar();
        getchar();
}



void pesquisarCliente(void) {
        FILE* fp;
        Usuario* usu;
        int achou;
        char procurado[15];
        fp = fopen("cliente.dat", "rb");
        if (fp == NULL) {
                printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
                printf("Não é possível continuar o programa...\n");
                exit(1);
        }
        printf("\n\n");
        printf("==============================================\n");
        printf("------|||     Pesquisar cliente     |||-------\n");
        printf("==============================================\n");
        printf("Informe o Nome do Cliente a ser buscado: ");
        scanf(" %14[^\n]", procurado);
        usu = (Usuario*) malloc(sizeof(Usuario));
        achou = 0;
        while((!achou) && (fread(usu, sizeof(Usuario), 1, fp))) {
                if ((strcmp(usu->nome, procurado) == 0) && (usu->status == '1')) {
                        achou = 1;
                }
        }
        fclose(fp);
        if (achou) {
                exibeCliente(usu);
                getchar();
                getchar();
        } else {
                printf("O cliente %s não foi encontrado...\n", procurado);
        }
        free(usu);
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

void exibeCliente(Usuario* usu) {
        printf("Nome: %s\n", usu->nome);
        printf("CPF: %s\n", usu->cpf);
        printf("Data de Nascimento: %d/%d/%d\n", usu->dia, usu->mes, usu->ano);
        printf("Email: %s\n", usu->email);
        printf("\n");
}

void gravaCliente(Usuario* usu) {
        FILE* fp;
        fp = fopen("cliente.dat", "ab");
        if (fp == NULL) {
                printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
                printf("Não é possível continuar o programa...\n");
        exit(1);
        }
        fwrite(usu, sizeof(Usuario), 1, fp);
        fclose(fp);
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
    system("cls || clear");
    
    do{
        limpaTela();
        menuCompras();
        printf("Escolha sua opção: \n");
        scanf(" %c",&op);
        getchar();
        switch(op){
            case '1':
                    system("cls || clear");
                    cadastrarCompra();
                    break;

            case'2':
                    system("cls || clear");
                    pesquisarCompra();
                    break;
            
            case '3':
                    system("cls || clear");
                    atualizarCompra();
                    break;   

            case '4':
                    system("cls || clear");
                    excluirCompra();
                    break;
            
            case '5':
                    system("cls || clear");
                    listarCompra();
                    break;
                    
            case '0':
                    system("cls || clear");
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
        Compras* com;
        com = (Compras*) malloc (sizeof(Compras));

        printf("==============================================\n");
        printf("------|||    Cadastro de Compras    |||-------\n");
        printf("==============================================\n");     

        printf("\n Nome do produto: ");
        scanf(" %99[^\n]", com->nome);
        printf("\n Preço: ");
        scanf(" %99[^\n]", com->preco);
        printf("\n Código de barras: ");
        scanf(" %69[^\n]", com->codBarra);

        printf("\nCompra cadastrada! Digite > Enter < para voltar ao menu Compras!");
        getchar();
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

/* void gravaCliente(Usuario* usu) {
  FILE* fp;
  fp = fopen("cliente.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(usu, sizeof(Usuario), 1, fp);
  fclose(fp);
} */
