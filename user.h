#ifndef _USER_H
#define _USER_H 

#include "provedor.h"


typedef struct usuario_t usuario; 

usuario * criar_usuario();
void free_usuario(Provedor * p, usuario * u);

int ler_idUsuario();
void insere_usuario(Provedor * p, int idUsuario);
void remove_usuario(Provedor * p, int idUsuario);


#endif /* _USER_H */