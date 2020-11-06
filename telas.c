#include "assinaturas.h"


char menuPrincipal(void) {
	char escolha = ' ';
	system("clear");
	printf("\n");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("|||                                                                     |||\n");
  	printf("|||            ============================================             |||\n");
	printf("|||            = = = = > > > > Menu Principal < < < < = = =             |||\n");
  	printf("|||            ============================================             |||\n");
	printf("|||                                                                     |||\n");
	printf("|||            1. Menu Cliente                                          |||\n");
	printf("|||            2. Menu Compras                                          |||\n");
	printf("|||            3. Menu Relatório                                        |||\n");
	printf("|||            4. Sobre o Programa                                      |||\n");
	printf("|||            0. Encerrar programa                                     |||\n");
  	printf("|||                                                                     |||\n");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("\n");
	printf("Por favor, escolha uma opção: \n");
    scanf(" %c", &escolha);
	getchar();
    return (escolha);
	printf("\n");
}



void menuCliente(void) {
    system("clear");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("|||                                                                     |||\n");
  	printf("|||            ============================================             |||\n");
	printf("|||            = = = = > > > > Menu Cliente < < < < = = = =	            |||\n");
  	printf("|||            ============================================             |||\n");
	printf("|||                                                                     |||\n");
	printf("|||            1. Cadastrar um novo cliente                             |||\n");
	printf("|||            2. Pesquisar os dados de um cliente                      |||\n");
	printf("|||            3. Atualizar o cadastro de um cliente                    |||\n");
	printf("|||            4. Excluir um cliente do sistema                         |||\n");
	printf("|||            5. Listar todos os clientes                              |||\n");
	printf("|||            0. Voltar ao menu anterior                               |||\n");
	printf("|||                                                                     |||\n");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("\n");
}

void menuRelatorios(void) {
    system("clear");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("|||                                                                     |||\n");
  	printf("|||            ===========================================              |||\n");
	printf("|||            = = = > > > > Menu Relatórios < < < < = = =              |||\n");
  	printf("|||            ===========================================              |||\n");
	printf("|||                                                                     |||\n");
	printf("|||            1. Relatório financeiro                                  |||\n");
	printf("|||            2. Relatório de vendas                                   |||\n");
	printf("|||            0. Voltar ao menu anterior                               |||\n");
	printf("|||                                                                     |||\n");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("\n");
}



void menuSobre(void) {
    system("clear");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("|||                                                                           |||\n");
	printf("|||              Universidade Federal do Rio Grande do Norte                  |||\n");
	printf("|||                  Centro de Ensino Superior do Seridó                      |||\n");
	printf("|||                Departamento de Computação e Tecnologia                    |||\n");
	printf("|||                   Disciplina DCT1106 -- Programação                       |||\n");
	printf("|||                   Projeto Sistema de Gestão Escolar                       |||\n");
	printf("|||               Developed by  @marcelovictor_js - Sep, 2020                 |||\n");
	printf("|||                                                                           |||\n");
	printf("|||///////////////////////////////////////////////////////////////////////////|||\n");
	printf("|||                                                                           |||\n");
	printf("|||           > > > > > Sistema de Controle de Clientes < < < < <             |||\n");
	printf("|||                                                                           |||\n");
	printf("|||  As empresas da atualidade utilizam complexos sistemas gerenciais para    |||\n");
	printf("|||  entre várias outras funções, gerenciar e manter seus clientes, além de   |||\n");
	printf("|||  ajudar a conseguir novos clientes. O presente projeto tem como objetivo  |||\n");
	printf("|||  propor um software que implemente funcionalidades básicas relacionadas   |||\n");
	printf("|||  ao controle de clientes de uma empresa, facilitando a gestão.            |||\n");
	printf("|||                                                                           |||\n");
	printf("|||///////////////////////////////////////////////////////////////////////////|||\n");
	printf("|||                                                                           |||\n");
	printf("|||         > > > > > Informações sobre o desenvolvedo < < < < <              |||\n");
	printf("|||                                                                           |||\n");
	printf("|||                 Nome:      MARCELO VICTOR MELO NUNES                      |||\n");
	printf("|||                                                                           |||\n");
	printf("|||                 Instagram: @marcelovictor_js                              |||\n");
	printf("|||                                                                           |||\n");
	printf("|||                 Email:     marcelo@ufrn.edu.br                            |||\n");
	printf("|||                                                                           |||\n");
	printf("|||                 Github:    github.com/marcelo1403                         |||\n");
	printf("|||                                                                           |||\n");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

