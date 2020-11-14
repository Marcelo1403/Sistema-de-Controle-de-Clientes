#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Assinaturas das telas.

char menuPrincipal(void);
void menuCliente(void);
void menuCompras(void);
void menuRelatorios(void);
void menuSobre(void);


// Assinaturas das funcionalidades.

void limpaTela(void);

void gerenciarCliente(void);
void cadastrarCliente(void);
void pesquisarCliente(void);
void atualizarCliente(void);
void excluirCliente(void);
void listarCliente(void);

void gerenciarCompras(void);
void cadastrarCompra(void);
void pesquisarCompra(void);
void atualizarCompra(void);
void excluirCompra(void);
void listarCompra(void);

void gerenciarRelatorios(void);

// Assinaturas para validações
int validaNome(char *);
int validaCpf(char *);
int dataValida(int , int , int );
int bissexto(int );
int validaEmail(char *);

int chartoint(char);
char inttochar(int);