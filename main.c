#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

int main (void) {
	char menu_principal = ' ';
	do {
		menu_principal = menuPrincipal();
		printf(" %c", &menu_principal);
		switch(menu_principal) {
			
			case '1':
					menuCliente();
					break;
			case '2':
					menuEmpresa();
					break;
			case '3':
					menuSobre();
					printf("teste");
					break;
			case '4':
					printf("\n");
					printf(" Obrigado por ultilizar nossos serviços.Volte sempre.\n");
					printf("\n");
					break;
			default:
			    	printf("\n");
					printf(">>>Opção errada. Digite uma opção válida: ");
					printf("\n");
		}
    }		
	while (menu_principal != '5');
	return 0;
}