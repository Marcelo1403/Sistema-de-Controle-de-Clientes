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
        FILE* fp;
        Usuario* usu;
        int achou;
        char resp;
        char procurado[15];
        fp = fopen("cliente.dat", "r+b");
        if (fp == NULL) {
                printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
                printf("Não é possível continuar o programa...\n");
                exit(1);
        }
        printf("\n\n");
	printf("==============================================\n");
        printf("-----|||   Atuaizar Dados do cliente   |||----\n");
        printf("==============================================\n");
	printf("Informe o nome do cliente a ser alterado: ");
        scanf(" %14[^\n]", procurado);
        usu = (Usuario*) malloc(sizeof(Usuario));
        achou = 0;
        while((!achou) && (fread(usu, sizeof(Usuario), 1, fp))) {
                if ((strcmp(usu->nome, procurado) == 0) && (usu->status == '1')) {
                        achou = 1;
                }
        }
        if (achou) {
                exibeCliente(usu);
                getchar();
                printf("Deseja realmente editar os dados deste cliente (s/n)? ");
                scanf("%c", &resp);
                if (resp == 's' || resp == 'S') {
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
                        fseek(fp, (-1)*sizeof(Usuario), SEEK_CUR);
                        fwrite(usu, sizeof(Usuario), 1, fp);
                        printf("\nCliente editado com sucesso!!!\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	                getchar();
                        getchar();
                } else {
                        printf("\nOk, os dados não foram alterados\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	                getchar();
                        getchar();
                }
        } else {
                printf("O Cliente %s não foi encontrado...\n", procurado);
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	        getchar();
                getchar();
        }
        free(usu);
        fclose(fp);
}

void excluirCliente(void) {
	FILE* fp;
        Usuario* usu;
        int achou;
        char resp;
        char procurado[15];
        fp = fopen("cliente.dat", "r+b");
        if (fp == NULL) {
                printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
                printf("Não é possível continuar o programa...\n");
                exit(1);
        }
        printf("\n\n");
        printf("==============================================\n");
        printf("-----|||   Excluir Dados do cliente   |||----\n");
        printf("==============================================\n");
        printf("Informe o nome do cliente a ser apagado: ");
        scanf(" %14[^\n]", procurado);
        usu = (Usuario*) malloc(sizeof(Usuario));
        achou = 0;
        while((!achou) && (fread(usu, sizeof(Usuario), 1, fp))) {
                if ((strcmp(usu->nome, procurado) == 0) && (usu->status == '1')) {
                        achou = 1;
                }
        }
  
        if (achou) {
                exibeCliente(usu);
                getchar();
                printf("Deseja realmente apagar este cliente (s/n)? ");
                scanf("%c", &resp);
                if (resp == 's' || resp == 'S') {
                usu->status = '0';
                fseek(fp, (-1)*sizeof(Usuario), SEEK_CUR);
                fwrite(usu, sizeof(Usuario), 1, fp);
                printf("\nCliente excluído com sucesso!!!\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	        getchar();
                getchar();
                } else {
                        printf("\nOk, os dados não serão deletados\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	                getchar();
                        getchar();
                }
        } else {
                printf("O cliente %s não foi encontrado...\n", procurado);
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	        getchar();
                getchar();
        }
        free(usu);
        fclose(fp);
}

void listarCliente(void) {
	FILE* fp;
        Usuario* usu;
        fp = fopen("cliente.dat", "rb");
        if (fp == NULL) {
                printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
                printf("Não é possível continuar o programa...\n");
                exit(1);
        }
        printf("\n\n");
        printf("==============================================\n");
        printf("-----|||    Listar todos os cliente    |||----\n");
        printf("==============================================\n");
        usu = (Usuario*) malloc(sizeof(Usuario));
        while(fread(usu, sizeof(Usuario), 1, fp)) {
                if (usu->status == '1') {
                exibeCliente(usu);
                }
        }
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        getchar();
        fclose(fp);
        free(usu);
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

        printf("==============================================\n");
        printf("------|||    Cadastro de Compras    |||-------\n");
        printf("==============================================\n");     

        com = (Compras*) malloc (sizeof(Compras));
        printf("\n Nome do produto: ");
        scanf(" %[^\n]", com->nome);
        while((validaNome(com->nome))) {
                printf("Nome invalido, digite novamente: ");
                scanf(" %[^\n]", com->nome);
        }
        printf("\n Preço: ");
        scanf(" %99[^\n]", com->preco);
        printf("\n Código de barras: ");
        scanf(" %69[^\n]", com->codBarra);
        printf("\n Código da compra: ");
        scanf(" %69[^\n]", com->codCompra);
        com->status = '1';
        exibeCompras(com);
        gravaCompras(com);
        printf("\nCompra cadastrada! Digite > Enter < para voltar ao menu Compras!");
        getchar();
        getchar();

}



void pesquisarCompra(void) {
	FILE* fp;
        Compras* com;
        int achou;
        char procurado[70];
        fp = fopen("compras.dat", "r+b");
        if (fp == NULL) {
                printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
                printf("Não é possível continuar o programa...\n");
                exit(1);
        }
        printf("\n\n");
        printf("==============================================\n");
        printf("------|||     Pesquisar Compras     |||-------\n");
        printf("==============================================\n");
        printf("Informe o código da compra a ser buscada: ");
        scanf(" %69[^\n]", procurado);
        com = (Compras*) malloc(sizeof(Compras));
        achou = 0;
        while((!achou) && (fread(com, sizeof(Compras), 1, fp))) {
                if ((strcmp(com->codCompra, procurado) == 0) && (com->status == '1')) {
                        achou = 1;
                }
        }
        fclose(fp);
        if (achou) {
                exibeCompras(com);
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                getchar();
        } else {
                printf("O código de compra %s não foi encontrado...\n", procurado);
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	        getchar();
                getchar();
        }
        free(com);
}


void atualizarCompra(void) {
	FILE* fp;
        Compras* com;
        int achou;
        char resp;
        char procurado[70];
        fp = fopen("compras.dat", "r+b");
        if (fp == NULL) {
                printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
                printf("Não é possível continuar o programa...\n");
                exit(1);
        }
        printf("\n\n");
	printf("==============================================\n");
        printf("-----|||   Atuaizar Dados da compra    |||----\n");
        printf("==============================================\n");
	printf("Informe o código da compra a ser buscada: ");
        scanf(" %69[^\n]", procurado);
        com = (Compras*) malloc(sizeof(Compras));
        achou = 0;
        while((!achou) && (fread(com, sizeof(Compras), 1, fp))) {
                if ((strcmp(com->codCompra, procurado) == 0) && (com->status == '1')) {
                        achou = 1;
                }
        }
        if (achou) {
                exibeCompras(com);
                getchar();
                printf("Deseja realmente editar os dados desta compra (s/n)? ");
                scanf("%c", &resp);
                if (resp == 's' || resp == 'S') {
                        printf("\n Nome do produto: ");
                        scanf(" %[^\n]", com->nome);
                        while((validaNome(com->nome))) {
                        printf("Nome invalido, digite novamente: ");
                        scanf(" %[^\n]", com->nome);
                        }
                        printf("\n Preço: ");
                        scanf(" %99[^\n]", com->preco);
                        printf("\n Código de barras: ");
                        scanf(" %69[^\n]", com->codBarra);
                        printf("\n Código da compra: ");
                        scanf(" %69[^\n]", com->codCompra);
                        com->status = '1';
                        fseek(fp, (-1)*sizeof(Compras), SEEK_CUR);
                        fwrite(com, sizeof(Compras), 1, fp);
                        printf("\nCompra editada com sucesso!!!\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	                getchar();
                        getchar();
                } else {
                        printf("\nOk, os dados não foram alterados\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	                getchar();
                        getchar();
                }
        } else {
                printf("O código de compra %s não foi encontrado...\n", procurado);
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	        getchar();
                getchar();
        }
        free(com);
        fclose(fp);
}

void excluirCompra(void) {
	FILE* fp;
        Compras* com;
        int achou;
        char resp;
        char procurado[70];
        fp = fopen("compras.dat", "r+b");
        if (fp == NULL) {
                printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
                printf("Não é possível continuar o programa...\n");
                exit(1);
        }
        printf("\n\n");
        printf("==============================================\n");
        printf("-------|||      Excluir Compra       |||------\n");
        printf("==============================================\n");
        printf("Informe o código da compra a ser apagada: ");
        scanf(" %69[^\n]", procurado);
        com = (Compras*) malloc(sizeof(Compras));
        achou = 0;
        while((!achou) && (fread(com, sizeof(Compras), 1, fp))) {
                if ((strcmp(com->codBarra, procurado) == 0) && (com->status == '1')) {
                        achou = 1;
                }
        }
  
        if (achou) {
                exibeCompras(com);
                getchar();
                printf("Deseja realmente apagar esta compra (s/n)? ");
                scanf("%c", &resp);
                if (resp == 's' || resp == 'S') {
                com->status = '0';
                fseek(fp, (-1)*sizeof(Compras), SEEK_CUR);
                fwrite(com, sizeof(Compras), 1, fp);
                printf("\nCompra excluída com sucesso!!!\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	        getchar();
                getchar();
                } else {
                        printf("\nOk, os dados não serão deletados\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	                getchar();
                        getchar();
                }
        } else {
                printf("O cliente %s não foi encontrado...\n", procurado);
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	        getchar();
                getchar();
        }
        free(com);
        fclose(fp);
}

void listarCompra(void) {
	FILE* fp;
        Compras* com;
        fp = fopen("compras.dat", "rb");
        if (fp == NULL) {
                printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
                printf("Não é possível continuar o programa...\n");
                exit(1);
        }
        printf("\n\n");
        printf("==============================================\n");
        printf("-----|||    Listar todas as compras    |||----\n");
        printf("==============================================\n");
        com = (Compras*) malloc(sizeof(Compras));
        while(fread(com, sizeof(Compras), 1, fp)) {
                if (com->status == '1') {
                exibeCompras(com);
                }
        }
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        getchar();
        fclose(fp);
        free(com);
}

void exibeCompras(Compras* com) {
        printf("Nome do produto: %s\n", com->nome);
        printf("Preço do produto: %s\n", com->preco);
        printf("Código de barras: %s\n", com->codBarra);
        printf("Código da compra: %s\n", com->codCompra);
        printf("\n");
}

void gravaCompras(Compras* com) {
  FILE* fp;
  fp = fopen("compras.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(com, sizeof(Compras), 1, fp);
  fclose(fp);
}
