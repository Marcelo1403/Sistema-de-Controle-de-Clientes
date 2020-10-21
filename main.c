#include "assinaturas.h"

int main (void) {
	char opcao = ' ';
	do {
		limpaTela();
		opcao = menuPrincipal();
		printf(" %s", &opcao);
		switch(opcao) {
			
			case '1':
					gerenciarCliente();
					break;
			case '2':
					gerenciarEmpresa();
					break;
			case '3':
					menuSobre();
					break;
			case '0':
					printf("\n");
					printf(" Obrigado por ultilizar nossos serviços.Volte sempre.\n");
					printf("\n");
					break;
			default:
			    	printf("\n");
					printf("Opção errada. Digite uma opção válida: ");
					printf("\n");
		}
    }		
	while (opcao != '0');
	return 0;
}