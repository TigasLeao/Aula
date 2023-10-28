#include "stdio.h"
#include "string.h"
#include "conio.h"

#define ENTER 13    // CÓDIGO ASCII DA TECLA ENTER
#define BACKSPACE 8 // CÓDIGO ASCII DA TECLA BACKSPACE
#define SPACE 32    // CÓDIGO ASCII DA TECLA BARRA DE ESPACO
#define TAB 9       // CÓDIGO ASCII DA TECLA BACKSPACE
#define ESC 27      // CÓDIGO ASCII DA TECLA ESC


int main()
{
 char ch = '\0';
 char vuser[20],user[20],vsenha[20],senha[20];
 int ctecla=0;

 strcpy(user,"Rogerio"); //Usuário correto
 strcpy(senha,"abcde"); //Senha correta

 memset(vuser, '\0', sizeof(vuser));
 memset(vsenha, '\0', sizeof(vsenha));

 printf("Usuario: ");
 scanf("%s", vuser);
 printf("Senha: ");

 while(ctecla<5)
 {
   ch = getch();

   switch(ch)
   {
    case BACKSPACE:
     if(ctecla>0)
     {
      fflush(stdin);
      putch(BACKSPACE);
      ch = '\0';
      vsenha[ctecla] = ch;
      ctecla--;
      putch(SPACE);
      putch(BACKSPACE);
     }
      break;
    case TAB:
     putch(TAB);
     ctecla = 5;
     break;
    case ENTER:
     putch(ENTER);
     ctecla = 5;
     break;
    default:
     vsenha[ctecla] = ch;
     putch('*');
     ctecla++;
     break;
   }
 }

 if(strcmp(user,vuser)==0 && strcmp(senha,vsenha)==0)
 {
   printf("\n\nAcesso permitido! %s %s",senha,vsenha);
 }
 else
 {
   printf("\n\nAcesso negado! %s %s",senha,vsenha);
 }

 return 0;
}
