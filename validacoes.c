#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int chartoint(char);
char inttochar(int);

int validaNome(char *pnome) {

    int tam = strlen(pnome);
    char letra;
    for (int i = 0; i < tam; i++)
    {
        letra = pnome[i];
        if (isdigit(letra)) {
            /*printf("Nome inVálido");
            break;*/
            return 1;
        }
        if (isspace(letra)) {
            //return 0;
        }
        if (isalpha(letra)) {
            //return 0;
        }
    }
    return 0;
    //printf("Nome Válido");
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
/*
int validaCpf(char *pcpf){

	int tamanho = strlen(pcpf);
    if (tamanho != 11) {
        return 0;
    } else {
      int num;
      int soma1 = 0;
      char digito1, digito2;
      int j = 0;
      for(int i = 10; i >= 2; i--){
        num = chartoint(pcpf[j]);
        num *= i;
        soma1 += num;
        j++;
      }
      soma1 = soma1 % 11;
      soma1 = 11 - soma1;
      if(soma1 > 9)
        soma1 = 0;
      digito1 = inttochar(soma1);
      if(digito1 != pcpf[9])
        return 0;
      else {
        j = 0;
        soma1 = 0;
        for(int i = 11; i >= 2; i--){
          num = chartoint(pcpf[j]);
          num *= i;
          soma1 += num;
          j++;
        }
        soma1 = soma1 % 11;
        soma1 = 11 - soma1;
        if(soma1 > 9)
          soma1 = 0;
        digito2 = inttochar(soma1);
        if(digito2 != pcpf[10])
          return 0;
        else
          return 1;
      }
    }  
}

int chartoint(char c){
    return c - '0';
}

char inttochar(int n){
  return n + 48;
} */