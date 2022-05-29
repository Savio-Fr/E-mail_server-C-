#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h"
#include "provedor.h"

struct usuario_t {
	int id;
	caixa_de_entrada *caixa;
	usuario *prox;
	usuario *anterior;
};

usuario *criar_usuario(){
    usuario *u = (usuario *) malloc(sizeof(usuario));
    
    return u;
}
void free_usuario(provedor *p, usuario *u){

   printf("chamada free_usuario.\n");
   if(u->prox != NULL && u->anterior != NULL){
        u->anterior->prox = u->prox;
        u->prox->anterior = u->anterior;
   }else if(u->anterior == NULL){
        p->usuario = u->prox;
   }

   free_caixa_de_entrada(u->caixa);
   free(u);
   p->qnt_usuarios--;
}

int ler_idUsuario(){
	
	int id;
	printf("Chamada: ler id do usuario.\n");
	printf(" DIGITE O ID DO USUÁRIO\n");
    scanf("%d", &id);
    
	return id;
}

void insere_usuario(provedor * p, int idUsuario) {
	printf("Chamada: Inserir usuario.\n");
    
    usuario *u = criar_usuario();
    usuario * aux = criar_usuario();
    caixa_de_entrada *caixa = criar_caixa_de_entrada();
    msg * m = criar_mensagem();
    u->id = idUsuario;
    u->caixa = caixa;
    u->caixa->msg = m;
    
    if(p->qnt_usuarios == 0){

        p->usuario = u;
        u->prox = NULL;
        u->anterior = NULL;
        p->qnt_usuarios++;

        printf("Usuário inserido com sucesso.\n");
    }else if(idUsuario < p->usuario->id){

       p->usuario->anterior = u;
       u->prox = p->usuario;
       u->anterior = NULL;
       p->usuario = u;
       p->qnt_usuarios++;
       printf("Usuário inserido com sucesso.\n");
    }else if(idUsuario >= p->usuario->id){

        aux = p->usuario;
        while(idUsuario > aux->id && aux->prox != NULL){
            aux = aux->prox;
        }
        if (idUsuario != aux->id){

            if(aux->anterior!= NULL){
                aux->anterior->prox = u;
            }

            u->prox = aux;
            u->anterior = aux->anterior;
            aux->anterior = u;
            p->qnt_usuarios++;

            printf("Usuário inserido com sucesso.\n");
        }else{
            printf ("usuario ja existente \n");
        }   
    }
    printf("qnt de usuários: %d \n", p->qnt_usuarios);    
}
void remove_usuario(provedor * p, int idUsuario) {
	printf("Chamada: Remove usuario.\n");
	
	usuario * aux = criar_usuario();
	aux = p->usuario;
	printf("qnt de usuários: %d \n", p->qnt_usuarios);
	
	if(p->qnt_usuarios > 0){
	    while(idUsuario != aux->id && aux->prox != NULL){
            aux = aux->prox;
        }
        if(idUsuario != aux->id){
	        printf("Usuário não existe.\n");
	    }else{

            if(aux->anterior != NULL && aux->prox != NULL){
               aux->prox->anterior = aux->anterior;

            } else if (aux->prox != NULL){
                p->usuario = aux->prox;
            }
          free_usuario(p, aux);
          printf("Usuário removido com sucesso.\n");
          printf("qnt de usuários: %d \n", p->qnt_usuarios);
        }           
	}else {
	    printf("Não existem usuários cadastrados.\n");
	}
    
}