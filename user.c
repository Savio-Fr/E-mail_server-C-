#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "inbox.h"

struct cadastro{
    User dados; // Conteúdo dos usuários
    Inbox *msgBox; // Ponteiro para a caixa de menssagem
    struct cadastro *prox; // Ponteiro para o próximo usuário
};

typedef struct cadastro UserList; // Typedef para a lista de Usuários

userList *ini_userList(){
    userList *li = (userList *) malloc(sizeof(userList)); // cria o primeiro elemento da lista
    if(li != NULL) // Verifica se a lista não está vazia
        *li = NULL;
    return li;
}
