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
                    printf("Opção de cadastro em desenvolvimento.");
                    break;

            case'2':
                    system("clear");
                    printf("Opção de pesquisar em desenvolvimento.");
                    break;
            
            case '3':
                    system("clear");
                    printf("Opção de atualizar dados em desenvolvimento.");
                    break;   

            case '4':
                    system("clear");
                    printf("Opção de excluir clientes em desenvolvimento.");
                    break;
            
            case '5':
                    system("clear");
                    printf("Opção de listar em desenvolvimento.");
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