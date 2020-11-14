#include "assinaturas.h"


//FUNÇÃO DESENVOLVIDA NA MONITORIA POR ALUNOS E MONITOR

int chartoint(char);
char inttochar(int);

int validaNome(char *pnome) {

    int tam = strlen(pnome);
    char letra;
    for (int i = 0; i < tam; i++)
    {
        letra = pnome[i];
        if (isdigit(letra)) {
            return 1;
        }
        else if (isspace(letra)) {
        }
        else if (isalpha(letra)) {
        }
        else {
            return 1;
        }
    }
    return 0;
}



// Fonte na qual a validação de CPF foi retirada: https://gist.github.com/eduardoedson/8f991b6d234a9ebdcbe3

//Retorno: [1] - Se for válido | [0] - Se for inválido


int validaCpf(char *pcpf) {
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(pcpf) != 11)
        return 0;
    else 
        if((strcmp(pcpf,"00000000000") == 0) || (strcmp(pcpf,"11111111111") == 0) || (strcmp(pcpf,"22222222222") == 0) ||
            (strcmp(pcpf,"33333333333") == 0) || (strcmp(pcpf,"44444444444") == 0) || (strcmp(pcpf,"55555555555") == 0) ||
            (strcmp(pcpf,"66666666666") == 0) || (strcmp(pcpf,"77777777777") == 0) || (strcmp(pcpf,"88888888888") == 0) ||
            (strcmp(pcpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(pcpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (pcpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((pcpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(pcpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (pcpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((pcpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
} 


int bissexto(int ano) {

    if((ano % 4 == 0) && (ano % 100 != 0)) {

        return 1;

    } else if(ano % 400 == 0) {

        return 1;

    } else {

        return 0;

    }

}

// FUNÇÃO FEITA E DISPONIBILIZADA POR GABRIEL AZEVEDO, GIT: https://github.com/GabrielAzevedo3/
int dataValida(int dia, int mes, int ano) {
    int maiorDia;
    if (dia < 1 || mes < 1 || mes > 12 || ano < 0 || ano > 2020) {
        return 0;
    }
    if (mes == 2 ) {
        if (bissexto(ano)) {
            maiorDia = 29;
        } else {
            maiorDia = 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        maiorDia = 30;
    } else {
        maiorDia = 31;
    }
    if (dia > maiorDia) {
        return 0;
    }
    return 1;   
}



// FUNÇÃO FEITA POR HIAGO E DANRLEY

int validaEmail(char *email) {

  int tam = strlen(email);
  int arroba = 0, ponto = 0, Aponto = 0, Dponto = 0, i;

  for (i = 0; i < tam; i++){
    char c = email[i];

    if(c == '@'){
      if (arroba)
        break;
      arroba = 1;
      if (i < 3)
        break;
    }
    else if (arroba){ 
      if (ponto){ 
        Dponto++;
      }
      else if (c == '.'){
        ponto = 1;
        if (Aponto < 3){
          break;
        }
      }
      else{
        Aponto++;
      }
    }
  } 

  if (i == tam && Dponto > 1)
    return 1;
  else
    return 0;
}
