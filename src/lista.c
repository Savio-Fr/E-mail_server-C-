#include "lista.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct msg_t {
	int peso;
	char * descricao;
	msg * prox;
	msg * anterior;
};

struct caixa_de_entrada_t {
	msg * msg;
	int quantidade_msg;
};

struct usuario_t {
	int id;
	caixa_de_entrada * caixa;
	usuario * prox;
	usuario * anterior;
};

typedef struct provedor_t {
	int qnt_usuarios;
	usuario * usuario;
}Provedor_t;

/* *
 *
 * */

provedor * criar_provedor() {
	provedor * p = (provedor *) malloc(sizeof(provedor));
	p->qnt_usuarios = 0;
	return p;
}

void free_provedor(provedor * p) {
	while(p->qnt_usuarios > 0){
	    printf("chamada free_provedor.\n");
	    free_usuario(p, p->usuario);
	}
	free(p);
}

usuario * criar_usuario(){
    usuario * u = (usuario *) malloc(sizeof(usuario));
    
    return u;
}

void free_usuario(provedor * p, usuario * u){
   
   printf("chamada free_usuario.\n");
   if(u->prox != NULL && u->anterior != NULL){
   u->anterior->prox = u->prox;
   u->prox->anterior = u->anterior;
   }
   else if(u->anterior == NULL){
   p->usuario = u->prox;
   }
   free_caixa_de_entrada(u->caixa);
   free(u);
   p->qnt_usuarios--;
}

caixa_de_entrada * criar_caixa_de_entrada(){
    caixa_de_entrada * caixa = (caixa_de_entrada *) malloc(sizeof(caixa_de_entrada));
	
	return caixa;
}
void free_caixa_de_entrada(caixa_de_entrada * c){
    
    printf("chamada free_caixa_de_entrada.\n");

    while (c->quantidade_msg != 0){
    free_mensagem(c , c->msg);
    }
    free(c);
}

msg * criar_mensagem(){
    msg * m = (msg *) malloc(sizeof(msg));
	
	return m;
} 
void free_mensagem(caixa_de_entrada * c,msg * m){
     
     printf("chamada free_mensagem\n");
     if(c->msg->prox != NULL){
     c->msg = c->msg->prox;
     free(m);
     }
     c->quantidade_msg-- ;
}


/* *
 *
 * */


int ler_idUsuario(){
	
	int id;
	printf("Chamada: ler id do usuario.\n");
	printf(" DIGITE O ID DO USUÁRIO\n");
    scanf("%d", &id);
    
	return id;
}


