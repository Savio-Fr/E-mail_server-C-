#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "caixa_de_entrada.h"

int main(){

    int a = 10;

    DESCRITOR_LISTA_DE_USUARIOS Descritor_Lista_de_Usuarios = {0, NULL, NULL};
    APONTADOR_LISTA_DE_USUARIOS *A= (APONTADOR_LISTA_DE_USUARIOS *)malloc(sizeof(APONTADOR_LISTA_DE_USUARIOS));
    
    cadastra_usuario(&Descritor_Lista_de_Usuarios,a);
    imprime_lista(A);
    free(A);
    printf("Hello world!\n");

    return 0;
}
