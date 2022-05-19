#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include "caixa_de_entrada.h"

typedef struct usuario {
    int Id;
    DESCRITOR_CAIXA_DE_ENTRADA Descritor_Caixa_de_Entrada;
} USUARIO;

typedef struct lista_de_usuarios *APONTADOR_LISTA_DE_USUARIOS;

typedef struct lista_de_usuarios {
    USUARIO Usuario;
    APONTADOR_LISTA_DE_USUARIOS Usuario_Anterior, Usuario_Posterior;
} LISTA_DE_USUARIOS;

typedef struct descritor_lista_de_usuarios {
    int Contador_Lista_de_Usuarios;
    APONTADOR_LISTA_DE_USUARIOS Primeiro_Usuario, Ultimo_Usuario;
} DESCRITOR_LISTA_DE_USUARIOS;

void cadastra_usuario(DESCRITOR_LISTA_DE_USUARIOS *, int);
void imprime_lista(APONTADOR_LISTA_DE_USUARIOS *);

#endif // USUARIO_H_INCLUDED
