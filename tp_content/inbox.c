#include <stdio.h>
#include <stdlib.h>
#include "inbox.h"
#include "user.h"

struct lista{
    struct lista *prox; // ponteiro para o próximo da lista de menssagem
    UserList *usuario;

};

inboxList *ini_userList(){
    inboxList *li = (inboxList *) malloc(sizeof(inboxList)); // cria o primeiro elemento da lista
    if(li != NULL) // Verifica se a lista não está vazia
        *li = NULL;
    return li;
}
