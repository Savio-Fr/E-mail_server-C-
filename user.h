#ifndef USER_H
#define USER_H
#include "inbox.h"

typedef struct user{
    int id;
} User; // Contéudo para os usuários, no caso cada usuário terá um id

typedef struct cadastro UserList;
typedef struct cadastro *userList;

userList *ini_userList();// Cria a lista de usuário
void singUp_User(int); // Função para cadastrar um usuário

#endif