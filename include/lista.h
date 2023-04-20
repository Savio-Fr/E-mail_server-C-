#ifndef __LISTA_H
#define __LISTA_H 

typedef struct msg_t msg;
typedef struct caixa_de_entrada_t caixa_de_entrada; 
typedef struct provedor_t provedor; 
typedef struct usuario_t usuario; 

/* *
 *
 * */

provedor * criar_provedor();
void free_provedor(provedor * p);

usuario * criar_usuario();
void free_usuario(provedor * p, usuario * u);

caixa_de_entrada * criar_caixa_de_entrada();
void free_caixa_de_entrada(caixa_de_entrada * c);

msg * criar_mensagem(); 
void free_mensagem(caixa_de_entrada * c, msg * m);

/* *
 *
 * */

int ler_idUsuario();
void escrever_mensagem(provedor *p);
void insere_usuario(provedor * p, int idUsuario);
void remove_usuario(provedor * p, int idUsuario);
void insere_msg(provedor * p, msg * m, int idUsuario);
void remover_msg(usuario * u);
void imprime_caixa(provedor * p, int idUsuario);

#endif /* __LISTA_H */
