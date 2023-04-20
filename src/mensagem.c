#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct msg_t{
	int peso;
	char * descricao;
	struct msg * prox;
	struct msg * anterior;
} msg;

int main () {
   
   
   msg * m = (msg *) malloc(sizeof(msg));
   char str[1024];
   const char s[2] = " ";
   const char t[2] = "F" ;
   char *token;
   int id;

   
    printf( "Digite a msg , exemplo: '5 1 Bom dia! FIM' \n");
    fgets(str, 1024, stdin); 
     
    token = strtok(str, s);
    id = atoi(token); 
    printf("ID: %d\n", id );
    
    token = strtok(NULL, s);
    m->peso = atoi(token);
    printf("PESO: %d\n", m->peso );
    
    token = strtok(NULL, t);
    m->descricao = token;
    printf( "MSG: %s\n", m->descricao );
   
   return(0);
}


