#include "assinaturas.h"

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
	printf("\n\n\nMódulo cadastrar Cliente\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
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

void gerenciarEmpresa(void){
    char opc = ' ';
    system("clear");
    
    do{
        limpaTela();
        menuEmpresa();
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