void insere_usuario(provedor * p, int idUsuario) {
	printf("Chamada: Inserir usuario.\n");
    
    usuario * u = criar_usuario();
    usuario * aux = criar_usuario();
    caixa_de_entrada * caixa = criar_caixa_de_entrada();
    msg * m = criar_mensagem();
    u->id = idUsuario;
    u->caixa = caixa;
    u->caixa->msg = m;
    
    
    if(p->qnt_usuarios == 0)
    {
        p->usuario = u;
        u->prox = NULL;
        u->anterior = NULL;
        p->qnt_usuarios++;
        printf("Usuário inserido com sucesso.\n");
    }
    else if(idUsuario < p->usuario->id)
    {
       p->usuario->anterior = u;
       u->prox = p->usuario;
       u->anterior = NULL;
       p->usuario = u;
       p->qnt_usuarios++;
       printf("Usuário inserido com sucesso.\n");
    }
    else if(idUsuario >= p->usuario->id)
        {
        aux = p->usuario;
        while(idUsuario > aux->id && aux->prox != NULL)
        {
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
        }
        
        else{
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
	while(idUsuario != aux->id && aux->prox != NULL)
        {
            aux = aux->prox;
        }
    if(idUsuario != aux->id){
	    printf("Usuário não existe.\n");
	}
	else
	{
	    if(aux->anterior != NULL && aux->prox != NULL){
	    aux->prox->anterior = aux->anterior;
	    }
	    else if(aux->prox != NULL){
	    p->usuario = aux->prox;
	    }
	    free_usuario(p, aux);
	    printf("Usuário removido com sucesso.\n");
	    printf("qnt de usuários: %d \n", p->qnt_usuarios);
	}    
	}
	else 
	{
	printf("Não existem usuários cadastrados.\n");
	}
	

	
}

void escrever_mensagem(provedor * p) {
   
   printf("Chamada: escrever_mensagem.\n");
   
   msg * m = criar_mensagem();
   char str[1024];
   const char s[2] = " ";
   const char t[4] = "FIM";
   char *token;
   int id;
   

    printf( " digite a msg , exemplo: '5 1 Bom dia! FIM' \n");
    fgets (str, 1024, stdin); 

    token = strtok(str, s);
    id = atoi(token); 
    printf("ID: %d\n", id);
    
    token = strtok(NULL, s);
    m->peso = atoi(token);
    printf("PESO: %d\n", m->peso );
    
    token = strtok(NULL, t);
    m->descricao = token;
    printf( "MSG: %s\n", m->descricao);
    
    insere_msg(p, m, id);

}


void insere_msg(provedor * p,msg * m, int idUsuario) {
	printf("Chamada: Inserir mensagem.\n");
	
    usuario * aux = criar_usuario();
	aux = p->usuario;

	
	if(p->qnt_usuarios > 0)
	{
       
	    while(idUsuario > aux->id && aux->prox != NULL)
        {
            aux = aux->prox;
        }
        
	    if(idUsuario != aux->id){
	        printf("Usuário não existe.\n");
	    }
        else if(aux->caixa->quantidade_msg > 0)
        {   
            if(m->peso > aux->caixa->msg->peso){
	        m->prox = aux->caixa->msg;
	        aux->caixa->msg->anterior = m;
	        aux->caixa->msg = m;
	        aux->caixa->quantidade_msg++;
	        printf("msg enviada.\n");
            }
	        else{
	            while(aux->caixa->msg->peso > m->peso && aux->caixa->msg->prox != NULL){
	                aux->caixa->msg = aux->caixa->msg->prox;
	        }
	        m->prox = aux->caixa->msg;
	        if (aux->caixa->msg->anterior != NULL){
	        m->anterior = aux->caixa->msg->anterior;
	        aux->caixa->msg->anterior->prox = m;
	        }
	        aux->caixa->msg->anterior = m;
	        aux->caixa->quantidade_msg++;
	        printf("msg enviada.\n");
	        }
	    }
	    else 
	    {
	        aux->caixa->msg = m;
	        aux->caixa->quantidade_msg++;
	        printf("msg enviada.\n");
	        
	    }
    }
    else
    {
        printf("Não existem usuários cadastrados.\n");
    }
}

void imprime_caixa(provedor * p, int idUsuario) {
	printf("Chamada: Imprime caixa. \n");
	
	int i = 0;
	usuario * aux = criar_usuario();
	aux = p->usuario;
	
	if (p->qnt_usuarios > 0){
	    while(idUsuario > aux->id && aux->prox != NULL)
            {
                aux = aux->prox;
            }
	    if(idUsuario != aux->id){
	        printf("Usuário não existe.\n");
	    }
	    else if(aux->caixa->quantidade_msg == 0){
	    printf("caixa de entrada vazia");  
	    }
	    else{
	    printf("%s \n", aux->caixa->msg->descricao);    
	    remover_msg(aux);
	    printf("Você ainda possui %d mensagens, Digite 1 para ler a proxima. \n" , aux->caixa->quantidade_msg);
	    scanf("%d", &i);
	    if (i == 1){
	    imprime_caixa(p , idUsuario);
	    }
	    }
    }
    else {
        printf("Não existem usuários cadastrados.\n");
    }
}


void remover_msg(usuario * u) {
	printf("Chamada: Remover mensagem.\n");
	free_mensagem(u->caixa, u->caixa->msg);
    printf("mensagem apagada.\n");
}

