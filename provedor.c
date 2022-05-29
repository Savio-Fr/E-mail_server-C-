#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "provedor.h"
#include "user.h"

struct msg_t {
	int peso;
	char *descricao;
	msg *prox;
	msg *anterior;
};

struct caixa_de_entrada_t {
	msg * msg;
	int quantidade_msg;
};

typedef struct provedor_t {
	int qnt_usuarios;
	usuario *usuario;
}provedor;

Provedor * criar_provedor() {
	Provedor * p = (Provedor *) malloc(sizeof(Provedor));
	p->qnt_usuarios = 0;
	return p;
}

void free_provedor(Provedor * p) {
	while(p->qnt_usuarios > 0){
	    printf("chamada free_provedor.\n");
	    free_usuario(p, p->usuario);
	}
	free(p);
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

void escrever_mensagem(Provedor * p) {
   
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


void insere_msg(Provedor * p,msg * m, int idUsuario) {
	printf("Chamada: Inserir mensagem.\n");
	
    usuario *aux = criar_usuario();
	aux = p->usuario;

	
	if(p->qnt_usuarios > 0){
       
	    while(idUsuario > aux->id && aux->prox != NULL){
            aux = aux->prox;
        }
        
	    if(idUsuario != aux->id){
	        printf("Usuário não existe.\n");
	    }
        else if(aux->caixa->quantidade_msg > 0){   

            if(m->peso > aux->caixa->msg->peso){
	        	m->prox = aux->caixa->msg;
	        	aux->caixa->msg->anterior = m;
	        	aux->caixa->msg = m;
	        	aux->caixa->quantidade_msg++;
	        	printf("msg enviada.\n");

            } else{
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

	    }else{

	        aux->caixa->msg = m;
	        aux->caixa->quantidade_msg++;
	        printf("msg enviada.\n");
	        
	    }
    }else{
        printf("Não existem usuários cadastrados.\n");
    }
}

void imprime_caixa(Provedor * p, int idUsuario) {
	printf("Chamada: Imprime caixa. \n");
	
	int i = 0;
	usuario * aux = criar_usuario();
	aux = p->usuario;
	
	if (p->qnt_usuarios > 0){

	    while(idUsuario > aux->id && aux->prox != NULL){
            aux = aux->prox;
        }
	    if(idUsuario != aux->id){
	        printf("Usuário não existe.\n");
	    }
	    else if(aux->caixa->quantidade_msg == 0){
	    	printf("caixa de entrada vazia");  

	    }else{

	    	printf("%s \n", aux->caixa->msg->descricao);    
	    	remover_msg(aux);
	    	printf("Você ainda possui %d mensagens, Digite 1 para ler a proxima. \n" , aux->caixa->quantidade_msg);
	    	scanf("%d", &i);

	    	if (i == 1){
	    		imprime_caixa(p , idUsuario);
	    	}
	    }
    }else {
        printf("Não existem usuários cadastrados.\n");
    }
}

void remover_msg(usuario * u) {
	printf("Chamada: Remover mensagem.\n");
	free_mensagem(u->caixa, u->caixa->msg);
    printf("mensagem apagada.\n");
}

