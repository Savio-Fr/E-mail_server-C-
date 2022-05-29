#ifndef _PROVEDOR_H
#define _PROVEDOR_H

#include "user.h"

typedef struct msg_t msg;
typedef struct caixa_de_entrada_t caixa_de_entrada; 
typedef struct provedor_t Provedor; 


Provedor *criar_provedor();
void free_provedor(Provedor *p);

caixa_de_entrada * criar_caixa_de_entrada();
void free_caixa_de_entrada(caixa_de_entrada *c);

msg * criar_mensagem(); 
void free_mensagem(caixa_de_entrada *c, msg *m);

void escrever_mensagem(Provedor *p);

void insere_msg(Provedor *p, msg *m, int idUsuario);
void remover_msg(usuario *u);
void imprime_caixa(Provedor *p, int idUsuario);

#endif /* _PROVEDOR_H */
